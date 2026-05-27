#include "SurveyManagement.h"

using namespace std;

/*
함수 이름 : SurveyManagement
기능 : SurveyManagement 생성자로서 파일을 열고 SurveyCollection을 동적 생성한다.
매개변수 : 없음
반환값 : 없음
*/
SurveyManagement::SurveyManagement()
{
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);
	pSurveycollection = new SurveyCollection();
}

/*
함수 이름 : ~SurveyManagement
기능 : SurveyManagement 소멸자로서 파일을 닫고 SurveyCollection을 해제한다.
매개변수 : 없음
반환값 : 없음
*/
SurveyManagement::~SurveyManagement()
{
	if (in_fp.is_open())
	{
		in_fp.close();
	}

	if (out_fp.is_open())
	{
		out_fp.close();
	}

	if (pSurveycollection)
	{
		delete pSurveycollection;
		pSurveycollection = nullptr;
	}
}

/*
함수 이름 : doTask
기능 : 입력 파일에서 메뉴를 읽어 해당 유스케이스의 컨트롤/바운더리 객체를 생성하고 기능을 수행한다.
매개변수 : 없음
반환값 : 없음
*/
void SurveyManagement::doTask()
{
	int menu = 0;            // 메뉴 파싱을 위한 변수
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		in_fp >> menu; // 입력 파일에서 메뉴 숫자 1개를 읽기

		switch (menu)
		{
		case 1:
		{
			AddSurvey* p_control = new AddSurvey(pSurveycollection);
			AddSurveyUI* p_boundary = new AddSurveyUI(p_control, in_fp, out_fp);
			p_boundary->createNewSurvey();
			delete p_boundary;
			delete p_control;
			break;
		}
		case 2:
		{
			AddResponse* p_control = new AddResponse(pSurveycollection);
			AddResponseUI* p_boundary = new AddResponseUI(p_control, in_fp, out_fp);
			p_boundary->createNewResponse();
			delete p_boundary;
			delete p_control;
			break;
		}
		case 3:
		{
			ListAllResponses* p_control = new ListAllResponses(pSurveycollection);
			ListAllResponsesUI* p_boundary = new ListAllResponsesUI(p_control, out_fp);
			p_boundary->listAllReponses();
			delete p_boundary;
			delete p_control;
			break;
		}
		case 4:
			program_exit();
			is_program_exit = 1;
			break;
		default:
			break;
		}
	}
}

/*
함수 이름 : program_exit
기능 : 프로그램 종료 기능의 수행 결과를 파일에 쓴다.
매개변수 : 없음
반환값 : 없음
*/
void SurveyManagement::program_exit()
{
	out_fp << "4. 종료" << endl;
}
