#include "php_zephir_parser.h"

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

    zval *result;
    MAKE_STD_ZVAL(result);
    array_init(result);

    RETURN_ZVAL(result);
}
