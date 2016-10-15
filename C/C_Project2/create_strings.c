/* We will explore the tree until every leaf, in each leaf we will encode the corresponding symbol. The distinguishing characteristic of each leaf is that it doesn't have right or left childern; because it is a leaf. We will use a string of fixed length (8) to codify everything, hoping that it is enough.(It would be enough for the ascii symbols because 2**8 = 128 and there are 127 ascii symbols) */


int code_generator = (tree_t tree,char *out_table){ /* missing allocation and deallocation */
  int out = 1,val;
  tree_t right_aux_tree;
  tree_t left_aux_tree;
  if (tree->right){
/* malocar  */
    code = code*2+1;
    right_aux_tree = tree->right;
    code_auxiliarString(right_aux_tree);}
  if (tree->left){
/* malocar */
    out = out*2;
    left_aux_tree = tree->left;
    code_auxiliarString(left_aux_tree);}

  val =  tree->value;
  out_table[val] = out;
  /* dealocar x 2 */
  return 0
}


  /* Muy incipiente, pensar con calma SIN ALCOHOL */
tree_t tree_generator(bamboo_t bamboo){
  tree_t tree, aux_tree;
  tree_t = malloc((tree_t) sizeof(tree_s));
  int a,b;
  float fa,fb;
  while((bamboo->next->frequency)!=1){
    a = bamboo->index;
    fa =bamboo -> freq;
    aux_tree = bamboo->next;
    b = aux_tree->index;
    fb = aux_tree-> freq;
    
}
}




