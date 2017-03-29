// program pyta uzytkownika o dane do wpisania

#include <stdlib.h>
#include <libpq-fe.h>
#include <stdio.h>

void doSQL(PGconn *conn, char *command)
{
  PGresult *result;

  printf("%s\n", command);

  result = PQexec(conn, command);
  printf("status is     : %s\n", PQresStatus(PQresultStatus(result)));
  printf("#rows affected: %s\n", PQcmdTuples(result));
  printf("result message: %s\n", PQresultErrorMessage(result));

  switch(PQresultStatus(result)) {
  case PGRES_TUPLES_OK:
    {
      int n = 0, r = 0;
      int nrows   = PQntuples(result);
      int nfields = PQnfields(result);
      printf("number of rows returned   = %d\n", nrows);
      printf("number of fields returned = %d\n", nfields);
      for(r = 0; r < nrows; r++) {
	for(n = 0; n < nfields; n++)
	  printf(" %s = %s", PQfname(result, n),PQgetvalue(result,r,n));
	printf("\n");
      }
    }
  }
  PQclear(result);
}
 
int main()
{
  PGresult *result;
  PGconn   *conn;
  char     odp, name[20], zapytanie[200];
  int      value;
  conn = PQconnectdb("host=localhost port=5432 dbname=nazwa user=login password=haslo");
  if(PQstatus(conn) == CONNECTION_OK) {
    printf("connection made\n");

    doSQL(conn, "DROP TABLE number");
    doSQL(conn, "CREATE TABLE number(value INTEGER PRIMARY KEY,name VARCHAR)");
    printf("\n\n ---- czy wpisujemy cos do tabeli? (t/n) ");
    while( (odp = getchar()) == 't' || (odp == 'T') ) {
      //getchar();
      printf("   numer = "); scanf("%d",&value);
      printf("   nazwa = "); scanf("%s",name);
      getchar();
      sprintf(zapytanie, "INSERT INTO number VALUES(%d, \'%s\')",value,name);
      //printf("%s\n",zapytanie);      
      doSQL(conn, zapytanie);
      printf("\n\n ---- czy wpisujemy cos do tabeli? (t/n) ");
    }

    doSQL(conn, "SELECT * FROM number");
    doSQL(conn, "UPDATE number SET name = 'Zaphod' WHERE value = 1");
    doSQL(conn, "DELETE FROM number WHERE value = 2");
    doSQL(conn, "SELECT * FROM number");
  }
  else
    printf("connection failed: %s\n", PQerrorMessage(conn));

  PQfinish(conn);
  return EXIT_SUCCESS;
}

