#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

clock_t base, total;
#define START_TIMER  base = clock();
#define PAUSE_TIMER  total += (clock() - base);

bool is_palindrome( char word[], int start, int end )
{

  /* base condition where the characters are same */
  if( start >= end ){
    return true;

  }else if( word[start] == word[end] ){
    return is_palindrome( word, start + 1, end - 1);

  }else{
    return false;

  }
  
}

void parse_string( char words[] )
{

  int i, j = 0;
  for( i = 0; i < strlen( words ); i++ ) {
    
    if( isalpha( words[ i ] ) ) {
      words[ j ] = tolower( words[ i ] );
      j++;
    }

  }
  words[ j ] = '\0';

}

char **word;

int findPalindromes(int n) {
  int palcount = 0;

  for(int i=0; i<n; i++) {

    parse_string( word[i] );
    
    if(is_palindrome( word[i], 0, strlen( word[i] ) - 1 ))
        palcount++;

  }

  return palcount;
}

int main( int argc, char** argv )
{
  
  char oneWord[81];
  int n = atoi(argv[1]);

  word = (char **) malloc(n * sizeof(char *));
  for(int i = 0; i < n; i++) {
    gets( oneWord );
    word[i] = (char *) malloc(strlen(oneWord) + 1);
    strcpy(word[i], oneWord);
  }

  START_TIMER
  
  int palcount = findPalindromes(n);
 
  PAUSE_TIMER

  for(int i = 0; i < n; i++) {
    free(word[i]);
  }
  free(word);

  printf("Time: %ld\n", total);
  printf("\nPalindromes : %d\n", palcount);

  return (EXIT_SUCCESS);
  
}