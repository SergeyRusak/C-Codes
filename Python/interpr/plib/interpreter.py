from .parser import Parser
from .tokens import TokenType
from .tree import NodeVisitor, Node, Number, BinOp, UnarOp


class InterpreterException(Exception):
    ...


class Interpreter(NodeVisitor):
    def __init__(self):
        self.parser = Parser()

    def visit(self, node: Node) -> float:
        if isinstance(node, Number):
            return self.__visit_number(node)
        if isinstance(node, BinOp):
            return self.visit_binop(node)
        if isinstance(node, UnarOp):
            return self.visit_unarop(node)

        raise InterpreterException("invalid node")

    def __visit_number(self, node: Number) -> float:
        return float(node.value.value)

    def visit_binop(self, node: BinOp) -> float:
        match node.op.type:
            case TokenType.PLUS:
                return self.visit(node.left) + self.visit(node.right)
            case TokenType.MINUS:
                return self.visit(node.left) - self.visit(node.right)
            case TokenType.MUL:
                return self.visit(node.left) * self.visit(node.right)
            case TokenType.DIV:
                return self.visit(node.left) / self.visit(node.right)
        raise InterpreterException("Invalid operator")

    def visit_unarop(self, node: UnarOp) -> float:
        match node.op.type:
            case TokenType.PLUS:
                return self.visit(node.right)
            case TokenType.MINUS:
                return -self.visit(node.right)

    def eval(self, s: str) -> float:
        self.parser.init_parser(s)
        tree = self.parser.expr()
        return self.visit(tree)
