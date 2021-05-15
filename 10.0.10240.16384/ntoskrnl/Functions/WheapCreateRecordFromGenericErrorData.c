// WheapCreateRecordFromGenericErrorData 
 
int __fastcall WheapCreateRecordFromGenericErrorData(int a1, unsigned int *a2, int a3, unsigned int a4)
{
  _DWORD *v7; // r5
  unsigned int v8; // r4
  unsigned int v9; // r3
  unsigned int v10; // r6
  unsigned int v11; // r3
  int v12; // r2
  unsigned int v13; // r2
  int v14; // r4
  unsigned int v16; // r1
  int v17; // r2
  unsigned int v18; // r3
  int v19; // r10
  unsigned int v20; // r2
  unsigned int v21; // r7
  int v22; // r3
  unsigned int v23; // r2

  v7 = (unsigned int *)((char *)a2 + a2[16]);
  v8 = a2[17];
  if ( v8 < 0x14 )
    goto LABEL_8;
  v9 = v7[3];
  v10 = v9 + 20;
  if ( v9 >= 0xFFFFFFEC )
    goto LABEL_8;
  v11 = v7[1];
  if ( v11 && (v12 = v7[2]) != 0 )
  {
    if ( v10 > v11 )
      goto LABEL_8;
    v13 = v12 + v11;
    if ( v13 < v11 || v13 > v8 )
      goto LABEL_8;
  }
  else if ( v10 > v8 )
  {
LABEL_8:
    v14 = -1073741811;
    goto LABEL_9;
  }
  if ( a4 < 0x80 )
    goto LABEL_8;
  memset((_BYTE *)a3, 0, a4);
  WheaInitializeRecordHeader(a3);
  v16 = 20;
  *(_DWORD *)(a3 + 12) = a2[5];
  *(_DWORD *)(a3 + 80) = a2[8];
  *(_DWORD *)(a3 + 84) = a2[9];
  *(_DWORD *)(a3 + 88) = a2[10];
  *(_DWORD *)(a3 + 92) = a2[11];
  v17 = ((unsigned __int8)*(_DWORD *)(a3 + 104) ^ (unsigned __int8)(2 * *((_BYTE *)a2 + 12))) & 2 ^ *(_DWORD *)(a3 + 104);
  *(_DWORD *)(a3 + 104) = v17;
  v18 = a2[3];
  *(_DWORD *)(a3 + 20) = a4;
  *(_DWORD *)(a3 + 104) = ((unsigned __int8)v17 ^ (unsigned __int8)(v18 >> 1)) & 4 ^ v17;
  v19 = (*v7 >> 4) & 0x3FF;
  if ( v19 )
  {
    while ( v16 + 64 >= v16 )
    {
      if ( v16 + 64 > v10 )
        break;
      v20 = *(_DWORD *)((char *)v7 + v16 + 24) + 64;
      if ( *(_DWORD *)((char *)v7 + v16 + 24) >= 0xFFFFFFC0 )
        break;
      v21 = v20 + v16;
      if ( v20 + v16 < v16 || v21 > v10 )
        break;
      v14 = WheapAddSectionFromGenericErrorData(a1, a3, a4, (int)v7 + v16, v20, 1);
      if ( v14 < 0 )
        goto LABEL_9;
      v16 = v21;
      if ( !--v19 )
        goto LABEL_21;
    }
    goto LABEL_8;
  }
LABEL_21:
  v22 = v7[1];
  if ( !v22 )
    return 0;
  v23 = v7[2];
  if ( !v23 )
    return 0;
  v14 = WheapAddSectionFromGenericErrorData(a1, a3, a4, (int)v7 + v22, v23, 0);
  if ( v14 >= 0 )
    return 0;
LABEL_9:
  WheapSqmDwordCommon(6, WHEA_SQM_EVENT_INCREMENTDWORD, 7203, 1);
  return v14;
}
