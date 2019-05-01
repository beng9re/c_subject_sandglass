//
//  main.c
//  subject
//
//  Created by 김병희 on 27/04/2019.
//  Copyright © 2019 김병희. All rights reserved.
//

#include <stdio.h>

int const STRING_MAX_SIZE=999;               //입력 문자의 제한크기 상수
int const A_UP_ASCII_CODE=(int)'A';          //A의 아스키값이 담긴 상수
int const A_DOWN_ASCII_CODE=(int)'a';        //a의 아스키값이 담긴 상수
int const Z_UP_ASCII_CODE=(int)'Z';          //Z의 아스키값이 담긴 상수
int const Z_DOWN_ASCII_CODE=(int)'z';        //z의 아스키값이 담긴 상수
int const EXIT_FLAG=0;                       // 종료 플레그
int const LIMIT_NUM=10;                      // 제한값 : 이 프로그램에서는 10이 제한값
int const LOWER_NUM=5;                       // 최소값 : 이 프로그램에서는 5가 제한값

void clearBuffer(void);                     //입력 버퍼를 지우는 함수
int charSize(char a[]);                     /* 문자열 배열의 사이즈를 구하는 함수*/
char autoCharUpOrDown(char msg);            /* 알파벳 대소문자 자동 변환 함수 */
void swapArray(char input[],int size);      /* 문자열을 순서를 바꿔주는 함수 */
void drawSandglass(int num);

void change_kbh(void);                      /* 1번 문항 함수  입력받은 문자열이 대문자이면 소문자로, 소문자이면 대문자로 변환 후 입력의 역순으로 출력하는 함수*/
void draw_kbh(void);                        /* 배열의 크기를 입력 받아 아래와 같이 출력하는 함수  */
                                            /*   1            13 */
                                            /*   2  6     10  14 */
                                            /*   3  7  9  11  15 */
                                            /*   4  8     12  16 */
                                            /*   5            17 */




int main(int argc, const char * argv[]) {
    
    change_kbh(); //1번 함수 호출
    draw_kbh();   //2번 함수 호출
    return 0;
}


void clearBuffer(){
    //입력 버퍼를 지우는 함수
    while (getchar() != '\n');
}

/* 문자열 배열의 사이즈를 구하는 함수*/
int charSize(char a[]){
    for(int i = 0; i<STRING_MAX_SIZE;i++){
        if(a[i] == '\0'){
            return  i;
        }
    }
    return 0;
}
/* 알파벳 대소문자 자동 변환 함수
 대소문자끼리의 아스키 코드값의 차는 32 차이;
 */
char autoCharUpOrDown(char msg){
    int ascii=(int)msg; //입력 받은 문자열을 아스키 코드로 변환
    if(ascii >= A_DOWN_ASCII_CODE && ascii <= Z_DOWN_ASCII_CODE){   //a ~ z 인 경우 아스키코드값 32만큼 빼줌
        ascii-=32;
    }
    else if(ascii >= A_UP_ASCII_CODE && ascii <= Z_UP_ASCII_CODE){ //A ~ Z 인 경우 아스키코드값 32을 더해줌
        ascii+=32;
    }
    return (char)ascii; //아무것도 아닌경우는 보존
}
/*
 문자열을 순서를 바꿔주는 함수
 */
void swapArray(char input[],int size){
    char temp;      //문자열 임시저장 변수
    int index=size-1;   //바꾼 인덱스
    for (int i=0;i<size/2;i++) {    //절반만 바꾸면 됨
        temp = input[i];            //임시저장
        input[i] = input[index];    // 앞부분과 뒷부분을 변경해줌
        input[index--]=temp;        // 뒷부분을 앞부분으로 변경후 바꾼인덱스를 증가시켜줌
    }
}

/*   1            13 */
/*   2  6     10  14 */
/*   3  7  9  11  15 */
/*   4  8     12  16 */
/*   5            17  그리는 함수*/
void drawSandglass(int num){
    int index = 1;  //배열의 숫자의 값
    int sandArray[num][num];    //그려줄 배열 선언
    
    for (int row = 0; row < num; row++){    //2차원 배열 0으로 초기화
        for(int cal = 0; cal<num; cal++) {
            sandArray[row][cal] = 0;
        }
     }
    
    for (int row = 0; row < num; row++){
        if(row<=num/2){                                 //가운대 열을 기준으로 왼쪽인지 오른쪽인지 판단
            for(int cal = row; cal<num - row; cal++) {  //왼쪽 열일 경우 행의 값을 찍어줌 찍어주는 범위는 2씩 줄어들고 시작점은 하나씩 줄어듬
                sandArray[row][cal] = index++;
            }
        }else{
            for(int cal = num-row-1; cal<=row; cal++) { //오른쪽 열일 경우 행의 값을 찍어줌 찍어주는 범위는 2씩늘어나고 시작점은 하나씩 늘어남
                sandArray[row][cal] = index++;
            }
        }
    }
    
    //최종 결과를 찍어주는 반복문
    for (int i = 0; i < num; i++) {
        for (int j =0 ; j<num; j++) {
            if(sandArray[j][i] != 0){
                printf("%d\t",sandArray[j][i]);     //값이 0이 아닌경우 숫자 출력
            }else{
                printf(" \t");                      //값이 0인 인경우 공백 문자 출력
            }
            
        }
        printf("\n");
    }
}

/*
 정의
 입력받은 문자열이 대문자이면 소문자로, 소문자이면 대문자로 변환 후 입력의 역순으로 출력하는 함수
 입력 : School   출력 : LOOHCs
 */
void change_kbh(){
    char inputString[STRING_MAX_SIZE];  //문자열 길이를 제한크기 만큼 사용
    char temp;
    int size;                           //입력 문자열 길이
    int index=0;
    printf("문자열을 대소문자를 구분하여 입력 : ");
    scanf("%[^\n]",&inputString);   //입력 개행 엔터할때까지 문자 읽기
    clearBuffer();                  // 버퍼 지우기
    size=charSize(inputString);     //문자열 사이즈 저장
    
    printf("----------------------------------------\n");
    printf("변환된 결과 출력==> ");
    swapArray(inputString,size);    //문자열 뒤집는 함수
    for (int i =0;i<size; i++) {
        inputString[i]=autoCharUpOrDown(inputString[i]);    //대소문자 변경 함수 호출하여 대소문자 변경
    }
    printf("%s\n",inputString);     //최종 문자열 출력
    printf("========================================\n");
}


/* 배열의 크기를 입력 받아 아래와 같이 출력하는 함수  */
/*   1            13 */
/*   2  6     10  14 */
/*   3  7  9  11  15 */
/*   4  8     12  16 */
/*   5            17 */
/* 제약조건 : 1. 5부터 10값이 아닐경우 TO-DO 출력
            2. 홀수가 아닐경우      TO-DO 출력
            3. 0일 경우 프로그램    종료
 
 */

void draw_kbh(){
    int num;
    printf("5부터 10사이의 홀수 숫자를 입력하시오\n (0을 입력시 프로그램 종료 \n");
    printf(" 숫자 입력 : ");
    scanf("%d",&num);
    clearBuffer();
    
    
    while (1) {
        if(num==EXIT_FLAG){     //0 일경우 출력후 프로그램 종료
            printf("-----------------------------\n");
            printf("♥프로그램을 종료합니다. 이름 : 김병희 \n");
            printf("-----------------------------\n");
            return;               // 함수 끝
        }else if(num < LOWER_NUM || num > LIMIT_NUM){     //5~10의 값이 아닐경우 제한
            printf("--------------------------------------------- \n");
            printf(" ☆ 5부터 10 사이의 홀수를 입력하시오. 학과 : 컴퓨터과학과 \n");
            printf("--------------------------------------------- \n");
        }else if (num%2==0){                            // 짝수 일경우 제한
            printf("--------------------------------------------------\n");
            printf("★ 홀수를 입력하시오. 이름 : 김병희 학번: 201734 - 357847  \n ");
            printf("-------------------------------------------------\n");
        }else{
            drawSandglass(num);         //모래시계 그리는 함수
        }
        printf(" 숫자 입력 : ");
        scanf("%d",&num);
        clearBuffer();
        
    
    }
}
