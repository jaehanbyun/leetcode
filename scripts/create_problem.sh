#!/bin/bash

# 사용법: ./scripts/create_problem.sh "문제번호.문제이름 난이도"
# 예시: ./scripts/create_problem.sh "3475.Fruits Into Baskets II easy"

# 입력된 인자가 없는 경우 사용법을 출력하고 종료합니다.
if [ -z "$1" ]; then
  echo "사용법: $0 \"<문제번호>.<문제이름> <난이도>\""
  echo "예시: $0 \"3475.Fruits Into Baskets II easy\""
  exit 1
fi

INPUT_STRING="$1"

# 난이도 추출 (마지막 단어)
DIFFICULTY=$(echo "$INPUT_STRING" | awk '{print $NF}')
# 난이도를 소문자로 변환하여 디렉토리 경로에 사용
DIFFICULTY_LOWER=$(echo "$DIFFICULTY" | tr '[:upper:]' '[:lower:]')

# 문제 번호 추출 (첫 번째 '.' 이전)
PROBLEM_NUMBER=$(echo "$INPUT_STRING" | cut -d'.' -f1)

# 문제 이름 추출 ('.'과 난이도 사이)
# 먼저 난이도와 그 앞의 공백을 제거합니다.
TEMP_NAME=${INPUT_STRING%" $DIFFICULTY"}
# 그 다음 문제 번호와 뒤의 '.'을 제거합니다.
PROBLEM_NAME=${TEMP_NAME#"$PROBLEM_NUMBER."}
# 앞뒤 공백을 제거합니다.
PROBLEM_NAME=$(echo "$PROBLEM_NAME" | xargs)

# 파일 이름 생성 (공백을 '_'로 변경)
FILE_NAME="${PROBLEM_NUMBER}_$(echo "$PROBLEM_NAME" | tr ' ' '_').cpp"

# 해당 난이도 디렉토리가 없으면 생성합니다.
if [ ! -d "$DIFFICULTY_LOWER" ]; then
    echo "디렉토리 생성: ${DIFFICULTY_LOWER}/"
    mkdir -p "$DIFFICULTY_LOWER"
fi

FILE_PATH="${DIFFICULTY_LOWER}/${FILE_NAME}"

# 파일이 이미 존재하는지 확인합니다.
if [ -f "$FILE_PATH" ]; then
    echo "오류: 파일이 이미 존재합니다: ${FILE_PATH}"
    exit 1
fi

# 파일을 생성합니다.
echo "파일 생성: ${FILE_PATH}"
touch "${FILE_PATH}"

echo "파일이 성공적으로 생성되었습니다!" 