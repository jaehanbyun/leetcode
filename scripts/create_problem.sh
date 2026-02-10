#!/bin/bash

# 인터랙티브 문제 파일 생성 스크립트
# 사용법: ./scripts/create_problem.sh

# 1. 문제 입력
read -p "문제를 입력하세요 (예: 3719. Longest Balanced Subarray I): " INPUT

if [ -z "$INPUT" ]; then
  echo "오류: 문제를 입력해주세요."
  exit 1
fi

# 2. 난이도 선택 (fzf 동적 UI, fallback: select)
if command -v fzf &>/dev/null; then
  DIFFICULTY=$(printf "easy\nmedium\nhard" | fzf --prompt="난이도 선택: " --height=5 --reverse)
else
  echo "난이도를 선택하세요:"
  select DIFFICULTY in easy medium hard; do
    [ -n "$DIFFICULTY" ] && break
    echo "1, 2, 3 중 선택해주세요."
  done
fi

if [ -z "$DIFFICULTY" ]; then
  echo "오류: 난이도를 선택해주세요."
  exit 1
fi

# 3. 언어 선택 (fzf 동적 UI, fallback: select)
if command -v fzf &>/dev/null; then
  LANGUAGE=$(printf "cpp\npython\nsql\ngo" | fzf --prompt="언어 선택: " --height=6 --reverse)
else
  echo "언어를 선택하세요:"
  select LANGUAGE in cpp python sql go; do
    [ -n "$LANGUAGE" ] && break
    echo "1, 2, 3, 4 중 선택해주세요."
  done
fi

if [ -z "$LANGUAGE" ]; then
  echo "오류: 언어를 선택해주세요."
  exit 1
fi

# 언어에 따른 확장자 매핑
case "$LANGUAGE" in
  cpp)    EXT="cpp" ;;
  python) EXT="py" ;;
  sql)    EXT="sql" ;;
  go)     EXT="go" ;;
esac

# 4. 파싱
PROBLEM_NUMBER=$(echo "$INPUT" | cut -d'.' -f1)
PROBLEM_NAME=$(echo "$INPUT" | sed 's/^[0-9]*\.[[:space:]]*//')

# 파일 이름 생성 (공백을 '_'로 변경)
FILE_NAME="${PROBLEM_NUMBER}_$(echo "$PROBLEM_NAME" | tr ' ' '_').${EXT}"

# 해당 난이도 디렉토리가 없으면 생성합니다.
if [ ! -d "$DIFFICULTY" ]; then
    echo "디렉토리 생성: ${DIFFICULTY}/"
    mkdir -p "$DIFFICULTY"
fi

FILE_PATH="${DIFFICULTY}/${FILE_NAME}"

# 파일이 이미 존재하는지 확인합니다.
if [ -f "$FILE_PATH" ]; then
    echo "오류: 파일이 이미 존재합니다: ${FILE_PATH}"
    exit 1
fi

# 파일을 생성합니다.
echo "파일 생성: ${FILE_PATH}"
touch "${FILE_PATH}"

echo "파일이 성공적으로 생성되었습니다!"
