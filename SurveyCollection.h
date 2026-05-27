/*
클래스 이름 : SurveyCollection
기능 : 시스템 전체의 Survey 객체들을 배열로 관리하는 컬렉션 클래스
*/
#ifndef SURVEY_COLLECTION_H
#define SURVEY_COLLECTION_H

#include "Survey.h"
#include "Constants.h"

class SurveyCollection
{
private:
	Survey* surveys[MAX_SURVEYS]; // Survey 포인터 배열
	int survey_count;             // 현재 저장된 Survey 수

public:
	SurveyCollection();  // 생성자 선언
	~SurveyCollection(); // 소멸자 선언

	void addSurvey(Survey* p_survey);  // Survey 추가
	Survey* findSurvey(char* topic);   // 주제로 Survey 검색
	Survey* getSurvey(int index);      // 인덱스로 Survey 반환
	int getSurveyCount();              // 저장된 Survey 수 반환
};

#endif
