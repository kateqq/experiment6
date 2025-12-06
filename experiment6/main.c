#include <stdio.h>
#include <stdlib.h>

#define MAX_STU 100
#define MAX_JUD 20

typedef struct student
{
	int scores[MAX_JUD];
	int average; 
}STUDENT;

//计算平均分 去掉最高分和最低分 
float calculate_average(int scores[], int numofjud); 

int main(){
	STUDENT stu[MAX_STU]; 
	
	//读入学生、评委人数 
	int numofstu = 0;
	int numofjud = 0;
	scanf("%d %d", &numofstu, &numofjud);
	
	//读入分数 
	int i, j;
	for(i = 0; i < numofstu; i++){
		for(j = 0; j < numofjud; j++){
			scanf("%d", &stu[i].scores[j]);
		}
	} 
	
//	for(i = 0; i < numofstu; i++){
//		for(j = 0; j < numofjud; j++){
//			printf("stu[%d].scores[%d] = %d\n", i, j, stu[i].scores[j]);
//		}
//	}

	//查找得分最高的同学分数 
	float max_average = 0;
	for(i = 0; i < numofstu; i++){
		stu[i].average = calculate_average(stu[i].scores, numofjud);
//		printf("stu[i].average = %f\n", stu[i].average);
		if(stu[i].average > max_average){
			max_average = stu[i].average;
		}
	}
	
	printf("%.2f", max_average);
	return 0;
}

float calculate_average(int scores[], int numofjud){
	float average = 0;
	float sum = 0;
	int max = 0;
	int min = 0;
	int i;
	
	//找出最高分和最低分 
	for(i = 0; i < numofjud; i++){
		if(scores[max] < scores[i]){
			max = i;
		}
		if(scores[min] > scores[i]){
			min = i;
		}
	}
	
	//计算平均分
	//讨论最大值等于最小值的特殊情况 
	if(max == min){
		average = scores[max];
	}else{
		for(i = 0; i < numofjud; i++){
			if(i != max && i != min){
				sum += scores[i];	 
//				printf("sum[%d] = %f\n", i, sum); 
			}
			average = sum / (numofjud - 2);
		} 
	}
		
	return average;
}
