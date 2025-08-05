#!/bin/bash

# 사용법: ./scripts/commit.sh "문제번호.문제이름 난이도"
# 예시: ./scripts/commit.sh "3477.Fruits Into Baskets II easy"

# 입력된 인자가 없는 경우 사용법을 출력하고 종료합니다.
if [ -z "$1" ]; then
  echo "사용법: $0 \"<문제번호>.<문제이름> <난이도>\""
  echo "예시: $0 \"3477.Fruits Into Baskets II easy\""
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
FILE_NAME_BASE="${PROBLEM_NUMBER}_$(echo "$PROBLEM_NAME" | tr ' ' '_').py"
FILE_PATH="${DIFFICULTY_LOWER}/${FILE_NAME_BASE}"

# 난이도의 첫 글자를 대문자로 변경합니다.
DIFFICULTY_CAPITALIZED="$(tr '[:lower:]' '[:upper:]' <<< ${DIFFICULTY:0:1})${DIFFICULTY:1}"

# 커밋 메시지를 생성합니다.
COMMIT_MESSAGE="solve #${PROBLEM_NUMBER} ${PROBLEM_NAME} (${DIFFICULTY_CAPITALIZED}) [Python]"

# 해당 파일이 존재하는지 확인합니다.
if [ ! -f "$FILE_PATH" ]; then
    echo "오류: 다음 경로에 파일이 없습니다: ${FILE_PATH}"
    # 다른 난이도 디렉토리에서 파일을 찾아봅니다.
    FOUND_PATH=$(find easy medium hard -name "${FILE_NAME_BASE}" 2>/dev/null | head -n 1)
    if [ -n "$FOUND_PATH" ]; then
        echo "일치하는 파일을 다음 경로에서 찾았습니다: ${FOUND_PATH}"
        FILE_PATH=$FOUND_PATH
    else
        echo "easy/, medium/, hard/ 디렉토리에서 '${FILE_NAME_BASE}' 패턴과 일치하는 파일을 찾을 수 없습니다."
        exit 1
    fi
fi


# 파일을 git에 추가하고 커밋합니다.
echo "파일 추가: ${FILE_PATH}"
git add "${FILE_PATH}"

echo "커밋 메시지: \"${COMMIT_MESSAGE}\""
git commit -m "${COMMIT_MESSAGE}"

echo "커밋이 성공적으로 완료되었습니다!"

