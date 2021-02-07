# Queue

### 큐
- 삽입과 삭제의 위치가 제한적이 자료구조
- 큐의 뒤에서는 삽입, 큐의 앞에서느 삭제만 이루어짐
- FIFO(First In First Out) : 가장 먼저 삽입된 원소는 가장 먼저 삭제됨
- 연산
  - enQueue(item) : 큐의 뒤쪽에 원소를 삽입
  - deQueue() : 큐의 앞쪽에서 원소를 삭제하고 반환
  - createQueue() : 공백 상태의 큐를 생성
  - isEmpty() : 큐가 공백상태인지 확인
  - isFull() : 큐가 포화상태인지 확인
  - Qpeek() : 큐의 앞쪽 원소를 반환
- 큐의 종류
  - 선형큐 : 1차원 배열을 이용한 큐
  - 원형큐 : 1차원 배열을 사용하되, 논리적으로는 배열의 처음과 끝이 연결되어 있는 큐
  - 연결큐 : Linkied List를 이용한 큐
  
### 선형큐
- 큐의 크기 = 배열의 크기
- front : 저장된 첫번째 원소의 인덱스
- rear : 저장된 마지막 원소의 인덱스
- 상태 표현
  - 초기 상태 : front = rear = -1
  - 공백 상태 : front = rear
  - 포화 상태 : rear = n - 1 (n : 배열의 크기, n - 1 : 배열의 마지막 인덱스)
- 문제점
  - 잘못된 포화상태 인식
    - 삽입과 삭제가 반복될 경우, 배열의 앞부분에 활용할 수 있는 공간이 있음에도 포화상탤 인식(rear = n - 1)

### 원형큐
- 상태 표현
  - 초기 공백 상태 : front = rear = 0
- index의 순환
  - front와 rear의 위치가 배열의 마지막 인덱스인 n - 1을 가리키 후, 배열의 처음 인덱스인 0으로 이동
- front 변수
  - 공백 상태와 포화 상태 구분을 쉽게 하기 위해 front가 있는 자리는 사용하지 않고 항상 빈자리 

### 연결큐
- 큐의 원소 : 단순 연결 리스트의 노드
- 큐의 원소 순서 : 노드의 연결 순서, 링크로 연결되어 있음
- front : 첫번째 노드를 가리키는 링크
- rear : 마지막 노드를 가리키는 링크
- 상태 표현
  - 초기상태 : front = rear = null
  - 공백상태 : front = rear = null
  
### 우선순위 큐(Priority Queue)
- 특성
  - 우선순위를 가진 항목들을 저장
  - 우선순위가 높은 순서대로 먼저 나감
- 구현
  - 배열을 이용한 우선순위 큐
  - 리스트를 이용한 우선순위 큐
  
### 버퍼
- 데이터를 한 곳에서 다른 한 곳으로 전송하는 동안 일시적으로 그 데이터를 보관하는 영역
- 버퍼링
  - 버퍼를 활용하는 방식 또는 버퍼를 채우는 동작

### BFS(너비 우선 탐색)
- 탐색 시작점의 **인접한 정점들을 먼저** 모두 차례로 방문한 후에, 방문했던 정점을 시작점으로 하여 다시 인접한 정점들을 차례로 방문하는 방식

#### 관련 문제
[1.Contact](https://github.com/KimUJin3359/Queue/tree/master/Contact)
- 비상연락망과 연락을 시작하는 당번에 대한 정보가 주어질 때, 가장 나중에 연락을 받게 되는 사람 중 번호가 가장 큰 사람을 구하는 문제
- 접근 방법
  - 각 node에 distance 속성을 주어 당번으로 부터의 거리를 data에 같이 저장 
  - BFS 활용

[2.Maze](https://github.com/KimUJin3359/Queue/tree/master/Maze)
- 이전에 나왔던 미로 찾기 문제와 동일
- 접근 방법
  - 이전에 풀이법이 DFS였다면 이번 풀이법은 BFS
  
[3.PasswordMaker](https://github.com/KimUJin3359/Queue/tree/master/PasswordMaker)
- 8개의 숫자를 입력받은 후, 첫 번째 숫자를 1 감소시킨 뒤 맨 뒤로 보냄
- 다음 첫번째 수는 2 감소 후 맨 뒤로, ..., 5 감소 후 맨 뒤로
- 숫자가 감소할 때 0보다 작아지는 경우 0으로 유지되며, 프로그램이 종료될 때 결과 값을 구하는 문제
- 접근 방법
  - queue에 삽입 되어 있는 원소를 dequeue하여 한 원소의 값이 0보다 작아질 때 까지 반복

[4.ProgramVertification](https://github.com/KimUJin3359/Queue/tree/master/ProgramVertification)
- [규칙](https://github.com/KimUJin3359/Queue/blob/master/ProgramVertification/%EB%AC%B8%EC%A0%9C(2).JPG)에 따라 동작하는 프로그램이 종료될 수 있는지 확인하는 문제
- **해당 문제 풀이 중으로 완료 후 업데이트 예정**

[5.ex03](https://github.com/KimUJin3359/Queue/tree/master/ex03)
- 정점과 간선이 주어질 때, 너비우선탐색을 할 경우 경로를 출력하는 문제
