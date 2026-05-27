/*
클래스 이름 : ResponseCollection
기능 : Survey 객체에 속한 Response 객체들을 배열로 관리하는 컬렉션 클래스
*/
#ifndef RESPONSE_COLLECTION_H
#define RESPONSE_COLLECTION_H

#include "Response.h"
#include "Constants.h"

class ResponseCollection
{
private:
	Response* responses[MAX_RESPONSES]; // Response 포인터 배열
	int response_count;                 // 현재 저장된 Response 수

public:
	ResponseCollection();  // 생성자 선언
	~ResponseCollection(); // 소멸자 선언

	void addResponse(Response* p_response); // Response 추가
	Response* getResponse(int index);       // 인덱스로 Response 반환
	int getResponseCount();                 // 저장된 Response 수 반환
};

#endif
