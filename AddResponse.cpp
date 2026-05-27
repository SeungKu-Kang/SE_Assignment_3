#include "AddResponse.h"

/*
함수 이름 : AddResponse
기능 : AddResponse 생성자로서 SurveyCollection 포인터를 저장한다.
매개변수 : SurveyCollection* p_collection -> 시스템 전체 Survey 컬렉션 포인터
반환값 : 없음
*/
AddResponse::AddResponse(SurveyCollection* p_collection)
	: pSurveycollection(p_collection)
{
}

/*
함수 이름 : addNewResponse
기능 : 주제로 Survey를 찾아 새 Response를 추가한다.
매개변수 : char* topic  -> 응답할 설문 주제
           int item_num -> 응답 항목 번호
반환값 : 없음
*/
void AddResponse::addNewResponse(char* topic, int item_num)
{
	Survey* p_survey = pSurveycollection->findSurvey(topic);

	if (p_survey)
	{
		p_survey->addNewResponse(item_num); // 1.1.1: addNewResponse() -> 1.1.1.1: Response()
	}
}
