@echo off
setlocal EnableDelayedExpansion

set "MSVC_BIN=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86"
set "MSVC_INC=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\include"
set "MSVC_LIB=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\lib\x86"

set "SDK_ROOT=C:\Program Files (x86)\Windows Kits\10"

for /f "delims=" %%v in ('dir /b /ad "%SDK_ROOT%\include" 2^>nul') do set "SDK_VER=%%v"

set "PATH=%MSVC_BIN%;%PATH%"
set "INCLUDE=%MSVC_INC%;%SDK_ROOT%\include\%SDK_VER%\ucrt;%SDK_ROOT%\include\%SDK_VER%\um;%SDK_ROOT%\include\%SDK_VER%\shared"
set "LIB=%MSVC_LIB%;%SDK_ROOT%\lib\%SDK_VER%\ucrt\x86;%SDK_ROOT%\lib\%SDK_VER%\um\x86"

cd /d "%~dp0"

echo Compiling...
cl /EHsc /W3 /D_CRT_SECURE_NO_WARNINGS /Fe:survey_test.exe main.cpp SurveyManagement.cpp SurveyCollection.cpp Survey.cpp ResponseCollection.cpp Response.cpp AddSurvey.cpp AddSurveyUI.cpp AddResponse.cpp AddResponseUI.cpp ListAllResponses.cpp ListAllResponsesUI.cpp

if %ERRORLEVEL% == 0 (
    echo.
    echo === Build OK ===
    copy "C:\Users\user\Desktop\SE\Assignment3\과제 요구사항 명세서\input.txt" input.txt 1>nul
    survey_test.exe
    echo.
    echo === output.txt ===
    type output.txt
) else (
    echo.
    echo === Build FAILED ===
)
endlocal
