// PopComputeDerivedHiberStats 
 
int __fastcall PopComputeDerivedHiberStats(int a1, __int64 a2, int *a3)
{
  unsigned int v5; // r6
  unsigned int v6; // r5
  __int64 v7; // r0
  int v8; // r9
  unsigned __int64 v9; // r2
  __int64 v10; // r0
  unsigned __int64 v11; // r2
  __int64 v12; // kr10_8
  __int64 v13; // r0
  unsigned __int64 v14; // r2
  __int64 v15; // kr18_8
  __int64 v16; // r0
  unsigned __int64 v17; // r2

  *a3 = 0;
  a3[1] = 0;
  a3[2] = 0;
  a3[3] = 0;
  v5 = 1000 * (*(_DWORD *)(a1 + 416) + *(_DWORD *)(a1 + 408)) * a2;
  v6 = (unsigned __int64)(1000 * (*(_QWORD *)(a1 + 416) + *(_QWORD *)(a1 + 408)) * a2) >> 32;
  v7 = *(_QWORD *)a1;
  v8 = v6 << 12;
  if ( v7 )
  {
    LODWORD(v9) = v8 | (v5 >> 20);
    HIDWORD(v9) = v6 >> 20;
    *a3 = _rt_udiv64(v7, v9);
  }
  else
  {
    *a3 = 0;
  }
  v10 = *(_QWORD *)(a1 + 32);
  if ( v10 )
  {
    LODWORD(v11) = v8 | (v5 >> 20);
    HIDWORD(v11) = v6 >> 20;
    LODWORD(v10) = _rt_udiv64(v10, v11);
    a3[2] = v10;
  }
  else
  {
    a3[2] = 0;
  }
  v12 = *(_QWORD *)(a1 + 136);
  if ( v12 || *(_QWORD *)(a1 + 280) )
  {
    v13 = *(_QWORD *)(a1 + 280) + v12;
    if ( !v13 )
      __brkdiv0();
    LODWORD(v14) = v8 | (v5 >> 20);
    HIDWORD(v14) = v6 >> 20;
    LODWORD(v10) = _rt_udiv64(v13, v14);
    a3[1] = v10;
  }
  else
  {
    a3[1] = 0;
  }
  v15 = *(_QWORD *)(a1 + 144);
  if ( v15 || *(_QWORD *)(a1 + 272) )
  {
    v16 = *(_QWORD *)(a1 + 272) + v15;
    if ( !v16 )
      __brkdiv0();
    LODWORD(v17) = v8 | (v5 >> 20);
    HIDWORD(v17) = v6 >> 20;
    LODWORD(v10) = _rt_udiv64(v16, v17);
    a3[3] = v10;
  }
  else
  {
    a3[3] = 0;
  }
  return v10;
}
