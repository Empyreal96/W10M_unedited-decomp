// _wcsistr 
 
char *__fastcall wcsistr(char *result, char *a2)
{
  int v3; // r3
  int v4; // r4
  _WORD *i; // r2
  unsigned int v6; // r1
  unsigned int v7; // r5
  int v8; // t1

  if ( *(_WORD *)a2 )
  {
    v3 = *(unsigned __int16 *)result;
    if ( *(_WORD *)result )
    {
      v4 = result - a2;
      while ( 1 )
      {
        for ( i = a2; v3; v3 = *(unsigned __int16 *)((char *)i + v4) )
        {
          v6 = (unsigned __int16)*i;
          if ( !*i )
            break;
          v7 = *(unsigned __int16 *)((char *)i + v4);
          if ( v7 >= 0x61 && v7 <= 0x7A )
            v7 = (unsigned __int16)(v7 - 32);
          if ( v6 >= 0x61 && v6 <= 0x7A )
            v6 = (unsigned __int16)(v6 - 32);
          if ( v7 != v6 )
            break;
          ++i;
        }
        if ( !*i )
          break;
        v8 = *((unsigned __int16 *)result + 1);
        result += 2;
        v3 = v8;
        v4 += 2;
        if ( !v8 )
          goto LABEL_17;
      }
    }
    else
    {
LABEL_17:
      result = 0;
    }
  }
  return result;
}
