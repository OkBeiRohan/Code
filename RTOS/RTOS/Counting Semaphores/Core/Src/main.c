/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Demo includes. */
#include "supporting_functions.c"
/* Private includes ----------------------------------------------------------*/
SemaphoreHandle_t xCountingSemaphore;
/* The number of the simulated interrupt used in this example.  Numbers 0 to 2
are used by the FreeRTOS Windows port itself, so 3 is the first number available
to the application. */
//#define mainINTERRUPT_NUMBER	3
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
/* The tasks to be created. */
static void vHandlerTask( void *pvParameters );
static void vPeriodicTask( void *pvParameters );
/* The service routine for the (simulated) interrupt.  This is the interrupt
that the task will be synchronized with. */
static uint32_t ulExampleInterruptHandler( void );


int main(void)
{
  /* USER CODE BEGIN 1 */

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();
  xCountingSemaphore = xSemaphoreCreateCounting( 10, 0 );

  	/* Check the semaphore was created successfully. */
  	if( xCountingSemaphore != NULL )
  	{
  		/* Create the 'handler' task, which is the task to which interrupt
  		processing is deferred, and so is the task that will be synchronized
  		with the interrupt.  The handler task is created with a high priority to
  		ensure it runs immediately after the interrupt exits.  In this case a
  		priority of 3 is chosen. */
  		xTaskCreate( vHandlerTask, "Handler", 1000, NULL, 3, NULL );

  		/* Create the task that will periodically generate a software interrupt.
  		This is created with a priority below the handler task to ensure it will
  		get preempted each time the handler task exits the Blocked state. */
  		xTaskCreate( vPeriodicTask, "Periodic", 1000, NULL, 1, NULL );

  		/* Install the handler for the software interrupt.  The syntax necessary
  		to do this is dependent on the FreeRTOS port being used.  The syntax
  		shown here can only be used with the FreeRTOS Windows port, where such
  		interrupts are only simulated. */
  		vPortSetInterruptHandler( mainINTERRUPT_NUMBER, ulExampleInterruptHandler );

  		/* Start the scheduler so the created tasks start executing. */
  		vTaskStartScheduler();
  	}

  	/* The following line should never be reached because vTaskStartScheduler()
  	will only return if there was not enough FreeRTOS heap memory available to
  	create the Idle and (if configured) Timer tasks.  Heap management, and
  	techniques for trapping heap exhaustion, are described in the book text. */
  	for( ;; );
  	return 0;
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
static void vHandlerTask( void *pvParameters )
{
	/* As per most tasks, this task is implemented within an infinite loop. */
	for( ;; )
	{
		/* Use the semaphore to wait for the event.  The semaphore was created
		before the scheduler was started so before this task ran for the first
		time.  The task blocks indefinitely meaning this function call will only
		return once the semaphore has been successfully obtained - so there is
		no need to check the returned value. */
		xSemaphoreTake( xCountingSemaphore, portMAX_DELAY );

		/* To get here the event must have occurred.  Process the event (in this
		case just print out a message). */
		vPrintString( "Handler task - Processing event.\r\n" );
	}
}
/*-----------------------------------------------------------*/

static void vPeriodicTask( void *pvParameters )
{
const TickType_t xDelay500ms = pdMS_TO_TICKS( 500UL );

	/* As per most tasks, this task is implemented within an infinite loop. */
	for( ;; )
	{
		/* This task is just used to 'simulate' an interrupt.  This is done by
		periodically generating a simulated software interrupt.  Block until it
		is time to generate the software interrupt again. */
		vTaskDelay( xDelay500ms );

		/* Generate the interrupt, printing a message both before and after
		the interrupt has been generated so the sequence of execution is evident
		from the output.

		The syntax used to generate a software interrupt is dependent on the
		FreeRTOS port being used.  The syntax used below can only be used with
		the FreeRTOS Windows port, in which such interrupts are only
		simulated. */
		vPrintString( "Periodic task - About to generate an interrupt.\r\n" );
		vPortGenerateSimulatedInterrupt( mainINTERRUPT_NUMBER );
		vPrintString( "Periodic task - Interrupt generated.\r\n\r\n\r\n" );
	}
}
/*-----------------------------------------------------------*/

static uint32_t ulExampleInterruptHandler( void )
{
BaseType_t xHigherPriorityTaskWoken;

	/* The xHigherPriorityTaskWoken parameter must be initialized to pdFALSE as
	it will get set to pdTRUE inside the interrupt safe API function if a
	context switch is required. */
	xHigherPriorityTaskWoken = pdFALSE;

	/* 'Give' the semaphore multiple times.  The first will unblock the deferred
	interrupt handling task, the following 'gives' are to demonstrate that the
	semaphore latches the events to allow the handler task to process them in
	turn without events getting lost.  This simulates multiple interrupts being
	processed by the processor, even though in this case the events are
	simulated within a single interrupt occurrence.*/
	xSemaphoreGiveFromISR( xCountingSemaphore, &xHigherPriorityTaskWoken );
	xSemaphoreGiveFromISR( xCountingSemaphore, &xHigherPriorityTaskWoken );
	xSemaphoreGiveFromISR( xCountingSemaphore, &xHigherPriorityTaskWoken );

	/* Pass the xHigherPriorityTaskWoken value into portYIELD_FROM_ISR().  If
	xHigherPriorityTaskWoken was set to pdTRUE inside xSemaphoreGiveFromISR()
	then calling portYIELD_FROM_ISR() will request a context switch.  If
	xHigherPriorityTaskWoken is still pdFALSE then calling
	portYIELD_FROM_ISR() will have no effect.  The implementation of
	portYIELD_FROM_ISR() used by the Windows port includes a return statement,
	which is why this function does not explicitly return a value. */
	portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
