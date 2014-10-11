#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#include "php.h"
#include "php_zephir_parser.h"
#include "scanner.h"
#include "zephir.h"

#include <ext/standard/info.h>
#include <main/php_streams.h>
#include <ext/standard/file.h>
#include <ext/standard/php_filestat.h>

/** Compatibility with PHP 5.3 */
#ifndef ZVAL_COPY_VALUE
    #define ZVAL_COPY_VALUE(z, v)\
            (z)->value = (v)->value;\
            Z_TYPE_P(z) = Z_TYPE_P(v);
#endif

static zend_function_entry zephir_parser_functions[] = {
    PHP_FE(zephir_parse_file, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry zephir_parser_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_ZEPHIR_PARSER_EXTNAME,
    zephir_parser_functions, /* Functions */
    NULL,        /* MINIT */
    NULL,        /* MSHUTDOWN */
    NULL,        /* RINIT */
    NULL,        /* RSHUTDOWN */
    NULL,        /* MINFO */
    PHP_ZEPHIR_PARSER_EXTVER,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_ZEPHIR_PARSER
ZEND_GET_MODULE(zephir_parser)
#endif

/**
 * @param string $filename
 *
 * @return array
 */
PHP_FUNCTION(zephir_parse_file) {
    char *filename, *contents;
    php_stream *stream;
    int filename_len, contents_len;
    long maxlen = PHP_STREAM_COPY_ALL;
    zval *zcontext = NULL, *parsed_program = NULL;
    php_stream_context *context = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) != SUCCESS) {
        return;
    }

    context = php_stream_context_from_zval(zcontext, 0);
    stream = php_stream_open_wrapper_ex(filename, "rb", 0 | REPORT_ERRORS, NULL, context);
    if (!stream) {
        return;
    }

    contents_len = php_stream_copy_to_mem(stream, &contents, maxlen, 0);
    if (contents_len > 0) {
        zephir_parse_program(&parsed_program, contents, contents_len, filename, NULL TSRMLS_CC);
        ZVAL_COPY_VALUE(return_value, parsed_program);
        zval_copy_ctor(return_value);
        efree(contents);
    }
    php_stream_close(stream);
}
