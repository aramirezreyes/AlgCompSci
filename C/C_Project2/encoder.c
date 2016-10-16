/* Say we have a table of the same length as the ascii table but each element has the srting that encodes the symbol ["11000","10010" etc]; */

#include <stdlib.h>
#include <stdio.h>

char encode_symbol(int symbol,int *codes){
  int bit;
  int bit_pos;
  char output_char=0;
  printf("Incoming symbol: %c, code %c \n",symbol,codes[symbol]);
  for (bit_pos=sizeof(int);bit_pos>=0;bit_pos--){
      bit = codes[symbol];
      output_char |= (bit<<bit_pos);
      printf("Output char: %c \n",output_char);
      }
    return output_char;
}

/* char encode_symbol(int symbol,long int *codes){ */
/*   char output_char; */
/*   printf("Símbolo: %c, código: %c \n", symbol, codes[symbol]); */
/*   output_char = codes[symbol]; */
/*     return output_char; */
/* } */

void encode_file(char *inputFile,char *outputFile,int *codes){
  FILE *ptr_inputFile, *ptr_outputFile;
  char buf_in[64],buf_out[64],output_char;
  int i,coded_sym,bit,bit_pos;
  ptr_inputFile =fopen(inputFile,"r");
  ptr_outputFile =fopen(outputFile,"w");
  if (!ptr_inputFile)
    printf("Error");
  while (fgets(buf_in,sizeof(buf_in), ptr_inputFile)!=NULL){
    for(i=0; i<sizeof(buf_out); i++){
      coded_sym = encode_symbol(buf_in[i], codes);
      buf_out[i] = coded_sym;
    }
    fputs(buf_out,ptr_outputFile);
  }
  fclose(ptr_inputFile);
  fclose(ptr_outputFile);
}


