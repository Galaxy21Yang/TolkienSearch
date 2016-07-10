#ifndef __UTIL_H__
#define __UTIL_H__

typedef uint32_t UTF32Char; //经过UTF-32编码的Unicode字符串
char *utf32toutf8(const UTF32Char *ustr, int ustr_len, char *str,
                  int *str_size);
#endif
