// RtlEqualString 
 
int __fastcall RtlEqualString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  int v3; // r4
  char *v5; // r5
  int v6; // r3
  unsigned __int8 *v7; // r6
  int v8; // r1
  int v9; // r2
  int v10; // t1
  int v11; // r8
  int v12; // r7
  int v13; // r3
  int v14; // r4

  v3 = *a1;
  if ( v3 != *a2 )
    return 0;
  v5 = (char *)*((_DWORD *)a1 + 1);
  v6 = *((_DWORD *)a2 + 1);
  v7 = (unsigned __int8 *)&v5[v3];
  if ( a3 )
  {
    if ( v5 < (char *)v7 )
    {
      v11 = v6 - (_DWORD)v5;
      while ( 1 )
      {
        v12 = (unsigned __int8)*v5;
        v13 = (unsigned __int8)v5[v11];
        if ( v12 != v13 )
        {
          v14 = RtlUpperChar((char)v13);
          if ( RtlUpperChar((char)v12) != v14 )
            break;
        }
        if ( ++v5 >= (char *)v7 )
          return 1;
      }
      return 0;
    }
  }
  else if ( v5 < (char *)v7 )
  {
    v8 = v6 - (_DWORD)v5;
    while ( 1 )
    {
      v9 = v5[v8];
      v10 = *v5++;
      if ( v10 != v9 )
        break;
      if ( v5 >= (char *)v7 )
        return 1;
    }
    return 0;
  }
  return 1;
}
