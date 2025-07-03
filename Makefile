APP = meta-tracker
SRC = src/main.c src/menu.c src/metas.c src/utils.c
CC = gcc
CFLAGS = -Wall

all:
	$(CC) $(SRC) -o build/$(APP) $(CFLAGS)

run:
	./build/$(APP)

clean:
	rm -f build/$(APP)
