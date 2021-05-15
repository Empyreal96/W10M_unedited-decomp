// HvpRemapAndEnlistHiveBins 
 
int __fastcall HvpRemapAndEnlistHiveBins(int a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r8
  int v4; // r9
  int v5; // r0
  unsigned int v6; // r8
  __int64 v7; // r2
  _DWORD *v8; // r7
  int v9; // r10
  unsigned int v10; // r6
  int v11; // r0
  int v12; // r6
  unsigned int v14; // r3
  int v15; // r10
  int v16; // r6
  int v17; // r0
  int v18; // r1
  unsigned int v19; // r7
  int v20; // r3
  int v21; // r7
  int v22; // r0
  int v23; // r3
  int v24; // r6
  int v25; // r7
  int v26; // r0
  unsigned int v27; // r10
  __int64 v28; // r2
  int v29; // r1
  _DWORD *v30; // r0
  _DWORD *v31; // r6
  int v32; // r7
  int v33; // [sp+14h] [bp-54h]
  int v34; // [sp+18h] [bp-50h] BYREF
  int v35; // [sp+1Ch] [bp-4Ch] BYREF
  unsigned int v36; // [sp+20h] [bp-48h]
  int v37; // [sp+24h] [bp-44h] BYREF
  int v38; // [sp+28h] [bp-40h] BYREF
  unsigned int v39; // [sp+2Ch] [bp-3Ch]
  int v40; // [sp+30h] [bp-38h]
  int v41; // [sp+34h] [bp-34h]
  int v42; // [sp+38h] [bp-30h] BYREF
  int v43; // [sp+3Ch] [bp-2Ch] BYREF
  unsigned int v44; // [sp+40h] [bp-28h]
  unsigned int v45; // [sp+44h] [bp-24h]

  v44 = 0;
  v2 = 0;
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
  v33 = 0;
  v4 = 0;
  v45 = v3;
  if ( !v3 )
  {
LABEL_12:
    while ( 1 )
    {
      v14 = *(_DWORD *)(a1 + 952);
      if ( v2 >= v14 )
        break;
      v30 = (_DWORD *)HvpGetCellMap(a1, v2);
      v31 = v30;
      if ( !v30 )
        KeBugCheckEx(81, 1, a1, v2, 1878);
      v32 = v30[4];
      HvpFreeBin(a1, v32, 0, v30[1] & 0xFFFFFFF0, v30[2] & 0xFFFFFFF0);
      while ( v32 )
      {
        v31[1] = 0;
        v31[2] = 0;
        *v31 = 0;
        v31[4] = 0;
        v32 -= 4096;
        v2 += 4096;
        if ( !v32 )
          break;
        v31 = (_DWORD *)HvpGetCellMap(a1, v2);
        if ( !v31 )
          KeBugCheckEx(81, 1, a1, v2, 1905);
      }
    }
    if ( v3 < v14 )
      HvpFreeMap(a1, *(_DWORD *)(a1 + 956), ((v3 - 1) >> 21) + 1, (v14 - 1) >> 21);
    *(_DWORD *)(a1 + 952) = v3;
    if ( v33 )
      return 1073741833;
    v12 = 0;
LABEL_17:
    if ( v4 )
      (*(void (__fastcall **)(int, unsigned int))(a1 + 16))(v4, v44);
    return v12;
  }
  while ( 1 )
  {
    v5 = HvpGetCellMap(a1, v2);
    if ( !v5 )
      KeBugCheckEx(81, 1, a1, v2, 1461);
    v7 = *(_QWORD *)(v5 + 4);
    v6 = *(_DWORD *)(v5 + 16);
    HIDWORD(v7) &= 0xFFFFFFF0;
    v40 = HIDWORD(v7);
    v41 = v7;
    v8 = (_DWORD *)(HIDWORD(v7) ? HIDWORD(v7) : v7 & 0xFFFFFFF0);
    v9 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
    if ( !HvpValidateLoadedBin(v8, v2, v9) )
      break;
    v10 = v8[2];
    if ( v10 == v6 )
    {
      v11 = HvpEnlistBinInMap(a1, v9, v41 & 0xFFFFFFF0, v40, v2);
      v12 = v11;
      if ( v11 < 0 )
        return v12;
      if ( v11 == 1073741833 )
        return sub_803BD8();
      v2 += v8[2];
    }
    else if ( v10 >= v6 )
    {
      v21 = v6 + v2;
      while ( v6 < v10 )
      {
        v22 = HvpGetCellMap(a1, v21);
        if ( !v22 )
          KeBugCheckEx(81, 1, a1, v21, 1718);
        v23 = *(_DWORD *)(v22 + 16);
        v6 += v23;
        v21 += v23;
      }
      v12 = HvpAllocateBin(a1, v6, 0, v2, 825445699, &v37, &v38);
      if ( v12 < 0 )
        return v12;
      if ( v38 )
        v24 = v38;
      else
        v24 = v37;
      v36 = 0;
      v25 = v2;
      while ( v36 < v6 )
      {
        v26 = HvpGetCellMap(a1, v25);
        if ( !v26 )
          KeBugCheckEx(81, 1, a1, v25, 1765);
        v28 = *(_QWORD *)(v26 + 4);
        v27 = *(_DWORD *)(v26 + 16);
        HIDWORD(v28) &= 0xFFFFFFF0;
        v40 = HIDWORD(v28);
        v41 = v28;
        if ( HIDWORD(v28) )
          v29 = HIDWORD(v28);
        else
          v29 = v28 & 0xFFFFFFF0;
        if ( v24 != v29 )
        {
          memmove(v24, v29, v27);
          LODWORD(v28) = v41;
        }
        v36 += v27;
        v24 += v27;
        v25 += v27;
        HvpFreeBin(a1, v27, 0, v28 & 0xFFFFFFF0, v40);
      }
      HvpPointMapEntriesToBuffer(a1, v37, v38, v6, v2, 0);
      v37 = 0;
      v38 = 0;
    }
    else
    {
      v39 = v10 + v2;
      v44 = v10;
      v12 = HvpAllocateBin(a1, v10, 0, v2, 825445699, &v34, &v42);
      if ( v12 < 0 )
        return v12;
      v15 = v42;
      if ( v42 )
        v4 = v42;
      else
        v4 = v34;
      if ( v8 != (_DWORD *)v4 )
        memmove(v4, (int)v8, v8[2]);
      v36 = v8[2];
      v12 = HvpAllocateBin(a1, v6 - v36, 0, v39, 825445699, &v35, &v43);
      if ( v12 < 0 )
        goto LABEL_17;
      v16 = v43;
      if ( v43 )
        v17 = v43;
      else
        v17 = v35;
      v18 = (int)v8 + v8[2];
      v19 = v36;
      if ( v17 != v18 )
        memmove(v17, v18, v6 - v36);
      HvpPointMapEntriesToBuffer(a1, v35, v16, v6 - v19, v39, 0);
      v12 = HvpEnlistBinInMap(a1, *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40), v34, v15, v2);
      HvpFreeBin(a1, v6, 0, v41 & 0xFFFFFFF0, v40);
      if ( v12 == 1073741833 )
      {
        HvpMarkDirty(a1, v2, *(_DWORD *)(v4 + 8), 0);
        v33 = 1;
      }
      if ( v12 < 0 )
        return v12;
      v20 = *(_DWORD *)(v4 + 8);
      v4 = 0;
      v2 += v20;
      v34 = 0;
      v35 = 0;
      v42 = 0;
      v43 = 0;
    }
LABEL_11:
    v3 = v45;
    if ( v2 >= v45 )
      goto LABEL_12;
  }
  if ( CmpSelfHeal || (CmpBootType & 6) != 0 )
  {
    *v8 = 1852400232;
    v8[1] = v2;
    v8[8] = 4064;
    v8[2] = 4096;
    *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
    HvpMarkDirty(a1, v8[1], 4096, 0);
    v33 = 1;
    goto LABEL_11;
  }
  return -1073741492;
}
