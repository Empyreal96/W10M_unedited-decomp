// MiMapContiguousMemory 
 
int __fastcall MiMapContiguousMemory(__int64 a1, int a2, unsigned int a3, int a4)
{
  int v4; // r6
  unsigned int v5; // r7
  unsigned int v6; // r4
  int v7; // r5
  int v8; // r9
  int v9; // r3
  unsigned int v10; // r8
  int v11; // r0
  int v12; // r2
  int v13; // r0
  unsigned int v14; // r6
  int v15; // r7
  unsigned int v16; // r2
  int v17; // r2
  int v18; // r5
  int v19; // r1
  unsigned int v20; // r4
  unsigned int v21; // r3
  unsigned int v22; // r10
  int v23; // lr
  int v24; // r4
  int v25; // r1
  int v26; // r1
  int v27; // r3
  int v28; // r3
  int v29; // r3
  int v30; // r5
  bool v31; // zf
  int v32; // r4
  int v33; // r5
  unsigned int v35; // r4
  int v36; // r0
  int v37; // r3
  unsigned int v38; // r4
  int v39; // r5
  unsigned __int16 v40; // r1
  int v41; // r0
  int v42; // r0
  int v43; // r2
  int v44; // [sp+8h] [bp-88h]
  int v45; // [sp+8h] [bp-88h]
  int v46; // [sp+Ch] [bp-84h]
  int v47; // [sp+10h] [bp-80h]
  int v48; // [sp+14h] [bp-7Ch] BYREF
  int v49; // [sp+18h] [bp-78h]
  int v50; // [sp+1Ch] [bp-74h]
  unsigned int v51; // [sp+20h] [bp-70h]
  int v52; // [sp+24h] [bp-6Ch]
  int v53; // [sp+28h] [bp-68h]
  int v54; // [sp+2Ch] [bp-64h]
  unsigned int v55; // [sp+30h] [bp-60h]
  int v56; // [sp+34h] [bp-5Ch]
  int v57; // [sp+38h] [bp-58h]
  unsigned int v58; // [sp+3Ch] [bp-54h]
  int v59; // [sp+40h] [bp-50h] BYREF
  int v60; // [sp+44h] [bp-4Ch]
  int v61; // [sp+48h] [bp-48h]
  char v62[12]; // [sp+50h] [bp-40h] BYREF
  int v63; // [sp+5Ch] [bp-34h]
  unsigned int v64; // [sp+60h] [bp-30h]
  unsigned int v65; // [sp+64h] [bp-2Ch]
  int v66; // [sp+68h] [bp-28h]
  int v67; // [sp+6Ch] [bp-24h]
  __int64 varg_r0; // [sp+98h] [bp+8h]
  int varg_r2; // [sp+A0h] [bp+10h]
  unsigned int varg_r3; // [sp+A4h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a2;
  varg_r3 = a3;
  v4 = a1;
  v60 = a1;
  v5 = a3;
  v55 = a2;
  if ( a3 == -1 )
    return 0;
  if ( a3 == 24 )
    return 0;
  if ( (a3 & 5) == 5 )
    return 0;
  v6 = a3 >> 3;
  if ( a3 >> 3 == 2 )
    return 0;
  v7 = 1;
  if ( v6 == 1 )
  {
    v7 = 0;
  }
  else if ( v6 == 3 && (a3 & 7) != 0 )
  {
    v7 = 2;
  }
  v8 = a1 >> 12;
  v9 = MiPlatformCacheAttributes[v7 + 6];
  v49 = MiPlatformCacheAttributes[v7];
  v53 = v9;
  v56 = a1 & 0xFFF;
  v10 = (unsigned int)(v56 + a2 + 4095) >> 12;
  v52 = v10;
  v47 = v8;
  v11 = MI_IS_PFN(v8);
  if ( (v5 & 2) != 0 && (!v11 || (MiFlags & 0x30000) != 0) )
    v5 &= 0xFFFFFFFD;
  v48 = 0;
  v12 = 0;
  v44 = 0;
  if ( (v4 & 0x3FFFFF) != 0 || v55 < 0x400000 || a4 )
  {
LABEL_12:
    if ( a4 != 1 || v10 != -1 )
      goto LABEL_13;
    return 0;
  }
  if ( v11 )
    return sub_512660(v11, 0);
  v37 = 3;
  v38 = 0;
  v39 = 0;
  if ( !v10 )
  {
LABEL_72:
    if ( v38 == v10 )
      goto LABEL_73;
    goto LABEL_12;
  }
  while ( 1 )
  {
    if ( MI_IS_PFN(v38 + v8) )
    {
LABEL_71:
      v12 = v44;
      v37 = 3;
      goto LABEL_72;
    }
    if ( !v38 )
    {
      v41 = MiIoSpaceIsConstant(v8, v10);
      v12 = v41;
      v44 = v41;
      if ( v41 )
        break;
    }
    ++v38;
    v39 += 24;
    if ( v38 >= v10 )
      goto LABEL_71;
  }
  v37 = *(_DWORD *)(v41 + 8);
LABEL_73:
  if ( !v12 )
  {
    if ( MiReferenceIoPages(1, v8, v10, v53, &v59, &v48) >= 0 )
    {
      if ( ((v59 - 1) & v59) == 0 )
      {
        v40 = *(_WORD *)(*(_DWORD *)(v48 + 24) + 2 * (v8 - *(_DWORD *)(v48 + 20)));
        __dmb(0xBu);
        v33 = v48;
        v37 = v40 >> 14;
        goto LABEL_77;
      }
      MiDereferenceIoPages(1, v8, v10);
    }
LABEL_13:
    v13 = MiReservePtes(&dword_634D58);
    v14 = v13;
    if ( v13 )
    {
      v61 = v13;
      v15 = v5 & 7;
      v57 = v56 + (v13 << 10);
      if ( v49 )
      {
        if ( v49 == 2 )
          v15 |= 0x18u;
      }
      else
      {
        v15 |= 8u;
      }
      v16 = (MmProtectToPteMask[v15] | MiDetermineUserGlobalPteMask(v13)) & 0x3ED | 0xFFFFF012;
      v58 = v16;
      if ( (v16 & 0x80) != 0 )
        v58 = v16 & 0xFFFFFDFF;
      v17 = MmPfnDatabase + 24 * v8;
      v45 = v17;
      v46 = 0;
      v48 = 0;
      v18 = 0;
      v19 = 0;
      LOWORD(v20) = 0;
      v21 = 0x3FFFFF;
      v50 = 0;
      v51 = 0x3FFFFF;
      v54 = 0;
      v22 = v14 + 0x40000000;
      v23 = v8;
      while ( 1 )
      {
        if ( v19 )
        {
          v20 = v20 & 0xFFF | (v23 << 12);
        }
        else
        {
          if ( MI_IS_PFN(v23) )
          {
            v17 = v45;
            LOWORD(v35) = v58;
            if ( !*(_WORD *)(v45 + 16) )
            {
              MiShowBadMapper(v47, 1);
              v17 = v45;
            }
            if ( (*(_BYTE *)(v17 + 18) & 0xC0) == 192 )
            {
              MiAssignInitialPageAttribute(v17, v49);
              v17 = v45;
            }
            if ( *(unsigned __int8 *)(v17 + 18) >> 6 == v49 )
            {
              v23 = v47;
            }
            else
            {
              v15 = MiMakeProtectionPfnCompatible(v15, v17);
              v23 = v47;
              v35 = (MmProtectToPteMask[v15] & 0x3ED | (v47 << 12) | MiDetermineUserGlobalPteMask(v14)) & 0xFFFFF3FF | 0x12;
              v17 = v45;
              if ( (v35 & 0x80) != 0 )
                LOWORD(v35) = v35 & 0xFDFF;
            }
            v20 = v35 & 0xFFF | (v23 << 12);
          }
          else
          {
            v24 = v61;
            v25 = v52;
            if ( v14 == v61 && (v36 = MiIoSpaceIsConstant(v47, v52), (v50 = v36) != 0) )
            {
              v28 = *(_DWORD *)(v36 + 8);
              v53 = v28;
            }
            else
            {
              if ( v18 )
              {
                v26 = v46;
              }
              else
              {
                v18 = MiIoPagesInRun(v47, v25);
                if ( MiReferenceIoPages(1, v47, v18, v53, 0, &v48) < 0 )
                {
                  MiZeroAndFlushPtes(v57, v10);
                  MiReleasePtes(&dword_634D58, v24, v10);
                  return 0;
                }
                v26 = v48;
              }
              v27 = *(_DWORD *)(v26 + 20);
              v54 = --v18;
              LOWORD(v27) = *(_WORD *)(*(_DWORD *)(v26 + 24) + 2 * (v47 - v27));
              __dmb(0xBu);
              v28 = (unsigned __int16)v27 >> 14;
              v46 = v48;
            }
            v15 &= 7u;
            if ( v28 )
            {
              if ( v28 == 2 )
                v15 |= 0x38u;
            }
            else
            {
              v15 |= 0x28u;
            }
            v23 = v47;
            v20 = (MmProtectToPteMask[v15] & 0x3ED | (v47 << 12) | MiDetermineUserGlobalPteMask(v14)) & 0xFFFFF3FF | 0x12;
            v17 = v45;
            if ( (v20 & 0x80) != 0 )
              v20 &= 0xFFFFFDFF;
          }
          v19 = v50;
          v21 = v51;
        }
        if ( v22 > v21 )
        {
          *(_DWORD *)v14 = v20;
        }
        else
        {
          v29 = *(_DWORD *)v14;
          v30 = 0;
          __dmb(0xBu);
          *(_DWORD *)v14 = v20;
          if ( (v29 & 2) == 0 && (v20 & 2) != 0 )
            v30 = 1;
          if ( v14 >= 0xC0300000 && v14 <= 0xC0300FFF )
          {
            v42 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v42, v42 + 4 * (v14 & 0xFFF), v20);
            v23 = v47;
            v17 = v45;
            v19 = v50;
          }
          if ( v30 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
          v21 = v51;
          v18 = v54;
        }
        v14 += 4;
        v17 += 24;
        v31 = v52 == 1;
        ++v23;
        --v52;
        v22 += 4;
        v45 = v17;
        v47 = v23;
        if ( v31 )
        {
          v32 = v57;
          v33 = v46;
          goto LABEL_43;
        }
      }
    }
    return 0;
  }
  v33 = 0;
LABEL_77:
  v32 = MiMapWithLargePages(v8, v10, v5, v37, 9);
  if ( !v32 )
  {
    if ( !v44 )
      MiDereferenceIoPages(1, v8, v10);
    goto LABEL_12;
  }
LABEL_43:
  if ( v33 )
    MiMappingHasIoReferences(v32);
  if ( (dword_681258 & 1) != 0 )
  {
    v43 = 0;
    v63 = v32;
    v64 = v60 & 0xFFFFF000;
    v66 = v56;
    v67 = v8;
    if ( v33 )
      v43 = 1;
    if ( a4 == 1 )
      v43 |= 2u;
    v65 = v55;
    MiInsertPteTracker(v62, 1, v43, v49);
  }
  return v32;
}
