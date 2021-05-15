// -StDmDeviceIoListBuild@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_PAGE_LOCATION@1@KPAXPAU_PF_QUEUE@@PAK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmDeviceIoListBuild(_DWORD *a1, unsigned int a2, unsigned int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r10
  unsigned int v7; // r4
  unsigned int v9; // r7
  unsigned int v11; // r0
  unsigned int *v12; // r5
  unsigned int v13; // r1
  int v14; // r9
  unsigned int v15; // r3
  int v16; // r5
  int v17; // r6
  unsigned int v18; // r0
  int v19; // r0
  int v20; // r10
  int v21; // r6
  __int64 v22; // r0
  int v23; // r0
  int v24; // r5
  int *v25; // r1
  int *v26; // r4
  int v27; // r5
  int i; // r4
  __int64 v29; // r0
  int v30; // r5
  int v31; // r4
  int *v32; // r2
  int v33; // r3
  int v35; // [sp+0h] [bp-38h]
  unsigned int v37; // [sp+8h] [bp-30h]
  unsigned int v38; // [sp+10h] [bp-28h] BYREF
  unsigned int *v39; // [sp+14h] [bp-24h]

  v39 = &v38;
  v6 = a4;
  v7 = a2 + 16;
  v9 = a2 + 16 * a3;
  v11 = *(_DWORD *)a2;
  v12 = (unsigned int *)(a2 + 16);
  v38 = 0;
  v35 = 0;
  if ( a2 + 16 < v9 )
  {
    do
    {
      v13 = *v12;
      if ( *v12 < v11 )
        break;
      v12 += 4;
      v11 = v13;
    }
    while ( (unsigned int)v12 < v9 );
    if ( (unsigned int)v12 < v9 )
      qsort(a2, a3, 0x10u, (int (__fastcall *)(unsigned int, _BYTE *))ST_STORE<SM_TRAITS>::StpLocationCompare);
  }
  v14 = *(_DWORD *)a2 >> a1[25];
  v15 = *(_DWORD *)a2 + ((a1[28] + (unsigned int)*(unsigned __int16 *)(a2 + 4) + 15) >> 4);
  v16 = 1;
  while ( v7 < v9 )
  {
    v17 = v14;
    v18 = *(_DWORD *)v7 - v15;
    v14 = *(_DWORD *)v7 >> a1[25];
    v15 = *(_DWORD *)v7 + ((a1[28] + (unsigned int)*(unsigned __int16 *)(v7 + 4) + 15) >> 4);
    v37 = v15;
    if ( v18 <= 0x400 && v17 == v14 )
    {
      ++v16;
    }
    else
    {
      v19 = ST_STORE<SM_TRAITS>::StDeviceIoBuild(a1, (_DWORD *)(v7 - 16 * v16), v16, v6);
      if ( !v19 )
        goto LABEL_18;
      *(_DWORD *)v19 = *(_DWORD *)v19 & 7 | (8 * ((*v39 >> 3) + 1));
      *v39 = *v39 & 7 | v19;
      v20 = a1[69];
      v39 = (unsigned int *)v19;
      v21 = *(_DWORD *)(v20 + 16);
      v16 = 1;
      while ( *(_DWORD *)v21 < *(_DWORD *)(v19 + 16) >> 5 )
        v21 += 32;
      ++*(_WORD *)(v21 + 4);
      LODWORD(v22) = KeQueryInterruptTime();
      *(_QWORD *)(v20 + 32) = v22;
      v6 = a4;
      v15 = v37;
      v35 += *(_DWORD *)(v21 + 8);
    }
    v7 += 16;
  }
  v23 = ST_STORE<SM_TRAITS>::StDeviceIoBuild(a1, (_DWORD *)(v7 - 16 * v16), v16, v6);
  if ( v23 )
  {
    *(_DWORD *)v23 = *(_DWORD *)v23 & 7 | (8 * ((*v39 >> 3) + 1));
    *v39 = *v39 & 7 | v23;
    v27 = a1[69];
    v39 = (unsigned int *)v23;
    for ( i = *(_DWORD *)(v27 + 16); *(_DWORD *)i < *(_DWORD *)(v23 + 16) >> 5; i += 32 )
      ;
    ++*(_WORD *)(i + 4);
    LODWORD(v29) = KeQueryInterruptTime();
    *(_QWORD *)(v27 + 32) = v29;
    v25 = (int *)v39;
    v30 = *(_DWORD *)(i + 8) + v35;
    if ( *v39 >> 3 )
    {
      v31 = (*v39 >> 3) + (**(_DWORD **)(a5 + 4) >> 3);
      *v39 = *(_DWORD *)a5 | *v39 & 7;
      *(_DWORD *)a5 = v38;
      if ( *(_DWORD *)(a5 + 4) == a5 )
        *(_DWORD *)(a5 + 4) = v39;
      v32 = *(int **)(a5 + 4);
      v25 = (int *)&v38;
      v33 = *v32 & 7 | (8 * v31);
      v26 = 0;
      *v32 = v33;
      v38 = 0;
      v39 = &v38;
    }
    else
    {
      v26 = (int *)v38;
    }
    *a6 = v30;
    v24 = 0;
    goto LABEL_29;
  }
LABEL_18:
  v24 = -1073741670;
  while ( 1 )
  {
    v26 = (int *)v38;
    v25 = (int *)v39;
LABEL_29:
    if ( v25 == (int *)&v38 )
      break;
    v38 = *v26 & 0xFFFFFFF8;
    if ( v26 == v25 )
    {
      v39 = &v38;
      v38 = 0;
    }
    else
    {
      *v25 = *v25 & 7 | (8 * ((unsigned int)*v25 >> 3) - 8);
    }
    ST_STORE<SM_TRAITS>::StDeviceWorkItemCleanup(a1, (int)v26);
  }
  return v24;
}
