#include <stdio.h>
#include <time.h>
char Rworld[20][20];
int isFree(int x,int y){
   if (Rworld[x][y]=='.') return(1);
   else return(0);
}
int random (int min, int max){
int a = min + max;
int b = rand()%a;
return (min+b);
}

int main(){
    FILE *map = fopen ("map.txt","w");
    srand(time (0));
    int side = rand()%19+2;
    for (int i=0 ; i<side ; i++)
    {
        for (int j=0 ; j<side ; j++)
        {
            Rworld[i][j]='.';
        }
    }
    char animals[10];
    int x,y;
    fprintf (map,"%d\n",side);
    fprintf (map,"# ");
    int num_of_deadends = rand()%(side*side/5)+(side*side/10);
    fprintf (map,"%d ",num_of_deadends);
    for (int i=1 ; i <= num_of_deadends ; i++)
    {
         do{
      x=random(0,side);
      y=random(0,side);
      }while(isFree(x,y)==0);
        fprintf (map,"(%d,%d)", x, y);
        Rworld[x][y]='#';
    }
    fprintf (map,"\n");
    fprintf (map,"H ");
    int num_of_paradises = rand()%(side*side/5)+1;
    fprintf (map,"%d ",num_of_paradises);
    for (int i=1 ; i <= num_of_paradises ; i++)
    {
         do{
      x=random(0,side);
      y=random(0,side);
      }while(isFree(x,y)==0);
        fprintf (map,"(%d,%d)", x, y);
        Rworld[x][y]='H';
    }
    fprintf (map,"\n");
    fprintf (map,"===\n");
    int num_of_foods = rand()%(side-4)+5;
    for (int i = 1; i <= num_of_foods ; i++)
    {
        fprintf (map,"F ");
        fprintf (map,"%d ",rand()%500+0);
        do{
        x=random(0,side);
        y=random(0,side);
        } while(isFree(x,y)==0);
        fprintf (map,"(%d,%d)\n", x, y);
    }
    fprintf(map,"===\n");
    int num_of_species = rand()%10+1;
    for (int i=1 ; i <= num_of_species ; i++)
    {
        animals[i-1] = rand()%26+65;
        fprintf (map,"%c ",animals[i-1]);
        int num_of_single_kind = rand()%10+1;
        fprintf (map,"%d ", num_of_single_kind);
        for (int j=1 ; j <= num_of_single_kind ; j++)
        {
            do{
                x=random(0,side);
                y=random(0,side);
                }while(isFree(x,y)==0);
            fprintf (map,"(%d,%d)\n",x,y);
        }
        fprintf (map,"\n");
    }
    fprintf (map,"===\n");
    int user_animal = rand()%num_of_species+1;
    fprintf (map,"%c\n", animals[user_animal-1]);
    fprintf (map,"===\n");
    for (int i=0 ; i < num_of_species ; i++)
    {
        fprintf (map,"%c ",animals[i]);
        fprintf (map,"%d ",rand()%401+100);
        fprintf (map,"%d$%d$%d$%d$%d\n", rand()%181+20, rand()%3+1, rand()%541+60, rand()%481+20, rand()%481+20);
    }
    fclose (map);

}
