// RtlCompareString 
 
int __fastcall RtlCompareString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  int v3; // r7
  int v4; // r8
  unsigned __int8 *v5; // r4
  int v6; // r6
  int v7; // r3
  unsigned __int8 *v8; // r5
  int v9; // r10
  int v11; // r1
  int v12; // r2
  int v13; // r3

  v3 = *a1;
  v4 = *a2;
  v5 = (unsigned __int8 *)*((_DWORD *)a1 + 1);
  v6 = *((_DWORD *)a2 + 1);
  if ( v3 > v4 )
    v7 = *a2;
  else
    v7 = *a1;
  v8 = &v5[v7];
  if ( a3 )
  {
    if ( v5 < v8 )
    {
      v9 = v6 - (_DWORD)v5;
      while ( *v5 == v5[v9] )
      {
        if ( ++v5 >= v8 )
          return v3 - v4;
      }
      return sub_7E82FC();
    }
    return v3 - v4;
  }
  if ( v5 >= v8 )
    return v3 - v4;
  v11 = v6 - (_DWORD)v5;
  while ( 1 )
  {
    v12 = *v5;
    v13 = v5[v11];
    if ( v12 != v13 )
      break;
    if ( ++v5 >= v8 )
      return v3 - v4;
  }
  return v12 - v13;
}
