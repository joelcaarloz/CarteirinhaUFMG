main: src/sistemascarteirinha.cpp src/carteirinha.cpp src/main.cpp
	c++ sistemascarteirinha.cpp carteirinha.cpp main.cpp -o saida

clean: 
	rm *.o obj/*