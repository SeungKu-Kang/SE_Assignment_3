/*
클래스 이름 : AddResponseUI
기능 : 설문 응답 유스케이스의 파일 입출력을 처리하는 바운더리 클래스
*/
#ifndef ADD_RESPONSE_UI_H
#define ADD_RESPONSE_UI_H

#include <fstream>
#include "AddResponse.h"
#include "Constants.h"

class AddResponseUI
{
private:
	AddResponse* pControl;  // 설문 응답 컨트롤 포인터
	std::ifstream& in_fp;   // 입력 파일 스트림 참조
	std::ofstream& out_fp;  // 출력 파일 스트림 참조

public:
	AddResponseUI(AddResponse* p_control, std::ifstream& in, std::ofstream& out); // 생성자 선언

	void createNewResponse(); // 파일에서 응답 정보 읽어 등록 요청 후 결과 출력
};

#endif
