// RtlPrefixString 
 
int __fastcall RtlPrefixString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  char *v3; // r5
  unsigned int v4; // r0
  int v5; // r4
  unsigned __int8 *v6; // r6
  int v7; // r8
  int v8; // r7
  int v9; // r3
  int v10; // r4
  int v12; // r1
  int v13; // r2
  int v14; // t1

  v3 = (char *)*((_DWORD *)a1 + 1);
  v4 = *a1;
  v5 = *((_DWORD *)a2 + 1);
  if ( *a2 >= v4 )
  {
    v6 = (unsigned __int8 *)&v3[v4];
    if ( a3 )
    {
      if ( v3 < (char *)v6 )
      {
        v7 = v5 - (_DWORD)v3;
        while ( 1 )
        {
          v8 = (unsigned __int8)*v3;
          v9 = (unsigned __int8)v3[v7];
          if ( v8 != v9 )
          {
            v10 = RtlUpperChar((char)v9);
            if ( RtlUpperChar((char)v8) != v10 )
              break;
          }
          if ( ++v3 >= (char *)v6 )
            return 1;
        }
        return 0;
      }
    }
    else if ( v3 < (char *)v6 )
    {
      v12 = v5 - (_DWORD)v3;
      while ( 1 )
      {
        v13 = v3[v12];
        v14 = *v3++;
        if ( v14 != v13 )
          break;
        if ( v3 >= (char *)v6 )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  return 0;
}
