#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N 400
int nummax=0;
int numstore[N];
char memo[N][9][20];
int sign=0;
char thekey[15];
struct students
{
    char num[13];
    char clas[3];
    char name[16];
    char sex[9];
    char year[5];
    char month[3];
    char day[3];
    char ID[19];
    char score[4];

}stu;
//子函数部分
//主函数菜单函数部分
void MainInterface();            //开始界面
void RepCryp();                  //密码修改与管理员模式
void MainMenu();                 //主功能菜单
void InfEdit();                  //编辑信息
void InfSearch();                //查询信息
void InfClear();
void InfStat();                  //统计信息
void InfIn();                    //添加信息
void InfAmend();                 //修改信息
void InfDelete();                //删除信息
void code();                     //管理员密码验证
void codeinput();                //密码输入
int itemsize();                  //检测结构体成员长度
int numcheck();                  //输入与检测整型数
void strcheck();                  //输入与检测字符串
void show();                     //查询界面提示
void clew();                     //结构体成员提示
void migrate();                  //删除文件中符合条件的信息
char *namedat();                 //返回扩展名为.dat的文件名
char *nametxt();                 //返回扩展名为.txt的文件名
void display();                  //查询信息中提取与分离信息并显示
void shuchu();
/*主函数*/
void main()
{
    jiemian();
    colors();
    MainInterface();
}
void jiemian()//系统总界面
{
	printf("☆************************☆*********************************☆**********************☆\n");
	printf("★************************★                                 ★**********************★\n");
	printf("☆************************☆        学生信息管理系统         ☆**********************☆\n");
	printf("★************************★                                 ★**********************★\n");
	printf("☆******◇************☆********************************************☆********◇******☆\n");
	printf("★*******                                                                   ********★\n");
	printf("☆*******                    设计团队信息简介:                              ********☆\n");
	printf("★*******                                                                   ********★\n");
	printf("☆*******                        学校: 山东科技大学                         ********☆\n");
	printf("★*******                                                                   ********★\n");
	printf("☆*******                        学院: 电子通信与物理学院                   ********☆\n");
	printf("★*******                                                                   ********★\n");
	printf("☆*******                        班级: 电科16-2                             ********☆\n");
	printf("★*******                                                                   ********★\n");
	printf("☆*******                        团队组成: 李  扬                           ********☆\n");
	printf("★*******                                  岳琦洪                           ********★\n");
	printf("☆*******                                  周君磊                           ********☆\n");
	printf("★*******                                                                   ********★\n");
        printf("☆******◇***************************************************************◇*******☆\n");
	printf("★**********************************************************************************★\n");
	printf("☆**********************************************************************************☆\n");
	printf("\n\n\t\t\t\t请按回车键继续...");
	fflush(stdin);                         //清空输入缓冲区，通常是为了确保不影响后面的数据读取
	getchar();
    system("cls");                             //清屏，但额外会耽误些时间
}


void colors()//颜色
{
         int choice;
         printf("\t  **********************************************************\n");
         printf("\t  $             选择你喜欢的界面色彩(背景/前景)            $\n");
		 printf("\t  **********************************************************\n");
	     printf("\n");
	     printf("\n");
		 printf("\t ╔*****☆***◎***◇****☆****★****☆****◇***◎***☆*****╗\n");
		 printf("\t  @╔***☆***◎***◇****☆****★****☆****◇***◎***☆***╗@\n");
	     printf("\t  @@@╔*☆***◎***◇****☆****★****☆****◇***◎***☆*╗@@@\n");
		 printf("\t  @@@@                                                  @@@@\n");
		 printf("\t  @@@@                                                  @@@@\n");
	     printf("\t  @@@@          ◎1、黑/红        ◎2、 白/黑           @@@@\n");
	     printf("\t  @@@@          ◎3、灰/蓝        ◎4、 灰/绿           @@@@\n");
         printf("\t  @@@@          ◎5、灰/红        ◎6、 灰/紫           @@@@\n");
	     printf("\t  @@@@          ◎7、灰/黄        ◎8、 白/蓝           @@@@\n");
		 printf("\t  @@@@          ◎9、白/黄        ◎10、白/紫           @@@@\n");
		 printf("\t  @@@@                                                  @@@@\n");
		 printf("\t  @@@@                                                  @@@@\n");
	     printf("\t  @@@╚*☆***◎***◇****☆****★****☆****◇***◎***☆*╝@@@\n");
		 printf("\t  @╚***☆***◎***◇****☆****★****☆****◇***◎***☆***╝@\n");
		 printf("\t ╚*****☆***◎***◇****☆****★****☆****◇***◎***☆*****╝\n");
		 printf("请输入您的选择:");
	     scanf("%d",&choice);
	     switch(choice)//背景 前景
		 {
		     case 1: system("color 04"); break;  //黑白
    	     case 2: system("color F0"); break;  //白黑
	         case 3: system("color 81"); break;  //灰蓝
     	 	 case 4: system("color 82"); break;  //灰绿
	    	 case 5: system("color 84"); break;  //灰红
        	 case 6: system("color 85"); break;  //灰紫
	         case 7: system("color 8E"); break;  //灰黄
			 case 8: system("color F3"); break;  //白蓝
			 case 9: system("color F6"); break;  //白黄
			 case 10: system("color F5"); break; //白紫
			 case 0:return;
			 default:break;
		 }
        printf("\n\n\t\t\t\t");
		system("pause");  //在命令行上输出一行类似于“Press   any   key   to   exit”的字，等待用户按一个键，然后返回。
	    system("cls");

}

//进入选择界面
void MainInterface()
{
    int select;
    char ch;
    while(1)
    {
        fflush(stdin);
        printf("\n\n\t                   学生的基本信息及成绩查询系统\n");
        printf("\t----------------------------------------------------------------------\n");
        printf("\n\t********************************************************************\n");
        printf("\t                    欢迎使用学生的基本信息及成绩查询软件\n");
        printf("\t             本软件用于对学生的基本信息及成绩查询进行统计整理\n");
        printf("\t                    您也可以对学生成绩进行查询和修改\n");
        printf("\t**********************************************************************\n");
        printf("\t======================================================================\n");
        printf("\t||        1 管理员               2 学生              0 退出      ||\n");
        printf("\t======================================================================\n");
        printf("\n\t 请选择登录方式:");
        select=numcheck();//输入与检测整型数
        switch(select)
        {
        case 1:
            code();//密码验证
            RepCryp();//密码验证后进入RepCryp函数
            break;
        case 2:
            system("cls");
            InfSearch();//普通用户查询信息
            system("cls");
            break;
        case 0:
            printf("\t请按任意键退出\n");
            exit(0);
        default:
            printf("\t对不起！没有您要的选项！\n\t退出程序：Esc   \n\t取消退出：按任意键\n");
            printf("%c",'\007');
            ch=getch();
            if(ch==27)
                exit(0);
            else
                system("cls");
        }
    }
}
/*进入管理员与密码修改模式*/
void RepCryp()
{
    int res,count1,select;
    char ch,code1[21],code2[21],ori[]="123";
    FILE *fp;
    while(1)
    {
        fflush(stdin);
        printf("\n\n\t                        欢迎登录本系统\n");
        printf("\t----------------------------------------------------------------------\n");
        printf("\t======================================================================\n");
        printf("\t||      1.使用系统功能                           2.修改密码          ||\n");
        printf("\t======================================================================\n");
        printf("\t======================================================================\n");
        printf("\t||           3.退出                              0 返回上层          ||\n");
        printf("\t======================================================================\n");
        printf("\n\t 请选择您的操作:");
        select=numcheck();//输入与检测整型数
        switch(select)
        {
        case 1:
            MainMenu();break;       //主功能菜单
        case 2:
            system("cls");
            printf("\n\n                            密码修改功能");
            printf("\n*******************************\n\n请输入您的新密码：");
            for(count1=1;;count1++)
            {
                codeinput(code1);
                printf("\n");
                printf("请再次输您的新密码：\n");
                codeinput(code2);
                printf("\n");
                res=strcmp(code1,code2);
                if(res==0)
                    {
                        fp=fopen("E:\\code.txt","w+");
                        fputs(code1,fp);
                        fclose(fp);
                        printf("密码修改成功！\n返回上一层：任意键\n退出程序【Esc】   \n");
                        ch=getch();
                        printf("\n");
                        if(ch==27)
                            exit(0);
                        system("cls");
                        break;
                    }
                    else
                    {
                        if(count1>=3)
                        {
                            printf("%c",'\007');
                            printf("对不起！您现在不能修改密码！\n退出程序【Esc】   \n返回上一层：任意键\n");
                            ch=getch();
                            printf("\n");
                            if(ch==27)
                                exit(0);
                            system("cls");
                            break;
                        }
                        else
                        {
                            printf("对不起！两次密码输入不一致\n\n请重新输入：\n");
                            printf("%c",'\007');
                        }
                    }
            }
            break;
        case 3:
            printf("请按任意键退出\n");
            exit(0);
        case 0:
            system("cls");
            break;
        default:
            system("cls");
            printf("%c",'\007');
            printf("对不起！没有您要的选项！\n请重新选择！\n");
        }
        if(select==0)
            break;
    }
}
/*主功能菜单*/
void MainMenu()
{
    int select;
    system("cls");
    while(1)
    {
        fflush(stdin);
        printf("\n\n                        主系统功能菜单\n");
        printf("\t----------------------------------------------------------------------\n");
        printf("\t======================================================================\n");
        printf("\t||     1 编辑信息            2 查询信息           3 输出信息        ||\n");
        printf("\t======================================================================\n");
        printf("\t======================================================================\n");
        printf("\t||     4 统计信息              5退出          0 返回上层             ||\n");
        printf("\t======================================================================\n");
        printf("\n\t 请选择您的操作:");
        select=numcheck();//输入与检测整型数
        system("cls");
        switch(select)
        {
            case 1:InfEdit();break;
            case 2:InfSearch();break;
            case 3:shuchu();break;//初始化
            case 4:InfStat();break;//统计信息
            case 5:printf("请按任意键结束程序\n");exit(0);
            case 0:break;
            default:
                printf("对不起！没有您要的选项！\n请重新选择！\n");
        }
        if(select==0)
            break;
        system("cls");
    }

}
/*编辑信息*/
void InfEdit()
{
    int select;
    system("cls");
    while(1)
    {
       fflush(stdin);
        printf("\n\n                        编辑信息功能菜单\n");
        printf("\t----------------------------------------------------------------------\n");
        printf("\t======================================================================\n");
        printf("\t||     1 添加信息                                  2 修改信息       ||\n");
        printf("\t======================================================================\n");
        printf("\t======================================================================\n");
        printf("\t||     3 删除信息                                  4 退出程序       ||\n");
        printf("\t======================================================================\n");
        printf("\t======================================================================\n");
        printf("\t||                         0 返回上一层                             ||\n");
        printf("\t======================================================================\n");
        printf("\n\t 请选择您的操作:");
        select=numcheck();//输入与检测整型数
        system("cls");
        switch(select)
        {
            case 1:InfIn();break;
            case 2:InfAmend();break;
            case 3:InfDelete();break;
            case 0:break;
            case 4:printf("请按任意键结束程序\n");exit(0);
            default:
                printf("对不起！没有您要的选项！\n请重新选择！\n");
        }
        if(select==0)
            break;
        system("cls");
    }
}
/*查询信息模式*/
void InfSearch()
{
    int select;
    char ch;
    while(1)
    {
        fflush(stdin);
        printf("\n\n                        查询信息功能菜单\n");
        show();
        printf("请输入您要查询用到的条件个数:");
        select=numcheck();//输入与检测整型数
        if(select>3||select<0)
        {
            system("cls");
            continue;
        }
        if(select==0)
            break;
        if(select==4)
            exit(0);
        nummax=0;display(select);//提取信息并按条件显示
        printf("\n返回上一层：任意键\n退出程序【Esc】   \n");
        ch=getch();
        if(ch==27)
                exit(0);
        system("cls");
    }
}

/*初始化信息模式*/
void InfClear()
{
    int select,temp[1];
    char ch;
    while(1)
    {
        printf("\n\n                                     初始化信息功能菜单\n");
        show();
        printf("请输入要初始化信息所用到的条件的个数:");
        select=numcheck();
        if(select>4||select<0)
        {
            printf("%c",'\007');
            system("cls");
            continue;
        }
        if(select==0)
        break;
        if(select==4)
        {
           printf("按任意键退出本程序\n");
           exit(0);
        }
        nummax=0;display(select);
        if(nummax==0)
        {
            printf("\n返回上级：任意键\n退出程序：【Esc】 \n");
            ch=getch();
            if(ch==27)
                exit(0);
            system("cls");
            continue;
        }
        fflush(stdin);
        printf("确认删除：【回车】，返回查询：【Esc】 \n");
        scanf("%c",&ch);
        if(ch==27)
            continue;
        temp[0]=numstore[0];
        migrate(nummax+1,numstore);
        fflush(stdin);
        migrate(1,temp);
        system("cls");
        printf("初始化信息成功！\n");
    }
}
/*统计信息模式*/
void InfStat()
{
    int j,k,m,n,select,i,sto[9],choice,max,choose;
    char ch,str[9][30],ret[N][2][10],temp[20],memo[N][9][20],t[N][9][20];
    while(1)
    {
        printf("\n\n                        统计信息功能菜单\n");
        show();
        printf("请输入您要统计用到的条件个数:");
        select=numcheck();
        if(select>4||select<0)
        {
            printf("%c",'\007');
            system("cls");
            continue;
        }
        if(select==0)
            break;
        if(select==4)
        {
            printf("请按任意键结束程序\n");
            exit(0);
        }
        nummax=0;
                    int i,cle[9],infcount=0,tcount=0,cont,num,sum=0;
                char insto[N][9][20],str[80],*p,*q;
                FILE *fp;
                fflush(stdin);
                printf("请输入您要查询的这%d个条件的序号：",select);
                for(i=0;i<select;i++)
                {
                    cle[i]=numcheck();
                    if(cle[i]<1||cle[i]>3)
                    {
                        printf("无此选项！请重新输入：");
                        i--;
                    }
                }
                printf("请输入：\n");
                for(i=0;i<select;i++)
                {
                    clew(cle[i]);
                    strcheck(insto[i],itemsize(cle[i]),1);
                }
                system("cls");
                printf("\n\n");
                printf("\t----------------------------------------------------------------------\n");
                printf("您要查询的");
                printf("的信息\n其搜索结果如下：\n\n");
                if(sign==0)
                    fp=fopen("E:\\memory.dat","r");
                else
                    fp=fopen(namedat(thekey,15),"r");
                thekey[15]='\0';
                nummax=0;
                printf("序号\t学号\t班级\t姓名\t年\t月\t日\t身份证\t性别\t分数\n");
                while(1)
                {

                    cont=0;
                    i=0;
                    fscanf(fp,"%s",str);//提取单挑信息
                    if(feof(fp)) break;
                    infcount++;//记录位置
                    q=str;
                    num=strlen(str);
                    str[num]=',';
                    str[num+1]=0;
                    p=strchr(str,',');
                    while(p!=NULL)
                    {
                        *p=0;
                        strcpy(memo[nummax][i++],q);
                        q=p+1;
                        p=strchr(q,',');
                    }
                    for(i=0;i<select;i++)
                    {
                        if(!strcmp(insto[i],memo[nummax][cle[i]-1]))
                            cont++;
                    }
                    if(cont!=select)
                        continue;
                    sum=sum+atoi(memo[nummax][8]);
                    tcount++;
                    numstore[nummax]=infcount;
                    printf(" %d",nummax+1);

                    for(i=0;i<9;i++)
                    {
                        switch(i)
                        {
                            case 0:printf("\t%s",memo[nummax][i]);break;
                            case 1:printf("\t%s",memo[nummax][i]);break;
                            case 2:printf("\t%s",memo[nummax][i]);break;
                            case 3:printf("\t%s",memo[nummax][i]);break;
                            case 4:printf("\t%s",memo[nummax][i]);break;
                            case 5:printf("\t%s",memo[nummax][i]);break;
                            case 6:printf("\t%s",memo[nummax][i]);break;
                            case 7:printf("\t%s",memo[nummax][i]);break;
                            case 8:printf("\t%s\n",memo[nummax][i]);break;
                        }
                    }
                    nummax++;
                }
                if(tcount==0)
                {
                    printf("对不起！您输入的无学生信息记录\n");
                }
                fclose(fp);
                printf("\n共搜索到%d个结果，占总数据的%f\n平均成绩%f。\n",nummax,(float)nummax/infcount,(float)sum/nummax);


        printf("1.按成绩排序\t2.按学号3.返回    \t0.退出\n");

        choose=numcheck();
        system("cls");
        switch(choose)
        {
            case 1:m=8;break;
            case 2:m=0;break;
            case 3:break;
            case 0:exit(0);

        }
                    printf("1.升序\t2.降序 3.返回    \t0.退出\n");
                    choice=numcheck();
                    switch(choice)
                    {
                        case 1:
                                for(i=0;i<nummax;i++)
                                {
                                    for(j=1;j<nummax-i;j++)
                                    {
                                       if(strcmp(memo[j-1][m],memo[j][m])>0)
                                       {
                                           memcpy(t[j-1],memo[j],180);
                                           memcpy(memo[j],memo[j-1],180);
                                           memcpy(memo[j-1],t[j-1],180);
                                       }
                                    }
                                }
                                for(k=0;k<nummax;k++)
                                {
                                            for(i=0;i<9;i++)
                                    {
                                        switch(i)
                                        {
                                            case 0:printf("\t%s",memo[k][i]);break;
                                            case 1:printf("\t%s",memo[k][i]);break;
                                            case 2:printf("\t%s",memo[k][i]);break;
                                            case 3:printf("\t%s",memo[k][i]);break;
                                            case 4:printf("\t%s",memo[k][i]);break;
                                            case 5:printf("\t%s",memo[k][i]);break;
                                            case 6:printf("\t%s",memo[k][i]);break;
                                            case 7:printf("\t%s",memo[k][i]);break;
                                            case 8:printf("\t%s\n",memo[k][i]);break;
                                        }
                                    }
                                }
                                break;
                                case 2:
                                        {
                                            for(i=0;i<nummax;i++)
                                            {
                                                for(j=1;j<nummax-i;j++)
                                                {
                                                        if(strcmp(memo[j-1][m],memo[j][m])<0)
                                                        {
                                                            memcpy(t[j-1],memo[j],180);
                                                            memcpy(memo[j],memo[j-1],180);
                                                            memcpy(memo[j-1],t[j-1],180);
                                                        }
                                                }
                                            }
                                            for(k=0;k<nummax;k++)
                                            {
                                                        for(i=0;i<10;i++)
                                                {
                                                    switch(i)
                                                    {
                                                        case 0:printf("\t%s",memo[k][i]);break;
                                                        case 1:printf("\t%s",memo[k][i]);break;
                                                        case 2:printf("\t%s",memo[k][i]);break;
                                                        case 3:printf("\t%s",memo[k][i]);break;
                                                        case 4:printf("\t%s",memo[k][i]);break;
                                                        case 5:printf("\t%s",memo[k][i]);break;
                                                        case 6:printf("\t%s",memo[k][i]);break;
                                                        case 7:printf("\t%s",memo[k][i]);break;
                                                        case 8:printf("\t%s\n",memo[k][i]);break;
                                                    }
                                                }
                                            }break;
                                            case 3:break;
                                            case 0:exit(0);
                                        }

            }

                                printf("1.返回    \t0.退出\n");
                                        choose=numcheck();
                                        switch(choose)
                                        {
                                            case 1:break;
                                            case 0:exit(0);
                                        }

        system("cls");

    }
}
/*子功能函数*/
/*添加信息模式*/
void InfIn()
{
    int i,j;
    char ch;
    FILE *fp;
    for(j=1;;j++)
    {
        if(sign==0)
            fp=fopen("E:\\memory.dat","a+");
        else
            fp=fopen(namedat(thekey,15),"a+");
        thekey[15]='\0';
        fflush(stdin);
        for(i=1;;i++)
        {
            system("cls");
             printf("\n\n                                         添加信息功能菜单\n");
            printf("------------------------------------------------------------------------------\n");
            printf("请输入学生的学号：");
            strcheck(stu.num,13,1,"00000000000","999999999999");
            printf("请输入出生年：");
            strcheck(stu.year,5,1,"1","9999");
            printf("请输入出生月：");
            strcheck(stu.month,3,1,"1","12");
            printf("请输入出生日：");
            strcheck(stu.day,3,1,"1","31");
            printf("请输入身份证号：");
            strcheck(stu.ID,19,1,"1","999999999999999999");
            printf("请输入分数：");
            strcheck(stu.score,4,1,"0","100");
            printf("请输入姓名：");
            strcheck(stu.name,16,1);
            printf("请输入性别：");
            strcheck(stu.sex,9,1);
            printf("请输入班级：");
            strcheck(stu.clas,20,1);
           fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",stu.num,stu.clas,stu.name,stu.year,stu.month,stu.day,stu.ID,stu.sex,stu.score);
            printf("\n继续输入：【回车】\n重输：【Esc】\n返回上级：【0】  \n");
            ch=getch();
            if(ch=='0')
                break;
            if(ch==27)
                break;
        }
        fclose(fp);
        system("cls");
        if(ch=='0')
            break;
    }
}

/*修改信息模式*/
void InfAmend()
{
    int select,tcount,str[N],ncount;
    char ch;
    while(1)
    {
        FILE *fp;
        printf("\n\n               修改信息功能菜单\n");
        show();
        printf("请输入您要修改用到的条件个数：");
        select=numcheck();
        if(select>4||select<0)
        {
            system("cls");
            continue;
        }
        if(select==0)
        break;
        if(select==4)
           exit(0);
        nummax=0;display(select);
        if(nummax==0)
        {
            printf("\n返回上级：任意键\n退出程序：【Esc】 \n");
            ch=getch();
            if(ch==27)
                exit(0);
            system("cls");
            continue;
        }
        printf("\n返回上级：【0】 \n继续操作：【回车】 \n");
        ch=getch();
        if(ch=='0')
            break;
        fp=fopen("E:\\store.dat","w+");
        for(tcount=0;tcount<nummax;tcount++)
        {
            printf("\n请输入对应的序号:");
            scanf("%d",&ncount);
            str[tcount]=numstore[ncount-1];
            printf("请输入学生的学号：");
            strcheck(stu.num,13,1,"000000000000","999999999999");
            printf("请输入出生年：");
            strcheck(stu.year,5,1,"1","9999");
            printf("请输入出生月：");
            strcheck(stu.month,3,1,"1","12");
            printf("请输入出生日：");
            strcheck(stu.day,3,1,"1","31");
            printf("请输入身份证号：");
            strcheck(stu.ID,19,1,"1","999999999999999999");
            printf("请输入分数：");
            strcheck(stu.score,4,1,"0","100");
            printf("请输入姓名：");
            strcheck(stu.name,16,1);
            printf("请输入性别：");
            strcheck(stu.sex,9,1);
            printf("请输入班级：");
            strcheck(stu.clas,20,1);
            fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",stu.num,stu.clas,stu.name,stu.year,stu.month,stu.day,stu.ID,stu.sex,stu.score);
            printf("\n修改成功！\n返回上级：【0】  \n继续操作：【回车】\n");
            ch=getch();
            if(ch=='0')
                break;
        }
        fclose(fp);
        migrate(tcount+1,str);
        system("cls");

    }
}
/*删除信息模式*/
void InfDelete()
{
    int select,tcount,str[N],ncount;
    char ch;
    while(1)
    {
        printf("\n\n               删除信息功能菜单\n");
        show();
        printf("请输入您删除用到的条件个数：");
        select=numcheck();
      if(select>4||select<0)
        {
            system("cls");
            continue;
        }
        if(select==0)
        break;
        if(select==4)
           exit(0);
        nummax=0;display(select);
        if(nummax==0)
        {
            printf("\n返回上级：任意键\n退出程序：【Esc】 \n");
            ch=getch();
            if(ch==27)
                exit(0);
            system("cls");
            continue;
        }
        printf("\n返回上级：【0】 \n继续操作：【回车】 \n");
        ch=getch();
        if(ch=='0')
            break;
        for(tcount=0;tcount<nummax;tcount++)
        {
            printf("\n请输入对应的序号：");
            ncount=numcheck();
            if(ncount==0)
            break;
            str[tcount]=numstore[ncount-1];
            printf("\n删除成功！\n返回上级：【0】  \n继续操作：【回车】\n");
            ch=getch();
            if(ch=='0')
                break;
        }
        migrate(tcount+1,str);
        system("cls");
     }
}
/*显示符合条件的信息*/
void display(int select)
{
    int i,cle[9],infcount=0,tcount=0,cont,num,sum=0;
    char insto[9][20],memo[9][20],str[80],*p,*q;
    FILE *fp;
    fflush(stdin);
    printf("请输入您要查询的这%d个条件的序号：",select);
    for(i=0;i<select;i++)
    {
        cle[i]=numcheck();
        if(cle[i]<1||cle[i]>3)
        {
            printf("无此选项！请重新输入：");
            i--;
        }
    }
    printf("请输入：\n");
    for(i=0;i<select;i++)
    {
        clew(cle[i]);
        strcheck(insto[i],itemsize(cle[i]),1);
    }
    system("cls");
    printf("\n\n");
    printf("\t----------------------------------------------------------------------\n");
    printf("您要查询的");
    printf("的信息\n其搜索结果如下：\n\n");
    if(sign==0)
        fp=fopen("E:\\memory.dat","r");
    else
        fp=fopen(namedat(thekey,15),"r");
    thekey[15]='\0';
    nummax=0;
    printf("序号\t学号\t班级\t姓名\t年\t月\t日\t身份证\t性别\t分数\n");
    while(1)
    {

        cont=0;
        i=0;
        fscanf(fp,"%s",str);//提取单挑信息
        if(feof(fp)) break;
        infcount++;//记录位置
        q=str;
        num=strlen(str);
        str[num]=',';
        str[num+1]=0;
        p=strchr(str,',');
        while(p!=NULL)
        {
            *p=0;
            strcpy(memo[i++],q);
            q=p+1;
            p=strchr(q,',');
        }
        for(i=0;i<select;i++)
        {
            if(!strcmp(insto[i],memo[cle[i]-1]))
                cont++;
        }
        if(cont!=select)
            continue;
        sum=sum+atoi(memo[7]);
        tcount++;
        numstore[nummax]=infcount;
        printf(" %d",nummax+1);
        nummax++;
        for(i=0;i<10;i++)
        {
            switch(i)
            {
                case 0:printf("\t%s",memo[i]);break;
                case 1:printf("\t%s",memo[i]);break;
                case 2:printf("\t%s",memo[i]);break;
                case 3:printf("\t%s",memo[i]);break;
                case 4:printf("\t%s",memo[i]);break;
                case 5:printf("\t%s",memo[i]);break;
                case 6:printf("\t%s",memo[i]);break;
                case 7:printf("\t%s",memo[i]);break;
                case 8:printf("\t%s\n",memo[i]);break;
            }
        }
    }
    if(tcount==0)
    {
        printf("对不起！您输入的无学生信息记录\n");
    }
    fclose(fp);
    printf("\n共搜索到%d个结果，占总数据的%f\n平均成绩%f。\n",nummax,(float)nummax/infcount,(float)sum/nummax);
}

/*按条件删除信息*/
void migrate(int nmax,int *memo)
{
    int tcount,ncount;
    char str[97];
    FILE *fp,*fpw;
    if(sign==0)
        fp=fopen("E:\\memory.dat","a+");
        else
            fp=fopen(namedat(thekey,15),"r");
        thekey[15]='\0';
        fpw=fopen("E:\\store.dat","a+");
        if(fpw==NULL)
            fpw=fopen("E:\\store.dat","w+");
        tcount=0;
        while(1)
        {
            fscanf(fp,"%s",str);
            if(feof(fp)) break;
            tcount++;
            for(ncount=0;ncount<nmax;ncount++)
            {
                if(tcount==memo[ncount])
                    break;
                if(ncount==nmax-1)
                    fprintf(fpw,"%s\n",str);
            }
        }
        fclose(fp);
        fclose(fpw);
        if(sign==1)
        {
            remove(namedat(thekey,9));
            thekey[15]='\0';
            rename("E:\\store.dat",namedat(thekey,9));
            thekey[15]='\0';
        }
        else
        {
            remove("E:\\memory.dat");
            rename("E:\\store.dat","E:\\memory.dat");
        }

}
/*返回一个扩展名为.txt的文件名*/
char* nametxt(char *str,int j)
{
    str[j]='.';
    str[++j]='t';
    str[++j]='x';
    str[++j]='t';
    str[++j]='\0';
    return str;

}
/*密码验证函数*/
void code()
{
    int i,res;
    char code[21],str[21],ori[]="123";
    FILE *fp;
    fp=fopen("E:\\code.txt","r");
    if(fp==NULL)
    {
        printf("\t你的初始密码为123，系统登录后请及时修改！\n");
        fp=fopen("E:\\code.txt","w+");
        fputs(ori,fp);
        rewind(fp);
    }
    fscanf(fp,"%s",code);
    fclose(fp);
    printf("\t请输入密码：");
    for(i=1;;i++)
    {
        codeinput(str);
        printf("\n");
        res=strcmp(str,code);
        if(res==0)
            break;
        else if(i==3)
        {
            printf("\t对不起！您不是本程序的合法用户！\n\t请按任意键结束\n");
            exit(0);
        }
        printf("\t密码输入错误！\n\t请重新输入密码：");
    }
    system("cls");
}
/*显示结构体成员*/
void clew(int select)
{
    switch(select)
    {
        case 1:printf("学号：");break;
        case 2:printf("班级：");break;
        case 3:printf("姓名：");break;
        case 4:printf("性别：");break;
        case 5:printf("年：");break;
        case 6:printf("月：");break;
        case 7:printf("日：");break;
        case 8:printf("身份证：");break;
        case 9:printf("分数：");break;
    }
}
/*输入结构体成员代号返回其长度*/
int itemsize(int number)
{
    switch(number)
    {
        case 1:return 12;
        case 2:return 16;
        case 3:return 9;
        case 4:return 5;
        case 5:return 3;
        case 6:return 3;
        case 7:return 19;
        case 8:return 20;
    }
    return -1;
}
/*输入满足条件的字符串*/
void strcheck(char *str,int len,int flag,char *strmin,char *strmax)
{
    int i;
    for(i=0;;i++)
    {
        scanf("%s",str);
        if(inspect(str,len,flag)==1)
        {
            if(flag==-1)
            {
                if(atoi(str)>=atoi(strmin)&&atoi(strmax)>=atoi(str))
                    break;
            }
            else
            {
                break;
            }
        }
        printf("输入在含有不被允许的字符或字符长度有误\n请重新输入！\n");
        printf("%c",'\007');
    }
}
/*验证字符串的长度及类型*/
int inspect(char *str,int len,int flag)
{
    int i;
    if(flag==1)
        return 1;
    for(i=0;i<len;i++)
    {
        if(str[i]=='\0')
            break;
        switch(flag)
        {
        case -1:
            if(str[i]>47&&str[i]<58)
                break;
            else
                return -1;
        case 0:
            if((str[i]>47&&str[i]<58)||(str[i]>64&&str[i]<91)||(str[i]>96&&str[i]<123))
               break;
               else
                return -1;
        default:
            return -1;
        }
    }
    if(i==len)
        return -1;
    return 1;
}
/*输入满足条件的整型数，并被返回*/
int numcheck()
{
    int i;
    char str[50];
    fflush(stdin);
    scanf("%s",str);
    for(i=0;i<50;i++)
    {
        switch(str[i])
        {
        case '\0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':break;
        default :
            return -1;
        }
        if(str[i]=='\0')
            break;
    }
    str[i]='\0';
    return atoi(str);
}
/*输入密码*/
void codeinput(char *str)
{
    int i;
    char ch;
    for(i=0;i<20;)
    {
        ch=getch();
        if(ch=='\r')
        {
            str[i]='\0';
            break;
        }
        else if(ch=='\b')
        {
            if(i>0)
            {
                printf("\b \b");
                i=i-1;
            }
        }
        else
        {
            printf("*");
            str[i]=ch;
            i=i+1;
        }
    }
}
/*查询信息选项提示*/
void show()
{
        printf("\t----------------------------------------------------------------------\n");
        printf("\t======================================================================\n");
        printf("\t||       1 学号               2 班级              3 姓名            ||\n");
        printf("\t======================================================================\n");
        printf("\t======================================================================\n");
        printf("\t||       4 退出程序                              0 返回上层           ||\n");
        printf("\t======================================================================\n");
        printf("\t----------------------------------------------------------------------\n");
}

/*返回一个扩展名为.dat的文件名*/
char* namedat(char *str,int j)
{
    str[j]='.';
    str[++j]='d';
    str[++j]='a';
    str[++j]='t';
    str[++j]='\0';
    return str;

}
/*输出全部*/
void shuchu()
{
    int ch,a;
    FILE *fp;
    printf("输出全部信息：\n");
    printf("学号  班级 姓名 年 月 日  性别    \n");
    if((fp=fopen("E:\\memory.dat","r"))==NULL)
    {
        printf("can't open file");
        return;
    }
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
    printf("按任意键退出返回上一级\n");
    a=getch();

}
