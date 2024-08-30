#include <stdio.h>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_util/stb_image.h"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_util/stb_image_resize2.h"

int main(int args, char* argv[])
{
    // 64 characters
    char ascii_char[] = "`^\":;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int char_len = strlen(ascii_char);

    int w, h, pix_size;
    unsigned char* image_data = stbi_load(argv[1], &w, &h, &pix_size, 0);

    if (image_data) {
        unsigned char* pixels = image_data;
        for (int i = 0; i < h; i++) {
            if(i % 2 == 0) {
                for (int j = 0; j < w; j++) {
                    unsigned char R = *pixels++;
                    unsigned char G = *pixels++;
                    unsigned char B = *pixels++;
                    if (pix_size >= 4) {
                        unsigned char A = *pixels++;
                    }
                    float avg = 0.299 * R + 0.587 * G + 0.114 * B;
                    int char_index = (int)(char_len * (avg / 255.0f));
                    putchar(ascii_char[char_index]);
                }
                putchar('\n');
            } else {
                // this block is to decrease the excessive height the ASCII image gains due to the structure of the font
                for(int j = 0; j < w; j++) {
                    *pixels++;
                    *pixels++;
                    *pixels++;
                    if (pix_size >= 4) {
                        *pixels++;
                    }
                }
            }
        }

    } else {
        printf("Failed to load image %s\n", argv[1]);
    }

    return 0;
}