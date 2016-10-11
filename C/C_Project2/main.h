#ifndef HEADER_FILE
#define HEADER_FILE


int strleng(char *word);
void get_next_max(int prev_idx,float prev_val,float *tab, float *new_val, int *idx);
float *build_dictionary(char *str);
/* void create_ordered_tree(); */

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
#endif
