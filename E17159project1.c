#include <stdio.h>
#include <ctype.h>
#include <string.h>
int moveto(int,int);
int movedown(int);
int moveleft(int); 
int oneChar(int,int,int,int);
int frame(int,int);
void hashstr(char string[],int length,char hashstrg[],int c); 

int main(int argc, char** argv)
{  
    int colno;                                      //required color number
    int move=0;                                     //decides whether print QR (move=1--> print   QR ,move=0--> not print
    char* color[7]={"black","red","green","yellow","blue","magenta","cyan"};    //colors supported by the program
    if(argc==1){                                                                 //if argc=1
        colno=40;                                                                //colno dafault black
        move=1;
    }
    
    else if(argc==2){                                                           //for argc=2
        if(argv[1][0]=='-'&& argv[1][1]=='h'){                                   // if "-h" is typed
          printf("usage :\n%s -c [black|red|green|yellow|blue|magenta|cyan]\n%s -h for the help about the program\n",argv[0],argv[0]);
        }
        else{                                                                      
          printf("Incorrect usage of arguments.\nusage :\n%s -c [black|red|green|yellow|blue|magenta|cyan]\n%s -h for the help about the program\n",argv[0],argv[0]);
        }
    }
    
    else if(argc==3){                                  //for argc=3
        if(argv[1][0]=='-'&&argv[1][1]=='c'){           //if "-c"is typed as argv[2]
            for(int r=0;r<7;r++){
               if(strlen(argv[2])==strlen(color[r])){       //check whether length is equal to color length
                 for(int g=0,s=0;g<strlen(argv[2]);g++){    
                  if(tolower(argv[2][g])==color[r][g]){      //check whether charecters are equal
                      s++;
                  }
                  if(s==strlen(argv[2])){                   
                    colno=40+r;                             //if the color is found then color number=colno
                    move=1;                                  //print   QR
                  } 
               }
            }
            }
          if(colno==0){                             //if color number not found
    printf("Invalid argument for color.\nusage :\n%s -c [black|red|green|yellow|blue|magenta|cyan]\n%s -h for the help about the program\n",argv[0],argv[0]);         
           }
       }
        
         
        
        else{                                            //argc[2] not "-c"
    printf("Incorrect usage of arguments.\nusage :\n%s -c [black|red|green|yellow|blue|magenta|cyan]\n%s -h for the help about the program\n",argv[0],argv[0]);         
           }
        
    }
    
    
    else{                   // argc>3
    printf("Incorrect usage of arguments.\nusage :\n%s -c [black|red|green|yellow|blue|magenta|cyan]\n%s -h for the help about the program\n",argv[0],argv[0]);
    }
    
    
    
    if(move==1){                 //Check whether print  QR or not             
    char string[10000];             //input URL
    
    printf("Enter the URL: "); 
    scanf("%s",string);                                        //gets input from user
    
    int length;                                       //length of the string 
    
    length=strlen(string);
    if(length<4){                                  //check whether input string is less than 4
        printf("String is too short. Not supported by available QR versions\n");       //error message
    }
    else if(length>119){                           //check whether input string is greater than 120
        printf("String is too long. Not supported by available QR versions\n");       //error message
    }
    else{                                                     //if  3<length<120
      if(length<=20){                                         //if length less or equal to 20
          char hashstrg[24];                                  //hash string 
          int laststr[24];                                    //hash string  in integers
          hashstr(string,length,hashstrg,24);                 //function hashstr
          for(int d=0;d<24;d++){
              laststr[d]=(int)hashstrg[d];                    //change as integer string
             
          }
          
          printf("\x1b[2J  ");
          moveto(1,1);
          frame(20,colno);                             //printing frame&positions with defined color
          int stra[24]={8,8,8,8,11,11,11,11,14,14,14,14,17,17,17,17,2,2,5,5,8,8,11,11};        //row position 
          int strb[24]={15,21,27,33,15,21,27,33,15,21,27,33,15,21,27,33,15,21,15,21,3,9,3,9};    //column position
          for(int q=0;q<24;q++){                                      //print 24 charcters
              oneChar(stra[q],strb[q],laststr[q],colno);              //function one char
              }
           moveto(21,1);
          printf("\n");
      }
      else if(length>20){                                               //if length greater than 20
          char hashstrg[132];                                           //hash string in integer  
          int laststr[132];
          hashstr(string,length,hashstrg,132);                          //function hashstr
          for(int d=0;d<132;d++){
              laststr[d]=(int)hashstrg[d];                               //change as integer string
          }
      
          printf("\x1b[2J  ");
          moveto(1,1);
          frame(38,colno);                                              //printing frame & positions
                                                                        //row & column positions
          int stra[132]={7,7,7,7,7,7,7,7,7,7,10,10,10,10,10,10,10,10,10,10,13,13,13,13,13,13,13,13,13,13,16,16,16,16,16,16,16,16,16,16,19,19,19,19,19,19,19,19,19,19,22,22,22,22,22,22,22,22,22,22,25,25,25,25,25,25,25,25,25,25,28,28,28,28,28,28,28,28,28,28,31,31,31,31,31,31,31,31,31,31,34,34,34,34,34,34,34,34,34,34,1,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4,7,7,10,10,13,13,16,16,19,19,22,22,25,25,28,28};
          int strb[132]={15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,63,69,15,21,27,33,39,45,51,57,15,21,27,33,39,45,51,57,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9};
      
           for(int q=0;q<132;q++){                                //print 132 char
              oneChar(stra[q]+1,strb[q],laststr[q],colno);        //onechar fuction
           }
          
           moveto(39,1);
           printf("\n");
      }
    }
    } 
      return 0;
  }
int moveto(int row,int col){              //move position  func
    printf("\x1b[%d;%df",row,col);
    return 0;
}
int movedown(int a){                      //move down func
    printf("\x1b[%dB",a);
    return 0;
}
int moveleft(int a){                      //move left  func
    printf("\x1b[%dD",a);
    return 0;
}
int oneChar(int row,int col,int input,int colno){    //fuction to print one char box 3*3    
    int count=0;
    moveto(row,col);
    for(int w=0;w<3;w++){
        for(int k=0;k<3;k++){
            if(w==0&&k==0){                          //first box (white)
                printf("\x1b[47m  ");            
            }
            else{
                if((input>>(7-count)) & 1){          //if bit is one print (color)
                   printf("\x1b[%dm  ",colno);
                }
                else{                                //if 0  print (white)
                    printf("\x1b[47m  ");
                 }
             count++;
             
            }
        }
        movedown(1);                  
        moveleft(6);
    }
    printf("\x1b[0m");
    return 0;
}
void hashstr(char string[],int length,char hashstrg[],int c){   //fuction for hash string
    int l=50+length;                                            //first character=50+length
        int m=0;
        char bff[c-length-1];                                   //the array of reversing part 
                  
            hashstrg[0]=l;          //first char
            hashstrg[c]='\0';       //end of array
            for(int i=0;i<length;i++){
                hashstrg[i+1]=string[i];          //adding input charcter to hashstring
            }
            
            for(int x=0;x<c;x++){                 //adding values to input string(a+1,b+2...,a+2....)
                for(int z=0;z<length;z++){
                    if(m<c-1-length){
                        bff[m]=string[z]+x+1;
                        m++;
                    }
                }
            }
            int b=0;                            
            for(int a=c-length-1;a>0;a--){          //reversing 
                if(b<c-length-1){
                    hashstrg[b+length+1]=bff[a-1];  //include reversed string to hashstring
                    b++;
                }
            }

}
int frame(int max,int colno){                //for frames & positions
    for(int i=0;i<max;i++){                  //if length<=20 ----> max=20,   length>20 ---->max=38
        for(int k=0;k<max;k++){
            if(i==0||i==max-1){              //horizontal border frame   (white)
                printf("\x1b[47m  ");              
            }
            else{
                if(((i>0&&i<7)&&(k>0&&k<7))||((i>(max-8)&&i<(max-1))&&(k>0&&k<7))||((i>0&&i<7)&&(k>(max-8)&&k<(max-1)))){
                    if(i==1||i==6||i==(max-7)||i==(max-2)){         //position horz lines (color)
                       printf("\x1b[%dm  ",colno);
                    }
                    else{
                        if(k==1||k==6||k==(max-2)||k==(max-7)){
                            printf("\x1b[%dm  ",colno);              //position vertcal (colr)
                        }
                        else if(((i==3||i==4)&&(k==3||k==4))||((i==(max-5)||i==(max-4))&&(k==3||k==4))||((i==3||i==4)&&(k==(max-5)||k==(max-4)))){
                            printf("\x1b[%dm  ",colno);               //mid box position (clr)            
                        }
                        else{
                            printf("\x1b[47m  ");     //whi
                        }
                    }
                }
                
                else if(k==0||k==(max-1)){
                    printf("\x1b[47m  ");          //frame vertical (white)             
                }
                else{
                    printf("\x1b[47m  ");  
                }
            }
        }
        printf("\x1b[0m");
        printf("\n");
    }return 0;
}
