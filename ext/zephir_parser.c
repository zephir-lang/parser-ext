#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#include "php.h"
#include "php_zephir_parser.h"

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
    char *filename;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename) != SUCCESS) {
        return;
    }

    array_init(return_value);
    return;
}
