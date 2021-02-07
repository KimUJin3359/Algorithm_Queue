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
- ㅋ