// -StDeviceIoBuild@-$ST_STORE@USM_TRAITS@@@@SAPAU_ST_WORK_ITEM@1@PAU_ST_DATA_MGR@1@PAU_ST_PAGE_LOCATION@1@KPAX@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ST_STORE<SM_TRAITS>::StDeviceIoBuild(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r2
  int v6; // lr
  int v7; // r9
  int v8; // r10
  int v9; // r4
  int v10; // r2
  int v11; // r6
  int v12; // r3
  int v13; // r5
  int v14; // r0
  int v15; // r3
  int v16; // r7
  int v17; // r4
  int v18; // r2
  int v19; // r1 OVERLAPPED
  int v20; // r2 OVERLAPPED
  int v23; // [sp+4h] [bp-2Ch]

  v23 = 0;
  v4 = a1[76];
  v6 = LOWORD(a2[4 * a3 - 3]) + 16 * (a2[4 * a3 - 4] - *a2) + a1[28];
  v7 = *a2 >> a1[25];
  v8 = ((a1[22] - 1) & (16 * (a1[24] & *a2)))
     - ((((a1[22] - 1) & (16 * (a1[24] & *a2))) + a1[22] + v6 - 1) & (a1[22] - 1))
     + a1[22]
     + v6
     - 1;
  v9 = 16 * a3 + 12;
  if ( (*(_WORD *)(v4 + 2 * v7) & 0x4000) != 0 )
  {
    v10 = a1[77];
    if ( *(unsigned __int8 *)(v10 + v7) == 255 )
      return v23;
    ++*(_BYTE *)(v10 + v7);
  }
  else
  {
    *(_WORD *)(v4 + 2 * v7) |= 0x4000u;
  }
  v11 = 1;
  v12 = a1[168];
  if ( v12 )
  {
    v13 = a1[168];
    a1[168] = v12 | 1;
    goto LABEL_8;
  }
  v13 = ExAllocatePoolWithTag(512, a1[22] + v9 + v8);
  if ( v13 )
  {
LABEL_8:
    memset((_BYTE *)v13, 0, v9);
    *(_DWORD *)v13 = a3;
    memmove(v13 + 12, (int)a2, 16 * a3);
    v14 = SmCalcIoWorkItemSize(a1[23], (a1[22] + 16 * *(_DWORD *)v13 + v13 + 11) & ~(a1[22] - 1), v8);
    v15 = a1[169];
    v16 = v14;
    if ( v15 )
    {
      v17 = a1[169];
      a1[169] = v15 | 1;
    }
    else
    {
      v17 = ExAllocatePoolWithTag(512, v14);
      if ( !v17 )
        goto LABEL_12;
    }
    memset((_BYTE *)v17, 0, v16);
    v23 = v17;
    *(_DWORD *)v17 |= 7u;
    *(_DWORD *)(v17 + 4) = a4;
    *(_DWORD *)(v17 + 8) = v13;
    v13 = 0;
    *(_DWORD *)(v17 + 12) = *a2;
    *(_DWORD *)(v17 + 16) = a1[29] & 2 | *(_DWORD *)(v17 + 16) & 0x1D | (32 * v8);
    v11 = 0;
LABEL_12:
    if ( v13 )
    {
      v18 = a1[168];
      if ( (v18 & 1) != 0 && (v13 | 1) == v18 )
        a1[168] = v18 & 0xFFFFFFFE;
      else
        ExFreePoolWithTag(v13);
    }
  }
  if ( v11 )
  {
    *(_QWORD *)&v19 = *((_QWORD *)a1 + 38);
    if ( *(_BYTE *)(v20 + v7) )
      --*(_BYTE *)(v20 + v7);
    else
      *(_WORD *)(v19 + 2 * v7) &= 0xBFFFu;
  }
  return v23;
}
