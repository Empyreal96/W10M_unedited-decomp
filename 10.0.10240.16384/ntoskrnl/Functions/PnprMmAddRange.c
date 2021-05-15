// PnprMmAddRange 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnprMmAddRange(int *a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  unsigned int v6; // r6
  int v7; // r8
  unsigned int v8; // r9
  unsigned int v9; // r5
  _DWORD *v10; // r0
  _DWORD *v11; // r4
  int *i; // r2 OVERLAPPED
  int v13; // r1 OVERLAPPED
  int v14; // r3
  int v15; // r2
  int v16; // r2
  unsigned int v18; // [sp+0h] [bp-20h]
  int *varg_r0; // [sp+28h] [bp+8h]

  varg_r0 = a1;
  v6 = a5 >> 12;
  v7 = 0;
  v8 = a3 >> 12;
  if ( a5 >> 12 )
  {
    while ( 1 )
    {
      v9 = 0x80000000;
      if ( v6 <= 0x80000000 )
        v9 = v6;
      v18 = (v9 + 32) & 0xFFFFFFE0;
      v10 = (_DWORD *)ExAllocatePoolWithTag(512, (v18 >> 3) + 24, 1383099984);
      v11 = v10;
      if ( !v10 )
        break;
      v10[2] = v8;
      v10[3] = v9;
      v10[4] = v18;
      v10[5] = v10 + 6;
      RtlSetAllBits(v10 + 4);
      for ( i = (int *)a1[1]; i != a1; i = (int *)i[1] )
      {
        if ( (unsigned int)i[2] < v11[2] )
          break;
      }
      v13 = *i;
      *(_QWORD *)v11 = *(_QWORD *)(&i - 1);
      if ( *(int **)(v13 + 4) != i )
        __fastfail(3u);
      *(_DWORD *)(v13 + 4) = v11;
      *i = (int)v11;
      v8 += v9;
      v6 -= v9;
      if ( !v6 )
        return v7;
    }
    v7 = -1073741670;
    v14 = PnprContext;
    v15 = *(_DWORD *)(PnprContext + 608);
    if ( !v15 )
      v15 = 4357;
    *(_DWORD *)(PnprContext + 608) = v15;
    v16 = *(_DWORD *)(v14 + 612);
    if ( !v16 )
      v16 = 10;
    *(_DWORD *)(v14 + 612) = v16;
  }
  return v7;
}
