struct monom_t{
  int coef;
  int power;
};

struct polynom_t{
  struct monom monomia;
  struct polynom *next;
};

polynom polyno_multiplyByX()
