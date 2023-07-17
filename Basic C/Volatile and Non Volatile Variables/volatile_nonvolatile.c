/**
 * Comparing the differences of volatile and non-volatile variables
 */

#include <stdio.h>

int main()
{
    /**
     * Volatile variables are variables that can be changed by other processes
     * outside of the program. This means that the compiler will not optimize the
     * code that uses the variable. This is useful for variables that are used
     * in an interrupt service routine (ISR) or a multi-threaded program.
     *
     * The volatile keyword is a type qualifier that prevents the compiler from
     * optimizing the code that uses the variable.
     */
    volatile int i = 4, x;
    int j = 4;

    /**
     * The post increment operator increments the variable after the expression
     * is evaluated. The pre increment operator increments the variable before
     * the expression is evaluated.
     *
     * The post increment operator is slower than the pre increment operator
     * because the post increment operator has to create a copy of the variable
     * before incrementing it. The pre increment operator does not have to create
     * a copy of the variable.
     *
     * The post increment operator is useful when the value of the variable is
     * needed before the variable is incremented. The pre increment operator is
     * useful when the value of the variable is needed after the variable is
     * incremented.
     */
    x = i++ + i++ + i++ + i++;
    printf("Post Increment Volatile: %d\n", x);

    /**
     * The pre increment operator is faster than the post increment operator
     * because the pre increment operator does not have to create a copy of the
     * variable.
     *
     * The pre increment operator is useful when the value of the variable is
     * needed after the variable is incremented. The post increment operator is
     * useful when the value of the variable is needed before the variable is
     * incremented.
     */
    i = 4;
    x = ++i + ++i + ++i + ++i;
    printf("Pre Increment Volatile: %d\n\n", x);
    x = j++ + j++ + j++ + j++;
    printf("Post Increment: %d\n", x);
    j = 4;
    x = ++j + ++j + ++j + ++j;
    printf("Pre Increment: %d\n", x);

    /**
     * Volatile in pre increment produces different results than volatile in
     * post increment. This is because the compiler optimizes the code that uses
     * the variable. The compiler does not optimize the code that uses the
     * volatile variable. 1 extra value is added to the pre increment non volatile variable
     * because the space for the variable is allocated before the variable is incremented.
     */
}