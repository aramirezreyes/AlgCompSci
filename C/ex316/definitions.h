/* Header file for excercise 3.16 */

#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct monom_t *monom;
typedef struct polynom_t *polynom;

struct monom_t{
  int coef;
  int power;
};

struct polynom_t{
  int coef;
  int power;
  struct polynom_t *next;
};



#endif

