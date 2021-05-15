// PspFoldProcessAccountingIntoJob 
 
int __fastcall PspFoldProcessAccountingIntoJob(int a1, _DWORD *a2, __int64 *a3)
{
  __int64 v3; // r8
  __int64 v4; // r3
  __int64 v5; // kr30_8
  __int64 v6; // r5
  unsigned int v7; // kr04_4
  unsigned int v8; // kr0C_4
  unsigned int v9; // kr14_4
  unsigned int v10; // kr18_4
  unsigned int v13; // r2
  unsigned int v14; // kr20_4
  unsigned int v15; // r2
  unsigned int v16; // kr28_4
  unsigned int v17; // r0
  __int64 v18; // kr38_8
  unsigned int v19; // r1
  unsigned int v20; // kr08_4
  unsigned int v21; // r1
  unsigned int v22; // kr10_4
  unsigned int v23; // r1
  unsigned int v24; // kr1C_4
  unsigned int v25; // r1
  unsigned int v26; // r1
  _QWORD *v27; // r4
  __int64 v28; // kr68_8
  __int64 v29; // kr78_8
  __int64 v30; // kr88_8
  __int64 v31; // kr98_8
  unsigned int v32; // r1
  int result; // r0
  unsigned int v34; // r6
  int v35; // r7
  _QWORD *v36; // r4
  __int64 v37; // krA0_8
  char v39[64]; // [sp+8h] [bp-B0h] BYREF
  __int64 v40; // [sp+48h] [bp-70h]
  __int64 v41; // [sp+50h] [bp-68h]
  __int64 v42; // [sp+58h] [bp-60h]
  __int64 v43; // [sp+60h] [bp-58h]
  __int64 v44; // [sp+68h] [bp-50h]
  __int64 v45; // [sp+80h] [bp-38h]
  __int64 v46; // [sp+90h] [bp-28h]

  v3 = a3[1];
  v4 = *(_QWORD *)(a1 + 88);
  v5 = *a3;
  v6 = *(_QWORD *)(a1 + 104);
  v7 = *(_DWORD *)(a1 + 88);
  *(_DWORD *)(a1 + 88) = v7 + v3;
  LODWORD(v4) = *(_DWORD *)(a1 + 96);
  *(_DWORD *)(a1 + 92) = (__PAIR64__(HIDWORD(v4), v7) + v3) >> 32;
  HIDWORD(v4) = *(_DWORD *)(a1 + 100);
  v8 = v4;
  *(_DWORD *)(a1 + 96) = v4 + v5;
  LODWORD(v4) = *((_DWORD *)a3 + 4);
  *(_DWORD *)(a1 + 100) = (__PAIR64__(HIDWORD(v4), v8) + v5) >> 32;
  HIDWORD(v4) = *((_DWORD *)a3 + 5);
  v9 = v4;
  v10 = v6;
  LODWORD(v4) = v4 + v6;
  *(_DWORD *)(a1 + 104) = v4;
  LODWORD(v4) = *(_DWORD *)(a1 + 112);
  *(_DWORD *)(a1 + 108) = (__PAIR64__(HIDWORD(v6), v9) + __PAIR64__(HIDWORD(v4), v10)) >> 32;
  v13 = *(_DWORD *)(a1 + 116);
  v14 = v4;
  *(_DWORD *)(a1 + 112) = v4 + v3;
  LODWORD(v4) = *(_DWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 116) = (__PAIR64__(v13, v14) + v3) >> 32;
  v15 = *(_DWORD *)(a1 + 124);
  v16 = v4;
  *(_DWORD *)(a1 + 120) = v4 + v5;
  LODWORD(v4) = *((_DWORD *)a3 + 6);
  v18 = *(_QWORD *)(a1 + 128);
  v17 = *(_DWORD *)(a1 + 132);
  *(_DWORD *)(a1 + 124) = (__PAIR64__(v15, v16) + v5) >> 32;
  v19 = *(_DWORD *)(a1 + 240);
  *(_QWORD *)(a1 + 128) = __PAIR64__(*((_DWORD *)a3 + 7), v4) + __PAIR64__(v17, v18);
  v20 = v19;
  v21 = *(_DWORD *)(a1 + 248);
  *(_QWORD *)(a1 + 240) = a3[4] + __PAIR64__(*(_DWORD *)(a1 + 244), v20);
  v22 = v21;
  v23 = *(_DWORD *)(a1 + 256);
  *(_QWORD *)(a1 + 248) = a3[5] + __PAIR64__(*(_DWORD *)(a1 + 252), v22);
  v24 = v23;
  v25 = *(_DWORD *)(a1 + 264);
  *(_QWORD *)(a1 + 256) = a3[6] + __PAIR64__(*(_DWORD *)(a1 + 260), v24);
  *(_QWORD *)(a1 + 264) = a3[7] + __PAIR64__(*(_DWORD *)(a1 + 268), v25);
  v26 = *(_DWORD *)(a1 + 280);
  *(_QWORD *)(a1 + 272) += a3[8];
  *(_QWORD *)(a1 + 280) = a3[9] + __PAIR64__(*(_DWORD *)(a1 + 284), v26);
  *(_DWORD *)(a1 + 136) += a2[148];
  v27 = (_QWORD *)a2[194];
  if ( v27 )
  {
    v28 = *(_QWORD *)(a1 + 296);
    *(_QWORD *)(a1 + 288) += *v27;
    v29 = *(_QWORD *)(a1 + 304);
    *(_QWORD *)(a1 + 296) = v27[1] + v28;
    v30 = *(_QWORD *)(a1 + 312);
    *(_QWORD *)(a1 + 304) = v27[2] + v29;
    v31 = *(_QWORD *)(a1 + 320);
    *(_QWORD *)(a1 + 312) = v27[3] + v30;
    *(_QWORD *)(a1 + 320) = v27[4] + v31;
  }
  v32 = a2[122];
  __dmb(0xBu);
  PspUpdateJobPeakProcessMemory(a1, v32);
  result = PoEnergyEstimationEnabled();
  if ( result )
  {
    PsQueryProcessEnergyValues(a2, v39);
    *(_QWORD *)(*(_DWORD *)(a1 + 752) + 64) += v40;
    *(_QWORD *)(*(_DWORD *)(a1 + 752) + 72) += v41;
    *(_QWORD *)(*(_DWORD *)(a1 + 752) + 80) += v42;
    *(_QWORD *)(*(_DWORD *)(a1 + 752) + 88) += v43;
    *(_QWORD *)(*(_DWORD *)(a1 + 752) + 96) += v44;
    *(_QWORD *)(*(_DWORD *)(a1 + 752) + 136) += v46;
    v34 = 0;
    *(_QWORD *)(*(_DWORD *)(a1 + 752) + 120) += v45;
    do
    {
      v35 = 2;
      do
      {
        v36 = (_QWORD *)(*(_DWORD *)(a1 + 752) + v34);
        v37 = *(_QWORD *)&v39[v34];
        result = HIDWORD(v37);
        v34 += 8;
        *v36 += v37;
        --v35;
      }
      while ( v35 );
    }
    while ( v34 < 0x40 );
  }
  return result;
}
