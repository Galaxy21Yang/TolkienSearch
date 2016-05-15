#ifndef __WISER_H__
#define __WISER_H__

#include "./include/utlist.h"
#include "./include/uthash.h"
#include "./include/utarray.h"
#include <sqlite3.h>

/*倒排列表*/
typedef struct _posting_list{
  int document_id;  /*文档编号*/
  UT_array *positions;  /*位置信息的数组*/
  int positions_count;  /*位置信息的条数*/
  struct _posting_list *next;   /*指向下一个倒排列表的指针*/
}posting_list;

/*倒排索引*/
typedef struct {
  int token_id; //词元编号
  posting_list *posting_list; //指向包含该词元的倒排列表的指针
  int doc_count;  //出现该词元的文档数
  int positions_count;  //该词元在所有文档中的出现次数之和
  UT_hash_handle hh;  //用于将该结构体转化为哈希表
} inverted_index_hash, inverted_index_values;

/*压缩倒排列表等数据的方法*/
typedef enum{
  compress_none, //不压缩
}compress_method;

/*应用程序的全局配置*/
typedef struct _tolkien_env {
  const char *db_path;  //数据库的路径

  int token_len; //词元的长度
  compress_method compress;
  int enable_phrase_search;

  inverted_index_hash *ii_buffer;
  int ii_buffer_count;
  int ii_buffer_update_threshold;
  int indexed_count;

  /* sqlite3相关的配置 */
  sqlite3 *db; //sqlite3的实例
  sqlite3_stmt *get_document_id_st;
  sqlite3_stmt *get_document_title_st;
  sqlite3_stmt *insert_document_st;
  sqlite3_stmt *update_document_st;
  sqlite3_stmt *get_token_id_st;
  sqlite3_stmt *get_token_st;
  sqlite3_stmt *store_token_st;
  sqlite3_stmt *get_postings_st;
  sqlite3_stmt *update_postings_st;
  sqlite3_stmt *get_settings_st;
  sqlite3_stmt *replace_settings_st;
  sqlite3_stmt *get_document_count_st;
  sqlite3_stmt *begin_st;
  sqlite3_stmt *commit_st;
  sqlite3_stmt *rollback_st;
} tolkien_env;
#endif
