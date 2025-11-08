
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>


int main(void) {
    int result = ft_printf("saad %s%%%f", "ssad");
    printf("\nReturn value: %d\n", result);
    return (0);
}