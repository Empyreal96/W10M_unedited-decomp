// RtlAddAce 
 
int __fastcall RtlAddAce(unsigned __int8 *a1, unsigned __int8 a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned __int8 v9; // r9
  int v10; // r1
  unsigned __int8 *v11; // r2
  __int16 v12; // lr
  unsigned int v13; // r0
  unsigned int v14; // r4
  unsigned __int8 *i; // r2
  int j; // r0
  unsigned int v17; // r0
  __int16 v18; // r3
  int result; // r0
  int v20[8]; // [sp+0h] [bp-20h] BYREF

  v20[0] = a3;
  v20[1] = a4;
  if ( !RtlValidAcl() || !RtlFirstFreeAce(a1, v20) )
    return -1073741811;
  if ( a2 > (unsigned int)*a1 )
    v9 = a2;
  else
    v9 = *a1;
  v10 = a5;
  v11 = (unsigned __int8 *)a4;
  v12 = 0;
  v13 = a4 + a5;
  if ( a4 >= a4 + a5 )
  {
LABEL_8:
    if ( (unsigned int)v11 <= v13 )
    {
      if ( !v20[0] || v20[0] + a5 > (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)] )
        return -1073741789;
      v14 = 0;
      for ( i = a1 + 8; v14 < a3; i += *((unsigned __int16 *)i + 1) )
      {
        if ( v14 >= *((unsigned __int16 *)a1 + 2) )
          break;
        ++v14;
      }
      for ( j = v20[0] - (_DWORD)i - 1; j >= 0; --j )
        i[a5 + j] = i[j];
      if ( a5 )
      {
        v17 = a4 - (_DWORD)i;
        do
        {
          --v10;
          *i = i[v17];
          ++i;
        }
        while ( v10 );
      }
      v18 = *((_WORD *)a1 + 2);
      *a1 = v9;
      result = 0;
      *((_WORD *)a1 + 2) = v18 + v12;
      return result;
    }
    return -1073741811;
  }
  while ( *v11 <= 3u )
  {
    ++v12;
    v11 += *((unsigned __int16 *)v11 + 1);
    if ( (unsigned int)v11 >= v13 )
      goto LABEL_8;
  }
  return sub_7C525C();
}
