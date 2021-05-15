// HvpFindFreeCell 
 
int __fastcall HvpFindFreeCell(int a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r10
  int v8; // r4
  int v10; // r8
  unsigned int v11; // r3
  int v12; // r4
  unsigned int v13; // r2
  unsigned int *v14; // r3
  int v15; // r5
  int v16; // r9
  unsigned int v17; // r0
  int v18; // r7
  int v19; // r0
  _DWORD *v20; // r5
  BOOL v21; // r0
  BOOL v22; // r0
  int v23; // r0
  unsigned int v24; // r0
  int v26; // r0
  unsigned int v27; // r2
  int v28; // r7
  unsigned int v29; // r3
  unsigned int v30; // r2
  char v31[4]; // [sp+10h] [bp-48h] BYREF
  unsigned int v32; // [sp+14h] [bp-44h]
  unsigned int *v33; // [sp+18h] [bp-40h]
  int v34; // [sp+1Ch] [bp-3Ch]
  int v35; // [sp+20h] [bp-38h]
  int v36; // [sp+24h] [bp-34h]
  int v37; // [sp+28h] [bp-30h]
  unsigned int v38; // [sp+2Ch] [bp-2Ch] BYREF
  int v39; // [sp+30h] [bp-28h]
  int v40[9]; // [sp+34h] [bp-24h] BYREF

  v6 = 412 * a4;
  v37 = a4;
  v8 = *(_DWORD *)(412 * a4 + a1 + 1360);
  v39 = a3;
  v10 = v8 & ~((1 << a2) - 1);
  v34 = 412 * a4;
  if ( v10 )
  {
    v11 = __clz(__rbit(v10));
    if ( v11 != a2 )
      a2 = v11;
    v12 = -1;
    v13 = *(_DWORD *)(v6 + 16 * a2 + a1 + 972);
    v36 = v6 + 16 * a2 + a1;
    v14 = (unsigned int *)(v6 + 16 * (a2 + 61) + a1);
    v15 = -a4;
    v35 = -a4;
    v16 = -1;
    v33 = v14;
    while ( 1 )
    {
      v17 = RtlFindSetBits(v14, 1u, v13);
      *(_DWORD *)(v36 + 972) = v17;
      v32 = v17 + 1;
      if ( v16 == v17 )
      {
        v10 &= v10 - 1;
        if ( !v10 )
          return v12;
        v27 = __clz(__rbit(v10));
        v28 = v6 + 16 * v27 + a1;
        v29 = v6 + 16 * (v27 + 61);
        v30 = *(_DWORD *)(v28 + 972);
        v36 = v28;
        v33 = (unsigned int *)(v29 + a1);
        v17 = RtlFindSetBits((unsigned int *)(v29 + a1), 1u, v30);
        v32 = v17 + 1;
        *(_DWORD *)(v28 + 972) = v17;
        v16 = v17;
      }
      v18 = (v17 << 12) + (v15 << 31);
      if ( v16 == -1 )
        v16 = v17;
      v38 = (v17 << 12) + (v15 << 31);
      v19 = HvpGetCellMap(a1, v38);
      v20 = (_DWORD *)v19;
      if ( !v19 )
        KeBugCheckEx(81, 1, a1, v18, 1078);
      v21 = HvpMapEntryIsDiscardable(v19);
      v13 = v32;
      v14 = v33;
      if ( v21 )
        goto LABEL_20;
      v22 = HvpMapEntryIsTrimmed((int)v20);
      v13 = v32;
      v14 = v33;
      if ( v22 )
        goto LABEL_20;
      v23 = HvpMapEntryIsNewAlloc((int)v20);
      v13 = v32;
      v14 = v33;
      if ( !v23 )
        goto LABEL_20;
      v24 = HvpMapEntryGetBinAddress(v23, v20, v31, v40);
      if ( *(_BYTE *)(a1 + 2560) )
        return sub_8042DC(v24);
      v26 = HvpFindFreeCellInBin(a1, v39, v37, v24, &v38, a5, a6);
      if ( v26 >= 0 )
      {
        if ( v31[0] )
          HvpMapEntryReleaseBinAddress(v26, (int)v20);
        return v38;
      }
      if ( v26 != -1073741275 )
      {
        if ( v31[0] )
          HvpMapEntryReleaseBinAddress(v26, (int)v20);
        return v12;
      }
      v6 = v34;
      v13 = v32;
      v14 = v33;
      if ( v31[0] )
        break;
LABEL_21:
      v15 = v35;
    }
    HvpMapEntryReleaseBinAddress(-1073741275, (int)v20);
    v13 = v32;
    v31[0] = 0;
    v14 = v33;
LABEL_20:
    v6 = v34;
    goto LABEL_21;
  }
  return -1;
}
