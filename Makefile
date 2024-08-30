CC = gcc

CFLAGS = -lm

TARGET = output

SRC = main.c

# input image file name
IMAGE_FILE = test_img.png

# output text file name
OUTPUT_FILE = result.txt

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)
	./$(TARGET) $(OUTPUT_FILE) > $(OUTPUT_FILE)

clean:
	rm -f $(TARGET)
