EXEC = programa_lista
CXX = g++
CXXFLAGS = -Wall -std=c++17
SRCS = main.cpp Lista_Sequencial.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) *.o
