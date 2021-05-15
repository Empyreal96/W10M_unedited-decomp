// RtlInvertRangeListEx 
 
int __fastcall RtlInvertRangeListEx(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // r5
  unsigned int v6; // r7
  bool v7; // zf
  int v9; // r1
  int v12; // lr
  int result; // r0
  _DWORD *v14; // r3
  _DWORD *v15; // r6
  int v16; // [sp+18h] [bp-20h]

  v16 = a1;
  v5 = 0;
  v6 = 0;
  v7 = a2[3] == 0;
  v9 = a5;
  v12 = a1;
  if ( v7 )
    return sub_80D8FC();
  v14 = (_DWORD *)*a2;
  while ( 1 )
  {
    v15 = v14 - 7;
    if ( a2 == v14 )
      break;
    if ( *(_QWORD *)v15 > __PAIR64__(v6, v5) )
    {
      result = RtlAddRange(
                 v12,
                 *v15 - 1,
                 v5,
                 v6,
                 *v15 - 1,
                 (unsigned __int64)(*(_QWORD *)v15 - 1i64) >> 32,
                 a3,
                 0,
                 a4,
                 v9);
      if ( result < 0 )
        return result;
      v12 = v16;
      v9 = a5;
    }
    v14 = (_DWORD *)v15[7];
    v6 = (unsigned __int64)(*((_QWORD *)v15 + 1) + 1i64) >> 32;
    v5 = v15[2] + 1;
  }
  if ( __PAIR64__(v6, v5) <= __PAIR64__(v6, v5) - 1
    || (result = RtlAddRange(v12, v9, v5, v6, -1, -1, a3, 0, a4, v9), result >= 0) )
  {
    result = 0;
  }
  return result;
}
