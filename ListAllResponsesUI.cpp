#include "ListAllResponsesUI.h"

using namespace std;

/*
함수 이름 : ListAllResponsesUI
기능 : ListAllResponsesUI 생성자로서 컨트롤 포인터와 출력 파일 스트림 참조를 저장한다.
매개변수 : ListAllResponses* p_control -> 응답 조회 컨트롤 포인터
           ofstream& out              -> 출력 파일 스트림
반환값 : 없음
*/
ListAllResponsesUI::ListAllResponsesUI(ListAllResponses* p_control, ofstream& out)
	: pControl(p_control), out_fp(out)
{
}

/*
함수 이름 : listAllReponses
기능 : 컨트롤에서 모든 응답 정보를 수집하여 파일에 출력한다.
매개변수 : 없음
반환값 : 없음
*/
void ListAllResponsesUI::listAllReponses()
{
	pControl->getAllResponses(); // 1.1: getAllResponses()

	out_fp << "3. 응답한 설문 조회" << endl;

	for (int i = 0; i < pControl->getTotalCount(); i++)
	{
		out_fp << "> " << pControl->getResponseTopic(i)
			   << " " << pControl->getResponseItemNum(i) << endl;
	}

	out_fp << endl;
}
