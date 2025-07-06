# -*- coding: utf-8 -*-
from random import randint

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)
            

    def getJogada(self) -> (int, int):
        # R1
        # Computador
        # Linhas
        for i in range(3):
            soma = 0
            i_vazio = -1
            j_vazio = -1
            for j in range(3):
                if self.tabuleiro.matriz[i][j] == Tabuleiro.JOGADOR_0:
                    soma += 1
                if self.tabuleiro.matriz[i][j] == Tabuleiro.DESCONHECIDO:
                    i_vazio = i
                    j_vazio = j
            
            if (soma == 2 and i_vazio != -1 and j_vazio != -1):
                return (i_vazio, j_vazio)
        
        # Colunas
        for i in range(3):
            soma = 0
            i_vazio = -1
            j_vazio = -1
            for j in range(3):
                if self.tabuleiro.matriz[j][i] == Tabuleiro.JOGADOR_0:
                    soma += 1
                if self.tabuleiro.matriz[j][i] == Tabuleiro.DESCONHECIDO:
                    i_vazio = i
                    j_vazio = j
            
            if (soma == 2 and i_vazio != -1 and j_vazio != -1):
                return (j_vazio, i_vazio)

        # D. Principal
        temp = 0
        i_vazio = -1
        for i in range(3):
            if self.tabuleiro.matriz[i][i] == Tabuleiro.JOGADOR_0:
                temp += 1
            if self.tabuleiro.matriz[i][i] == Tabuleiro.DESCONHECIDO:
                i_vazio = i
        if (temp == 2 and i_vazio != -1):
            return (i_vazio, i_vazio)
        
        # D. Secundaria
        temp = 0
        i_vazio = -1
        for i in range(3):
            if self.tabuleiro.matriz[i][2-i] == Tabuleiro.JOGADOR_0:
                temp += 1
            if self.tabuleiro.matriz[i][2-i] == Tabuleiro.DESCONHECIDO:
                i_vazio = i
        if (temp == 2 and i_vazio != -1):
            return (i_vazio, 2-i_vazio)


        # Jogador
        # Linhas
        for i in range(3):
            soma = 0
            i_vazio = -1
            j_vazio = -1
            for j in range(3):
                if self.tabuleiro.matriz[i][j] == Tabuleiro.JOGADOR_X:
                    soma += 5
                if self.tabuleiro.matriz[i][j] == Tabuleiro.DESCONHECIDO:
                    i_vazio = i
                    j_vazio = j
            
            if (soma == 10 and i_vazio != -1 and j_vazio != -1):
                return (i_vazio, j_vazio)
        
        # Colunas
        for i in range(3):
            soma = 0
            i_vazio = -1
            j_vazio = -1
            for j in range(3):
                if self.tabuleiro.matriz[j][i] == Tabuleiro.JOGADOR_X:
                    soma += 5
                if self.tabuleiro.matriz[j][i] == Tabuleiro.DESCONHECIDO:
                    i_vazio = i
                    j_vazio = j
            
            if (soma == 10 and i_vazio != -1 and j_vazio != -1):
                return (j_vazio, i_vazio)

        # D. Principal
        temp = 0
        i_vazio = -1
        for i in range(3):
            if self.tabuleiro.matriz[i][i] == Tabuleiro.JOGADOR_X:
                temp += 5
            if self.tabuleiro.matriz[i][i] == Tabuleiro.DESCONHECIDO:
                i_vazio = i
        if (temp == 10 and i_vazio != -1):
            return (i_vazio, i_vazio)
        
        # D. Secundaria
        temp = 0
        i_vazio = -1
        for i in range(3):
            if self.tabuleiro.matriz[i][2-i] == Tabuleiro.JOGADOR_X:
                temp += 5
            if self.tabuleiro.matriz[i][2-i] == Tabuleiro.DESCONHECIDO:
                i_vazio = i
        if (temp == 10 and i_vazio != -1):
            return (i_vazio, 2 - i_vazio)

        # R2
        for i in range(3):
            for j in range(3):
                if self.tabuleiro.matriz[i][j] == Tabuleiro.DESCONHECIDO:
                    verif = 0
                    ok_0 = False
                    ok_vazio = False
    
                    # Linha
                    for k in range(3):
                        if (k == j): 
                            continue
                        
                        if (self.tabuleiro.matriz[i][k] == Tabuleiro.JOGADOR_0):
                            ok_0 = True
                        elif (self.tabuleiro.matriz[i][k] == Tabuleiro.DESCONHECIDO):
                            ok_vazio = True
                        elif (self.tabuleiro.matriz[i][k] == Tabuleiro.JOGADOR_X):
                            ok_0 = False
                            ok_vazio = False
                            break

                    if (ok_0 and ok_vazio):
                        verif += 1
                        ok_0 = False
                        ok_vazio = False
                    
                    # Coluna
                    for k in range(3):
                        if (k == i): 
                            continue
                        if (self.tabuleiro.matriz[k][j] == Tabuleiro.JOGADOR_0):
                            ok_0 = True
                        elif (self.tabuleiro.matriz[k][j] == Tabuleiro.DESCONHECIDO):
                            ok_vazio = True
                        elif (self.tabuleiro.matriz[k][j] == Tabuleiro.JOGADOR_X):
                            ok_0 = False
                            ok_vazio = False
                            break
                        
                    if (ok_0 and ok_vazio):
                        verif += 1
                        ok_0 = False
                        ok_vazio = False
                    
                    if (i != 1 and j != 1):
                        # Temos diagonal
                        if (i == 0 and j == 0) or (i == 2 and j == 2):
                            # D. Principal
                            for k in range(3):
                                if (k == i and k == j): 
                                    continue

                                if (self.tabuleiro.matriz[k][k] == Tabuleiro.JOGADOR_0):
                                    ok_0 = True

                                if (self.tabuleiro.matriz[k][k] == Tabuleiro.DESCONHECIDO):
                                    ok_vazio = True

                                elif (self.tabuleiro.matriz[k][k] == Tabuleiro.JOGADOR_X):
                                    soma = 0
                                    break

                            if (ok_0 and ok_vazio):
                                verif += 1

                        elif (i == 0 and j == 2) or (i == 2 and j == 0):
                            # D. Secundaria
                            for k in range(3):
                                if (k == i and 2 - k == j): 
                                    continue

                                if (self.tabuleiro.matriz[k][2-k] == Tabuleiro.JOGADOR_0):
                                    ok_0 = True
                                
                                if (self.tabuleiro.matriz[k][2-k] == Tabuleiro.DESCONHECIDO):
                                    ok_vazio = True

                                elif (self.tabuleiro.matriz[k][2-k] == Tabuleiro.JOGADOR_X):
                                    soma = 0
                                    break

                            if (ok_0 and ok_vazio):
                                verif += 1
                    
                    if verif >= 2:
                        return (i, j)

        # R3
        if (self.tabuleiro.matriz[1][1] == Tabuleiro.DESCONHECIDO):
            return (1, 1)
    
        # R4
        if (self.tabuleiro.matriz[0][0] == Tabuleiro.JOGADOR_X and self.tabuleiro.matriz[2][2] == Tabuleiro.DESCONHECIDO):
            return (2, 2)
        
        if (self.tabuleiro.matriz[2][2] == Tabuleiro.JOGADOR_X and self.tabuleiro.matriz[0][0] == Tabuleiro.DESCONHECIDO):
            return (0, 0)
        
        if (self.tabuleiro.matriz[0][2] == Tabuleiro.JOGADOR_X and self.tabuleiro.matriz[2][0] == Tabuleiro.DESCONHECIDO):
            return (2, 0)
        
        if (self.tabuleiro.matriz[2][0] == Tabuleiro.JOGADOR_X and self.tabuleiro.matriz[0][2] == Tabuleiro.DESCONHECIDO):
            return (0, 2)
        
        # R5
        if (self.tabuleiro.matriz[0][0] == Tabuleiro.DESCONHECIDO):
            return (0, 0)
        
        if (self.tabuleiro.matriz[0][2] == Tabuleiro.DESCONHECIDO):
            return (0, 2)
        
        if (self.tabuleiro.matriz[2][0] == Tabuleiro.DESCONHECIDO):
            return (2, 0)
        
        if (self.tabuleiro.matriz[2][2] == Tabuleiro.DESCONHECIDO):
            return (2, 2)

        # R6
        for i in range(3):
            for j in range(3):
                if self.tabuleiro.matriz[i][j] == Tabuleiro.DESCONHECIDO:
                    return (i, j)
                