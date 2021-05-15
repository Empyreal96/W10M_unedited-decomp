// wcscmp 
 
int __fastcall wcscmp(char *a1, char *a2)
{
  int v3; // r3
  int v4; // r2
  int result; // r0
  int v6; // r4
  int v7; // t1
  int v8; // r3

  v3 = *(unsigned __int16 *)a1;
  v4 = *(unsigned __int16 *)a2;
  result = v3 - v4;
  if ( v3 == v4 )
  {
    v6 = a1 - a2;
    do
    {
      if ( !v4 )
        break;
      v7 = *((unsigned __int16 *)a2 + 1);
      a2 += 2;
      v4 = v7;
      v8 = *(unsigned __int16 *)&a2[v6];
      result = v8 - v7;
    }
    while ( v8 == v7 );
  }
  if ( result < 0 )
    return -1;
  if ( result > 0 )
    result = 1;
  return result;
}
