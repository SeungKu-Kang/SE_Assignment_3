#include "AddSurvey.h"

/*
함수 이름 : AddSurvey
기능 : AddSurvey 생성자로서 SurveyCollection 포인터를 저장한다.
매개변수 : SurveyCollection* p_collection -> 시스템 전체 Survey 컬렉션 포인터
반환값 : 없음
*/
AddSurvey::AddSurvey(SurveyCollection* p_collection)
	: pSurveycollection(p_collection)
{
}

/*
함수 이름 : addNewSurvey
기능 : 새 Survey 객체를 생성하여 SurveyCollection에 추가한다.
매개변수 : char* topic    -> 설문 주제
           int item_count -> 설문 항목 수
반환값 : 없음
*/
void AddSurvey::addNewSurvey(char* topic, int item_count)
{
	Survey* p_survey = new Survey(topic, item_count); // 1.1.1: Survey()
	pSurveycollection->addSurvey(p_survey);
}
