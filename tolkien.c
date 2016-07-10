#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

#include "database.h"
#include "tolkien.h"
#include "util.h"

#define VERSION "0.0.1"

/*入口*/
int main(int argc, char *argv[]) {
  extern int optind;
  // printf("%d\n", optind);
  int ch = 0;

  while ((ch = getopt(argc, argv, "vb")) != -1) {
    switch (ch) {
    case 'v':
      printf("Tolkien Version %s\n", VERSION);
      break;
    case 'b':
      printf("optind = %d\n", optind);
      break;
    default:
      printf("other option");
    }
  }

  // printf("%d\n", optind);
  // printf("%d\n", argc);
  if (argc == 1) {
    printf("  Tolkien %s, Developed By Galaxy21\n"
           "\n"
           "  Usage:\n"
           "    %s [options] db_file\n"
           "\n"
           "  Options:\n"
           "    -v version          :give the version and exit\n",
           VERSION, argv[0]);
    return -1;
  }
}
