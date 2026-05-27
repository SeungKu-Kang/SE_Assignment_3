#include "ResponseCollection.h"

/*
함수 이름 : ResponseCollection
기능 : ResponseCollection 생성자로서 배열 포인터를 초기화하고 카운터를 0으로 설정한다.
매개변수 : 없음
반환값 : 없음
*/
ResponseCollection::ResponseCollection()
	: response_count(0)
{
	for (int i = 0; i < MAX_RESPONSES; i++)
	{
		responses[i] = nullptr;
	}
}

/*
함수 이름 : ~ResponseCollection
기능 : ResponseCollection 소멸자로서 동적 할당된 Response 객체를 모두 해제한다.
매개변수 : 없음
반환값 : 없음
*/
ResponseCollection::~ResponseCollection()
{
	for (int i = 0; i < response_count; i++)
	{
		if (responses[i])
		{
			delete responses[i];
			responses[i] = nullptr;
		}
	}
}

/*
함수 이름 : addResponse
기능 : Response 포인터를 배열에 추가한다.
매개변수 : Response* p_response -> 추가할 Response 포인터
반환값 : 없음
*/
void ResponseCollection::addResponse(Response* p_response)
{
	if (response_count < MAX_RESPONSES)
	{
		responses[response_count] = p_response;
		response_count++;
	}
}

/*
함수 이름 : getResponse
기능 : 인덱스에 해당하는 Response 포인터를 반환한다.
매개변수 : int index -> 배열 인덱스
반환값 : Response* -> 해당 인덱스의 Response 포인터, 범위 초과 시 nullptr
*/
Response* ResponseCollection::getResponse(int index)
{
	if (index >= 0 && index < response_count)
	{
		return responses[index];
	}

	return nullptr;
}

/*
함수 이름 : getResponseCount
기능 : 저장된 Response 수를 반환한다.
매개변수 : 없음
반환값 : int -> 저장된 Response 수
*/
int ResponseCollection::getResponseCount()
{
	return response_count;
}
