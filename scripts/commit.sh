#!/bin/bash

# 인터랙티브 커밋 스크립트
# 사용법: ./scripts/commit.sh

# 1. 변경된 파일 감지 (easy/, medium/, hard/ 디렉토리)
CHANGED_FILES=$(git status --porcelain -- easy/ medium/ hard/ 2>/dev/null | awk '{print $NF}')

if [ -z "$CHANGED_FILES" ]; then
    echo "오류: easy/, medium/, hard/ 디렉토리에 변경된 파일이 없습니다."
    exit 1
fi

# 2. 파일 선택 (하나면 자동 선택, 여러 개면 fzf)
FILE_COUNT=$(echo "$CHANGED_FILES" | wc -l | tr -d ' ')

if [ "$FILE_COUNT" -eq 1 ]; then
    FILE_PATH="$CHANGED_FILES"
    echo "변경된 파일: ${FILE_PATH}"
else
    echo "변경된 파일이 ${FILE_COUNT}개 있습니다."
    if command -v fzf &>/dev/null; then
        FILE_PATH=$(echo "$CHANGED_FILES" | fzf --prompt="커밋할 파일 선택: " --height=10 --reverse)
    else
        echo "커밋할 파일을 선택하세요:"
        select FILE_PATH in $CHANGED_FILES; do
            [ -n "$FILE_PATH" ] && break
        done
    fi
fi

if [ -z "$FILE_PATH" ]; then
    echo "오류: 파일을 선택해주세요."
    exit 1
fi

# 3. 파일 경로에서 정보 자동 추출
DIFFICULTY=$(echo "$FILE_PATH" | cut -d'/' -f1)
FILE_BASE=$(basename "$FILE_PATH")
EXT="${FILE_BASE##*.}"

# 확장자 제거한 파일명에서 번호와 이름 추출
NAME_PART="${FILE_BASE%.*}"
PROBLEM_NUMBER=$(echo "$NAME_PART" | cut -d'_' -f1)
PROBLEM_NAME=$(echo "$NAME_PART" | cut -d'_' -f2- | tr '_' ' ')

# 난이도 첫 글자 대문자
DIFFICULTY_CAPITALIZED="$(tr '[:lower:]' '[:upper:]' <<< ${DIFFICULTY:0:1})${DIFFICULTY:1}"

# 언어 태그 대문자
LANGUAGE_TAG=$(echo "$EXT" | tr '[:lower:]' '[:upper:]')

# 4. 커밋 메시지 생성 및 확인
COMMIT_MESSAGE="solve #${PROBLEM_NUMBER} ${PROBLEM_NAME} (${DIFFICULTY_CAPITALIZED}) [${LANGUAGE_TAG}]"

echo ""
echo "커밋 메시지: \"${COMMIT_MESSAGE}\""
read -p "진행하시겠습니까? (Y/n): " CONFIRM
CONFIRM=${CONFIRM:-Y}

if [[ ! "$CONFIRM" =~ ^[Yy]$ ]]; then
    echo "취소되었습니다."
    exit 0
fi

# 5. git add, commit, push
git add "${FILE_PATH}"
git commit -m "${COMMIT_MESSAGE}"
echo "커밋이 성공적으로 완료되었습니다!"
git push
