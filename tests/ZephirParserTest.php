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

    public function testFile()
    {
        $this->assertNull(zephir_parse_file(__DIR__ . '/fixtures/EmptyFile.zep'));
        $this->assertNotEmpty(zephir_parse_file(__DIR__ . '/fixtures/EmptyClass.zep'));
        $this->assertNotEmpty(zephir_parse_file(__DIR__ . '/fixtures/ClassWithMethod.zep'));
    }
}
