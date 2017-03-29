#include <stdlib.h>
#include <libpq-fe.h>

int main()
{
  PGresult *result;
  PGconn *conn;
  conn = PQconnectdb("host=localhost port=5432 dbname=nazwa user=login password=haslo");  if(PQstatus(conn) == CONNECTION_OK) 
  {
    result = PQexec(conn, "SELECT * FROM number");
    if(PQresultStatus(result)==PGRES_TUPLES_OK) 
    { 
      PQprintOpt pqp;
      pqp.header = 1;
      pqp.align = 1;
      pqp.html3 = 1;
      pqp.expanded = 0;
      pqp.pager = 0;
      pqp.fieldSep = "";
      pqp.tableOpt = "align=center";
      pqp.caption = "Bingham Customer List";
      pqp.fieldName = NULL;
      printf("<HTML><HEAD></HEAD><BODY>\n");
      PQprint(stdout, result, &pqp);
      printf("</BODY></HTML>\n");
    }
  }
  PQfinish(conn);
  return EXIT_SUCCESS;
}

