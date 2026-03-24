# 🟡 Random Password Generator

**Recommended Time:** 20 - 25 min

**Topics:** String Shuffling, ASCII Character Manipulation, Random Numbers

## Description
Write a program that generates and displays a 10-character password based on these rules:
1. The password must contain at least one character from each of the four categories:
    * Uppercase Letter (A-Z)
    * Lowercase Letter (a-z)
    * Digit (0-9)
    * Symbol (Select from: !, @, #, $, %, ^, &, *)
2. The remaining characters should be filled randomly from all four pools.
3. The final password must be thoroughly randomized (i.e., you should shuffle the 10 characters before outputting the final string).

Note: The program takes no user input.

## Challenge
Write a helper function, `int isValidPassword(const char *pwd)` that takes the generated password as input and returns 1 (true) if it meets all four required constraints (uppercase, lowercase, digit, symbol) and 0 (false) otherwise. Use this function to test your own output immediately after it is generated.

## Examples
```text
Output: Ab9#fQ2rP!
```
```text
Output: zT3&kLm8A$
```
```text
Output: G7@tRw5nLc
```
