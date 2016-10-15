/* Say we have a table of the same length as the ascii table but each element has the srting that encodes the symbol ["11000","10010" etc]; */



int encode_symbol(int symbol,int *codes){
    for (bit_pos=7;bit_pos>=0;bit_pos--){
      bit = getchar((codes[bit_pos]));
      output_char |= (bit<<bit_position);
      }
    return output_char;
}

encode_file(char file_name,char output_text){
  FILE *ptr_inputFile, *ptr_outputFile;
  char buf_in[64];
  int i,coded_sym;
  ptr_inputFile =fopen("input.txt","r");
  ptr_outputFile =fopen("input.txt","w");
  if (!ptr_file)
    return 1;
  while (fgets(buf_in,64, ptr_inputFile)!=NULL){
    while(i=0; ((i<64) & (buf[i])); i++){
      coded_sym = encode_symbol(buf[id]);
      buf_out[i] = coded_sym;
    }
    buf[i+1] = '\0';
    fputs(buf_out,ptr_outputFile);
  }
  fclose(ptr_inputFile);
  fclose(ptr_outputFile);
  return 0;
}


