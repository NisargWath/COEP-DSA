typedef struct node{
    int coef;
    int exp;
}node;

typedef struct Poly{
    node * p;
    int len;
    int size;
}Poly;

void init(Poly * p, int size);
void append(Poly *p ,int coef,int exp);
void display(Poly *p);
void sort_exp(Poly * p);
Poly convert_to_form(Poly * p);
int max(int a, int b);
Poly add_poly(Poly * p,Poly *q);
Poly sub_poly(Poly * p,Poly *q);
void freePolynomial(Poly *p);
