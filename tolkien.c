#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include "tolkien.h"

#define VERSION "0.0.1"

/*
  将文档添加到数据库中，建立倒排索引
  env 结构体
  title 文档标题
  body 文档正文
*/
// static void add_document(wiser_env *env, const char *title, const char *body){
//   if (title && body){
//     UT
//   }
// }

/*入口*/
int main(int argc, char *argv[]){
  extern int optind;
  //printf("%d\n", optind);
  int ch = 0;

  while ((ch = getopt(argc,argv,"vb"))!=-1){
    switch(ch){
      case 'v':
              printf("Tolkien Version %s\n",VERSION);
              break;
      case 'b':
              printf("optind = %d\n", optind);
              break;
      default:
              printf("other option");
    }
  }

  //printf("%d\n", optind);
  //printf("%d\n", argc);
  if (argc == 1){
    printf(
      "  Tolkien %s, Developed By Galaxy21\n"
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
