#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// Include your ft_printf header
#include "ft_printf.h"

void test_char_conversion(void)
{
    printf("=== %%c CONVERSION TESTS ===\n\n");
    
    struct test_case {
        int input;
        char *description;
    } tests[] = {
        {'A', "Regular uppercase letter"},
        {'z', "Regular lowercase letter"},
        {' ', "Space character"},
        {'\\n', "Newline character"},
        {'\\t', "Tab character"},
        {'\\0', "Null character"},
        {0, "Zero (null terminator)"},
        {127, "ASCII 127 (DEL)"},
        {128, "Extended ASCII 128"},
        {255, "Extended ASCII 255"},
        {65, "Integer 65 (should print 'A')"},
        {48, "Integer 48 (should print '0')"},
        {-1, "Negative number (implementation defined)"},
    };
    
    for (int i = 0; i < 13; i++)
    {
        printf("Test %2d: %s\n", i + 1, tests[i].description);
        printf("Input: %d\n", tests[i].input);
        
        printf("Real: '");
        int real_ret = printf("%c", tests[i].input);
        printf("' (%d chars)\n", real_ret);
        
        printf("Fake: '");
        int fake_ret = ft_printf("%c", tests[i].input);
        printf("' (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
}

void test_string_conversion(void)
{
    printf("=== %%s CONVERSION TESTS ===\n\n");
    
    char *tests[] = {
        "hello world",       // Normal string
        "",                  // Empty string
        "a",                 // Single character
        "multiple words",    // String with spaces
        "special\tchars\n",  // String with special chars
        "line1\nline2",      // String with newline
        "12345",             // Numeric string
        "~!@#$%^&*()",       // Special characters
        "very long string that goes on and on and on and on and on", // Long string
        NULL,                // NULL pointer
    };
    
    char *descriptions[] = {
        "Normal string",
        "Empty string",
        "Single character string", 
        "String with spaces",
        "String with special characters",
        "String with newline",
        "Numeric string",
        "Special characters string",
        "Very long string",
        "NULL pointer",
    };
    
    for (int i = 0; i < 10; i++)
    {
        printf("Test %2d: %s\n", i + 1, descriptions[i]);
        printf("Input: %s\n", tests[i] ? tests[i] : "NULL");
        
        printf("Real: \"");
        int real_ret = printf("%s", tests[i]);
        printf("\" (%d chars)\n", real_ret);
        
        printf("Fake: \"");
        int fake_ret = ft_printf("%s", tests[i]);
        printf("\" (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
}

void test_pointer_conversion(void)
{
    printf("=== %%p CONVERSION TESTS ===\n\n");
    
    // Create various pointers to test
    int x = 42;
    char c = 'A';
    char *str = "test";
    int arr[10];
    void *heap_ptr = malloc(100);
    
    struct test_case {
        void *ptr;
        char *description;
    } tests[] = {
        {&x, "Stack integer pointer"},
        {&c, "Stack character pointer"},
        {str, "String literal pointer"},
        {arr, "Array pointer"},
        {heap_ptr, "Heap allocated pointer"},
        {NULL, "NULL pointer"},
        {(void *)0, "Zero pointer"},
        {(void *)-1, "Pointer value -1"},
        {(void *)LONG_MAX, "Maximum pointer value"},
        {(void *)0x123456789ABCDEF, "Large pointer value"},
    };
    
    for (int i = 0; i < 10; i++)
    {
        printf("Test %2d: %s\n", i + 1, tests[i].description);
        
        printf("Real: ");
        int real_ret = printf("%p", tests[i].ptr);
        printf(" (%d chars)\n", real_ret);
        
        printf("Fake: ");
        int fake_ret = ft_printf("%p", tests[i].ptr);
        printf(" (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
    
    free(heap_ptr);
}

void test_decimal_conversion(void)
{
    printf("=== %%d CONVERSION TESTS ===\n\n");
    
    int tests[] = {
        0,          // Zero
        1,          // Small positive
        -1,         // Small negative
        42,         // Medium positive
        -42,        // Medium negative
        123456789,  // Large positive
        -123456789, // Large negative
        INT_MAX,    // Maximum integer
        INT_MIN,    // Minimum integer
        1000000000, // Billion
        -1000000000,// Negative billion
        9,          // Single digit
        -9,         // Single digit negative
    };
    
    char *descriptions[] = {
        "Zero",
        "Small positive (1)",
        "Small negative (-1)", 
        "Medium positive (42)",
        "Medium negative (-42)",
        "Large positive (123456789)",
        "Large negative (-123456789)",
        "INT_MAX",
        "INT_MIN",
        "Billion",
        "Negative billion",
        "Single digit positive",
        "Single digit negative",
    };
    
    for (int i = 0; i < 13; i++)
    {
        printf("Test %2d: %s\n", i + 1, descriptions[i]);
        printf("Input: %d\n", tests[i]);
        
        printf("Real: ");
        int real_ret = printf("%d", tests[i]);
        printf(" (%d chars)\n", real_ret);
        
        printf("Fake: ");
        int fake_ret = ft_printf("%d", tests[i]);
        printf(" (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
}

void test_integer_conversion(void)
{
    printf("=== %%i CONVERSION TESTS ===\n\n");
    
    // %i should behave identically to %d for decimal numbers
    int tests[] = {
        0,
        1,
        -1,
        42,
        -42,
        123456789,
        -123456789,
        INT_MAX,
        INT_MIN,
        010,        // Octal literal (should print 8)
        0x10,       // Hex literal (should print 16)
    };
    
    char *descriptions[] = {
        "Zero",
        "Small positive",
        "Small negative",
        "Medium positive", 
        "Medium negative",
        "Large positive",
        "Large negative",
        "INT_MAX",
        "INT_MIN",
        "Octal literal 010",
        "Hex literal 0x10",
    };
    
    for (int i = 0; i < 11; i++)
    {
        printf("Test %2d: %s\n", i + 1, descriptions[i]);
        printf("Input: %d\n", tests[i]);
        
        printf("Real: ");
        int real_ret = printf("%i", tests[i]);
        printf(" (%d chars)\n", real_ret);
        
        printf("Fake: ");
        int fake_ret = ft_printf("%i", tests[i]);
        printf(" (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
}

void test_unsigned_conversion(void)
{
    printf("=== %%u CONVERSION TESTS ===\n\n");
    
    unsigned int tests[] = {
        0,          // Zero
        1,          // Small
        42,         // Medium
        123456789,  // Large
        UINT_MAX,   // Maximum unsigned
        1000000000, // Billion
        9,          // Single digit
        4294967295, // UINT_MAX explicit
        -1,         // Should wrap around to UINT_MAX
        -42,        // Should wrap around
    };
    
    char *descriptions[] = {
        "Zero",
        "Small (1)",
        "Medium (42)",
        "Large (123456789)",
        "UINT_MAX",
        "Billion",
        "Single digit",
        "UINT_MAX explicit",
        "-1 (wraps to UINT_MAX)",
        "-42 (wraps)",
    };
    
    for (int i = 0; i < 10; i++)
    {
        printf("Test %2d: %s\n", i + 1, descriptions[i]);
        printf("Input: %u\n", tests[i]);
        
        printf("Real: ");
        int real_ret = printf("%u", tests[i]);
        printf(" (%d chars)\n", real_ret);
        
        printf("Fake: ");
        int fake_ret = ft_printf("%u", tests[i]);
        printf(" (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
}

void test_hex_lowercase_conversion(void)
{
    printf("=== %%x CONVERSION TESTS (lowercase) ===\n\n");
    
    unsigned int tests[] = {
        0,          // Zero
        1,          // Small
        10,         // a
        15,         // f
        16,         // 10
        255,        // ff
        4095,       // fff
        65535,      // ffff
        0xABCDEF,   // abcdef
        UINT_MAX,   // ffffffff
        0x12345678, // Mixed case test
        0xDEADBEEF, // Fun value
    };
    
    char *descriptions[] = {
        "Zero",
        "One",
        "Ten (a)",
        "Fifteen (f)",
        "Sixteen (10)",
        "255 (ff)",
        "4095 (fff)",
        "65535 (ffff)",
        "0xABCDEF (abcdef)",
        "UINT_MAX (ffffffff)",
        "0x12345678",
        "0xDEADBEEF",
    };
    
    for (int i = 0; i < 12; i++)
    {
        printf("Test %2d: %s\n", i + 1, descriptions[i]);
        printf("Input: %u (0x%x)\n", tests[i], tests[i]);
        
        printf("Real: ");
        int real_ret = printf("%x", tests[i]);
        printf(" (%d chars)\n", real_ret);
        
        printf("Fake: ");
        int fake_ret = ft_printf("%x", tests[i]);
        printf(" (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
}

void test_hex_uppercase_conversion(void)
{
    printf("=== %%X CONVERSION TESTS (uppercase) ===\n\n");
    
    unsigned int tests[] = {
        0,          // Zero
        1,          // Small
        10,         // A
        15,         // F
        16,         // 10
        255,        // FF
        4095,       // FFF
        65535,      // FFFF
        0xABCDEF,   // ABCDEF
        UINT_MAX,   // FFFFFFFF
        0x12345678, // Mixed case test
        0xDEADBEEF, // Fun value
    };
    
    char *descriptions[] = {
        "Zero",
        "One",
        "Ten (A)",
        "Fifteen (F)",
        "Sixteen (10)",
        "255 (FF)",
        "4095 (FFF)",
        "65535 (FFFF)",
        "0xABCDEF (ABCDEF)",
        "UINT_MAX (FFFFFFFF)",
        "0x12345678",
        "0xDEADBEEF",
    };
    
    for (int i = 0; i < 12; i++)
    {
        printf("Test %2d: %s\n", i + 1, descriptions[i]);
        printf("Input: %u (0x%X)\n", tests[i], tests[i]);
        
        printf("Real: ");
        int real_ret = printf("%X", tests[i]);
        printf(" (%d chars)\n", real_ret);
        
        printf("Fake: ");
        int fake_ret = ft_printf("%X", tests[i]);
        printf(" (%d chars)\n", fake_ret);
        
        printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    }
}

void test_percent_conversion(void)
{
    printf("=== %%%% CONVERSION TESTS ===\n\n");
    
    printf("Test 1: Single percent sign\n");
    printf("Real: ");
    int real_ret = printf("%%");
    printf(" (%d chars)\n", real_ret);
    
    printf("Fake: ");
    int fake_ret = ft_printf("%%");
    printf(" (%d chars)\n", fake_ret);
    printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    
    printf("Test 2: Multiple percent signs\n");
    printf("Real: ");
    real_ret = printf("%%%%%%");
    printf(" (%d chars)\n", real_ret);
    
    printf("Fake: ");
    fake_ret = ft_printf("%%%%%%");
    printf(" (%d chars)\n", fake_ret);
    printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    
    printf("Test 3: Percent in middle of text\n");
    printf("Real: ");
    real_ret = printf("Hello%%World");
    printf(" (%d chars)\n", real_ret);
    
    printf("Fake: ");
    fake_ret = ft_printf("Hello%%World");
    printf(" (%d chars)\n", fake_ret);
    printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
}

void test_mixed_conversions(void)
{
    printf("=== MIXED CONVERSIONS TESTS ===\n\n");
    
    int x = 42;
    char *str = "test";
    
    printf("Test 1: All conversions mixed\n");
    printf("Real: ");
    int real_ret = printf("Chars: %c %c | Strings: %s %s | Numbers: %d %i %u | Hex: %x %X | Ptr: %p | Percent: %%", 
                         'A', 'B', "hello", "world", 100, -100, 200, 255, 4095, &x);
    printf(" (%d chars)\n", real_ret);
    
    printf("Fake: ");
    int fake_ret = ft_printf("Chars: %c %c | Strings: %s %s | Numbers: %d %i %u | Hex: %x %X | Ptr: %p | Percent: %%", 
                            'A', 'B', "hello", "world", 100, -100, 200, 255, 4095, &x);
    printf(" (%d chars)\n", fake_ret);
    printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
    
    printf("Test 2: Complex format string\n");
    printf("Real: ");
    real_ret = printf("%c%s%d%i%u%x%X%p%%%%%c", 'S', "tring", 1, 2, 3, 4, 5, &x, 'E');
    printf(" (%d chars)\n", real_ret);
    
    printf("Fake: ");
    fake_ret = ft_printf("%c%s%d%i%u%x%X%p%%%%%c", 'S', "tring", 1, 2, 3, 4, 5, &x, 'E');
    printf(" (%d chars)\n", fake_ret);
    printf("Result: %s\n\n", (real_ret == fake_ret) ? "✓ PASS" : "✗ FAIL");
}

int main(void)
{
    printf("=== COMPREHENSIVE FT_PRINTF CONVERSION TESTS ===\n\n");
    
    test_char_conversion();
    test_string_conversion();
    test_pointer_conversion();
    test_decimal_conversion();
    test_integer_conversion();
    test_unsigned_conversion();
    test_hex_lowercase_conversion();
    test_hex_uppercase_conversion();
    test_percent_conversion();
    test_mixed_conversions();
    
    printf("=== ALL TESTS COMPLETED ===\n");
    printf("Check for any FAIL results above and fix your implementation!\n");
    
    return (0);
}
