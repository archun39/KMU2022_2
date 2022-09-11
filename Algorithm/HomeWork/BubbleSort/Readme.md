# Bubble Sort Algorithm 및 Improved Algorithms 구현
강의 노트에 제시된 Bubble Sort 알고리즘, 개선된 Bubble Sort 알고리즘 1, 2 를 각각 구현하 고, 
각 알고리즘에서 실행한 비교 연산자의 총 횟수와 비교 연산의 결과로 비교한 두 데이터를 교환(swap)한 횟수를 계산하는 프로그램을 작성하시오.  

## 입력
입력은 표준입력(standard input)을 사용한다. 입력은 𝑡𝑡 개의 테스트 케이스로 주어진다. 입력의 첫 번째 줄에 테스트 케이스의 개수를 나타내는 정수 𝑡𝑡가 주어진다. 두 번째 줄부터 t 개의 줄에 는 한 줄에 한 개의 테스트 케이스에 해당하는 데이터가 입력된다. 각 줄에서 첫 번째로 입력되 는 정수 𝑛𝑛(1≤𝑛𝑛≤100)은 정렬하여야 할 정수의 개수를 나타낸다. 그 다음으로는 𝑛𝑛개의 정수가 입력된다. 이 정수는 최소 1이며 최대 10,000이다. 각 정수들 사이에는 한 개의 공백이 있으며, 잘못된 데이터가 입력되는 경우는 없다.
## 출력
출력은 표준출력(standard output)을 사용한다. 입력되는 테스트 케이스의 순서대로 다음 줄에 이어서 각 테스트 케이스의 결과를 출력한다. 먼저 Bubble Sort 알고리즘에서 실행한 비교 연산 자의 총 횟수와 교환 횟수를 출력하고, 그 다음으로는 개선 알고리즘 1, 그리고 마지막으로 개 선 알고리즘 2 의 비교 연산자의 총 횟수와 교환 횟수를 출력한다. 모두 6 개 정수들 사이에는 한 개의 공백을 둔다.

### 입력 예
3  
9 1 2 3 4 5 6 7 8 9  
9 9 8 7 6 5 4 3 2 1  
9 9 6 3 1 2 4 5 7 8  

### 출력 예
36 0 8 0 8 0  
36 36 36 36 36 36  
36 15 26 15 20 15  