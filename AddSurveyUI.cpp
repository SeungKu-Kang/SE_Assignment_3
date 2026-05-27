#include "AddSurveyUI.h"

using namespace std;

/*
함수 이름 : AddSurveyUI
기능 : AddSurveyUI 생성자로서 컨트롤 포인터와 파일 스트림 참조를 저장한다.
매개변수 : AddSurvey* p_control -> 설문 등록 컨트롤 포인터
           ifstream& in         -> 입력 파일 스트림
           ofstream& out        -> 출력 파일 스트림
반환값 : 없음
*/
AddSurveyUI::AddSurveyUI(AddSurvey* p_control, ifstream& in, ofstream& out)
	: pControl(p_control), in_fp(in), out_fp(out)
{
}

/*
함수 이름 : createNewSurvey
기능 : 파일에서 설문 정보를 읽고 등록을 요청한 후 결과를 파일에 쓴다.
매개변수 : 없음
반환값 : 없음
*/
void AddSurveyUI::createNewSurvey()
{
	char topic[MAX_STRING];
	int item_count;

	in_fp >> topic >> item_count; // 입력 형식: [설문주제] [항목수]

	pControl->addNewSurvey(topic, item_count); // 1.1: addNewSurvey()

	out_fp << "1. 설문 등록" << endl;
	out_fp << "> " << topic << " " << item_count << endl;
	out_fp << endl;
}
