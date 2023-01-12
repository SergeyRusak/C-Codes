from plib.interpreter import Interpreter
from plib.parser import Parser
import pytest


class TestInterpreter:

    def test_interpreter(self):
        interp = Interpreter()
        assert interp.eval("2+2") == 4
        assert interp.eval("2-2") == 0
        assert interp.eval(" 2 +     3") == 5
        assert interp.eval("22 +     323") == 345
        assert interp.eval("0.5 + 2") == 2.5
        assert interp.eval("2 * 2") == 4
        assert interp.eval("2 / 2") == 1
        assert interp.eval("2 + 2 + 3 + 3") == 10
        assert interp.eval("2 * 2 * 2") == 8
        assert interp.eval("2 + 2 * 3 + 3") == 11
        assert interp.eval("2") == 2.0
        assert interp.eval("(2 + 2) * 3 + 3") == 15.0
        assert interp.eval("(2 + 2) * (3 + (3 * 3))") == 48.0
        assert interp.eval("-2") == -2
        assert interp.eval("+2") == 2
        assert interp.eval("--2--3") == 5.0
        assert interp.eval("-(2 + 3)") == -5
