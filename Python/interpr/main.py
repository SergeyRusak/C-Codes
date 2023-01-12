from plib.pascalinterp import PascalInterpreter

interp = PascalInterpreter()
text = "BEGIN\
    y: = 2;\
    BEGIN\
        a := 3;\
        a := a;\
        b := 10 + a + 10 * y / 4;\
        c := a - b\
    END;\
    x := a+b-c/y;\
    END."
interp.program(text)
print(interp.showmem())