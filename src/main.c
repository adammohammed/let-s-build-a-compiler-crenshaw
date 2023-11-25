#include <stdio.h>
#include "cradle.h"

void compiler_expression();

void compiler_factor() {
  if (look == '(') {
    match('(');
    compiler_expression();
    match(')');
  } else if (is_alpha(look)) {
    char code[1024];
    char n = compiler_get_name();
    sprintf(code, "MOVE %c(PC),D0", n);
    compiler_emit_ln(code);
  } else {
    char code[1024];
    char n = compiler_get_num();
    sprintf(code, "{move,{integer,%c},{x,0}}.", n);
    compiler_emit_ln(code);
  }
}

void compiler_multiply() {
  match('*');
  compiler_factor();
  compiler_emit_ln("{gc_bif,'*',{f,0},3,[{x,2}, {x,0}],{x,0}}.");
}

void compiler_divide() {
  match('/');
  compiler_factor();
  compiler_emit_ln("{gc_bif,'/',{f,0},3,[{x,2}, {x,0}],{x,0}}.");
}

int is_mulop() {
  switch(look) {
  case '*':
    return 1;
  case '/':
    return 2;
  default:
    return 0;
  }
}

void compiler_term() {
  compiler_factor();
  while (is_mulop()) {
    compiler_emit_ln("{move,{x,0},{x,2}}.");
    switch (look) {
    case '*':
      compiler_multiply();
      break;
    case '/':
      compiler_divide();
      break;
    default:
      compiler_expected("Mulop");
      break;
    }
  }
}

void compiler_add() {
  match('+');
  compiler_term();
  compiler_emit_ln("{gc_bif,'+',{f,0},2,[{x,0}, {x,1}],{x,0}}.");
}

void compiler_subtract() {
  match('-');
  compiler_term();
  compiler_emit_ln("{gc_bif,'-',{f,0},2,[{x,0}, {x,1}],{x,0}}.");
}

int is_addop() {
  switch(look) {
  case '+':
    return 1;
  case '-':
    return 2;
  default:
    return 0;
  }
}

void compiler_expression() {
  if (is_addop()) {
      compiler_emit_ln("{move,{integer,0},{x,0}}.");
  } else {
    compiler_term();
  }

  while (is_addop()) {
    compiler_emit_ln("{move,{x,0},{x,1}}.");
    switch (look) {
    case '+':
      compiler_add();
      break;
    case '-':
      compiler_subtract();
      break;
    default:
      compiler_expected("Addop");
      break;
    }
  }
}



int main() {
  compiler_init();
  compiler_expression();
}
