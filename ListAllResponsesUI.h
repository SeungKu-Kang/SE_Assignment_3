/*
클래스 이름 : ListAllResponsesUI
기능 : 응답한 설문 조회 유스케이스의 파일 출력을 처리하는 바운더리 클래스
*/
#ifndef LIST_ALL_RESPONSES_UI_H
#define LIST_ALL_RESPONSES_UI_H

#include <fstream>
#include "ListAllResponses.h"

class ListAllResponsesUI
{
private:
	ListAllResponses* pControl; // 응답 조회 컨트롤 포인터
	std::ofstream& out_fp;     // 출력 파일 스트림 참조

public:
	ListAllResponsesUI(ListAllResponses* p_control, std::ofstream& out); // 생성자 선언

	void listAllReponses(); // 모든 응답 정보를 파일에 출력
};

#endif
