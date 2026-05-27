#include "Response.h"

/*
함수 이름 : Response
기능 : Response 클래스의 생성자로서 응답 항목 번호를 초기화한다.
매개변수 : int num -> 응답 항목 번호
반환값 : 없음
*/
Response::Response(int num)
	: item_num(num)
{
}

/*
함수 이름 : getResponseInfo
기능 : 응답 항목 번호를 반환한다.
매개변수 : 없음
반환값 : int -> 응답 항목 번호
*/
int Response::getResponseInfo()
{
	return item_num;
}
