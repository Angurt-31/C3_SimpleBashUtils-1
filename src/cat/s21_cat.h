#ifndef S21_CAT_H

#define S21_CAT_H

typedef struct arguments {
  int b, n, s, e, E, T, v;
} arguments_T;

arguments_T argument_pareser(int argc, char** argv);
char v_output(char ch);
void outline(arguments_T* arg, char* line, int n);
void output(arguments_T* arg, char** argv, int* line_count);

#endif