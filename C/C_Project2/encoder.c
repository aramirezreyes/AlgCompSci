/* Say we have a table of the same length as the ascii table but each element has the srting that encodes the symbol ["11000","10010" etc]; */

#include <stdlib.h>
#include <stdio.h>

char encode_symbol(int symbol,long int *codes){
  long int bit;
  int bit_pos;
  char output_char;
    for (bit_pos=7;bit_pos>=0;bit_pos--){
      bit = codes[symbol];
      output_char |= (bit<<bit_pos);
      }
    return output_char;
}

void encode_file(char file_name,char output_text, long int *codes){
  FILE *ptr_inputFile, *ptr_outputFile;
  char buf_in[64],buf_out[64];
  int i,coded_sym;
  ptr_inputFile =fopen("input.txt","r");
  ptr_outputFile =fopen("input.txt","w");
  if (!ptr_inputFile)
    printf("Error");
  while (fgets(buf_in,64, ptr_inputFile)!=NULL){
    for(i=0; ((i<64) & (buf_in[i])); i++){
      coded_sym = encode_symbol(buf_in[i], codes);
      buf_out[i] = coded_sym;
    }
    buf_in[i+1] = '\0';
    fputs(buf_out,ptr_outputFile);
  }
  fclose(ptr_inputFile);
  fclose(ptr_outputFile);
}


