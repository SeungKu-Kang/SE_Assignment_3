/*
클래스 이름 : ListAllResponses
기능 : 응답한 설문 조회 유스케이스의 비즈니스 로직을 처리하는 컨트롤 클래스
*/
#ifndef LIST_ALL_RESPONSES_H
#define LIST_ALL_RESPONSES_H

#include "SurveyCollection.h"
#include "Constants.h"

#define MAX_TOTAL_RESPONSES (MAX_SURVEYS * MAX_RESPONSES)

class ListAllResponses
{
private:
	SurveyCollection* pSurveycollection;                   // 시스템 전체 Survey 컬렉션 포인터
	char response_topics[MAX_TOTAL_RESPONSES][MAX_STRING]; // 수집된 응답의 설문 주제 배열
	int response_item_nums[MAX_TOTAL_RESPONSES];           // 수집된 응답의 항목 번호 배열
	int total_count;                                       // 수집된 응답 수

public:
	ListAllResponses(SurveyCollection* p_collection); // 생성자 선언

	void getAllResponses();              // 모든 Survey 순회하며 응답 정보 수집
	int getTotalCount();                // 수집된 전체 응답 수 반환
	char* getResponseTopic(int index);  // 인덱스에 해당하는 설문 주제 반환
	int getResponseItemNum(int index);  // 인덱스에 해당하는 응답 항목 번호 반환
};

#endif
