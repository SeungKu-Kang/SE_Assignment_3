/*
클래스 이름 : AddSurveyUI
기능 : 설문 등록 유스케이스의 파일 입출력을 처리하는 바운더리 클래스
*/
#ifndef ADD_SURVEY_UI_H
#define ADD_SURVEY_UI_H

#include <fstream>
#include "AddSurvey.h"
#include "Constants.h"

class AddSurveyUI
{
private:
	AddSurvey* pControl;    // 설문 등록 컨트롤 포인터
	std::ifstream& in_fp;   // 입력 파일 스트림 참조
	std::ofstream& out_fp;  // 출력 파일 스트림 참조

public:
	AddSurveyUI(AddSurvey* p_control, std::ifstream& in, std::ofstream& out); // 생성자 선언

	void createNewSurvey(); // 파일에서 설문 정보 읽어 등록 요청 후 결과 출력
};

#endif
