#include "AddResponseUI.h"

using namespace std;

/*
함수 이름 : AddResponseUI
기능 : AddResponseUI 생성자로서 컨트롤 포인터와 파일 스트림 참조를 저장한다.
매개변수 : AddResponse* p_control -> 설문 응답 컨트롤 포인터
           ifstream& in           -> 입력 파일 스트림
           ofstream& out          -> 출력 파일 스트림
반환값 : 없음
*/
AddResponseUI::AddResponseUI(AddResponse* p_control, ifstream& in, ofstream& out)
	: pControl(p_control), in_fp(in), out_fp(out)
{
}

/*
함수 이름 : createNewResponse
기능 : 파일에서 응답 정보를 읽고 등록을 요청한 후 결과를 파일에 쓴다.
매개변수 : 없음
반환값 : 없음
*/
void AddResponseUI::createNewResponse()
{
	char topic[MAX_STRING];
	int item_num;

	in_fp >> topic >> item_num; // 입력 형식: [설문주제] [응답항목번호]

	pControl->addNewResponse(topic, item_num); // 1.1: addNewResponse()

	out_fp << "2. 설문 응답" << endl;
	out_fp << "> " << topic << " " << item_num << endl;
	out_fp << endl;
}
