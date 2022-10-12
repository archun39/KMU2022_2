#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define MAX_STACK_SIZE 100

using namespace std;

int err = 0;  //에러가 발생했는지 체크하는 변수(0: 에러 없음, 1: 에러 발생)

typedef char element;


// ===== 스택 코드의 시작 ===== 
typedef struct {
   element data[MAX_STACK_SIZE];
   int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
   s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
   return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
   return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
   if (is_full(s)) {
      fprintf(stderr, "스택 포화 에러\n");
      return;
   }
   else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
   if (is_empty(s)) {
      fprintf(stderr, "스택 공백 에러\n");
      exit(1);
   }
   else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType *s)
{
   if (is_empty(s)) {
      fprintf(stderr, "스택 공백 에러\n");
      exit(1);
   }
   else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 

// 후위 표기 수식 계산 함수
int eval(char exp[])
{
   int op1, op2, value, i = 0;
   int len = strlen(exp);
   char ch;
   StackType s;

   init_stack(&s);
   for (i = 0; i < len; i++) {
      ch = exp[i];
      if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
         value = ch - '0';   // 입력이 피연산자이면
         push(&s, value);
      }
      else {   //연산자이면 피연산자를 스택에서 제거
         op2 = pop(&s);
         op1 = pop(&s);
         switch (ch) { //연산을 수행하고 스택에 저장 
         case '+': push(&s, op1 + op2); break;
         case '-': push(&s, op1 - op2); break;
         case '*': push(&s, op1 * op2); break;
         case '/': push(&s, op1 / op2); break;
         }
      }
   }
   return pop(&s);
}

// 연산자의 우선순위를 반환한다.
int prec(char op)
{
   switch (op) {
   case '(': case ')': return 0;
   case '+': case '-': return 1;
   case '*': case '/': return 2;
   }
return -1;
}

void check_error(element exp[]) {
   err = -1;
   int len = strlen(exp);

   // error 0 : / 연산자 후 0이 오면 예외처리
   for (int i = 0; i < len; i++) {
      if (i + 1 < len && exp[i] == '/' && exp[i + 1] == '0') {
    
         err = 0;
         break;
      }
   }

   int count = 0;
   // error 1 : 괄호의 짝이 맞지 않으면 예외처리
   for (int i = 0; i < len; i++) {
      if (exp[i] == '(') {
         count++;
      }
      else if (exp[i] == ')') {
         count--;
      }
   }
   if (count > 0) {
      
      err = 1;
   }
   else if (count < 0) {
      
      err = 1;
   }

   // error 2 : 예외 문자 포함
   for (int i = 0; i < len; i++) {
      if (exp[i] == '(' || exp[i] == ')') {
         continue;
      }
      else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
         continue;
      }
      else if ('0' <= exp[i] && exp[i] <= '9') {
         continue;
      }
      else {
       
         err = 2;
      }
   }

   // error 3 : 한 자리 수 이상의 수 입력에 대해 예외 처리(예시: 23, 123, ...)
   int count_len = 0;
   int max_len = 0;
   for (int i = 0; i < len; i++) {
      if ('0' <= exp[i] && exp[i] <= '9') {
         count_len++;
         if (count_len >= max_len) {
            max_len = count_len;
         }
      }
      else {
         count_len = 0;
      }
   }
   if (max_len >= 2) {
    
      err = 3;
   }
}

// 수식 변환함수
element* infix_to_postfix(element exp[])
{
   // 입력받은 표기식 에러 검사
   check_error(exp);
   // 에러가 있다면 다시 실행
   if (err != -1) {
      return NULL;
   }

   int i, idx = 0; //i는 for문의 제어변수, idx는 post_arr의 index
   int len = strlen(exp);
   char ch, op;
   StackType s;
   element* postfix_arr = (element*)malloc(MAX_STACK_SIZE);
   if (postfix_arr == NULL) {
     
      exit(1);
   }

   init_stack(&s);  //스택 초기화

   // 중위 표기식으로 표현된 식을 순회
   for (int i = 0; i < len; i++)
   {
      // 값을 뽑는다
      ch = exp[i];

      // 일반 숫자라면 그대로 postfix_arr에 추가
      if ('0' <= ch && ch <= '9') {
         postfix_arr[idx++] = ch;
      }

      // 연산자 +,-,*,/라면
      else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
         // 스택의 top 값이 현재 연산자보다 우선순위가 높다면
         while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
         {
            // 해당 값들은 모두 추가해준다.
            postfix_arr[idx++] = peek(&s);
            pop(&s);
         }
         // 자기자신을 스택에 추가한다.
         push(&s, ch);
      }

      // '('는 무조건 스택에 추가한다.
      else if (ch == '(') {
         push(&s, ch);
      }

      // ')'가 나오면 '('가 나올때 까지 스택에서 pop하여 추가해준다.
      else if (ch == ')') {
         op = pop(&s);
         while (op != '(')
         {
            postfix_arr[idx++] = op;
            op = pop(&s);
         }
      }
   }

   //아직 스택에 남아있는 값들을 모두 추가해준다.
   while (!is_empty(&s)) {
      op = peek(&s);
      pop(&s);
      postfix_arr[idx++] = op;
   }

   // 문자열의 끝을 지정해준다.
   postfix_arr[idx] = '\0';
   return postfix_arr;
}

int main(void)
{
   element expression[MAX_STACK_SIZE];
   char word[100];
   int tc;
   cin >> tc;
   for(int testcas=0; testcas<tc; testcas++){
       int n;
       cin >> n;
       for(int i=0; i<n; i++){
           cin >> expression[i];
       }
   // 무한 반복문
   while (1) {
      // 중위 표기식 입력
      

      
      element *result = infix_to_postfix(expression);
      if (err == -1) {
         printf("후위표기수식 : %s\n", result);
         printf("결과값 : %d\n\n", eval(result));
      }

      // 다시 입력할지 여부 검사
      int exit = 0;
      while (1) {
         printf("다시 입력하시겠습니까?(yes/no) : ");
         scanf("%s", word);

         // yes면 다시 시작
         if (strcmp(word, "yes") == 0) {
            break;
         }
         // no 면 exit = 1로 값 설정
         else if (strcmp(word, "no") == 0) {
            exit = 1;
            break;
         }
         // 이외 값은 yes, no중 입력 들어오도록 while문 다시 시작
         else {
            printf("yes 혹은 no로 입력해주세요.\n");
            continue;
         }
      }
      // exit가 1이면 (no입력시) break를 통해 종료
      if (exit == 1) {
         break;
      }
      else {
         printf("\n");
      }
   }
   }
   return 0;
}
