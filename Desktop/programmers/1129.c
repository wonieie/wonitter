#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int reporting[1001][1001];
int reported[1001];



// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(id_list_len, sizeof(int)); //할당받아서 바아로 0넣어버리기~
    char copy[21];
    char *chart;
    char *report_chart;

    // for(int i=0; i<id_list_len; i++)
    // {
    //     strcpy(reported, id_list[i]);
    //     printf("%d", reported);
    // }
    for (int i=0; i< report_len; i++)
    {
        strcpy(copy, report[i]); // 문자열 복사해서 쓰래서 복사해서 씀.!
        chart = strtok(copy, " "); // 문자열 기준으로 나누는 함수가 있을거같아서 검색해보니 strtok이 뜸.
        
        // printf("%s\n\n", chart);
        for(int j=0; j<id_list_len; j++)
        {
            if (strcmp(chart, id_list[j]) == 0)
            {
                report_chart = strtok(NULL, " ");
                for(int k=0; k<id_list_len; k++)
                {
                    if (strcmp(report_chart, id_list[k])==0)
                    {
                        if (reporting[j][k] == 0)
                        {
                            reporting[j][k] = 1;
                            reported[k] += 1;
                        }
            
                    }
                    
                    
                }
                // printf("%s", report_chart);
            }
            
        }
    }
        for (int i=0; i<id_list_len; i++)
        {
            if (reported[i]>=k)
            {
                for(int j=0; j< reported[i]; j++)
                {
                    answer[reported[i][j]]++;
                }
            }
        }
        // for (int j=0; j< id_list_len; j++)
        // {
        //     printf("%s", "nunu");
        //     if (strcmp(chart, id_list[j]) == 0)
        //     {
        //         chart = strtok(NULL, " ");
        //         printf("%s", chart);
        //     }
        // }
            // for(int k=0; k< id_list_len; k++)
            // {
            //     // if(strcmp(chart, id_list[]))

            
            //     if (strcmp(chart, id_list[k]==0))
            //     {
            //         chart = strtok(NULL, " ");
            //         printf("%s\n", chart);
            //         if (reporting[j][i] == 0)
            //         {
            //             reporting[j][i] = 1;
            //             reported[i] += 1;
            //         }     
            //     }
            // }
        
    
    return answer;
}

int main()
{
    const char* id_list[] = {"muzi", "frodo", "apeach", "neo"};
    const char* report[] = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;
    int* answer = solution(id_list, 4, report, 5, k);
    for(int i = 0; i<4; ++i){
       printf("%d ", answer[i]);
    }
    printf("\n");
    const char* id_list2[] = {"con", "ryan"};
    const char* report2[] = {"ryan con", "ryan con", "ryan con", "ryan con"};
    int k2 = 3;
    int* answer2 = solution(id_list2, 2, report2, 4, k2);
    for(int i = 0; i<2; ++i){
        printf("%d ", answer2[i]);
    }
    printf("\n");
    return 0;
}