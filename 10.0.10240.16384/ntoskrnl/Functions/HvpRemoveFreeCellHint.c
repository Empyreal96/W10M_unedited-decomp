// HvpRemoveFreeCellHint 
 
void *__fastcall HvpRemoveFreeCellHint(int a1, int a2, int a3, int a4)
{
  int v6; // r9
  _DWORD *v7; // r0
  int v8; // r10
  unsigned int v9; // r6
  unsigned int v10; // r0
  unsigned int v11; // r2
  unsigned int *v12; // r1
  unsigned int v13; // r5
  unsigned int v14; // r4
  unsigned int v15; // r2
  int v16; // r1
  unsigned int v17; // r5
  int v18; // r6
  int v19; // r4
  void *result; // r0
  int v21; // r1
  unsigned int v22; // r3
  unsigned int v23; // r3
  int v24; // r4
  char v25[4]; // [sp+8h] [bp-30h] BYREF
  unsigned int v26; // [sp+Ch] [bp-2Ch] BYREF
  int v27; // [sp+10h] [bp-28h]
  int v28; // [sp+14h] [bp-24h]

  v27 = a4;
  v28 = a2;
  v6 = 0;
  v7 = (_DWORD *)HvpGetCellMap(a1, a2);
  v8 = (int)v7;
  if ( !v7 )
    sub_804028();
  v9 = HvpMapEntryGetBinAddress((int)v7, v7, v25, &v26);
  v11 = *(_DWORD *)(v9 + 8);
  v10 = *(_DWORD *)(v9 + 4);
  v12 = (unsigned int *)(v9 + 32);
  v13 = v11 + v9;
  v14 = v10 + 32;
  v26 = v11;
  if ( v9 + 32 >= v11 + v9 )
    goto LABEL_8;
  while ( 1 )
  {
    v15 = *v12;
    if ( (*v12 & 0x80000000) == 0 )
      break;
    v15 = -v15;
LABEL_6:
    v12 = (unsigned int *)((char *)v12 + v15);
    v14 += v15;
    if ( (unsigned int)v12 >= v13 )
      goto LABEL_7;
  }
  v22 = (v15 >> 3) - 1;
  if ( v22 >= 0x10 )
  {
    v23 = v22 >> 4;
    if ( v23 > 0xFF )
      v22 = 23;
    else
      v22 = 47 - __clz(v23);
  }
  if ( a3 != v22 || v14 == (v28 & 0x7FFFFFFF) )
    goto LABEL_6;
  v6 = 1;
LABEL_7:
  v11 = v26;
LABEL_8:
  v16 = v27;
  v17 = v10 >> 12;
  if ( v6 )
  {
    v24 = 412 * v27;
    *(_DWORD *)(412 * v27 + a1 + 1360) |= 1 << a3;
    *(_DWORD *)(412 * v16 + 16 * a3 + a1 + 972) = v17;
    result = RtlSetBits((_BYTE *)(v24 + 16 * (a3 + 61) + a1), v17, *(_DWORD *)(v9 + 8) >> 12);
  }
  else
  {
    v18 = 412 * v27;
    v19 = 412 * v27 + 16 * (a3 + 61);
    RtlClearBits((_BYTE *)(v19 + a1), v17, v11 >> 12);
    result = (void *)RtlFindSetBits((unsigned int *)(v19 + a1), 1u, v17);
    v21 = v18 + a1;
    if ( result == (void *)-1 )
    {
      *(_DWORD *)(v21 + 1360) &= ~(1 << a3);
    }
    else
    {
      *(_DWORD *)(v21 + 1360) |= 1 << a3;
      *(_DWORD *)(v18 + 16 * a3 + a1 + 972) = result;
    }
  }
  if ( v25[0] )
    result = HvpMapEntryReleaseBinAddress((int)result, v8);
  return result;
}
