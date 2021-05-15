// -SmStEtwFillStoreStatsEvent@-$SMKM_STORE@USM_TRAITS@@@@SAKPAU1@PAU_SMKM_EVENT_DESCRIPTOR@@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStEtwFillStoreStatsEvent(_DWORD *a1, _DWORD *a2)
{
  int v3; // r3
  int result; // r0
  _DWORD *v6; // r4
  _DWORD *v7; // r3
  int v8; // r2
  int v9; // r3
  _DWORD *v10; // r1
  _DWORD *v11; // r3
  int v12; // r1
  int v13; // r3
  int v14; // r2
  int v15; // r3
  unsigned int *v16; // r4
  unsigned int **v17; // r3
  int v18; // r1

  v3 = a1[184];
  result = 0;
  if ( v3 )
  {
    v6 = (_DWORD *)(a2[4] + a2[1]);
    *v6 = a1;
    v7 = (_DWORD *)(*a2 + 16 * a2[2]);
    *v7 = v6;
    v7[1] = 0;
    v7[2] = 4;
    v7[3] = 0;
    ++a2[2];
    v8 = a2[4] + 4;
    v9 = a2[1];
    a2[4] = v8;
    v10 = (_DWORD *)(v8 + v9);
    *v10 = 1348;
    v11 = (_DWORD *)(*a2 + 16 * a2[2]);
    *v11 = v10;
    v11[1] = 0;
    v11[2] = 4;
    v11[3] = 0;
    v12 = a2[2] + 1;
    v13 = a2[4];
    a2[2] = v12;
    v14 = v13 + 4;
    v15 = a2[1];
    a2[4] = v14;
    v16 = (unsigned int *)(v14 + v15);
    v17 = (unsigned int **)(*a2 + 16 * v12);
    *v17 = v16;
    v17[1] = 0;
    v17[2] = (unsigned int *)1348;
    v17[3] = 0;
    ++a2[2];
    a2[4] += 1348;
    ST_STORE<SM_TRAITS>::StCopyIoStats(v16, (int)(a1 + 458));
    StLcBucketsCopy(v16 + 321, v18, a1[784], a1[783]);
    result = 1;
  }
  return result;
}
