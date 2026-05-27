#include "SurveyCollection.h"
#include <cstring>

/*
함수 이름 : SurveyCollection
기능 : SurveyCollection 생성자로서 배열 포인터를 초기화하고 카운터를 0으로 설정한다.
매개변수 : 없음
반환값 : 없음
*/
SurveyCollection::SurveyCollection()
	: survey_count(0)
{
	for (int i = 0; i < MAX_SURVEYS; i++)
	{
		surveys[i] = nullptr;
	}
}

/*
함수 이름 : ~SurveyCollection
기능 : SurveyCollection 소멸자로서 동적 할당된 Survey 객체를 모두 해제한다.
매개변수 : 없음
반환값 : 없음
*/
SurveyCollection::~SurveyCollection()
{
	for (int i = 0; i < survey_count; i++)
	{
		if (surveys[i])
		{
			delete surveys[i];
			surveys[i] = nullptr;
		}
	}
}

/*
함수 이름 : addSurvey
기능 : Survey 포인터를 배열에 추가한다.
매개변수 : Survey* p_survey -> 추가할 Survey 포인터
반환값 : 없음
*/
void SurveyCollection::addSurvey(Survey* p_survey)
{
	if (survey_count < MAX_SURVEYS)
	{
		surveys[survey_count] = p_survey;
		survey_count++;
	}
}

/*
함수 이름 : findSurvey
기능 : 주제 문자열로 Survey를 검색하여 포인터를 반환한다.
매개변수 : char* topic -> 검색할 설문 주제
반환값 : Survey* -> 찾은 Survey 포인터, 없으면 nullptr
*/
Survey* SurveyCollection::findSurvey(char* topic)
{
	for (int i = 0; i < survey_count; i++)
	{
		if (strcmp(surveys[i]->getSurveyInfo(), topic) == 0)
		{
			return surveys[i];
		}
	}

	return nullptr;
}

/*
함수 이름 : getSurvey
기능 : 인덱스에 해당하는 Survey 포인터를 반환한다.
매개변수 : int index -> 배열 인덱스
반환값 : Survey* -> 해당 인덱스의 Survey 포인터, 범위 초과 시 nullptr
*/
Survey* SurveyCollection::getSurvey(int index)
{
	if (index >= 0 && index < survey_count)
	{
		return surveys[index];
	}

	return nullptr;
}

/*
함수 이름 : getSurveyCount
기능 : 저장된 Survey 수를 반환한다.
매개변수 : 없음
반환값 : int -> 저장된 Survey 수
*/
int SurveyCollection::getSurveyCount()
{
	return survey_count;
}
