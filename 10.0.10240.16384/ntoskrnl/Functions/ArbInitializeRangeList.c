// ArbInitializeRangeList 
 
int __fastcall ArbInitializeRangeList(int a1, int a2, unsigned __int8 *a3, int a4)
{
  unsigned __int8 *v5; // r5
  unsigned int v6; // r7
  int v8; // r2
  int v9; // t1
  int v10; // r3
  int v11; // r4
  __int64 v13; // [sp+18h] [bp-40h] BYREF
  unsigned __int64 v14; // [sp+20h] [bp-38h] BYREF
  int v15[12]; // [sp+28h] [bp-30h] BYREF

  v15[1] = (int)v15;
  v5 = a3;
  v6 = (unsigned int)&a3[16 * a2];
  v15[0] = (int)v15;
  v15[2] = 0;
  v15[3] = 0;
  v15[4] = 0;
  if ( (unsigned int)a3 >= v6 )
  {
LABEL_10:
    v11 = RtlInvertRangeList(a4, v15);
    if ( v11 >= 0 )
      v11 = 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = *v5;
      v5 += 16;
      v8 = v9;
      v10 = *(_DWORD *)(a1 + 16);
      if ( v9 == v10 || v8 == 7 && v10 == 3 )
      {
        v11 = (*(int (__fastcall **)(unsigned __int8 *, unsigned __int64 *, __int64 *))(a1 + 68))(v5 - 16, &v14, &v13);
        if ( v11 < 0 )
          break;
        if ( v13 )
          v11 = RtlAddRange((int)v15, v14, v14 + v13 - 1, 0, 3, 0, 0);
        if ( v11 < 0 )
          break;
      }
      if ( (unsigned int)v5 >= v6 )
        goto LABEL_10;
    }
  }
  RtlFreeRangeList(v15);
  return v11;
}
