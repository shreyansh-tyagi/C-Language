#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>


static char *host="localhost";
static char *user="root";
static char *pass="mythemiz1524";
static char *db="operator";

unsigned int port=3306;
static char *unix_socket=NULL;
unsigned int flag=0;

int main()
{
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW col;
conn=mysql_init(NULL);
if(!(mysql_real_connect(conn,host,user,pass,db,port,unix_socket,flag)))
{
fprintf(stderr,"\nError: %s [%d]\n", mysql_error(conn),mysql_errno(conn));
exit(1);
}
printf("\nHELLO SHREYANSH!----- you are successfully connected to mysql server------\n\n");
mysql_query(conn,"use operator");
mysql_query(conn,"select * from clothes");
res=mysql_store_result(conn);
while(col=mysql_fetch_row(res))
{
    printf("%s\n",col[0]);


}
mysql_free_result(res);
mysql_close(conn);
return EXIT_SUCCESS;
}