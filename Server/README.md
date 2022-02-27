# Server

## 멀티스레드
```cs
Thread 선언 파라미터로 함수를 넣어준다
background 실행과 foreground실행이 있을 때, background는 메인이 끝나면 끝난다
잠깐만 쓰는 스레드는 스레드풀로 이용 -> 유니티 풀링과 유사 -> 한정된 스레드가 끝나야만 다음스레드 실행
기본적인 스레드는 foreground, 스레드풀은 background
Task는 스레드풀의 일종
Task에서 LongrunningTask 설정을 해주면 오래 걸리는 것도 관리할 수 있음
메모리 배리어 - 코드 재배치 억제, 가시성
풀 메모리 베리어와 스토어 메모리 베리어, 로드 메모리 베리어가 있음
interlocked.Increment(ref number)로 원자성을 만들 수도 있다
	-> Monitor.Enter로 크리티컬 섹션을 보호할 수 있음
	-> lock(_obj)로 데드락을 어느정도 방지할 수 있음
	-> lock이 여러개를 동시에 할 때 생기는 데드락을 크래시가 나고 구조를 변경하는게 제일 쉽긴함
스핀락 - Interlocked.CompareExchange로 이전값을 받으며 변경, 이전값으로 비었는지 아닌지 체크 가능
 -> 면접에서 자주 물어봄
슬립 - 일정시간 후 깨서 락을 확인함
 -> Sleep(1) - 무조건 휴식
 -> Sleep(0) - 우선순위가 낮은 애들한테 양보 안함
 -> Yield() - 관대한 양보
AutoResetEvent - 자동으로 문을 잠가줌 _available.WaitOne(), Set()으로 출입을 제어
ManualResetEvent - 내가 직접 문을 닫아야 하지만, 크리티컬 섹션을 완벽히 지키지 못함
Mutex - 커널단위까지 내려가서 막아줌, 많은 정보를 담고있다보니 실행속도가 오토리셋보다 느림
RWLock(ReaderWriterLock) - 리더는 여러명, 라이터는 한명만 들어가는 락
패킷이 여러개가 한데 뭉친다거나 하는 경우에 멀티 스레드로 이용하는게 더 구려짐
ThreadLocal을 이용해서 스레드별로 사용하는 전역변수로 만듬

```