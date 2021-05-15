// HvIsCellAllocated 
 
int __fastcall HvIsCellAllocated(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r9
  unsigned int v7; // r7
  int v8; // r1
  int v9; // r3
  _DWORD *v10; // r7
  int v11; // r0
  int *v12; // r4
  int v13; // r0
  int v14; // r3
  unsigned int v15; // r6
  unsigned int v16; // r4
  unsigned int v17; // r2
  unsigned int v19; // r1
  int v20; // [sp+0h] [bp-28h] BYREF
  int v21; // [sp+4h] [bp-24h] BYREF
  _DWORD v22[8]; // [sp+8h] [bp-20h] BYREF

  v20 = a1;
  v22[0] = a3;
  v22[1] = a4;
  v21 = -1;
  v4 = 1;
  if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
    return 1;
  v7 = a2 >> 31;
  if ( (a2 & 0x7FFFFFFF) >= *(_DWORD *)(a1 + 412 * (a2 >> 31) + 952) || (a2 & 7) != 0 )
    return 0;
  if ( a3 && (a2 & 0x80000000) == 0 )
  {
    v19 = a2 >> 3;
    if ( ((*(int *)(*(_DWORD *)(a3 + 4) + 4 * (a2 >> 8)) >> ((unsigned __int8)a2 >> 3)) & 1) == 0 )
      return 0;
    RtlClearBits((_BYTE *)a3, v19, 1u);
  }
  v8 = a1 + 412 * v7;
  if ( a2 + (v7 << 31) >= *(_DWORD *)(v8 + 952) )
    return 0;
  v9 = *(_DWORD *)(*(_DWORD *)(v8 + 956) + 4 * ((a2 >> 21) & 0x3FF));
  v10 = (_DWORD *)(v9 + 20 * ((a2 >> 12) & 0x1FF));
  if ( !v10 || HvpMapEntryIsDiscardable(v9 + 20 * ((a2 >> 12) & 0x1FF)) )
    return 0;
  v11 = (*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, a2, &v21);
  if ( !v11 )
    return 1;
  v12 = (int *)(v11 - 4);
  if ( v11 == 4 )
    return 1;
  v13 = HvpMapEntryGetBinAddress(v11, v10, (char *)&v20, v22);
  v14 = *v12;
  v15 = (unsigned int)v12 - v13;
  v16 = -*v12;
  if ( v14 >= 0 || v16 - 8 > 0xFFFF8 || (v17 = *(_DWORD *)(v13 + 8), v16 > v17 - 32) || v16 + v15 > v17 || v15 < 0x20 )
    v4 = 0;
  if ( (_BYTE)v20 )
    HvpMapEntryReleaseBinAddress(v13, (int)v10);
  HvpReleaseHCell(a1);
  return v4;
}
