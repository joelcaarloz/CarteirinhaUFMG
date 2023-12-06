main: src/sistemacarteirinha.cpp src/carteirinha.cpp src/main.cpp
	c++ src/sistemacarteirinha.cpp src/carteirinha.cpp src/main.cpp -o saida.o

clean: 
	rm *.o obj/*