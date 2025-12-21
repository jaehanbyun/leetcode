#!/bin/bash

# 사용법: ./scripts/commit.sh "문제번호.문제이름 난이도" [언어]
# 예시: ./scripts/commit.sh "3477.Fruits Into Baskets II easy"
# 예시: ./scripts/commit.sh "3477.Fruits Into Baskets II easy" py
# 예시: ./scripts/commit.sh "1757. Recyclable and Low Fat Products easy" sql

# 입력된 인자가 없는 경우 사용법을 출력하고 종료합니다.
if [ -z "$1" ]; then
  echo "사용법: $0 \"<문제번호>.<문제이름> <난이도>\" [언어]"
  echo "예시: $0 \"3477.Fruits Into Baskets II easy\""
  echo "예시: $0 \"3477.Fruits Into Baskets II easy\" py"
  echo "예시: $0 \"1757. Recyclable and Low Fat Products easy\" sql"
  echo ""
  echo "지원 언어: cpp (기본값), py, sql, java, js, ts 등"
  exit 1
fi

INPUT_STRING="$1"

# 언어 설정 (두 번째 인자, 기본값: cpp)
LANGUAGE="${2:-cpp}"

# 언어에 따른 확장자 매핑
case "$LANGUAGE" in
  cpp) EXT="cpp" ;;
  py) EXT="py" ;;
  sql) EXT="sql" ;;
  java) EXT="java" ;;
  js) EXT="js" ;;
  ts) EXT="ts" ;;
  *) EXT="$LANGUAGE" ;;  # 기타 언어는 그대로 사용
esac

# 언어 태그를 대문자로 변환 (커밋 메시지용)
LANGUAGE_TAG=$(echo "$LANGUAGE" | tr '[:lower:]' '[:upper:]')

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
PROBLEM_NAME=$(echo "$PROBLEM_NAME" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')

# 파일 이름 생성 (공백을 '_'로 변경)
FILE_NAME_BASE="${PROBLEM_NUMBER}_$(echo "$PROBLEM_NAME" | tr ' ' '_').${EXT}"
FILE_PATH="${DIFFICULTY_LOWER}/${FILE_NAME_BASE}"

# 난이도의 첫 글자를 대문자로 변경합니다.
DIFFICULTY_CAPITALIZED="$(tr '[:lower:]' '[:upper:]' <<< ${DIFFICULTY:0:1})${DIFFICULTY:1}"

# 커밋 메시지를 생성합니다.
COMMIT_MESSAGE="solve #${PROBLEM_NUMBER} ${PROBLEM_NAME} (${DIFFICULTY_CAPITALIZED}) [${LANGUAGE_TAG}]"

# 해당 파일이 존재하는지 확인합니다.
if [ ! -f "$FILE_PATH" ]; then
    echo "오류: 다음 경로에 파일이 없습니다: ${FILE_PATH}"
    # 다른 난이도 디렉토리에서 파일을 찾아봅니다.
    FOUND_PATH=$(find easy medium hard -name "${FILE_NAME_BASE}" 2>/dev/null | head -n 1)
    if [ -n "$FOUND_PATH" ]; then
        echo "일치하는 파일을 다음 경로에서 찾았습니다: ${FOUND_PATH}"
        FILE_PATH=$FOUND_PATH
        # 찾은 파일의 확장자를 사용하여 언어 태그 업데이트
        FOUND_EXT="${FOUND_PATH##*.}"
        case "$FOUND_EXT" in
          cpp) LANGUAGE_TAG="CPP" ;;
          py) LANGUAGE_TAG="PY" ;;
          sql) LANGUAGE_TAG="SQL" ;;
          java) LANGUAGE_TAG="JAVA" ;;
          js) LANGUAGE_TAG="JS" ;;
          ts) LANGUAGE_TAG="TS" ;;
          *) LANGUAGE_TAG=$(echo "$FOUND_EXT" | tr '[:lower:]' '[:upper:]') ;;
        esac
        COMMIT_MESSAGE="solve #${PROBLEM_NUMBER} ${PROBLEM_NAME} (${DIFFICULTY_CAPITALIZED}) [${LANGUAGE_TAG}]"
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

git push
