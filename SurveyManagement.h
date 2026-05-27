/*
클래스 이름 : SurveyManagement
기능 : 파일 입출력을 관리하고 메뉴를 파싱하여 각 유스케이스의 컨트롤/바운더리 객체를 생성하는 클래스
*/
#ifndef SURVEY_MANAGEMENT_H
#define SURVEY_MANAGEMENT_H

#include <fstream>
#include "SurveyCollection.h"
#include "AddSurveyUI.h"
#include "AddSurvey.h"
#include "AddResponseUI.h"
#include "AddResponse.h"
#include "ListAllResponsesUI.h"
#include "ListAllResponses.h"
#include "Constants.h"

class SurveyManagement
{
private:
	std::ifstream in_fp;                     // 입력 파일 스트림
	std::ofstream out_fp;                    // 출력 파일 스트림
	SurveyCollection* pSurveycollection;     // 시스템 전체에서 사용되는 Survey 컬렉션 포인터

public:
	SurveyManagement();  // 생성자 선언
	~SurveyManagement(); // 소멸자 선언

	void doTask();        // 메뉴 파싱 및 유스케이스 수행
	void program_exit();  // 종료 결과를 파일에 쓰기
};

#endif
