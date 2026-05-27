#include "Survey.h"
#include <cstring>

/*
함수 이름 : Survey
기능 : Survey 생성자로서 설문 주제와 항목 수를 초기화하고 ResponseCollection을 동적 생성한다.
매개변수 : char* t   -> 설문 주제 문자열
           int count -> 설문 항목 수
반환값 : 없음
*/
Survey::Survey(char* t, int count)
	: item_count(count)
{
	strcpy(topic, t);
	pResponseCollection = new ResponseCollection();
}

/*
함수 이름 : ~Survey
기능 : Survey 소멸자로서 동적 할당된 ResponseCollection을 해제한다.
매개변수 : 없음
반환값 : 없음
*/
Survey::~Survey()
{
	if (pResponseCollection)
	{
		delete pResponseCollection;
		pResponseCollection = nullptr;
	}
}

/*
함수 이름 : addNewResponse
기능 : 새 Response 객체를 생성하여 ResponseCollection에 추가한다.
매개변수 : int item_num -> 응답 항목 번호
반환값 : 없음
*/
void Survey::addNewResponse(int item_num)
{
	Response* p_response = new Response(item_num);
	pResponseCollection->addResponse(p_response);
}

/*
함수 이름 : getSurveyInfo
기능 : 설문 주제 문자열을 반환한다.
매개변수 : 없음
반환값 : char* -> 설문 주제 문자열
*/
char* Survey::getSurveyInfo()
{
	return topic;
}

/*
함수 이름 : getItemCount
기능 : 설문 항목 수를 반환한다.
매개변수 : 없음
반환값 : int -> 설문 항목 수
*/
int Survey::getItemCount()
{
	return item_count;
}

/*
함수 이름 : getResponseCollection
기능 : 이 설문의 ResponseCollection 포인터를 반환한다.
매개변수 : 없음
반환값 : ResponseCollection* -> ResponseCollection 포인터
*/
ResponseCollection* Survey::getResponseCollection()
{
	return pResponseCollection;
}
