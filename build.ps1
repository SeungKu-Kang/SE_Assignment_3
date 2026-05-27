# ── MSVC 환경 설정 ──────────────────────────────────
$msvcRoot = "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133"
$sdkRoot  = "C:\Program Files (x86)\Windows Kits\10"
$sdkVer   = (Get-ChildItem "$sdkRoot\include" | Sort-Object Name | Select-Object -Last 1).Name

$env:PATH    = "$msvcRoot\bin\Hostx86\x64;" + $env:PATH
$env:INCLUDE = "$msvcRoot\include;$sdkRoot\include\$sdkVer\ucrt;$sdkRoot\include\$sdkVer\um;$sdkRoot\include\$sdkVer\shared"
$env:LIB     = "$msvcRoot\lib\onecore\x64;$sdkRoot\lib\$sdkVer\ucrt\x64;$sdkRoot\lib\$sdkVer\um\x64"

# ── 소스 파일 목록 ────────────────────────────────────
$sources = @(
    "main.cpp",
    "SurveyManagement.cpp", "SurveyCollection.cpp",
    "Survey.cpp", "ResponseCollection.cpp", "Response.cpp",
    "AddSurvey.cpp",        "AddSurveyUI.cpp",
    "AddResponse.cpp",      "AddResponseUI.cpp",
    "ListAllResponses.cpp", "ListAllResponsesUI.cpp"
) -join " "

# ── 컴파일 ───────────────────────────────────────────
Write-Host "`n[1] 컴파일 중..." -ForegroundColor Cyan
$result = cmd /c "cl /EHsc /utf-8 /D_CRT_SECURE_NO_WARNINGS /Fe:survey_test.exe $sources 2>&1"

$hasError = $result | Where-Object { $_ -match "error C\d+" }
if ($hasError) {
    Write-Host "`n컴파일 실패:" -ForegroundColor Red
    $hasError
    exit 1
}
Write-Host "컴파일 성공!" -ForegroundColor Green

# ── 실행 ─────────────────────────────────────────────
Write-Host "`n[2] 실행 중..." -ForegroundColor Cyan
.\survey_test.exe

# ── 결과 출력 ─────────────────────────────────────────
Write-Host "`n[3] output.txt 내용:" -ForegroundColor Cyan
Write-Host "─────────────────────────"
Get-Content output.txt -Encoding UTF8
Write-Host "─────────────────────────"
Write-Host "완료. output.txt를 VSCode에서 열어 확인하세요." -ForegroundColor Yellow
