/*********************************
*主题:学生选修课程系统设计 
* 
*设计要求： 
*1.添加功能：程序能够任意添加课程和学生记录，可提供选择界面供用户选择所需要添加的类别，要求编号要唯一，如果添加了重复编号的记录是，则提示数据添加重复并取消添加。 
*2.查询功能：可根据编号、姓名等信息对已添加的同学和课程记录进行查询，如果未找到，给出相应的提示信息，如果找到，则显示相应的记录信息。 
*3.显示功能：可显示当前系统中所有学生和课程的记录，每条记录占据一行。 
*4.编辑功能：可根据查询结果对相应的记录进行修改，修改时注意编号的唯一性。 
*5.删除功能：主要实现对已添加的学生和课程记录进行删除。如果当前系统中没有对应的记录，则提示“记录为空！”并返回操作。 
*6.统计功能：能根据多种参数进行统计。能统计学生人数、课程门数、选修某门课程的学生的相关信息。 
*
*********************************/
/* 
*	Verson：2.0（basic） 
*	
*	History: 完成课程信息的录入，查询等操作；完成选课功能(2017-05-05 20:30:00-01:20:00) 
*
*	Author：王壮 
*
*
*********************************/
/* 
*	Verson：1.9
*	
*	History:完成了学生信息的查询操作 (2017-05-04 22:00:32-01:11:00) 
*
*	Author：王壮 
*
*
********************************/
/* 
*	Verson：1.5
*	
*	HIstory2:添加查重功能 （2017-05-02 23:39:19-01:06:05） 
*	History1:完成了用户对课程和学生信息的添加操作（没有查重功能）（2017-05-02 22:06:13-23:39:19） 
*
*	Author：王壮 
*
*
********************************/
/* 
*	Verson：1.0 
*
*	History:完成了用户的选择功能框架（2017-04-19 22:06:13-22:40:47） 
*
*	Author：王壮 
*
*
********************************/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STU 10
#define SIZE_COU 10
#define SIZE_SEL 10
//////////////函数声明部分 
void home(void);
void stu_operate(void);
void cou_operate(void);
void statistic(void);
void choose(void);
void delete_sel(int);
//--学生信息部分： 
void input_stu(void);
void search_stu(void);
void search_stu_id(void);
void search_stu_name(void);
void show_stu(void);
void edit_stu(void);
void renew_stu(void); 
void delete_stu(void);
//--课程信息部分： 
void input_cou(void);
void search_cou(void);
void search_cou_id(void);
void search_cou_name(void);
void show_cou(void);
void edit_cou(void);
void renew_cou(void); 
void delete_cou(void);

/*学生信息结构体*/
struct student_info {
	char stu_ID[9];
	char stu_name[5];
	char sex[9];
	char age[9];
	char collage[9];
	char grade[9];
	char contact[9];
}stu[SIZE_STU];

/*课程信息结构体*/
struct course_info {
	char course_ID[9];
	char course_name[9];
	char property[9];
	char period[9];
	char credit[9];
	char time[9];
	int people;
}cou[SIZE_COU];

/*选课记录结构体*/
struct select {
	int s;//存放学生信息的数组下标 
	int c;//存放课程信息的数组下标 
}sel[SIZE_SEL]; 

//全局变量i,j,x分别是学生,课程,选课信息数组下标
int i = -1;
int j = -1;
int x = -1;

int main(void){
	//进入欢迎界面 
	home();
	return 0;
}

//欢迎界面 
void home(void) {
	printf("\n-------------------------欢迎进入选课系统！----------------------"); 
	int h;
	printf("\n\n                        请选择你要进行的操作：");
	printf("\n\n                             1.学生操作");
	printf("\n                             2.课程操作");
	printf("\n                             3.开始选课");
	printf("\n                             4.选课统计");
	printf("\n                             5.退出系统");
	printf("\n                                                      ");
	printf("\n                        请输入：");
	scanf("%d",&h);
	system("cls");
	switch(h){
		case 1:
			stu_operate();
			break;
		case 2:
			cou_operate(); 
			break;
		case 3:
			choose();
			break;
		case 4:
			statistic();
			break;
		default:
			system("cls");
			printf("BYE!");
			break;
	}
}
/*开始选课*/
void choose(void){
	char stu_id[10],cou_id[10];
	printf("\n-------------------------欢迎进入选课系统！----------------------"); 
	//输入选课学生信息 
	printf("\n\n                 请输入选课人学号：");
	fflush(stdin);
	scanf("%s",stu_id);
	int h,flag = 0;
	for(h = 0;h <= i;h++){
		if(strcmp(stu[h].stu_ID,stu_id)==0){
			flag = 0;
			break;
		} else {
			flag = 1;
		}
	}
	if(flag||i==-1){
		printf("\n                 不存在此学号\n");
		system("pause");
		system("cls");
		home();
	}
	//录入姓名信息 
	x++;
	sel[x].s = h; 
	//输入课程信息 
	printf("\n\n                 请输入选修课程号：");
	fflush(stdin);
	scanf("%s",cou_id);
	flag = 0;
	for(h = 0;h <= j;h++){
		if(strcmp(cou[h].course_ID,cou_id)==0){
			flag = 0;
			break;
		} else {
			flag = 1;
		}
	}
	if(flag||j==-1){
		printf("\n                 不存在此课程号\n");
		x--;
		system("pause");
		system("cls");
		home();
	}
	//录入课程信息
	sel[x].c = h;
	cou[h].people++; 
	printf("\n                 录入成功!\n");
	system("pause");
	system("cls");
	home();
}
/*删除选课记录*/
void delete_sel(int q){//删除第q+1条记录 
/*注意！本函数没有将x减1，请在函数外手动减1（考虑外层函数循环的需要）*/	
	int h;
	cou[sel[q].c].people--;
	for(h = q;q < x;h++){
		q++;
		sel[h].c = sel[q].c;
		sel[h].s = sel[q].s;
	}
	
}
//对学生记录进行操作
void stu_operate(void) {
	printf("\n-------------------------欢迎进入选课系统！----------------------"); 
	printf("\n\n                 请选择你要对学生记录进行的操作：");
	printf("\n\n                             1.添加");
	printf("\n                             2.查询");
	printf("\n                             3.显示");
	printf("\n                             4.返回主页面");
	printf("\n                                                      ");
	printf("\n                        请输入：");
	int i;
	scanf("%d",&i);
	system("cls");
	switch(i){
		case 1://添加学生信息 
			input_stu();
			break;
		case 2://查询学生信息 
			search_stu(); 
			break;
		case 3://显示所有学生信息
			show_stu(); 
			break;
		case 4:
			home();
			break; 
	}
}
//对课程记录进行操作 
void cou_operate(void) {
	printf("\n-------------------------欢迎进入选课系统！----------------------"); 
	printf("\n\n                 请选择你要对课程记录进行的操作：");
	printf("\n\n                             1.添加");
	printf("\n                             2.查询");
	printf("\n                             3.显示");
	printf("\n                             4.返回主页面");
	printf("\n                                                      ");
	printf("\n                        请输入：");
	int i;
	scanf("%d",&i);
	system("cls");
	switch(i){
		case 1:
			input_cou();
			break;
		case 2:
			search_cou();
			break;
		case 3:
			show_cou();
		case 4:
			home();
			break; 
	}
}
//选课信息统计记录
void statistic(void){
	printf("\n-------------------------欢迎进入选课系统！----------------------"); 
	printf("\n\n                     共有学生信息：%d 条",i+1); 
	printf("\n                     共有课程信息：%d 条",j+1);
	if(x == -1){
		printf("\n                       选课记录：0 条");
		printf("\n\n                     "); 
		system("pause");
		system("cls");
		home();
	} else {
		printf("\n\n                        选课记录 %d 条：",x+1);
		int m;
		for(m = 0;m <= x;m++){
			printf("\n                     ================");
			printf("\n                     第%d条",m+1);
			printf("\n                     学生学号：%s",stu[sel[m].s].stu_ID);
			printf("\n                     学生姓名：%s",stu[sel[m].s].stu_name);
			printf("\n                     课程号：%s",cou[sel[m].c].course_ID);
			printf("\n                     课程名：%s",cou[sel[m].c].course_name); 
		}
		printf("\n\n            "); 
		system("pause");
		system("cls");
		home();
	}
	
}


//--------------------------------------学生信息插入--------------------------------------
void input_stu(void){
	char flag;
	FILE * fp;
	//--判断文件是否为空 
	fp = fopen("student.txt","r+");
	flag = fgetc(fp);
	if(flag==EOF){
		fprintf(fp,"学号\t姓名\t性别\t年龄\t系别\t班级\t联系方式\n");
	}
	fclose(fp);
	//-- 
	fp = fopen("student.txt","a+");
	if(fp == NULL){
		printf("打开文件失败！");
		system("cls");
		stu_operate();
	}
	printf("学号\t姓名\t性别\t年龄\t系别\t班级\t联系方式\n");
	while(1){
		i++;
		scanf("%s %s %s %s %s %s %s",&stu[i].stu_ID,&stu[i].stu_name,&stu[i].sex,&stu[i].age,&stu[i].collage,&stu[i].grade,&stu[i].contact);
		//--数据查重
		int h; 
		for(h = 0;h < i;h++){
			if(i == 0) break;//第一条数据不需要查重 
			if (strcmp(stu[h].stu_ID,stu[i].stu_ID)==0) {
				printf("该学号已存在，请重新输入！\n");
				scanf("\n%s %s %s %s %s %s %s",&stu[i].stu_ID,&stu[i].stu_name,&stu[i].sex,&stu[i].age,&stu[i].collage,&stu[i].grade,&stu[i].contact);
				h = -1;
			}
		}
		//-- 
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",stu[i].stu_ID,stu[i].stu_name,stu[i].sex,stu[i].age,stu[i].collage,stu[i].grade,stu[i].contact);
		printf("\n录入成功，继续录入输入y，返回上一级请按任意键：");
		fflush(stdin); 
		scanf("%c",&flag); 
		fclose(fp);
		if(flag!='y'&&'Y') break;
		fp = fopen("student.txt","a");
	}
	renew_stu();
	system("cls");
	stu_operate();
} 
/*查询学生信息*/
void search_stu(void){
	system("cls");
	printf("\n请选择查询方式：");
	printf("\n  1.学号查询");
	printf("\n  2.姓名查询");
	printf("\n请选择：");
	int h;
	scanf(" %d",&h);
	switch(h){
		case 1:
			search_stu_id();
			break;
		case 2:
			search_stu_name();
			break;
			
	} 
}
/*学号查询*/
void search_stu_id(void){
	system("cls");
	char id[9];
	printf("\n输入学生的学号:");
	fflush(stdin); 
	scanf("%s",id);
	int h;
	for(h = 0;h <= i;h++){
		if(strcmp(stu[h].stu_ID,id)==0){
			system("cls");
			printf("查找成功!"); 
			printf("\n\n\t学号\t姓名\t性别\t年龄\t系别\t班级\t联系方式");
			printf("\n\t-----------------------------------------------------------------"); 
			printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex,stu[h].age,stu[h].collage,stu[h].grade,stu[h].contact);
			system("pause");
			system("cls");
			stu_operate();
		}
	}
	system("cls");
	printf("没有此学号！\n");
	system("pause");
	system("cls");
	stu_operate();
} 
/*姓名查询*/
void search_stu_name(void){
	system("cls");
	char name[9];
	printf("\n输入学生的姓名:");
	fflush(stdin); 
	scanf("%s",name);
	int h;
	for(h = 0;h <= i;h++){
		if(strcmp(stu[h].stu_name,name)==0){
			system("cls");
			printf("查找成功!"); 
			printf("\n\n\t学号\t姓名\t性别\t年龄\t系别\t班级\t联系方式");
			printf("\n\t---------------------------------------------------------"); 
			printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex,stu[h].age,stu[h].collage,stu[h].grade,stu[h].contact);
			system("pause");
			system("cls");
			stu_operate();
		}
	}
	system("cls");
	printf("没有此姓名！");
	system("pause");
	system("cls");
	stu_operate();
} 
/*显示所有学生信息*/
void show_stu(void){
	int h;
	if(i == -1){
		printf("\n还没有录入信息！\n");
		system("pause");
		system("cls");
		stu_operate();
	}
	system("cls");
	printf("\n\n\t学号\t姓名\t性别\t年龄\t系别\t班级\t联系方式");
	printf("\n\t---------------------------------------------------------"); 
	for(h = 0;h <= i;h++){
		printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex,stu[h].age,stu[h].collage,stu[h].grade,stu[h].contact);
	}
	//
	fflush(stdin);
	printf("\n\t1.修改");
	printf("\n\t2.删除"); 
	printf("\n\t3.返回");
	printf("\n\n  选择要进行的操作：");
	int flag;
	fflush(stdin);
	scanf("%d",&flag);
	switch(flag){
		case 1:
			edit_stu();
			break; 
		case 2:
			delete_stu();
			break;
		default:
			system("cls");
			stu_operate();
			break;
			
	} 
}
/*编辑学生信息*/
void edit_stu(void){
	printf("\n输入需要编辑的学生的学号：");
	char id[10];
	getchar();
	scanf("%s",id);
	int h;
	for(h = 0;h <= i;h++){
		if(strcmp(stu[h].stu_ID,id)==0){//找到需要编辑的行 
			system("cls");
			printf("\n\n\t学号\t姓名\t性别\t年龄\t系别\t班级\t联系方式");
			printf("\n\t---------------------------------------------------------"); 
			printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex,stu[h].age,stu[h].collage,stu[h].grade,stu[h].contact);
			printf("\n这是修改前的数据，请依次输入修改值：\n\t");
			fflush(stdin);
			scanf("%s %s %s %s %s %s %s",&stu[h].stu_ID,&stu[h].stu_name,&stu[h].sex,&stu[h].age,&stu[h].collage,&stu[h].grade,&stu[h].contact);
			int k;
			for(k = 0;k <= i;k++){
				if(strcmp(stu[k].stu_ID,stu[h].stu_ID)==0){
					if(k==h){
						continue;
					} else {//学号不唯一 
						printf("\n此学号已存在！重新输入学号：");
						fflush(stdin);
						scanf("%s",&stu[h].stu_ID);
						k = -1;
					}
				}
			}
			/*将修改信息写入文件*/
			//思想：将原文件重新写入一遍
			renew_stu();
			system("cls");
			printf("修改成功！\n");
			system("pause"); 
			system("cls");
			stu_operate();
		}
	}
	printf("\n此学号不存在！\n");
	system("pause");
	system("cls");
	stu_operate();
}
/*删除学生信息*/
void delete_stu(void){
	printf("\n输入需要编辑的学生的学号：");
	char id[10];
	getchar();
	scanf("%s",id);
	int h;
	for(h = 0;h <= i;h++){
		if(strcmp(stu[h].stu_ID,id)==0){//找到需要编辑的行 
			system("cls");
			//检查他/她是否选课了
			int a;
			for(a = 0;a <= x;a++){
				if(h==sel[a].s){//选课了则将对应课程记录减1,以及选课数组减1 
					delete_sel(a);
					a = -1;
					x--;
					continue;
				}
			} 
			//如果只有一条记录
			if(i==0){
				i = -1;
				renew_stu();
				printf("修改成功！\n");
				system("pause"); 
				system("cls");
				stu_operate();
			} 
			
			int k;
			for(k = h+1;k <= i;k++,h++){//将数组直接向前移动 
				strcpy(stu[h].stu_ID,stu[k].stu_ID); 
				strcpy(stu[h].stu_name,stu[k].stu_name); 
				strcpy(stu[h].sex,stu[k].sex); 
				strcpy(stu[h].grade,stu[k].grade); 
				strcpy(stu[h].contact,stu[k].contact); 
				strcpy(stu[h].collage,stu[k].collage); 
				strcpy(stu[h].age,stu[k].age); 
			}
			/*将修改信息写入文件*/
			//思想：将原文件重新写入一遍
			renew_stu();
			i--;
			system("cls");
			printf("修改成功！\n");
			system("pause"); 
			system("cls");
			stu_operate();
		}
	}
	printf("\n此学号不存在！\n");
	system("pause");
	system("cls");
	stu_operate();
}
//--------------------------------------课程信息插入--------------------------------------
void input_cou(void){
	char flag;
	FILE * fp;
	//--判断文件是否为空 
	fp = fopen("course.txt","r+");
	flag = fgetc(fp);
	if(flag==EOF){
		fprintf(fp,"代码\t名称\t性质\t总学时\t学分\t开课学期\t选修人数\n");
	}
	fclose(fp);
	//-- 
	fp = fopen("course.txt","a+");
	if(fp == NULL){
		printf("打开文件失败！");
		system("cls");
		cou_operate();
	}
	printf("代码\t名称\t性质\t总学时\t学分\t开课学期\n");
	while(1){
		j++;
		scanf("%s %s %s %s %s %s",&cou[j].course_ID,&cou[j].course_name,&cou[j].property,&cou[j].period,&cou[j].credit,&cou[j].time);
		//--数据查重
		int h; 
		for(h = 0;h < j;h++){
			if(j == 0) break;//第一条数据不需要查重 
			if (strcmp(cou[h].course_ID,cou[j].course_ID)==0) {
				printf("该课程号已存在，请重新输入！\n");
				scanf("\n%s %s %s %s %s %s",&cou[j].course_ID,&cou[j].course_name,&cou[j].property,&cou[j].period,&cou[j].credit,&cou[j].time);
				h = -1;
			}
		}
		//-- 
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t\t%d\n",cou[j].course_ID,cou[j].course_name,cou[j].property,cou[j].period,cou[j].credit,cou[j].time,cou[j].people);
		printf("\n录入成功，继续录入输入y，返回上一级请按任意键：");
		fflush(stdin); 
		scanf("%c",&flag); 
		fclose(fp);
		if(flag!='y'&&'Y') break;
		fp = fopen("course.txt","a");
	}
	renew_cou();
	system("cls");
	cou_operate();
} 
/*查询课程信息*/
void search_cou(void){
	system("cls");
	printf("\n请选择查询方式：");
	printf("\n  1.课程号查询");
	printf("\n  2.课程名查询");
	printf("\n请选择：");
	int h;
	scanf(" %d",&h);
	switch(h){
		case 1:
			search_cou_id();
			break;
		case 2:
			search_cou_name();
			break;
			
	} 
}
/*课程号查询*/
void search_cou_id(void){
	system("cls");
	char id[9];
	printf("\n输入课程号:");
	fflush(stdin); 
	scanf("%s",id);
	int h;
	for(h = 0;h <= j;h++){
		if(strcmp(cou[h].course_ID,id)==0){
			system("cls");
			printf("查找成功!"); 
			printf("\n\n\t代码\t名称\t性质\t总学时\t学分\t开课学期\t选修人数");
			printf("\n\t-----------------------------------------------------------------"); 
			printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\t\t%d\n",cou[h].course_ID,cou[h].course_name,cou[h].property,cou[h].period,cou[h].credit,cou[h].time,cou[h].people);
			system("pause");
			system("cls");
			cou_operate();
		}
	}
	system("cls");
	printf("没有此课程号！\n");
	system("pause");
	system("cls");
	cou_operate();
} 
/*课程名查询*/
void search_cou_name(void){
	system("cls");
	char name[9];
	printf("\n输入课程名:");
	fflush(stdin); 
	scanf("%s",name);
	int h;
	for(h = 0;h <= j;h++){
		if(strcmp(cou[h].course_name,name)==0){
			system("cls");
			printf("查找成功!"); 
			printf("\n\n\t代码\t名称\t性质\t总学时\t学分\t开课学期\t选修人数");
			printf("\n\t---------------------------------------------------------"); 
			printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\t\t%d\n",cou[h].course_ID,cou[h].course_name,cou[h].property,cou[h].period,cou[h].credit,cou[h].time,cou[h].people);
			system("pause");
			system("cls");
			cou_operate();
		}
	}
	system("cls");
	printf("没有此课程名！");
	system("pause");
	system("cls");
	cou_operate();
} 
/*显示所有课程信息*/
void show_cou(void){
	int h;
	if(j == -1){
		printf("\n还没有录入信息！\n");
		system("pause");
		system("cls");
		cou_operate();
	}
	system("cls");
	printf("\n\n\t代码\t名称\t性质\t总学时\t学分\t开课学期\t选修人数");
	printf("\n\t-------------------------------------------------------------"); 
	for(h = 0;h <= j;h++){
		printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\t\t%d\n",cou[h].course_ID,cou[h].course_name,cou[h].property,cou[h].period,cou[h].credit,cou[h].time,cou[h].people);
	}
	//
	fflush(stdin);
	printf("\n\t1.修改");
	printf("\n\t2.删除"); 
	printf("\n\t3.返回");
	printf("\n\n  选择要进行的操作：");
	int flag;
	fflush(stdin);
	scanf("%d",&flag);
	switch(flag){
		case 1:
			edit_cou();
			break; 
		case 2:
			delete_cou();
			break;
		default:
			system("cls");
			cou_operate();
			break;
			
	} 
}
/*编辑课程信息*/
void edit_cou(void){
	printf("\n输入需要编辑的课程号：");
	char id[10];
	getchar();
	scanf("%s",id);
	int h;
	for(h = 0;h <= j;h++){
		if(strcmp(cou[h].course_ID,id)==0){//找到需要编辑的行 
			system("cls");
			printf("\n\n\t代码\t名称\t性质\t总学时\t学分\t开课学期");
			printf("\n\t-------------------------------------------------------------"); 
			printf("\n\t%s\t%s\t%s\t%s\t%s\t%s\n",cou[h].course_ID,cou[h].course_name,cou[h].property,cou[h].period,cou[h].credit,cou[h].time);
			printf("\n这是修改前的数据，请依次输入修改值：\n\t");
			fflush(stdin);
			scanf("%s %s %s %s %s %s",&cou[h].course_ID,&cou[h].course_name,&cou[h].property,&cou[h].period,&cou[h].credit,&cou[h].time);
			int k;
			for(k = 0;k <= j;k++){
				if(strcmp(cou[k].course_ID,cou[h].course_ID)==0){
					if(k==h){
						continue;
					} else {//课程号不唯一 
						printf("\n此课程号已存在，重新输入：");
						fflush(stdin);
						scanf("%s",&cou[h].course_ID);
						k = -1;
					}
				}
			}
			/*将修改信息写入文件*/
			//思想：将原文件重新写入一遍
			renew_cou();
			system("cls");
			printf("修改成功！\n");
			system("pause"); 
			system("cls");
			cou_operate();
		}
	}
	printf("\n此课程号不存在！\n");
	system("pause");
	system("cls");
	cou_operate();
}
/*删除课程信息*/
void delete_cou(void){
	printf("\n输入需要编辑的课程号：");
	char id[10];
	getchar();
	scanf("%s",id);
	int h;
	for(h = 0;h <= j;h++){
		if(strcmp(cou[h].course_ID,id)==0){//找到需要编辑的行 
			system("cls");
			//如果只有一条记录
			if(j==0){
				j = -1;
				renew_cou();
				printf("修改成功！\n");
				system("pause"); 
				system("cls");
				cou_operate();
			}
			//查看是否有人选课
			if(cou[h].people!=0){//有人选课时
				int a;
				for(a = 0;a <= x;a++){
					if(sel[a].c == h){
						delete_sel(a);
						a = -1;
						x--;
						continue;
					}
				}
			}
			int k;
			for(k = h+1;k <= j;k++,h++){//将数组直接向前移动 
				strcpy(cou[h].course_ID,cou[k].course_ID); 
				strcpy(cou[h].course_name,cou[k].course_name); 
				strcpy(cou[h].property,cou[k].property); 
				strcpy(cou[h].period,cou[k].period); 
				strcpy(cou[h].credit,cou[k].credit); 
				strcpy(cou[h].time,cou[k].time); 
			}
			/*将修改信息写入文件*/
			//思想：将原文件重新写入一遍
			renew_cou();
			j--;
			system("cls");
			printf("修改成功！\n");
			system("pause"); 
			system("cls");
			cou_operate();
		}
	}
	printf("\n此课程号不存在！\n");
	system("pause");
	system("cls");
	cou_operate();
}

//--功能函数
/*更新系统数据至文件*/
void renew_stu(void){
	FILE * fp;
	fp = fopen("student.txt","w+");
	if(fp == NULL){
		printf("\n打开文件失败,无法保存至文件。\n");
		fclose(fp);
		return ;
	}
	fprintf(fp,"学号\t姓名\t性别\t年龄\t系别\t班级\t联系方式\n");
	if(i == -1){
		fclose(fp);
		return;
	}
	int h;
	for(h = 0;h <= i;h++){
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex,stu[h].age,stu[h].collage,stu[h].grade,stu[h].contact);
	}
	fclose(fp);
	
} 
void renew_cou(void){
	FILE * fp;
	fp = fopen("course.txt","w+");
	if(fp == NULL){
		printf("\n打开文件失败,无法保存至文件。\n");
		fclose(fp);
		return ;
	}
	fprintf(fp,"代码\t名称\t性质\t总学时\t学分\t开课学期\t选修人数\n");
	if(j == -1){
		fclose(fp);
		return;
	}
	int h;
	for(h = 0;h <= j;h++){
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t\t%s\n",cou[h].course_ID,cou[h].course_name,cou[h].property,cou[h].period,cou[h].credit,cou[h].time,cou[h].people);	}
	fclose(fp);
	
} 
