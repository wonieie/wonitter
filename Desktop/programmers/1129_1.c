#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int reporting[1001][1001];
int reported[1001];
char  *chart;
char  *report_chart;

int compare_index(const char *charts, const char* id_list[], size_t id_list_len)
{
    for (int i=0; i<id_list_len; i++)
    {
        if (strcmp(charts, id_list[i])==0)
            return i;
    }
    return 0;
}

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) 
{
    int* answer = (int*)calloc(id_list_len, sizeof(int)); //할당받아서 바아로 0넣어버리기~
    char copy[21];
    int a, b;

    for (int i=0; i< report_len; i++)
    {
        strcpy(copy, report[i]); // 문자열 복사해서 쓰래서 복사해서 씀.!
        chart = strtok(copy, " "); // 문자열 기준으로 나누는 함수가 있을거같아서 검색해보니 strtok이 뜸.
        report_chart = strtok(NULL, " ");
        a = compare_index(chart, id_list, id_list_len);
        b = compare_index(report_chart, id_list, id_list_len);

        if (a==b)
            continue;
        if (reporting[a][b] == 0)
        {
            reporting[a][b] = 1;
            reported[b]++;
        }
        // printf("%s\n\n", chart);
        // for(int j=0; j<id_list_len; j++)
        // {
        //     if (strcmp(chart, id_list[j]) == 0)
        //     {
        //         report_chart = strtok(NULL, " ");
        //         for(int k=0; k<id_list_len; k++)
        //         {
        //             if (strcmp(report_chart, id_list[k])==0)
        //             {
        //                 if (reporting[j][k] == 0)
        //                 {
        //                     reporting[j][k] = 1;
        //                     reported[k] += 1;
        //                 }
            
        //             }
                    
                    
        //         }
        //         // printf("%s", report_chart);
        //     }
            
        // }
    }
        for (int i=0; i<id_list_len; i++)
        {
            // if (reported[i]>=k)
            // {
                for(int j=0; j< id_list_len; j++)
                {
                    if (reporting[i][j] == 1 && reported[j] >= k)
                        answer[i]++;
                }
            // }
        }

        
    
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