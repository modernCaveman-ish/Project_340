

typedef double (*arithmetic_func_t)(double x, double y);
void execute_arithmetic (instruction* instr);
void execute_add (instruction* instr);
void execute_sub (instruction* instr);
void execute_mul (instruction* instr);
void execute_div (instruction* instr);
void execute_mod (instruction* instr);
double add_impl (double x, double y);
double sub_impl (double x, double y);
double mul_impl (double x, double y);
double div_impl (double x, double y);
double mod_impl (double x, double y);
