# Binary-Searching (재귀함수로 구현)
오름차순으로 나열된 𝑛𝑛개 정수의 수열 𝐴𝐴 = 〈𝑎𝑎0, 𝑎𝑎1, … , 𝑎𝑎𝑛𝑛−1〉 (𝑎𝑎0 < 𝑎𝑎1 < ⋯ < 𝑎𝑎𝑛𝑛−1)가 주어졌을 때,
주어진 또 다른 정수 𝐾𝐾가 수열 𝐴𝐴에 속하는 숫자인지를 판별하는 이진탐색 알고리즘을 구현하시
오. 정수 𝐾𝐾가 수열 𝐴𝐴에 속하면 그 숫자의 index 를 리턴하고, 그렇지 않으면 -1 을 리턴한다. 수
열에서 나열된 정수의 index 는 0 부터 시작한다.
예를 들어, 다음과 같은 7 개의 정수가 주어졌을 때,
𝐴𝐴 = 〈2, 5, 9, 14, 21, 23, 29 〉
정수 21 은 수열 𝐴𝐴에 속하므로 이 정수의 index 인 4 를 리턴한다. 그러나 정수 20 은 수열 𝐴𝐴에
속하지 않으므로 -1 을 리턴한다.
<< 주의 >>
다음과 같은 경우 혹은 그 외의 편법을 통한 프로그램을 제출하는 경우에는 이 문제의 점수 뿐
만 아니라 다른 모든 과제의 점수를 0 점으로 처리함.
1. 위 해결 프로그램을 재귀적(recursive)으로 구현하지 않고, 반복문을 사용하거나 등의 다
른 방법으로 구현하여 제출하는 경우.
2. 채점 프로그렘 시스템에 재귀적 프로그램이 아닌 반복문을 사용하거나 정렬을 사용하는 등
의 다른 방법으로 구현하여 프로그램을 한 번이라도 제출하는 경우.
## 입력
입력은 표준입력(standard input)을 사용한다. 입력은 𝑡𝑡개의 테스트 케이스로 주어진다. 입력의
첫 번째 줄에 테스트 케이스의 개수를 나타내는 정수 𝑡𝑡가 주어진다. 두 번째 줄부터 한 개의 테
스트 케이스에 대하여 두 줄씩 데이터가 입력된다. 각 테스트 케이스에 해당하는 첫 번째 줄에
는 두 개의 정수 𝑛𝑛 𝐾𝐾 (1 ≤ 𝑛𝑛 ≤ 100)가 주어진다. 첫 번째 정수 𝑛𝑛은 수열 𝐴𝐴에 속하는 정수의 개수
를 나타내며, 두 번째 정수는 탐색할 정수이다. 각 테스트 케이스의 두 번째 줄에는 수열 𝐴𝐴에 속
하는 𝑛𝑛개의 정수들이 주어진다. 이 수들은 1000 보다 작은 자연수들이며 오름차순으로 나열되어
있다. 같은 줄에 주어진 모든 정수들 사이에는 한 개의 공백이 있으며, 잘못된 데이터가 입력되
는 경우는 없다.
## 출력
출력은 표준출력(standard output)을 사용한다. 입력되는 테스트 케이스의 순서대로 다음 줄에 이어서 각 테스트 케이스의 결과를 출력한다. 각 테스트 케이스에 해당하는 출력의 입력되는 정
수 𝐾𝐾가 수열 𝐴𝐴에 속하면 그 숫자의 index 를 리턴하고, 그렇지 않으면 -1 을 리턴한다.