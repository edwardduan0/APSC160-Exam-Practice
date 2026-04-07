# 🟢 Random Text Mutation

**Recommended Time:** 15 - 20 min

**Topics:** String Swapping, Standard Library Functions, Random Numbers

## Description
Write a C program that reads a single lowercase word (string) from the user and applies exactly one random mutation from the list below, printing the result. The program should handle a string maximum length of 50. Repeatedly print an error message (it must contain the word error somewhere in it) if the user does not provide any input or provides a string greater than the allowed length until an acceptable string is entered.

Note: All mutations must be performed in-place, meaning they do not change the string length.

1. **Uppercase**: Uppercase a random character in the string.
2. **Replace**: Replace a random character in the string with the literal character ‘*’
3. **Swap Ends**: Swap the first and the last characters of the string.

## Examples
```text
Input: hello
Output: helLo 
Explanation: Mutation changed lowercase 'l' to uppercase 'L'
```
```text
Input: programming
Output: grogramminp 
Explanation: Mutation swapped the ends
```
```text
Input: student
Output: st*dent 
Explanation: Mutation replaced 'u' with '*'
```
```text
Input: iamsinglehandedlythebestprogrammingstudentintheentirewideworld
Output: Error. String exceeds maximum character limit. Please try again.
Explanation: String exceeds maximum character limit of 50.
```
```text
Input: (Empty)
Output: Error. No characters provided. Please try again.
Explanation: String is empty. User must provide at least one character.
```
