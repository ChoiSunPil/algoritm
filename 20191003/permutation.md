# C++ next_permutation 사용법

## 헤더 파일

###### #include <algorithm>



## 기본 구조

```c++
// 첫번째 인자가 구하고자 하는 순열의 시작, 두번째 인자가 순열의 끝
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);

// 아래처럼 직접 비교함수를 넣어줘도 됩니다.
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);
```



## 구현 방법

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	vector<int> v(4);

	// 1부터 4까지 벡터에 저장


	// next_permutation을 통해서 다음 순열 구하기
	do{

		for(int i=0; i<4; i++){
			cout << v[i] << " ";
		}

		cout << '\n';

	}while(next_permutation(v.begin(),v.end()));

	return 0;

}
```

