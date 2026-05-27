/*
클래스 이름 : AddSurvey
기능 : 설문 등록 유스케이스의 비즈니스 로직을 처리하는 컨트롤 클래스
*/
#ifndef ADD_SURVEY_H
#define ADD_SURVEY_H

#include "SurveyCollection.h"

class AddSurvey
{
private:
	SurveyCollection* pSurveycollection; // 시스템 전체 Survey 컬렉션 포인터

public:
	AddSurvey(SurveyCollection* p_collection); // 생성자 선언

	void addNewSurvey(char* topic, int item_count); // 새 설문 등록
};

#endif
