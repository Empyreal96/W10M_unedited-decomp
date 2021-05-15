// PspQueryProcessAccountingInformationCallback 
 
int __fastcall PspQueryProcessAccountingInformationCallback(_DWORD *a1, int a2)
{
  __int64 v4; // kr18_8
  __int64 v5; // r4
  __int64 v6; // kr28_8
  __int64 v7; // kr38_8
  __int64 v8; // kr48_8
  __int64 v9; // kr58_8
  __int64 v10; // kr68_8
  __int64 v11; // kr78_8
  __int64 v12; // kr88_8
  _QWORD *v13; // r4
  _QWORD *v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // kr04_4
  unsigned int v17; // r1
  unsigned int v18; // kr08_4
  unsigned int v19; // r1
  unsigned int v20; // kr0C_4
  unsigned int v21; // r1
  unsigned int v22; // kr10_4
  unsigned int v23; // r1
  unsigned int v24; // kr14_4
  unsigned int v25; // r1
  _QWORD *v26; // r5
  int v27; // r7
  int v28; // r6
  _QWORD v30[21]; // [sp-4h] [bp-A8h] BYREF

  if ( (a1[47] & 2) == 0 )
  {
    PsQueryStatisticsProcess();
    v4 = *(_QWORD *)(a2 + 96);
    v5 = *(_QWORD *)(a2 + 88);
    *(_QWORD *)(a2 + 80) += *(_QWORD *)a2;
    *(_QWORD *)(a2 + 88) = *(_QWORD *)(a2 + 8) + v5;
    v6 = *(_QWORD *)(a2 + 104);
    *(_QWORD *)(a2 + 96) = *(_QWORD *)(a2 + 16) + v4;
    v7 = *(_QWORD *)(a2 + 112);
    *(_QWORD *)(a2 + 104) = *(_QWORD *)(a2 + 24) + v6;
    v8 = *(_QWORD *)(a2 + 120);
    *(_QWORD *)(a2 + 112) = *(_QWORD *)(a2 + 32) + v7;
    v9 = *(_QWORD *)(a2 + 128);
    *(_QWORD *)(a2 + 120) = *(_QWORD *)(a2 + 40) + v8;
    v10 = *(_QWORD *)(a2 + 136);
    *(_QWORD *)(a2 + 128) = *(_QWORD *)(a2 + 48) + v9;
    v11 = *(_QWORD *)(a2 + 144);
    *(_QWORD *)(a2 + 136) = *(_QWORD *)(a2 + 56) + v10;
    v12 = *(_QWORD *)(a2 + 152);
    *(_QWORD *)(a2 + 144) = *(_QWORD *)(a2 + 64) + v11;
    *(_QWORD *)(a2 + 152) = *(_QWORD *)(a2 + 72) + v12;
    *(_DWORD *)(a2 + 200) += a1[148];
    v13 = (_QWORD *)a1[194];
    if ( v13 )
    {
      *(_QWORD *)(a2 + 160) += *v13;
      *(_QWORD *)(a2 + 168) += v13[1];
      *(_QWORD *)(a2 + 176) += v13[2];
      *(_QWORD *)(a2 + 184) += v13[3];
      *(_QWORD *)(a2 + 192) += v13[4];
    }
    if ( PoEnergyEstimationEnabled() )
    {
      PsQueryProcessEnergyValues(a1, (int)v30);
      v14 = (_QWORD *)(a2 + 208);
      v15 = *(_DWORD *)(a2 + 280);
      *(_QWORD *)(a2 + 272) += v30[8];
      v16 = v15;
      v17 = *(_DWORD *)(a2 + 288);
      *(_QWORD *)(a2 + 280) = v30[9] + __PAIR64__(*(_DWORD *)(a2 + 284), v16);
      v18 = v17;
      v19 = *(_DWORD *)(a2 + 296);
      *(_QWORD *)(a2 + 288) = v30[10] + __PAIR64__(*(_DWORD *)(a2 + 292), v18);
      v20 = v19;
      v21 = *(_DWORD *)(a2 + 304);
      *(_QWORD *)(a2 + 296) = v30[11] + __PAIR64__(*(_DWORD *)(a2 + 300), v20);
      v22 = v21;
      v23 = *(_DWORD *)(a2 + 344);
      *(_QWORD *)(a2 + 304) = v30[12] + __PAIR64__(*(_DWORD *)(a2 + 308), v22);
      v24 = v23;
      v25 = *(_DWORD *)(a2 + 328);
      *(_QWORD *)(a2 + 344) = v30[17] + __PAIR64__(*(_DWORD *)(a2 + 348), v24);
      v26 = v30;
      *(_QWORD *)(a2 + 328) = v30[15] + __PAIR64__(*(_DWORD *)(a2 + 332), v25);
      v27 = 4;
      do
      {
        v28 = 2;
        do
        {
          *v14++ += *v26++;
          --v28;
        }
        while ( v28 );
        --v27;
      }
      while ( v27 );
    }
  }
  return 0;
}
