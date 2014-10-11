#ifndef PHP_ZEPHIR_PARSER_H
    #define PHP_ZEPHIR_PARSER_H
    #define PHP_ZEPHIR_PARSER_EXTNAME "Zephir Parser"
    #define PHP_ZEPHIR_PARSER_EXTVER  "0.1"

    PHP_FUNCTION(zephir_parse_file);

    extern zend_module_entry zephir_parser_module_entry;
    #define phpext_zephir_parser_ptr &zephir_parser_module_entry
#endif
