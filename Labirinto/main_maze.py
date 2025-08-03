import time
from maze import Maze
from collections import deque


maze_csv_path = ".\labirinto1.txt"  # Substitua pelo caminho correto
maze = Maze() 

maze.load_from_csv(maze_csv_path)

# Exibir o lab
maze.run()
maze.init_player()

pilha = deque()
pilha.append(maze.get_init_pos_player())

dX = [0, 1, -1, 0]
dY = [1, 0, 0, -1]

while(len(pilha)):
    [x, y] = pilha.pop()

    if maze.find_prize((x, y)):
        print("FIM")
        break
    
    maze.mov_player((x, y))
    time.sleep(0.1)

    for i in range(0, 4):
        if maze.is_free((x+dX[i], y+dY[i])):
            pilha.append([x+dX[i], y+dY[i]])