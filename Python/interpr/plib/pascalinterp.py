from plib.interpreter import Interpreter
class PascalInterpreterException(Exception):
    ...


class PascalInterpreter():
    def __init__(self):
        self.interp = Interpreter()
        self.data = {}

    def naming_valid(self,var):
        if var[0].isalpha():
            for i in var[1:]:
                if not(i.isalpha() or i.isdigit() or i not in ['+','-','*','/','(',')',':','=',' ']):
                    return False
            return True
        return False
    def printv(self,var):
        if var not in self.data:
            raise  PascalInterpreterException(f"Variable exception. Except name of variable, but \"{var}\" found")
        print(self.data[var])

    def showmem(self):
        for i in self.data.keys():
            print(i,end=" = ")
            print(self.data[i])

    def program(self,text):
        if (text.strip()[-1] != "."):
            raise PascalInterpreterException("Syntax Exception: Excepted dot")
        complex_text = text.strip()[:-1]
        self.complex_statement(complex_text)

    def complex_statement(self,text):
        if text.find("BEGIN") ==-1:
            raise PascalInterpreterException(f"SyntaxError: BEGIN exepted but {text[:5]} found")
        if text.rfind("END") == -1:
            raise PascalInterpreterException(f"SyntaxError: END exepted but {text[-3:]} found")
        statement_list = text[text.find("BEGIN")+5:text.rfind("END")-3]
        if statement_list.find("BEGIN") != -1:
            start_state = statement_list[:statement_list.find("BEGIN")]
            if statement_list.rfind("END")==-1:
                raise PascalInterpreterException("Syntax exception: END excepted")
            last_state = statement_list[statement_list.rfind("END")+4:]
            complex_state = statement_list[statement_list.find("BEGIN"):statement_list.rfind("END")+3]


            self.statements_list(start_state)
            self.complex_statement(complex_state)
            self.statements_list(last_state)
        else:
            self.statements_list(statement_list)


    def statements_list(self,list):
        statements = list.split(";")
        for i in statements:
            self.statement(i)
    def statement(self,s):
        s = s.strip()
        if len(s) == 0:
            pass
        elif s.find("BEGIN")!= -1:
            self.complex_statement(s)
        else:
            self.assignment(s)


    def assignment(self,line):
        line = "".join(line.split())
        if line.find(":=") == -1:
            raise  PascalInterpreterException(f"Assignment Exception. \":=\" not found")
        if line.count(":=") > 1:
            raise PascalInterpreterException(f"Assignment Exception. Except expresion, but \":=\" found")
        var,expr = line.split(":=")
        expr = expr + " "
        var = var.strip()
        if not self.naming_valid(var):
            raise PascalInterpreterException(f"Variable Error Naming. \"{var}\" is invalid")
        pos = 0
        result = []
        while pos < len(expr):
            if expr[pos].isalpha():
                temp = [expr[pos]]
                leng = 1
                curr = expr[pos+leng]
                while(curr != "" and (curr.isalpha() or curr.isdigit() or curr not in ['+','-','*','/','(',')',':','=',' '])):
                    temp.append(curr)
                    leng += 1
                    if pos + leng < len(expr):
                        curr = expr[pos+leng]
                    else:
                        curr = ""
                temp = "".join(temp)
                if temp not in self.data:
                    raise PascalInterpreterException(f"Variable exception. variable\"{temp}\" not found")
                result.append(temp)
                pos+=leng
            else:
                pos+=1
        for i in set(result):
            expr = expr.replace(i,str(self.data[i]))
        self.data[var] = self.interp.eval(expr)