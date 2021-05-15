// MmMapLockedPagesSpecifyCache 
 
int __fastcall MmMapLockedPagesSpecifyCache(int a1, char a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int v7; // r6
  unsigned int v10; // r6
  __int16 v11; // r3
  int *v12; // r8
  unsigned int v13; // r6
  int v14; // r2
  int v15; // r3
  int v16; // r7
  unsigned int v17; // r3
  unsigned int v18; // r9
  unsigned int v19; // r4
  unsigned int v20; // r7
  int v21; // r5
  int v22; // t1
  int v23; // r2
  int v24; // r3
  int v25; // r4
  int v26; // r4
  unsigned int v27; // r5
  __int16 v28; // r2
  __int16 v29; // r3
  int v31; // r0
  int v32; // r0
  unsigned __int16 v33; // r1
  int v34; // r3
  int v35; // r4
  int v36; // r0
  int v37; // r2
  unsigned int v38; // r4
  unsigned int v39; // r5
  int v40; // [sp+8h] [bp-48h]
  int v41; // [sp+Ch] [bp-44h]
  int v42; // [sp+10h] [bp-40h] BYREF
  int v43; // [sp+14h] [bp-3Ch]
  unsigned int v44; // [sp+18h] [bp-38h]
  unsigned int v45; // [sp+1Ch] [bp-34h]
  int v46; // [sp+20h] [bp-30h]
  unsigned int v47; // [sp+24h] [bp-2Ch]
  int v48; // [sp+28h] [bp-28h]
  unsigned int v49; // [sp+2Ch] [bp-24h]
  unsigned int v50; // [sp+30h] [bp-20h]

  v6 = *(_DWORD *)(a1 + 24);
  v7 = *(_DWORD *)(a1 + 16);
  v46 = a1;
  if ( a2 )
    return MiMapLockedPagesInUserSpace(a1, v6 + v7, a3);
  v10 = (*(_DWORD *)(a1 + 20) + (((_WORD)v6 + (_WORD)v7) & 0xFFFu) + 4095) >> 12;
  v11 = *(_WORD *)(a1 + 6);
  v12 = (int *)(a1 + 28);
  v44 = v10;
  if ( (v11 & 0x2000) == 0 && a5 )
    sub_50E394();
  if ( (a6 & 0x20) == 0 && !MiGetSystemPteAvailability(v10, a6 & 0x3FFFFFFF) )
    return 0;
  if ( MmProtectFreedNonPagedPool == 1 )
    JUMPOUT(0x50E39A);
  v13 = MiReservePtes(&dword_634D58, v10);
  if ( !v13 )
  {
    if ( (*(_WORD *)(a1 + 6) & 0x2000) == 0 && a5 )
      MiIssueNoPtesBugcheck(v44);
    return 0;
  }
  v50 = (unsigned int)&v12[v44];
  v47 = *(_DWORD *)(a1 + 24) + (v13 << 10);
  v40 = 0;
  v42 = 0;
  v14 = MiPlatformCacheAttributes[a3];
  v15 = MiPlatformCacheAttributes[a3 + 6];
  v43 = v14;
  v48 = v15;
  if ( a6 < 0 )
    v16 = 1;
  else
    v16 = 4;
  v41 = v16;
  if ( (a6 & 0x40000000) == 0 && (MiFlags & 0x30000) == 0 )
  {
    v16 |= 2u;
    v41 = v16;
  }
  if ( v14 )
  {
    if ( v14 == 2 )
    {
      v16 |= 0x18u;
      v41 = v16;
    }
  }
  else
  {
    v16 |= 8u;
    v41 = v16;
  }
  v17 = (MmProtectToPteMask[v16] | MiDetermineUserGlobalPteMask(v13)) & 0x3ED | 0xFFFFF012;
  v45 = v17;
  if ( (v17 & 0x80) != 0 )
  {
    v17 &= 0xFFFFFDFF;
    v45 = v17;
  }
  v18 = v13 + 0x40000000;
  v49 = 0x3FFFFF;
  do
  {
    v19 = *v12;
    LOWORD(v20) = v17;
    if ( *v12 <= (unsigned int)dword_633850
      && (!dword_634C9C || ((*(_DWORD *)(dword_634C9C + 4 * (v19 >> 5)) >> (v19 & 0x1F)) & 1) != 0) )
    {
      v21 = MmPfnDatabase + 24 * v19;
      if ( !*(_WORD *)(v21 + 16) )
        MiShowBadMapper(*v12, 1);
      if ( (*(_BYTE *)(v21 + 18) & 0xC0) == 192 )
        MiAssignInitialPageAttribute(v21, v43);
      if ( v43 != *(unsigned __int8 *)(v21 + 18) >> 6 )
      {
        v41 = MiMakeProtectionPfnCompatible(v41, v21);
        v20 = (MmProtectToPteMask[v41] | MiDetermineUserGlobalPteMask(v13)) & 0x3ED | 0xFFFFF012;
        if ( (v20 & 0x80) != 0 )
          LOWORD(v20) = v20 & 0xFDFF;
      }
      goto LABEL_25;
    }
    v31 = MiIoSpaceIsConstant(*v12, 1);
    if ( v31 )
    {
      v34 = *(_DWORD *)(v31 + 8);
    }
    else
    {
      if ( MiReferenceIoPages(1, v19, 1, v48, 0, &v42) < 0 )
      {
        v38 = v44;
        v39 = v47;
        MiZeroAndFlushPtes(v47, v44);
        MiReleasePtes(&dword_634D58, ((v39 >> 10) & 0x3FFFFC) - 0x40000000, v38);
        return 0;
      }
      v32 = v42;
      *(_WORD *)(v46 + 6) |= 0x800u;
      v33 = *(_WORD *)(*(_DWORD *)(v32 + 24) + 2 * (*v12 - *(_DWORD *)(v32 + 20)));
      __dmb(0xBu);
      v34 = v33 >> 14;
      v40 = v42;
    }
    v35 = v41 & 7;
    v41 = v35;
    if ( !v34 )
    {
      v35 |= 0x28u;
LABEL_50:
      v41 = v35;
      goto LABEL_51;
    }
    if ( v34 == 2 )
    {
      v35 |= 0x38u;
      goto LABEL_50;
    }
LABEL_51:
    v20 = (MmProtectToPteMask[v35] | MiDetermineUserGlobalPteMask(v13)) & 0x3ED | 0xFFFFF012;
    if ( (v20 & 0x80) != 0 )
      LOWORD(v20) = v20 & 0xFDFF;
LABEL_25:
    v22 = *v12++;
    v23 = v20 & 0xFFF | (v22 << 12);
    if ( v18 > v49 )
    {
      *(_DWORD *)v13 = v23;
    }
    else
    {
      v24 = *(_DWORD *)v13;
      v25 = 0;
      __dmb(0xBu);
      if ( (v24 & 2) == 0 )
        v25 = 1;
      *(_DWORD *)v13 = v23;
      if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
      {
        v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v36, (_DWORD *)(v36 + 4 * (v13 & 0xFFF)), v23);
      }
      if ( v25 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v13 += 4;
    v18 += 4;
    LOWORD(v17) = v45;
  }
  while ( (unsigned int)v12 < v50 );
  v26 = v46;
  v27 = v47;
  v28 = *(_WORD *)(v46 + 6);
  *(_DWORD *)(v46 + 12) = v47;
  *(_WORD *)(v26 + 6) = v28 | 1;
  if ( (dword_681258 & 1) != 0 )
  {
    v37 = v40 != 0;
    if ( MmProtectFreedNonPagedPool == 1 )
      v37 |= 2u;
    MiInsertPteTracker(v26, 0, v37, v43);
  }
  if ( v40 )
    MiMappingHasIoReferences(v27);
  v29 = *(_WORD *)(v26 + 6);
  if ( (v29 & 0x10) != 0 )
  {
    *(_WORD *)(v26 + 6) = v29 | 0x20;
    return v27;
  }
  return v27;
}
