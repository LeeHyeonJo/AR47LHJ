// 선생님 필기 007_Operator001부터 

#include <iostream>

int main()
{
    // f5 => 중단점이 존재하는 데까지 한번에 실행해라.
    // f10 => 처리형태가 구분되는 한 명령씩 실행하라 입니다.

    int Left = 7; // int = 자료형(정수 / 4바이트)
    int Right = 3;
    int Result = 0;

    // 1. 단항연산자: 메모리 영역 1개 
    Result = -Left;// -7
    Result = +Left; // +7 >> 여기까지 실행하면 상단의 Result(-7) >> (+7)로 덧씌워짐. 

    // 2. 이항연산자: 메모리 영역 2개 * "산술연산자"가 대부분 여기에 속함. 
    Result = Right + Left; // 더하기 10 
    Result = Right - Left; // 빼기 -4 (음수도 가능)  
    Result = Right * Left; // 곱하기 21
    Result = Left / Right; // 나누기 *정수의 나누기는 몫만 표기. R(작음)/L(큼)=0,  L(큼)/R(작음)=2
    Result = Right % Left; // 나머지 *R(작음:3)%L(큼:7)=3,  L(큼:7)%R(작음:3)=1

        // 전치, 후치는 나중에~
   
    // 3. 삼항연산자: 메모리 영역 3개 >> 안쓸거임 





    // *자료형 bool(부울)
    // 부울 변수(boolean variables): 참, 거짓만 갖는 변수. 선언시 논리형 키워드 bool을 사용. 
    // 부울 변수를 초기화하거나 값을 할당할 때 true/false(논리형 상수)를 사용함. 
    // 거짓 = 메모리에서 only 0만 존재하는 상태 <-> 참 = 메모리에서 0이외의 값이 단 1개라도 존재하는 상태 
  

   bool bResult = true; //beResult = 참이라는 의미
   bool bResult2 = false; //beResult2 = 거짓이라는 의미
   

    // 1.비교(관계) 연산자: 6종류를 배움 >> 논리형 변수에서 사용하는 연산자(같은지 다른지 어쩌구 등등이 "맞냐/아니냐"를 따지니까.) 
     // 특정 조건이 참인지, 거짓인지 테스트할 수 있는 연산자. 그러나 한번에 하나의 조건만 테스트할 수 있다. 
    
    // 위에서 선언한 Left = 7, Right = 3
        // 여기서 bResult는 부울 변수니까 ... 참or거짓 중 하나를 출력해줄거임. 
        // 자료형을 bool 대신 int로 바꾼다면~ 
           // bResult와 bResult2에 각각 알 수 없는 값이 할당되는 것을 확인할 수 있음. 이는 논리형 상수 true와 false가 정수 1,0이 아니라는 것을 의미함. 
           // 거짓 = 메모리에서 only 0만 존재하는 상태 <-> 참 = 메모리에서 0이외의 값이 단 1개라도 존재하는 상태임을 잊지 말것. 

   bResult = Left == Right; // 두 변수가 같다 => 같지 않으므로 false
   bResult = Left != Right; // 두 변수가 같지 않다 => 같지 않으므로 true
   bResult = Left < Right; // 우측 변수가 좌측보다 크다 => 크지 않으므로 false
   bResult = Left <= Right; // 우측 변수가 좌측보다 크거나 같다 => 크거나 같지 않으므로 false
   bResult = Left > Right; // 좌측 변수가 우측보다 크다 => 크므로 true
   bResult = Left >= Right; // 좌측 변수가 우측보다 크거나 같다 => 크거나 같으므로 true  _ 전부 확인 완료. 


   // 2. 논리 연산자: 3종류를 배움.  and(&&), or(||), not(!)
    // 특정 조건이 참인지, 거짓인지 테스트할 수 있는 연산자. 다중조건의 참/거짓 여부를 테스트할 수 있다. (ex.복권 당첨 확인 - 선택한 모든 숫자의 일치 여부를 비교해야 함) 

   // 1) and(변수&&변수): 변수(메모리) 둘 다 참이라면 참, 하나라도 거짓이면 거짓
   // bool bResult = true;  - bool bResult2 = false; 라고 bResult/bResult2 가 각각 true.false로 정의된 상태. 
   // Q.아니 이거 왜 bResult 만 지정이 되는거임 아니 왜 ??? 이유를 모르겠음. 
        // A.알았다 새로운 변수를 불러낼땐 반드시 Data type 을 무조건 지정해줘야함. bResult, bResult2, Result 3개는 각자 bool,bool,int 로 정의되어있음. 
        // 하지만 새로운 변수 ex) xy 를 새롭게 사용한다면, 반드시 키워드를 앞에 넣어서 xy가 어떠한 타입의 변수인지 지정해주어야 함. (= 초기화)
        // 이걸 하지 않아서 "식별자 xy과 정의되어 있지 않았다" 고 뜬 것. 
        // 단, 같은 이름의 변수의 초기화는 한 번만! 변수의 값을 바꾸고 싶다면 대입으로.  
   
   bool xy = true && true; // 둘 다 true 니까 xy는 true. (새로운 변수 xy 에 bool 키워드를 사용해서 초기화 함) 
   xy = true && false; // 한 쪽만 true 이므로 xy는 false.
   xy = false && false;// 둘 다 false 이므로 xy는 false. 

   // 2) or(변수||변수): 변수 둘 중 하나라도 참이면 참, 모두 거짓이면 거짓. 
   xy = true || true; // 둘 다 참이므로 xy는 true. 
   xy = true || false; // 둘 중 하나가 참이므로 xy는 true. 
   xy = false || false; // 둘 다 false 이므로 xy는 false. 

   // 3) not(!변수): 변수가 거짓이라면 참, 변수가 참이라면 거짓. 
   xy = true; // ** 주의: 변수(xy) 의 참/거짓을 판단하므로, 변수값이 "미지"인 상태이면 안됨. (초기화가 된 변수여야 함) 
   bool xy1 = !xy; // 위에 지정한 xy가 true이므로, xy1는 false(거짓) 
   // 81라인의 xy값 대입을 빼고 진행한다면, 78번 라인에서 xy는 false로 지정된 상태이므로 xy1 은 true (참) 이 됨. 


   // int Left = 7; 으로 이미 선언된 상태 
   Left = Left + 3;


}
