#ifndef PHP_ZEPHIR_PARSER_H
    #define PHP_ZEPHIR_PARSER_H
    #define PHP_ZEPHIR_PARSER_EXTNAME "Zephir Parser"
    #define PHP_ZEPHIR_PARSER_EXTVER "0.1"

    #ifdef HAVE_CONFIG_H
        #include "config.h"
    #endif
    #include "php.h"

    extern zend_module_entry ZEPHIR_PARSER_module_entry;
    #define phpext_ZEPHIR_PARSER_ptr &ZEPHIR_PARSER_module_entry
#endif
