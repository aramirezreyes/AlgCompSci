#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct bamboo_s *bamboo_t;
typedef struct leaf_s *leaf_t;
typedef struct tree_s *tree_t;

int strleng(char *word);
void get_next_max(float *tab, float *new_val, int *idx);
void get_next_in(float *tab, float *new_val, int *idx);
float *build_dictionary(char *str);
bamboo_t create_ordered_tree(float *oc);
tree_t append_to_tree(tree_t tree1, tree_t tree2);
tree_t tree_generator(bamboo_t bamboo);
void free_bamboo(bamboo_t bamboo);
void code_generator(int base,tree_t tree,int *out_table,int dist);
void encode_file(char *file_name,char *output_text,int *codes);
char encode_symbol(char symbol,int *codes);
/* struct polynom_t{ */
/*   int coef; */
/*   int power; */
/*   struct polynom_t *next; */
/* };	*/

struct leaf_s{
  char symbol;
  float freq;
};
struct tree_s{
  /* leaf_t leaf; */
  char symbol;
  float freq;
  tree_t left;
  tree_t right;
  };

struct bamboo_s{
  /* leaf_t leaf; */
  /* char symbol; */
  /* float freq; */
  tree_t tree;
  struct bamboo_s *next;
  };


#endif
