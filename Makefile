CC = gcc

CFLAGS = -lm

TARGET = output

SRC = main.c

IMAGE_FILE = test_img.png

OUTPUT_FILE = result.txt

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)
	./$(TARGET) $(OUTPUT_FILE) > $(OUTPUT_FILE)

clean:
	rm -f $(TARGET)
