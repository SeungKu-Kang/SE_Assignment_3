#include "ListAllResponses.h"
#include <cstring>

/*
함수 이름 : ListAllResponses
기능 : ListAllResponses 생성자로서 SurveyCollection 포인터를 저장하고 카운터를 초기화한다.
매개변수 : SurveyCollection* p_collection -> 시스템 전체 Survey 컬렉션 포인터
반환값 : 없음
*/
ListAllResponses::ListAllResponses(SurveyCollection* p_collection)
	: pSurveycollection(p_collection), total_count(0)
{
}

/*
함수 이름 : getAllResponses
기능 : 모든 Survey를 순회하며 응답 정보를 내부 배열에 수집한다.
매개변수 : 없음
반환값 : 없음
*/
void ListAllResponses::getAllResponses()
{
	total_count = 0;

	for (int i = 0; i < pSurveycollection->getSurveyCount(); i++)
	{
		Survey* p_survey = pSurveycollection->getSurvey(i);
		char* topic = p_survey->getSurveyInfo(); // 1.1.1*: getSurveyInfo()

		ResponseCollection* p_rc = p_survey->getResponseCollection();

		for (int j = 0; j < p_rc->getResponseCount(); j++)
		{
			Response* p_response = p_rc->getResponse(j);
			int item_num = p_response->getResponseInfo(); // 1.1.1.1*: getResponseInfo()

			strcpy(response_topics[total_count], topic);
			response_item_nums[total_count] = item_num;
			total_count++;
		}
	}
}

/*
함수 이름 : getTotalCount
기능 : 수집된 전체 응답 수를 반환한다.
매개변수 : 없음
반환값 : int -> 수집된 응답 수
*/
int ListAllResponses::getTotalCount()
{
	return total_count;
}

/*
함수 이름 : getResponseTopic
기능 : 인덱스에 해당하는 설문 주제를 반환한다.
매개변수 : int index -> 배열 인덱스
반환값 : char* -> 설문 주제 문자열, 범위 초과 시 nullptr
*/
char* ListAllResponses::getResponseTopic(int index)
{
	if (index >= 0 && index < total_count)
	{
		return response_topics[index];
	}

	return nullptr;
}

/*
함수 이름 : getResponseItemNum
기능 : 인덱스에 해당하는 응답 항목 번호를 반환한다.
매개변수 : int index -> 배열 인덱스
반환값 : int -> 응답 항목 번호, 범위 초과 시 -1
*/
int ListAllResponses::getResponseItemNum(int index)
{
	if (index >= 0 && index < total_count)
	{
		return response_item_nums[index];
	}

	return -1;
}
