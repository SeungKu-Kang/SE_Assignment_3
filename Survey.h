/*
클래스 이름 : Survey
기능 : 설문 주제, 항목 수, 응답 컬렉션을 저장하고 관리하는 엔터티 클래스
*/
#ifndef SURVEY_H
#define SURVEY_H

#include "ResponseCollection.h"
#include "Constants.h"

class Survey
{
private:
	char topic[MAX_STRING];                  // 설문 주제
	int item_count;                          // 설문 항목 수
	ResponseCollection* pResponseCollection; // 이 설문에 달린 응답 컬렉션

public:
	Survey(char* t, int count); // 생성자 선언
	~Survey();                  // 소멸자 선언

	void addNewResponse(int item_num);              // 새 응답 추가
	char* getSurveyInfo();                          // 설문 주제 반환
	int getItemCount();                             // 설문 항목 수 반환
	ResponseCollection* getResponseCollection();    // 응답 컬렉션 포인터 반환
};

#endif
