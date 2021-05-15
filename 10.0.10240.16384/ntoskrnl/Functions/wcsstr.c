// wcsstr 
 
char *__fastcall wcsstr(char *result, char *a2)
{
  int v3; // r3
  int v4; // r1
  _WORD *i; // r2
  int v6; // t1

  if ( *(_WORD *)a2 )
  {
    v3 = *(unsigned __int16 *)result;
    if ( *(_WORD *)result )
    {
      v4 = result - a2;
      while ( 1 )
      {
        for ( i = a2; v3 && *i && *(_WORD *)((char *)i + v4) == *i; v3 = *(unsigned __int16 *)((char *)i + v4) )
          ++i;
        if ( !*i )
          break;
        v6 = *((unsigned __int16 *)result + 1);
        result += 2;
        v3 = v6;
        v4 += 2;
        if ( !v6 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      result = 0;
    }
  }
  return result;
}
