/*
 +--------------------------------------------------------------------------+
 | Zephir Language                                                          |
 +--------------------------------------------------------------------------+
 | Copyright (c) 2013-2014 Zephir Team and contributors                     |
 +--------------------------------------------------------------------------+
 | This source file is subject the MIT license, that is bundled with        |
 | this package in the file LICENSE, and is available through the           |
 | world-wide-web at the following url:                                     |
 | http://zephir-lang.com/license.html                                      |
 |                                                                          |
 | If you did not receive a copy of the MIT license and are unable          |
 | to obtain it through the world-wide-web, please send a note to           |
 | license@zephir-lang.com so we can mail you a copy immediately.           |
 +--------------------------------------------------------------------------+
*/

#ifndef PHP_ZEPHIR_PARSER_MAIN_H
#define PHP_ZEPHIR_PARSER_MAIN_H 1

#include "scanner.h"

#define ZEPHIR_PARSING_OK 1
#define ZEPHIR_PARSING_FAILED 0

typedef struct _zephir_parser_token {
    int opcode;
    char *token;
    int token_len;
    int free_flag;
} zephir_parser_token;

typedef struct _zephir_parser_status {
    int status;
    zval *ret;
    zephir_scanner_state *scanner_state;
    zephir_scanner_token *token;
    char *syntax_error;
    unsigned int syntax_error_len;
    unsigned int number_brackets;
} zephir_parser_status;

int zephir_parse_program(zval **return_value, char *program, unsigned int program_length, const char *file_path, zval **error_message TSRMLS_DC);

#endif
