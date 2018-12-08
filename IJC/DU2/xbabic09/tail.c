/**
*	@file	tail.c
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief POSIX function tail -> print last n lines from file or stdin
*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include <stdarg.h>
 #include <stdbool.h>

 #define MAX_LENGTH 1024
 #define DEFAULT_LINES_COUNT 10

 typedef struct params_t {
   char filename[420];
   unsigned long lines;
 } params_t;

 /**
  * @brief Function for error message and error exit from program
  *
  * @param String with error message
  */
 void errorExit(const char *fmt, ...){
   va_list(ap);
   va_start(ap, fmt);
   vfprintf(stderr, fmt, ap);
   va_end(ap);
   exit(1);
 }

 /**
  * @brief Function for parsing arguments
  *
  * @param Array of arguments
  * @param Number of argmunets
  * @return Arguments parsed to params_t struct
  */
params_t getParams(char *argv[], int argc) {
  params_t param;

  if (argc > 4) errorExit("Incorrect usage! Wrong parameters inserted!\n");
  else {
    switch (argc) {
      case 1:
        param.lines = DEFAULT_LINES_COUNT;
        param.filename[0] = 's';
        break;

      case 2:
        param.lines = DEFAULT_LINES_COUNT;
        memcpy(param.filename,argv[1],strlen(argv[1]));
        param.filename[strlen(argv[1])]='\0';
        break;

      case 3:
        sscanf(argv[2], "%lu", &param.lines);
        param.filename[0] = 's';
        break;

      case 4:
        sscanf(argv[2], "%lu", &param.lines);
        memcpy(param.filename,argv[3],strlen(argv[3]));
        param.filename[strlen(argv[3])]='\0';
        break;
    }
  }
  return param;
}

/**
 * @brief Function for file opening
 *
 * @param Name of file
 * @return Opened file
 */
FILE *readFile(char *filename) {
  FILE *fr;

  if ((fr = fopen(filename, "r")) == NULL) {
    errorExit("Error while opening file!\n");
  }
  return fr;
}

/**
 * @brief Function for counting lines in file
 *
 * @param File to count lines from
 * @return Number of counted lines
 */
unsigned long linesCount(FILE *file) {
  unsigned long counter = 0;
  char c;

  while ((c = getc(file)) != EOF) {
    if (c == '\n') {
      counter++;
    }
  }
  return counter;
}

/**
 * @brief Function for printing last n lines from file
 *
 * @param File to print from
 * @param Number of lines in file
 * @param Number of lines to print
 */
void printFromFile(FILE *file, unsigned long total_lines, unsigned long lines_to_print) {
  int c;
  int char_counter = 0;
  bool error = true;

  fseek(file, 0, SEEK_SET);
  while ((c = getc(file)) != EOF) {
    char_counter++;

    if (total_lines <= lines_to_print) {
      if (char_counter > MAX_LENGTH) {
        if (error) fprintf(stderr, "String too long! Using only first 1024 characters!\n");
        error = false;
        if (c == '\n') {
          total_lines--;
          char_counter = 0;
        }
        continue;
      }
      putchar(c);
    }

    if (c == '\n') {
      total_lines--;
      char_counter = 0;
    }
  }
}

/**
 * @brief Function to print last n lines from stdin
 *
 * @param Number of lines to print
 */
void printFromStdin(unsigned long lines_to_print) {
  bool error = true;
  unsigned int i, j;
  int c, tmp;

  char **output = (char **) malloc(sizeof(char *) * lines_to_print);
  if (output == NULL) errorExit("Error while memory allocation!\n");

  for (i = 0; i < lines_to_print; i++) {
		output[i] = (char *) calloc(MAX_LENGTH + 1, sizeof(char));
		if (output[i] == NULL){
			for (i = 0; i < lines_to_print; i++) free(output[i]);
			free(output);
			errorExit("Error while memory allocation!\n");
		}
}

  for (i = 0, j = 0; (c = getchar() != EOF); ) {
    if (j < MAX_LENGTH) output[i][j] = (char) c;
    else {
      if (error) fprintf(stderr, "String too long! Using only first 1024 characters!\n");
      error = false;
      if (c != '\n') continue;
      else output[i][j] = '\n';
    }

    if (c == '\n') {
      output[i][j+1] = '\0';
      i++;
      j=0;
    }
    else j++;

    tmp = c;
    if ((c = getchar()) == EOF) {
      if (tmp != '\n') {
        output[i][j] = '\0';
      }
      break;
    }
    else {
      ungetc(c, stdin);
      if (i > lines_to_print-1) {
        for (unsigned int x = 0; x < lines_to_print-1; x++) {
          strcpy(output[x], output[x+1]);
        }
        i = lines_to_print-1;
      }
    }
  }

  for (i = 0; i < lines_to_print; i++) printf("%s\n", output[i]);
  free(output);

}

int main(int argc, char *argv[]) {
  params_t param = getParams(argv, argc);

  if (param.filename[0] == 's') printFromStdin(param.lines);
  else {
    FILE *file = readFile(param.filename);
    int total_lines = linesCount(file);
    printFromFile(file, total_lines, param.lines);
    fclose(file);
  }

  return EXIT_SUCCESS;
}
