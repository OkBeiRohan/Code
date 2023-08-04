/*
 * dma.c
 *
 *  Created on: Aug 3, 2023
 *      Author: WON1COB
 */

#include <dma.h>
#include <stm32f405xx.h>

void dma2_mem2mem_config(void)
{
    // Enable DMA2 clock
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

    // Disable DMA2 Stream 0
    DMA2_Stream0->CR = 0;

    // Wait for DMA2 Stream 0 to be disabled
    while (DMA2_Stream0->CR & DMA_SxCR_EN)
        ;

    // Memory size to halfword>>bit 14 and 13 of CR to be 0 1
    DMA2_Stream0->CR |= (1 << 13);

    // Peripheral size to be also halfword>>bit 12 and 11 of CR to be 0 1
    DMA2_Stream0->CR |= (1 << 11);

    // Set memory increment mode
    DMA2_Stream0->CR |= DMA_SxCR_MINC;

    // Set peripheral increment mode
    DMA2_Stream0->CR |= DMA_SxCR_PINC;

    // Set data transfer direction to memory-to-memory
    DMA2_Stream0->CR |= (1 << 7);
}

void dma2_transfer_start(uint32_t src, uint32_t dst, uint32_t size)
{
    // Wait for DMA2 Stream 0 to be disabled
    while (DMA2_Stream0->CR & DMA_SxCR_EN)
        ;

    // Set source address
    DMA2_Stream0->PAR = src;

    // Set destination address
    DMA2_Stream0->M0AR = dst;

    // Set number of data items to transfer
    DMA2_Stream0->NDTR = size;

    // Enable DMA2 Stream 0
    DMA2_Stream0->CR |= DMA_SxCR_EN;
}
