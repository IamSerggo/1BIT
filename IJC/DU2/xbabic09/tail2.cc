/**
*	@file	tail.cc
*	@author	Radovan Babic, xbabic09
*	@date	24.4.2018
*	@brief POSIX function tail -> print last n lines from file or stdin
*/

#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <iterator>

#include <string.h>

using namespace std;

const unsigned long MAX_LENGTH = 1024;
const unsigned long DEFAULT_LINES_COUNT = 10;

typedef struct params {
  char const *filename;
  unsigned long lines;
} params_t;

inline void errorExit(const char *fmt, ...) {
  cerr << "Error!: " << fmt << endl;
  exit(1);
}

params_t getParams(char *argv[], int argc) {
  params_t param;

  if (argc > 4) errorExit("Incorrect usage! Wrong parameters inserted!\n");
  else {
    switch (argc) {
      case 1:
        param.lines = DEFAULT_LINES_COUNT;
        param.filename = "s";
        break;

      case 2:
        param.lines = DEFAULT_LINES_COUNT;
        param.filename = argv[1];
        break;

      case 3:
        sscanf(argv[2], "%lu", &param.lines);
        param.filename = "s";
        break;

      case 4:
        sscanf(argv[2], "%lu", &param.lines);
        param.filename = argv[3];
        break;
    }
  }
  return param;
}

void printFromFile(istream & file, unsigned long lines) {

  string str;
  deque<string> buffer;
  unsigned long counted_lines = 0;

  while (getline(file, str)) { // read lines from file
    buffer.push_back(str); // save line to buffer

    if (counted_lines == lines) buffer.pop_front(); // if already readed all lines delete last
    else counted_lines++;
  }

  copy(buffer.begin(), buffer.end(), ostream_iterator<string>(cout,"\n")); // printing
}

int main(int argc, char *argv[]) {
  params_t param = getParams(argv, argc);

  istream *file = &cin; // input stream
  fstream temp; // temporary stream

  if (strcmp(param.filename, "s") != 0) {
    temp.open(param.filename, ios::in);
    if (!temp.is_open()) errorExit("Error while file opening!\n");
    else file = &temp;
  }

  printFromFile(*file, param.lines);
  return 0;
}
