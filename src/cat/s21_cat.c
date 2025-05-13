#include "s21_cat.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

arguments_T argument_pareser(int argc, char **argv) {
  arguments_T arg = {0};

  struct option long_options[] = {{"number", 0, 0, 'n'},
                                  {"number-nonblank", 0, 0, 'b'},
                                  {"squeeze-blank", 0, 0, 's'},
                                  {0, 0, 0, 0}};

  int opt = 0;
  int longindex = 0;  // Add this variable

  while ((opt = getopt_long(argc, argv, "bnEeTtsv", long_options,
                            &longindex)) != -1) {
    switch (opt) {
      case 'b':
        arg.b = 1;
        arg.n = 0;  // если b = 1 то n = 0
        break;
      case 'n':
        if (!arg.b) arg.n = 1;  // если b  нету то только тогда n = 1
        arg.n = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'e':
        arg.E = 1;
        arg.v = 1;
        break;
      case 'E':
        arg.E = 1;
        break;
      case 't':
        arg.T = 1;
        arg.v = 1;
        break;
      case 'T':
        arg.T = 1;
        break;
      case '?':
        perror("ERROR");
        exit(1);
        break;
        // default:
        //   break;
    }
  }
  return arg;  // вернуть arg когда обработано всё.
}
char v_output(char ch) {
  if (ch == '\n' || ch == '\t') return ch;

  if (ch < 32) {
    printf("M-");
    ch = ch & 0x7F;
  }

  if (ch <= 31) {
    putchar('^');
    ch += 64;
  } else if (ch == 127) {
    putchar('^');
    ch = '?';
  }

  return ch;
}

void outline(arguments_T *arg, char *line, int n) {
  for (int i = 0; i < n; i++) {
    if (arg->T && line[i] == '\t') {
      printf("^I");
    } else {
      if (arg->E && line[i] == '\n') putchar('$');
    }
    if (arg->v) line[i] = v_output(line[i]);
    if (!arg->T || line[i] != '\t') putchar(line[i]);
  }
}

void output(arguments_T *arg, char **argv, int *line_count) {
  int last_blank = 0;
  for (int i = optind; argv[i] != NULL; i++) {
    FILE *fl = fopen(argv[i], "r");
    if (fl == NULL) {
      perror("Error opening file");
      continue;
    }
    char *line = NULL;
    size_t memline = 0;
    int read = 0;
    read = getline(&line, &memline, fl);
    while (read != -1) {
      int this_blank = (line[0] == '\n');
      if (arg->s && last_blank && this_blank) {
        // пропуск лишних строк
      } else {
        if (arg->n || arg->b) {
          if (arg->b && line[0] != '\n') {
            printf("%6d\t", *line_count);
            (*line_count)++;
          } else if (arg->n) {
            printf("%6d\t", *line_count);
            (*line_count)++;
          }
        }
        outline(arg, line, read);
      }
      last_blank = this_blank;
      read = getline(&line, &memline, fl);
    }
    free(line);
    fclose(fl);
    // printf("\n"); // это было надо но теперь лишнее :)
  }
}

int main(int argc, char *argv[]) {
  arguments_T arg = argument_pareser(argc, argv);
  int line_count = 1;
  output(&arg, argv, &line_count);

  return 0;
}