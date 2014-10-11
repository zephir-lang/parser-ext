PHP_ARG_ENABLE(zephir_parser, whether to enable Zephir Parser [ --enable-zephir-parser   Enable Zephir Parser])

if test $PHP_ZEPHIR_PARSER != "no"; then
    PHP_SUBST(ZEPHIR_PARSER_SHARED_LIBADD)
    PHP_NEW_EXTENSION(zephir_parser, zephir_parser.c, $ext_shared)
fi
