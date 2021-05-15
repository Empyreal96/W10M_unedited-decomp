// HvpDropPagedBins 
 
int __fastcall HvpDropPagedBins(int a1, int a2, int a3)
{
  char v3; // r3
  int v4; // r7
  int v6; // r9
  unsigned int v7; // r10
  int v9; // r8
  int v10; // r6
  int v11; // r5
  unsigned int v12; // r3
  int v13; // r0
  unsigned int v14; // r2
  unsigned int v15; // r6
  int v16; // r0
  unsigned int v17; // r0
  _DWORD *v18; // r1
  unsigned int v19; // r0
  int v20; // r5
  unsigned int v21; // r0
  unsigned int v22; // r0
  char v23[4]; // [sp+10h] [bp-40h] BYREF
  int v24; // [sp+14h] [bp-3Ch] BYREF
  int v25; // [sp+18h] [bp-38h]
  int v26; // [sp+1Ch] [bp-34h] BYREF
  unsigned int v27; // [sp+20h] [bp-30h]
  unsigned int v28; // [sp+24h] [bp-2Ch]
  int v29; // [sp+28h] [bp-28h] BYREF
  unsigned int v30; // [sp+2Ch] [bp-24h]

  v23[0] = 0;
  v29 = -1;
  v3 = *(_BYTE *)(a1 + 72);
  v4 = 0;
  v24 = 0;
  v6 = 0;
  v26 = 0;
  v7 = 0;
  if ( (v3 & 4) != 0 )
    return sub_80B288();
  v9 = (*(_DWORD *)(a1 + 92) & 0x10) == 0;
  if ( HvpIsHiveEligibleForSystemCacheBacking(a1, a2, a3) )
    v10 = 2;
  else
    v10 = 1;
  if ( v9 == v10 )
    goto LABEL_33;
  if ( v10 != 2 )
  {
LABEL_9:
    v12 = *(_DWORD *)(a1 + 952);
    v27 = v12;
    if ( v12 )
    {
      if ( v9 )
      {
        v14 = 0;
      }
      else
      {
        v13 = HvpGetCellMap(a1, 0);
        if ( !v13 )
          KeBugCheckEx(81, 1, a1, 0, 5669);
        v14 = *(_DWORD *)(v13 + 16);
        v12 = v27;
      }
      v28 = v14;
      if ( v10 == 1 )
      {
        v12 = v14;
        v27 = v14;
      }
      v15 = 0;
      if ( v12 )
      {
        do
        {
          v16 = HvpGetCellMap(a1, v15);
          if ( !v16 )
            KeBugCheckEx(81, 1, a1, v15, 5693);
          v17 = HvpMapEntryGetFreeBin(v16);
          v30 = v17;
          if ( !v17 || (*(_DWORD *)(v17 + 16) & 1) != 0 )
          {
            v19 = HvpMapEntryGetBinAddress(v17, v18, v23, &v29);
            v7 = *(_DWORD *)(v19 + 8);
            v25 = v19;
            v11 = HvpAllocateBin(a1, v7, 0, v15, 892489027, &v26, &v24);
            v6 = v26;
            v4 = v24;
            if ( v11 < 0 )
              goto LABEL_39;
            if ( v24 )
              v26 = v24;
            if ( (*(_BYTE *)(a1 + 72) & 4) != 0
              && (!RtlAreBitsClear((unsigned int *)(a1 + 36), v15 >> 9, v7 >> 9)
               || !RtlAreBitsClear((unsigned int *)(a1 + 52), v15 >> 9, v7 >> 9)) )
            {
              v11 = HvViewMapPinForFileOffset(a1 + 152, v15 + 4096, v7);
              if ( v11 < 0 )
                goto LABEL_39;
            }
            if ( v26 == v4 || (*(_BYTE *)(a1 + 72) & 4) == 0 )
            {
              v20 = v25;
              memmove(v26, v25, v7);
            }
            else
            {
              if ( !RtlAreBitsClear((unsigned int *)(a1 + 36), v15 >> 9, v7 >> 9)
                || !RtlAreBitsClear((unsigned int *)(a1 + 52), v15 >> 9, v7 >> 9) )
              {
                v11 = HvViewMapCopyToFileOffset(a1 + 152, v15 + 4096, v25, v7);
                if ( v11 < 0 )
                  goto LABEL_39;
              }
              v20 = v25;
            }
            HvpPointMapEntriesToBuffer(a1, v6, v4, v7, v15, v30);
            v6 = 0;
            v4 = 0;
            v26 = 0;
            v24 = 0;
            if ( v15 >= v28 )
              (*(void (__fastcall **)(int, unsigned int))(a1 + 16))(v20, v7);
            v15 += v7;
          }
          else
          {
            v15 += *(_DWORD *)(v17 + 8);
          }
        }
        while ( v15 < v27 );
      }
    }
LABEL_33:
    v11 = 0;
    if ( !v9 )
    {
      __dmb(0xBu);
      do
      {
        v21 = __ldrex((unsigned int *)&CmpPreloadedHivesCount);
        v22 = v21 - 1;
      }
      while ( __strex(v22, (unsigned int *)&CmpPreloadedHivesCount) );
      __dmb(0xBu);
      if ( !v22 )
        MmFreeBootRegistry();
      *(_DWORD *)(a1 + 92) &= 0xFFFFFFEF;
LABEL_39:
      if ( v6 || v4 )
        HvpFreeBin(a1, v7, 0, v6, v4);
    }
    return v11;
  }
  v11 = HvViewMapStart(a1 + 152, a1, *(_DWORD *)(a1 + 1776), *(_DWORD *)(a1 + 1944), 1);
  if ( v11 >= 0 )
  {
    *(_BYTE *)(a1 + 72) |= 4u;
    goto LABEL_9;
  }
  return v11;
}
