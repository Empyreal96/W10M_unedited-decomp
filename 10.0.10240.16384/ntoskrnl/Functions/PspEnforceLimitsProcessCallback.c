// PspEnforceLimitsProcessCallback 
 
int __fastcall PspEnforceLimitsProcessCallback(int a1, int a2)
{
  int v4; // r6
  unsigned int v5; // r0
  unsigned int v6; // r1
  int v7; // r3
  unsigned int v8; // kr08_4
  unsigned int v9; // r1
  __int64 v10; // kr18_8
  unsigned int v11; // r0
  int v12; // r3
  unsigned int v13; // kr14_4
  unsigned int v14; // r1
  __int64 v15; // kr30_8
  unsigned int v16; // r0
  int v17; // r3
  unsigned int v18; // kr20_4
  unsigned int v19; // r1
  __int64 v20; // kr48_8
  unsigned int v21; // r0
  int v22; // r3
  unsigned int v23; // kr2C_4
  unsigned int v24; // r1
  __int64 v25; // kr58_8
  unsigned int v26; // r0
  int v27; // r3
  unsigned int v28; // kr38_4
  unsigned int v29; // r1
  __int64 v30; // kr60_8
  unsigned int v31; // r0
  int v32; // r3
  unsigned int v33; // kr44_4
  unsigned int v34; // r1
  __int64 v35; // kr68_8
  unsigned int v36; // r0
  int v37; // r3
  unsigned int v38; // kr50_4
  unsigned int v39; // r1
  __int64 v40; // kr70_8
  unsigned int v41; // r0
  int result; // r0
  __int64 v43; // [sp+0h] [bp-68h]
  __int64 v44; // [sp+8h] [bp-60h]
  __int64 v45; // [sp+10h] [bp-58h]
  __int64 v46; // [sp+18h] [bp-50h]
  __int64 v47; // [sp+20h] [bp-48h]
  __int64 v48; // [sp+28h] [bp-40h]
  __int64 v49; // [sp+30h] [bp-38h]
  __int64 v50; // [sp+38h] [bp-30h]
  __int64 v51; // [sp+40h] [bp-28h]
  __int64 v52; // [sp+48h] [bp-20h]

  if ( (*(_DWORD *)(a1 + 188) & 2) != 0 )
    goto LABEL_4;
  PsQueryStatisticsProcess();
  v4 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  v5 = *(_DWORD *)(v4 + 620);
  v6 = *(_DWORD *)(v4 + 616);
  *(_QWORD *)(v4 + 600) += v43;
  *(_QWORD *)(v4 + 608) += v44;
  v8 = v6;
  v7 = v45 + v6;
  v9 = *(_DWORD *)(v4 + 624);
  *(_DWORD *)(v4 + 616) = v7;
  v10 = v45 + __PAIR64__(v5, v8);
  v11 = *(_DWORD *)(v4 + 628);
  *(_DWORD *)(v4 + 620) = HIDWORD(v10);
  v13 = v9;
  v12 = v46 + v9;
  v14 = *(_DWORD *)(v4 + 632);
  *(_DWORD *)(v4 + 624) = v12;
  v15 = v46 + __PAIR64__(v11, v13);
  v16 = *(_DWORD *)(v4 + 636);
  *(_DWORD *)(v4 + 628) = HIDWORD(v15);
  v18 = v14;
  v17 = v47 + v14;
  v19 = *(_DWORD *)(v4 + 640);
  *(_DWORD *)(v4 + 632) = v17;
  v20 = v47 + __PAIR64__(v16, v18);
  v21 = *(_DWORD *)(v4 + 644);
  *(_DWORD *)(v4 + 636) = HIDWORD(v20);
  v23 = v19;
  v22 = v48 + v19;
  v24 = *(_DWORD *)(v4 + 648);
  *(_DWORD *)(v4 + 640) = v22;
  v25 = v48 + __PAIR64__(v21, v23);
  v26 = *(_DWORD *)(v4 + 652);
  *(_DWORD *)(v4 + 644) = HIDWORD(v25);
  v28 = v24;
  v27 = v49 + v24;
  v29 = *(_DWORD *)(v4 + 656);
  *(_DWORD *)(v4 + 648) = v27;
  v30 = v49 + __PAIR64__(v26, v28);
  v31 = *(_DWORD *)(v4 + 660);
  *(_DWORD *)(v4 + 652) = HIDWORD(v30);
  v33 = v29;
  v32 = v50 + v29;
  v34 = *(_DWORD *)(v4 + 664);
  *(_DWORD *)(v4 + 656) = v32;
  v35 = v50 + __PAIR64__(v31, v33);
  v36 = *(_DWORD *)(v4 + 668);
  *(_DWORD *)(v4 + 660) = HIDWORD(v35);
  v38 = v34;
  v37 = v51 + v34;
  v39 = *(_DWORD *)(v4 + 672);
  *(_DWORD *)(v4 + 664) = v37;
  v40 = v51 + __PAIR64__(v36, v38);
  v41 = *(_DWORD *)(v4 + 676);
  *(_DWORD *)(v4 + 668) = HIDWORD(v40);
  *(_QWORD *)(v4 + 672) = v52 + __PAIR64__(v41, v39);
  if ( *(_DWORD *)(a2 + 12) || !*(_QWORD *)a2 )
LABEL_4:
    result = 0;
  else
    result = sub_7C2D08();
  return result;
}
