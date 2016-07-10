#include <bson.h>

int main(int argc, char *argv[]) {
  bson_t *document;
  bson_t child;
  char *str;

  document = bson_new();

  /*
   * Append {"hello" : "world"} to the document.
   * Passing -1 for the length argument tells libbson to calculate the string
   * length.
   */
  bson_append_utf8(document, "hello", -1, "world", -1);

  /*
   * For convenience, this macro is equivalent.
   */
  BSON_APPEND_UTF8(document, "hello", "world");

  /*
   * Begin a subdocument.
   */
  BSON_APPEND_DOCUMENT_BEGIN(document, "subdoc", &child);
  BSON_APPEND_UTF8(&child, "subkey", "value");
  bson_append_document_end(document, &child);

  /*
   * Print the document as a JSON string.
   */
  str = bson_as_json(document, NULL);
  printf("%s\n", str);
  bson_free(str);

  /*
   * Clean up allocated bson documents.
   */
  bson_destroy(document);
  return 0;
}
