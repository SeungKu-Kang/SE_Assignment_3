/*
클래스 이름 : AddResponse
기능 : 설문 응답 유스케이스의 비즈니스 로직을 처리하는 컨트롤 클래스
*/
#ifndef ADD_RESPONSE_H
#define ADD_RESPONSE_H

#include "SurveyCollection.h"

class AddResponse
{
private:
	SurveyCollection* pSurveycollection; // 시스템 전체 Survey 컬렉션 포인터

public:
	AddResponse(SurveyCollection* p_collection); // 생성자 선언

	void addNewResponse(char* topic, int item_num); // 해당 설문에 응답 추가
};

#endif
