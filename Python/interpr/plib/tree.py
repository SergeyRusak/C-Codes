from abc import ABC
from .tokens import Token


class Node(ABC):
    ...


class Number(Node):
    def __init__(self, value: Token):
        self.value = value

    def __str__(self):
        return f"{self.__class__.__name__}({self.value})"


class BinOp(Node):
    def __init__(self, left: Node, op: Token, right: Node):
        self.left = left
        self.op = op
        self.right = right

    def __str__(self):
        return f"BinOp{self.op.value} ({self.left}, {self.right})"


class UnarOp(Node):
    def __init__(self, op: Token, right: Node):
        self.op = op
        self.right = right

    def __str__(self):
        return f"UnarOp{self.op.value} ({self.right})"


class NodeVisitor:
    def visit(self, node: Node) -> float:
        raise NotImplementedError
