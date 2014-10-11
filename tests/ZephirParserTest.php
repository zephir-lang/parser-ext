<?php

namespace Zephir\Test;

class ZephirParserTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @expectedException PHPUnit_Framework_Error_Warning
     */
    public function testWithoutArguments()
    {
        zephir_parse_file();
    }
}
