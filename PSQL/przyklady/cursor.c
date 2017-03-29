//pobieranie po dwa wiersze w kursorze
#include <stdlib.h>
#include <libpq-fe.h>

void printTuples(PGresult *result)
{
      int m, n;
      int nrows = PQntuples(result);
      int nfields = PQnfields(result);
      printf("number of rows returned = %d\n", nrows);
      printf("number of fields returned = %d\n", nfields);
      for(m = 0; m < nrows; m++) {
	for(n = 0; n < nfields; n++)
	  printf(" %s = %s(%d),\t", 
		 PQfname(result, n), 
		 PQgetvalue(result, m, n),
		 PQgetlength(result, m, n));
	printf("\n");
      }
}

void doSQL(PGconn *conn, char *command)
{
  PGresult *result;

  printf("%s\n", command);

  result = PQexec(conn, command);
  printf("status is %s\n", PQresStatus(PQresultStatus(result)));
  printf("#rows affected %s\n", PQcmdTuples(result));
  printf("result message: %s\n", PQresultErrorMessage(result));

  switch(PQresultStatus(result)) {
  case PGRES_TUPLES_OK:
    printTuples(result);
    break;
  }
  PQclear(result);
}
 
int main()
{
  PGresult *result;
  PGconn *conn;
  int ntuples = 0;
  conn = PQconnectdb("host=localhost port=5432 dbname=nazwa user=login password=haslo");
  if(PQstatus(conn) == CONNECTION_OK) {
    printf("connection made\n");
    doSQL(conn, "BEGIN work");
    doSQL(conn, "DECLARE mycursor CURSOR FOR SELECT * FROM number");
    do {
      result = PQexec(conn, "FETCH 2 IN mycursor");
      if(PQresultStatus(result) == PGRES_TUPLES_OK) {
	ntuples = PQntuples(result);
	printTuples(result);
	PQclear(result);
      }
      else ntuples = 0;
    } while(ntuples);
    doSQL(conn, "CLOSE mycursor");
    doSQL(conn, "COMMIT work");
  }
  else 
    printf("connection failed: %s\n", PQerrorMessage(conn));
  PQfinish(conn);
  return EXIT_SUCCESS;
}
