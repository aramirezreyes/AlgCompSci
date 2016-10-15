#ifndef HEADER_FILE
#define HEADER_FILE


int strleng(char *word);
void get_next_max(float *tab, float *new_val, int *idx);
void get_next_in(float *tab, float *new_val, int *idx);
float *build_dictionary(char *str);
void create_ordered_tree(float *oc);

typedef struct bamboo_s *bamboo_t;
typedef struct leaf_s *leaf_t;

/* struct polynom_t{ */
/*   int coef; */
/*   int power; */
/*   struct polynom_t *next; */
/* };	*/

struct leaf_s{
  char symbol;
  float freq;
};

struct bamboo_s{
  /* leaf_t leaf; */
    char symbol;
  float freq;
  struct bamboo_s *next;
  };

struct tree_s{
  /* leaf_t leaf; */
    char symbol;
  float freq;
  struct tree_s *left;
  struct tree_s *right;
  };
#endif
