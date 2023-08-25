enum {
  ast_type_add,
  ast_type_mul,
  ast_type_statement,
  ast_type_number,
  ast_type_identifier,
  ast_type_symbol
};

typedef struct ast {
  char* type;                   // type of the AST node
  union{
    struct {
      struct ast* left;
      struct ast* right;
    } operation;
    struct {
      char * identifier;
      Symbol symbol;
      ast expression;
      ast next;
    } statement;
    int number;
    char* id;
    Symbol symbol;
  } u;
} ast;

ast* ast_new_operation(char*, ast*, ast*);
ast* ast_new_number(int);
ast* ast_new_id(char*);
void ast_print(ast*, int);
