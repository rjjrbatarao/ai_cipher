
/*
   0 - 9 : 30 - 39
   A - Z : 65 - 90
   a - z : 97 - 122
*/
#include <Arduino.h>

char numeric_table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  char cipher[32] = "";
  char decoded[32] = "";
  char message[] = "my";
  int msg_len = strlen(message);
  int cipher_len;
  int table_len = 10;
  int i = 0;
  Serial.println("*************************");
  for (i = 0; i < msg_len; i++) {
    cipher[i] = (numeric_table[message[i] % table_len ]);
    Serial.print("pos: ");
    Serial.print(message[i] % table_len);
    Serial.print(" dec: ");
    Serial.println(message[i], DEC);
  }
  cipher_len = strlen(cipher);
  cipher[i] = '\0';
  Serial.println(cipher);
  Serial.println("*************************");
  for (i = 0; i < cipher_len; i++) {
    Serial.print("pos: ");
    Serial.print(cipher[i] % table_len);
    Serial.print(" dec: ");
    Serial.println(cipher[i], DEC);
  }
  Serial.println();
  Serial.println("*************************");
  char decoded_array[10][10] = {};
  for (i = 0; i < cipher_len; i++) {
    int k = 0;
    for (int j = 97; j < 122; j++) {
      if ((j % table_len) == String(cipher[i]).toInt()) {
        Serial.print("cha: ");
        Serial.print((char)j);
        Serial.print(" ");
        decoded_array[i][k++] += (char)j;
      }
    }
    Serial.println();
  }
  Serial.println();
  Serial.println("*************************");
  uint16_t combination_size = 1;
  int row_size = 0;
  for (int i = 0; i < 10; i++) {
    if (decoded_array[i][0] != '\0') {
      Serial.print("len: ");
      Serial.print(strlen(decoded_array[i]));
      Serial.print(" array: ");
      Serial.println(decoded_array[i]);
      combination_size = combination_size * strlen(decoded_array[i]);
      row_size++;
    } else {
      break;
    }
  }

  Serial.println("*************************");
  Serial.print("total combination: ");
  Serial.println(combination_size); //
  Serial.print("row size: ");
  Serial.println(row_size); //
  char combination_array[10][10] = {};
  int x = 0;
  int z = 0;
  int pattern_repeated = row_size + 1;
  int pattern_shuffle = row_size - 2;
  for (int i = 0; i < combination_size; i++) {
    for (int j = 0; j < row_size; j++) {
      Serial.print(decoded_array[j][i % strlen(decoded_array[j])]);
    }
    Serial.println();
    if (i % pattern_repeated == row_size) {
      Serial.println("***************");
      if (x % row_size == 0) {
        int number = strlen(decoded_array[x % row_size]);
        char temp = decoded_array[x ][number - 1];
        for (int m = number - 1; m > 0; m--) decoded_array[x % row_size][m] = decoded_array[x % row_size][m - 1];
        decoded_array[x % row_size][0] = temp;
        //Serial.println(decoded_array[x]);
      } else {
        x++;
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
