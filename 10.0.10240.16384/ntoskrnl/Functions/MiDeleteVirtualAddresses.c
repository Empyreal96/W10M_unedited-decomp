// MiDeleteVirtualAddresses 
 
unsigned int __fastcall MiDeleteVirtualAddresses(unsigned int result, unsigned int a2, char a3, int a4, int a5)
{
  int v5; // r7
  int v6; // r6
  unsigned int v7; // r4
  unsigned int v8; // r5
  char v9; // r0
  unsigned int v10; // r9
  unsigned int v11; // r2
  unsigned int v12; // r7
  unsigned int v13; // r6
  unsigned int v14; // r5
  unsigned int v15; // r5
  int v16; // r7
  int v17; // r6
  _DWORD *v18; // r8
  unsigned int v19; // r0
  unsigned int v20; // r10
  _DWORD *v21; // r7
  int v22; // r6
  int v23; // r2
  unsigned int v24; // r0
  unsigned int *v25; // r7
  unsigned int v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // r1
  unsigned int v29; // r2
  unsigned int v30; // r6
  int v31; // r1
  int v32; // r0
  unsigned int v33; // r6
  unsigned int v34; // r1
  unsigned int v35; // r5
  unsigned int v36; // r6
  int v37; // r7
  unsigned int v38; // r8
  int *v39; // r5
  int v40; // r1
  unsigned int v41; // r2
  unsigned int v42; // r0
  int v43; // r6
  unsigned int v44; // r6
  unsigned int v45; // r2
  int v46; // r1
  int v47; // r7
  int v48; // r1
  int v49; // r2
  int v50; // r3
  unsigned int v51; // r3
  __int64 v52; // kr00_8
  int v53; // r2
  unsigned int *v54; // r9
  int v55; // r0
  unsigned int *v56; // r5
  unsigned __int8 *v57; // r3
  unsigned int v58; // r1
  unsigned int *v59; // r2
  unsigned int v60; // r0
  unsigned int v61; // r1
  bool v62; // zf
  unsigned int v63; // r2
  int v64; // r0
  int v65; // r0
  unsigned int v66; // r1
  int v67; // r0
  int v68; // r0
  unsigned int v69; // [sp+8h] [bp-120h]
  int *v70; // [sp+Ch] [bp-11Ch]
  unsigned int v71; // [sp+10h] [bp-118h]
  int v73; // [sp+18h] [bp-110h]
  int v74; // [sp+1Ch] [bp-10Ch]
  unsigned int v75; // [sp+24h] [bp-104h]
  int v76; // [sp+38h] [bp-F0h]
  BOOL v77; // [sp+3Ch] [bp-ECh]
  unsigned int v78; // [sp+40h] [bp-E8h]
  unsigned int v79; // [sp+48h] [bp-E0h]
  unsigned int v80; // [sp+4Ch] [bp-DCh]
  _WORD *v81; // [sp+54h] [bp-D4h]
  unsigned int v82; // [sp+5Ch] [bp-CCh]
  char v83[4]; // [sp+60h] [bp-C8h] BYREF
  int v84; // [sp+64h] [bp-C4h]
  _DWORD *v85; // [sp+68h] [bp-C0h]
  char v86[4]; // [sp+6Ch] [bp-BCh] BYREF
  int v87; // [sp+70h] [bp-B8h] BYREF
  char v88; // [sp+74h] [bp-B4h]
  char v89; // [sp+75h] [bp-B3h]
  unsigned int v90; // [sp+78h] [bp-B0h]
  unsigned int v91; // [sp+7Ch] [bp-ACh]
  unsigned int v92; // [sp+80h] [bp-A8h]
  int v93[41]; // [sp+84h] [bp-A4h] BYREF

  v5 = a4;
  v76 = a4;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v91 = 0;
  v89 = 0;
  v90 = 33;
  v88 = 0;
  v92 = 0;
  v93[0] = 0;
  v87 = 1;
  v7 = ((result >> 10) & 0x3FFFFC) - 0x40000000;
  v8 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v82 = v8;
  v73 = v6;
  v74 = 0;
  if ( v7 > v8 )
    return result;
  v84 = 0x7FFFF;
  v70 = (int *)(v6 + 492);
  do
  {
    result = MiGetNextPageTable(v7, v8, &v87, v5, 1, v83);
    v7 = result;
    if ( !result )
      return result;
    v9 = a3;
    v77 = (*(_BYTE *)(v6 + 607) & 1) != 0;
    if ( (a3 & 2) != 0 && (*(_BYTE *)(v6 + 607) & 1) == 0 && dword_634484 )
      return sub_5312AC();
    v10 = v7 << 10;
    v11 = *(unsigned __int16 *)(2 * ((v7 << 10 >> 22) - 534769440));
    v81 = (_WORD *)(2 * ((v7 << 10 >> 22) - 534769440));
    v12 = (v7 & 0xFFFFF000) + 4092;
    v13 = 0;
    v71 = v12;
    v78 = v7 << 10;
    v69 = v11;
    if ( v12 > v8 )
    {
      v12 = v8;
      v71 = v8;
    }
    v14 = 0;
    v75 = 0;
    v80 = 0;
    if ( v7 > v12 )
    {
LABEL_99:
      v47 = 0;
      goto LABEL_100;
    }
    while ( 1 )
    {
      v15 = *(_DWORD *)v7;
      if ( !*(_DWORD *)v7 )
        goto LABEL_12;
      v79 = (unsigned __int16)(v13 + 1);
      if ( v79 > v11 )
        KeBugCheckEx(26, 268179, v7);
      if ( (v15 & 2) != 0 )
      {
        v16 = *(_DWORD *)(MmPfnDatabase + 24 * (v15 >> 12));
        v17 = MmPfnDatabase + 24 * (v15 >> 12);
        if ( (v9 & 8) == 0 )
          goto LABEL_17;
        if ( MiRotatedToFrameBuffer(v7) == 1 )
        {
          MiUnmapFrameBuffer(v7, 3, 0, v86);
          MiInsertTbFlushEntry(&v87, v10, 1);
        }
        else
        {
          v9 = a3;
LABEL_17:
          if ( (*(_DWORD *)(v17 + 12) & 0x3FFFFFFF) == 1 )
          {
            if ( (v9 & 1) != 0 )
            {
              v63 = *(unsigned __int8 *)(v17 + 19);
              if ( ((v63 >> 3) & 1) == 1 || (v63 & 7) > 2 && (v63 & 7) <= 5 )
              {
                MiLockSetPfnPriority(v17, 2);
                v9 = a3;
              }
            }
            if ( (v9 & 4) != 0 && !v74 && (v15 & 0x200) != 0 && MiBoostUnmapPfn(v17) )
            {
              if ( (*(_BYTE *)(v17 + 19) & 8) != 0 )
                v64 = 5;
              else
                v64 = *(_BYTE *)(v17 + 19) & 7;
              v74 = MiCreateDecayPfn(v64);
            }
          }
          if ( !v77 )
          {
            v85 = (_DWORD *)v70[23];
            v18 = v85;
            v19 = MiLocateWsle(v10, v70, v16);
            v20 = v19;
            if ( (*(_DWORD *)(v18[9] * v19 + v18[63]) & 8) != 0
              && (*(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(((v10 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) + 20) & 0x8000000) == 0 )
            {
              --v70[16];
              if ( v10 < 0xC0000000 || v10 > 0xC03FFFFF )
                --v70[14];
            }
            v21 = (_DWORD *)v70[23];
            if ( v19 > v21[4] )
              KeBugCheckEx(26, 268165, v21);
            v22 = *(_DWORD *)(v21[9] * v19 + v21[63]);
            if ( (v22 & 1) == 0 )
              KeBugCheckEx(26, 20496, v21);
            v23 = (int)v70;
            v24 = v22 & 0xFFFFF000;
            if ( v70 == &dword_634F00 )
            {
              if ( PsNtosImageBase
                && (v24 >= PsNtosImageBase && v24 < PsNtosImageEnd || v24 >= PsHalImageBase && v24 < PsHalImageEnd) )
              {
                --dword_632F50;
              }
              else if ( v24 >= dword_63389C )
              {
                v23 = (int)v70;
                if ( *((_BYTE *)&MiState[2423]
                     + ((int)(((v24 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12 )
                  --dword_632F54;
              }
            }
            if ( (v22 & 8) == 0 && (v22 & 4) != 0 )
            {
              MiUpdateWsleHash(v24, v20, v23, 1);
              v23 = (int)v70;
            }
            if ( (dword_682604 & 0x8000000) != 0 )
              MiLogRemoveWsleEvent(v22, *(_BYTE *)(v23 + 112) & 7);
            *(_DWORD *)(v21[9] * v20 + v21[63]) = v22 & 0xFFFFFFFE;
            v25 = (unsigned int *)v70[23];
            v26 = v25[1];
            if ( v20 < v26 )
            {
LABEL_76:
              v32 = (int)v70;
            }
            else
            {
              v27 = v25[9];
              v28 = v25[63];
              v29 = v28 + v27 * v20;
              v30 = *(_DWORD *)v29;
              if ( v27 == 16 && (int)(16 * v20) >> 4 >= v26 )
              {
                v52 = *(_QWORD *)(v29 + 4);
                v53 = 2 * ((v30 >> 9) & 7);
                if ( v30 < 0xC0000000 || v30 > 0xC03FFFFF )
                  ++v53;
                v54 = &v25[2 * v53];
                if ( HIDWORD(v52) == 0xFFFFF )
                  v54[31] = v52;
                else
                  *(_DWORD *)(v28 + 16 * HIDWORD(v52) + 4) = v52;
                if ( (_DWORD)v52 == 0xFFFFF )
                  v54[32] = HIDWORD(v52);
                else
                  *(_DWORD *)(v28 + 16 * v52 + 8) = HIDWORD(v52);
                v18 = v85;
                v10 = v78;
                --v25[v53 + 15];
              }
              v31 = (v30 >> 9) & 7;
              v32 = (int)v70;
              if ( v31 )
              {
                --v70[v31 + 4];
                if ( v31 == 7 )
                {
                  MiVolunteerForTrimFirst(v70, -1);
                  goto LABEL_76;
                }
              }
            }
            v33 = *v25;
            if ( *v25 != 0xFFFFF )
            {
              if ( v33 < v25[1] || v33 > v25[4] )
                KeBugCheckEx(26, 20484, v25);
              *(_DWORD *)(v33 * v25[9] + v25[63]) ^= (*(_DWORD *)(v33 * v25[9] + v25[63]) ^ (2 * v20)) & 0xFFE;
              v32 = (int)v70;
            }
            *(_DWORD *)(v25[9] * v20 + v25[63]) = (v33 << 12) | 0xFFE;
            *v25 = v20;
            --*(_DWORD *)(v32 + 60);
            if ( v10 < 0xC0000000 || v10 > 0xC03FFFFF )
              --*(_DWORD *)(v32 + 52);
            if ( v20 < v18[1] )
              MiRemoveLockedPageFromWorkingSet(
                v32,
                v10,
                v20,
                MmPfnDatabase + 24 * (*(_DWORD *)(((v10 >> 10) & 0x3FFFFC) - 0x40000000) >> 12));
          }
          v34 = *(_DWORD *)v7;
          v35 = v15 & 0xFFFFFFFC | 0x400;
          __dmb(0xBu);
          if ( (v34 & 0x10) != 0 )
            goto LABEL_43;
          __dmb(0xBu);
          do
            v45 = __ldrex((unsigned int *)v7);
          while ( v45 == v34 && __strex(v35, (unsigned int *)v7) );
          __dmb(0xBu);
          if ( v45 != v34 )
          {
LABEL_43:
            if ( v7 + 0x40000000 > 0x3FFFFF )
            {
              *(_DWORD *)v7 = v35;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)v7 = v35;
              if ( v7 >= 0xC0300000 && v7 <= 0xC0300FFF )
              {
                v65 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v65, v65 + 4 * (v7 & 0xFFF), v35);
              }
            }
            v36 = v91;
            v37 = 1;
            v38 = v10;
            if ( !v91 )
              goto LABEL_92;
            v39 = &v87 + v91;
            v40 = v39[4];
            if ( (v40 & 0x800) == 0 )
            {
              v41 = v39[4] & 0x7FF;
              v42 = v41 + 1;
              if ( (v40 & 0xFFFFF000) + ((v41 + 1) << 12) == v10 && v42 > v41 && v42 <= 0x7FF )
              {
                ++v92;
                v39[4] = v40 & 0xFFFFF800 | (v40 + 1) & 0x7FF;
                goto LABEL_51;
              }
            }
            if ( (v40 & 0x800) == 0
              && (v40 & 0xFFFFF000) == v10 + 4096
              && (v66 = v39[4] & 0x7FF, v66 + 1 > v66)
              && v66 + 1 <= 0x7FF )
            {
              MiMergeTbFlushEntryBackwards((int)&v87, v66, 1);
            }
            else
            {
LABEL_92:
              if ( v91 < v90 )
              {
                while ( 1 )
                {
                  v46 = (unsigned int)(v37 - 1) > 0x7FF ? 2048 : v37;
                  v93[v36] = ((_WORD)v46 - 1) & 0x7FF | v38 & 0xFFFFF000;
                  v37 -= v46;
                  v36 = v91 + 1;
                  v91 = v36;
                  v92 += v46;
                  v38 += v46 << 12;
                  if ( v36 == v90 )
                  {
                    qsort(v93, v36, 4, MiTbFlushSort);
                    MiCompressTbFlushList((int)&v87);
                    v36 = v91;
                    if ( v91 == v90 )
                      break;
                  }
                  if ( !v37 )
                    goto LABEL_51;
                }
                v11 = v69;
                v62 = v37 == 0;
                v12 = v71;
                if ( !v62 )
                {
                  v89 = 1;
                  v92 = v91;
                }
                goto LABEL_53;
              }
              v89 = 1;
            }
          }
        }
LABEL_51:
        v12 = v71;
LABEL_52:
        v11 = v69;
        goto LABEL_53;
      }
      if ( (v15 & 0x400) != 0 )
      {
        v44 = (*(_DWORD *)v7 & 0x1FC | (*(_DWORD *)v7 >> 2) & 0x3FFFFE00) - 0x40000000;
        if ( v15 >> 13 == v84 || v44 < dword_640484 || v44 >= dword_640488 )
        {
          if ( *(_DWORD *)(v73 + 272) )
          {
            if ( v15 >> 13 != v84 )
            {
              v67 = MiLocateCloneAddress(v73, v44);
              if ( v67 )
              {
                v55 = MiDecrementCloneBlockReference(v67, v44, v73);
                goto LABEL_128;
              }
            }
          }
        }
        else
        {
          v55 = MiDecrementCombinedPte((*(_DWORD *)v7 & 0x1FC | (*(_DWORD *)v7 >> 2) & 0x3FFFFE00) - 0x40000000);
LABEL_128:
          if ( v55 == 3 )
          {
            ++*(_DWORD *)(a5 + 4);
          }
          else if ( v55 == 5 )
          {
            ++*(_DWORD *)(a5 + 8);
          }
        }
        if ( v7 + 0x40000000 > 0x3FFFFF )
          goto LABEL_194;
        __dmb(0xBu);
        *(_DWORD *)v7 = 0;
        if ( v7 < 0xC0300000 || v7 > 0xC0300FFF )
          goto LABEL_52;
LABEL_193:
        v68 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v68, v68 + 4 * (v7 & 0xFFF), 0);
        goto LABEL_52;
      }
      if ( (v15 & 0x800) == 0 )
      {
        if ( (v15 & 0x3E0) == 0 )
          KeBugCheckEx(26, 268178, v7);
        v43 = (v15 >> 4) & 1;
        if ( !v43 && (v15 & 8) == 0 )
          v15 = 0;
        if ( v15 )
          MiReleasePageFileInfo(MiSystemPartition, v15, 0);
        if ( v43 )
        {
          v59 = (unsigned int *)(v73 + 276);
          do
            v60 = __ldrex(v59);
          while ( __strex(v60 - 1, v59) );
        }
        if ( v7 + 0x40000000 > 0x3FFFFF )
        {
LABEL_194:
          v11 = v69;
          *(_DWORD *)v7 = 0;
          goto LABEL_57;
        }
        __dmb(0xBu);
        *(_DWORD *)v7 = 0;
        if ( v7 < 0xC0300000 || v7 > 0xC0300FFF )
          goto LABEL_52;
        goto LABEL_193;
      }
LABEL_53:
      if ( *(_DWORD *)v7 )
      {
        if ( !v75 )
          v75 = v7;
        v80 = v7;
      }
LABEL_57:
      v13 = v79;
      if ( v7 != v12
        && v79 != v11
        && (((v7 + 4) & 0x3C) == 0 && (*(_DWORD *)(v73 + 492) & 0x40000000) != 0 || KeShouldYieldProcessor()) )
      {
        break;
      }
      v9 = a3;
LABEL_12:
      v7 += 4;
      v10 += 4096;
      v78 = v10;
      if ( v7 > v12 )
      {
        v14 = v75;
        goto LABEL_99;
      }
      v11 = v69;
    }
    v14 = v75;
    v47 = 2;
    v7 += 4;
LABEL_100:
    MiFlushTbList(&v87);
    if ( v14 )
      MiDeletePteRun(v14, v80, v73, v74, a5);
    if ( v74 )
    {
      MiDecayPfnFullyInitialized(v74, v48, v49, v50);
      v74 = 0;
    }
    if ( v13 )
    {
      v51 = (unsigned __int16)(*v81 - v13);
      if ( v51 >= 0x400 )
        KeBugCheckEx(26, 268176, v81);
      *v81 = v51;
    }
    if ( !*v81 )
      MiDeletePageTableHierarchy(0, v7 - 4);
    v6 = v73;
    if ( v47 == 2 || (*(_DWORD *)(v73 + 492) & 0x40000000) != 0 || (result = KeShouldYieldProcessor()) != 0 )
    {
      v56 = (unsigned int *)(v73 + 492);
      MiUnlockWorkingSetExclusive(v73 + 492, v76);
      v5 = KfRaiseIrql(2);
      v76 = v5;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v73 + 492);
      }
      else
      {
        v57 = (unsigned __int8 *)(v73 + 495);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 | 0x80, v57) );
        __dmb(0xBu);
        if ( v58 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v73 + 492));
        while ( 1 )
        {
          result = *v56;
          if ( (*v56 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (result & 0x40000000) == 0 )
          {
            do
              v61 = __ldrex(v56);
            while ( v61 == result && __strex(result | 0x40000000, v56) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    else
    {
      v5 = v76;
    }
    v8 = v82;
  }
  while ( v7 <= v82 );
  return result;
}
