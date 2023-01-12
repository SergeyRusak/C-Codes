import pytest

from plib.pascalinterp import PascalInterpreter

class TestPascal:

    def test_syntax(self):
        interp = PascalInterpreter()
        with pytest.raises(Exception):
            text = "BEGIN END"
            interp.program(text)
    def test_variable(self):
        interp = PascalInterpreter()
        with pytest.raises(Exception):
            text = "BEGIN x:=y; END."
            interp.program(text)
            text = "BEGIN 123x:=13; END."
            interp.program(text)

    def test_complex(self):
        interp = PascalInterpreter()
        text = "BEGIN\
        x := 2 + 3 * (2 + 3);\
        y := 2 / 2 - 2 + 3 * ((1 + 1) + (1 + 1));\
    END."
        interp.program(text)
        assert  interp.data["x"] == 17.0
        text = "BEGIN\
    y: = 2;\
    BEGIN\
        a := 3;\
        a := a;\
        b := 10 + a + 10 * y / 4;\
        c := a - b\
    END;\
    x := a+b-c;\
END."
        interp.program(text)
        assert interp.data["x"] == 21.0




