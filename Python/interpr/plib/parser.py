# parser.py
from .tokens import Token, TokenType
from .lexer import Lexer
from .tree import Node, BinOp, Number, UnarOp


class ParserException(Exception):
    ...


class Parser:

    def __init__(self):
        self.current_token: Token = None
        self.lexer = Lexer()

    def check_type(self, type_: TokenType):
        if self.current_token.type == type_:
            self.current_token = self.lexer.next()
            return
        raise ParserException(f"Invalid token order. Expected {type_}, Received {self.current_token}")

    def term(self) -> Node:
        ops = [TokenType.DIV, TokenType.MUL]
        result = self.factor()
        while self.current_token.type in ops:
            token = self.current_token
            match token.type:
                case TokenType.DIV:
                    self.check_type(TokenType.DIV)
                    # result /= self.term()
                case TokenType.MUL:
                    self.check_type(TokenType.MUL)
                    # result *= self.term()
            result = BinOp(result, token, self.factor())
        return result

    def expr(self) -> Node:
        ops = [TokenType.PLUS, TokenType.MINUS]
        result = self.term()
        while self.current_token.type in ops:
            token = self.current_token
            match token.type:
                case TokenType.PLUS:
                    self.check_type(TokenType.PLUS)
                    # result += self.term()
                case TokenType.MINUS:
                    self.check_type(TokenType.MINUS)
                    # result -= self.term()
            result = BinOp(result, token, self.term())
        return result

    def init_parser(self, s: str) -> float:
        self.lexer.init_lexer(s)
        self.current_token = self.lexer.next()

    def factor(self) -> Node:
        token = self.current_token
        if token.type == TokenType.MINUS:
            self.check_type(TokenType.MINUS)
            return UnarOp(token, self.factor())
        if token.type == TokenType.PLUS:
            self.check_type(TokenType.PLUS)
            return UnarOp(token, self.factor())

        if token.type == TokenType.NUMBER:
            self.check_type(TokenType.NUMBER)
            return Number(token)
        if token.type == TokenType.LPAREN:
            self.check_type(TokenType.LPAREN)
            result = self.expr()
            self.check_type(TokenType.RPAREN)
            return result
        raise ParserException("invalid pactor")
