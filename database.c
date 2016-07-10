#include "database.h"

/*将文档添加到documents表中*/
// int db_add_document(const tolkien_env *env, const char *title,
//                     unsigned int title_size, const char *body,
//                     unsigned int body_size) {
//
//   sqlite3_stmt = *st;
//   int rc, document_id;
// }

/* 根据文档的标题获取文档编号 */
int db_get_document_id(const tolkien_env *env, const char *title,
                       unsigned int title_size) {
  int rc;
  sqllite3_reset(env->get_document_id_st);
  sqlite3_bind_text(env->get_document_id_st)
}
