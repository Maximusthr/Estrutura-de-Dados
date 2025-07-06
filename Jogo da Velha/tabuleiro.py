# -*- coding: utf-8 -*-

class Tabuleiro:
    DESCONHECIDO = 0
    JOGADOR_0 = 1
    JOGADOR_X = 5


    def __init__(self):
        self.matriz = [ [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO], 
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO],
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO]]
       
    def venceu(self, x):
        return (x == 3 or x == 15)
        
    def tem_campeao(self):
        # Linhas
        for i in range(3):
            soma = 0
            for j in range(3):
                if (self.matriz[i][j] == Tabuleiro.JOGADOR_0):
                    soma += 1
                elif (self.matriz[i][j] == Tabuleiro.JOGADOR_X):
                    soma += 5

            if (self.venceu(soma)):
                return Tabuleiro.JOGADOR_0 if soma == 3 else Tabuleiro.JOGADOR_X

        # Colunas
        for i in range(3):
            soma = 0
            for j in range(3):
                if (self.matriz[j][i] == Tabuleiro.JOGADOR_0):
                    soma += 1
                elif (self.matriz[j][i] == Tabuleiro.JOGADOR_X):
                    soma += 5

            if (self.venceu(soma)):
                return Tabuleiro.JOGADOR_0 if soma == 3 else Tabuleiro.JOGADOR_X 

        # D. Principal
        temp = 0
        for i in range(3):
            temp += 1 if self.matriz[i][i] == Tabuleiro.JOGADOR_0 else 5

            if (self.venceu(temp)):
                return Tabuleiro.JOGADOR_0 if temp == 3 else Tabuleiro.JOGADOR_X

        # D. Secundaria

        temp = 0
        for i in range(3):
            temp += 1 if self.matriz[i][2 - i] == Tabuleiro.JOGADOR_0 else 5

            if (self.venceu(temp)):
                return Tabuleiro.JOGADOR_0 if temp == 3 else Tabuleiro.JOGADOR_X

        # Ninguem venceu
        return Tabuleiro.DESCONHECIDO