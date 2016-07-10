#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <sqlite3.h>

#include "tolkien.h"

int db_add_document(const tolkien_env *env, const char *title,
                    unsigned int title_size, const char *body,
                    unsigned int body_size);

int db_get_document_id(const tolkien_env *env, const char *title,
                       unsigned int title_size);

#endif
