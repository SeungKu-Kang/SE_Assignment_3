/*
클래스 이름 : Response
기능 : 설문에 대한 응답 항목 번호를 저장하는 엔터티 클래스
*/
#ifndef RESPONSE_H
#define RESPONSE_H

class Response
{
private:
	int item_num; // 응답한 항목 번호

public:
	Response(int num); // 생성자 선언

	int getResponseInfo(); // 응답 항목 번호 반환
};

#endif
