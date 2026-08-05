#include <iostream>
#include <cstdio>
#include <cassert>

int main()
{
	//문자열 쓰기.
	float framerate = 120.0f;
	int width = 30;
	int height = 20;

	// 위의 변수를 포맷 지정해서 문자열로 만들기
	// 포맷 : 키(변수) =  값;
	const int length = 256;
	char string[length] = {};

	sprintf_s(string,
		length,
		"framerate = %f\nwidth = %d\nheight = %d\n"
		, framerate, width, height
	);
	
	FILE* configFile = nullptr;
	fopen_s(&configFile, "Setting.txt", "wt");
	if (!configFile)
	{
		return 1;
	}
	fwrite(string, sizeof(char), strlen(string), configFile);

	fclose(configFile);
	configFile = nullptr;

	
	// 파일 입출력을 위한 변수
	FILE* file = nullptr;



	//파일 열기
	auto result = fopen_s(&file, "Test.txt", "rb");
	
	//파일 제대로 열었는지 확인
	if (!file)
	{
		std::cout << "파일 열기 실패\n";
		return 1;
	}
	
	//파일 열기 성공
	std::cout << "파일 열기 성공\n";
	
	//파일에 쓰기  
	const char* message = "C 라이브러리로 기록한 텍스트\n";

	//if (fputs(message, file) == EOF)
	//{
	//	std::cout << "파일에 쓰기 실패\n";
	//	fclose(file);
	//	return 1;
	//} 
	//std::cout << "파일에 쓰기 성공\n";

	//파일에서 읽기
	//읽어온 데이터를 저장할 버퍼
	const int size = 256;
	char buffer[size] = {};
	size_t readSize = fread(buffer, sizeof(char), size, file);

	//복사할 파일 생성 (쓰기모드로 열기).
	FILE* copyFile = nullptr;
	errno_t errorCode = fopen_s(&copyFile, "Test2.txt", "wb");
	if (!copyFile)
	{
		return 1;
	}

	//쓰기
	size_t writtenSize = fwrite(buffer, sizeof(char), readSize, copyFile);

	//결과 확인.
	assert(readSize == writtenSize);



	std::cout << buffer << '\n';
	


	
	//파일 닫기
	fclose(file);
	file = nullptr;
	fclose(copyFile);
	copyFile = nullptr;
}