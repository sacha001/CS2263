#ifndef TOKENHELPER_H
#define TOKENHELPER_H

/*
This function tokenizes str, using the separator characters specified in sep. It
puts deep copies of the tokens into a dynamically allocated array of strings,
and returns the array. This array includes an extra element with the value
of NULL, which allows looping through the array without knowing its length.
*/
char **stringToTokens(char *str, char *sep);

/*
This function deallocates the memory allocated for an array of strings, as created
by stringToTokens
*/
void destroyTokens(char **tokenArray);

/*
This function reverses string s in place.
*/
void reverse(char *s);

#endif /* TOKENHELPER */
