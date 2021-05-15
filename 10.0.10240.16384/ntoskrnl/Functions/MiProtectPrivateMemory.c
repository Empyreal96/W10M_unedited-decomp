// MiProtectPrivateMemory 
 
int __fastcall MiProtectPrivateMemory(int a1, unsigned int a2, unsigned int a3, int a4, __int16 a5, int a6, _DWORD *a7)
{
  int *v7; // r10
  unsigned int v10; // r5
  unsigned int *v11; // r6
  int v12; // r9
  int result; // r0
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  int v17; // r4
  int v18; // r8
  int v19; // r0
  int v20; // r2
  int v21; // r3
  unsigned int v22; // r4
  unsigned int v23; // r4
  int v24; // r7
  int v25; // r10
  int v26; // r1
  int v27; // r0
  int v28; // r4
  unsigned int v29; // r3
  int v30; // r8
  unsigned int v31; // r1
  int v32; // r4
  unsigned __int8 *v33; // r3
  unsigned int v34; // r1
  unsigned int v35; // r0
  unsigned int v36; // r1
  int v37; // r4
  bool v38; // zf
  int v39; // r3
  unsigned int v40; // r10
  int v41; // r4
  unsigned int v42; // r8
  _DWORD *v43; // r7
  unsigned int *v44; // r9
  unsigned int v45; // r0
  unsigned int v46; // r3
  int v47; // r1
  int v48; // r0
  int v49; // [sp+8h] [bp-170h]
  int v50; // [sp+Ch] [bp-16Ch]
  unsigned int v51; // [sp+10h] [bp-168h]
  int v54; // [sp+1Ch] [bp-15Ch]
  unsigned int v55; // [sp+20h] [bp-158h]
  int v56; // [sp+24h] [bp-154h]
  int v57; // [sp+2Ch] [bp-14Ch] BYREF
  int *v58; // [sp+30h] [bp-148h]
  _DWORD *v59; // [sp+34h] [bp-144h]
  int v60; // [sp+38h] [bp-140h] BYREF
  char v61; // [sp+3Ch] [bp-13Ch]
  char v62; // [sp+3Dh] [bp-13Bh]
  int v63; // [sp+40h] [bp-138h]
  int v64; // [sp+44h] [bp-134h]
  int v65; // [sp+48h] [bp-130h]
  int v66; // [sp+4Ch] [bp-12Ch]
  unsigned int v67[42]; // [sp+D0h] [bp-A8h] BYREF

  v7 = (int *)a6;
  v58 = (int *)a6;
  v59 = a7;
  v64 = 0;
  v65 = 0;
  v61 = 0;
  v62 = 0;
  v63 = 33;
  v66 = 0;
  v60 = 1;
  v10 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v54 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v55 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
  v51 = 0;
  v67[0] = 0;
  v49 = 0;
  v11 = (unsigned int *)(v54 + 492);
  v12 = KfRaiseIrql(2);
  v56 = v12;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53E7C4();
  v14 = (unsigned __int8 *)(v54 + 495);
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 | 0x80, v14) );
  __dmb(0xBu);
  if ( v15 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v11);
  while ( 1 )
  {
    v16 = *v11;
    if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v16 & 0x40000000) == 0 )
    {
      do
        v31 = __ldrex(v11);
      while ( v31 == v16 && __strex(v16 | 0x40000000, v11) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( MiComputePageCommitment(a2, a3, a1, v12, &v57) != ((int)(v55 - v10) >> 2) + 1 )
  {
    MiUnlockWorkingSetExclusive(v11, v12);
    return -1073741779;
  }
  v17 = v57;
  v50 = v57;
  if ( v57 )
  {
    MiUnlockWorkingSetExclusive(v11, v12);
    result = MiChargeFullProcessCommitment(v54, v17);
    if ( result < 0 )
      return result;
    v32 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11);
    }
    else
    {
      v33 = (unsigned __int8 *)(v54 + 495);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 | 0x80, v33) );
      __dmb(0xBu);
      if ( v34 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v11);
      while ( 1 )
      {
        v35 = *v11;
        if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v35 & 0x40000000) == 0 )
        {
          do
            v36 = __ldrex(v11);
          while ( v36 == v35 && __strex(v35 | 0x40000000, v11) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v7 = v58;
    }
    v12 = v32;
    v56 = v32;
    v17 = v57;
  }
  MiMakeSystemAddressValid(((a2 >> 10) & 0x3FFFFC) - 0x40000000, 0);
  v18 = a1;
  if ( *(_DWORD *)v10 )
  {
    v19 = MiGetPageProtection(a1, v10, v12, 1);
    v20 = 1;
    v49 = 1;
    v21 = MmProtectToValue[v19];
  }
  else
  {
    v21 = MmProtectToValue[(unsigned __int8)*(_DWORD *)(a1 + 28) >> 3];
    v20 = 0;
  }
  *v7 = v21;
  while ( v10 <= v55 )
  {
    if ( v20 == 1 || (v10 & 0xFFF) == 0 )
    {
      v49 = 0;
      MiFlushTbList(&v60);
      MiMakeSystemAddressValid(v10, 0);
    }
    v22 = *(_DWORD *)v10;
    if ( (*(_DWORD *)v10 & 2) != 0 )
    {
      v23 = v22 >> 12;
      v24 = MmPfnDatabase + 24 * v23;
      if ( (*(_DWORD *)(v18 + 28) & 7) == 6 && MiRotatedToFrameBuffer(v10) == 1 )
      {
        v25 = a4;
      }
      else
      {
        if ( (*(_DWORD *)(v24 + 20) & 0x8000000) != 0 )
        {
          v37 = 0;
          if ( (*(_DWORD *)(v24 + 4) & 0x80000000) != 0 )
          {
            v37 = MiLocateCloneAddress(v54);
            if ( MEMORY[0xC0402140] <= *(_QWORD *)(v37 + 40) )
              v37 = 0;
          }
          MiFlushTbList(&v60);
          if ( MiCopyOnWriteEx(v10 << 10, v10, -1, v12, 0) )
          {
            v20 = v49;
            v38 = v37 == 0;
            v17 = v50;
            if ( !v38 )
              v17 = --v50;
            goto LABEL_26;
          }
          goto LABEL_78;
        }
        if ( (a5 & 0x101) != 0 )
        {
          v40 = v55;
          if ( ((v55 ^ v10) & 0xFFFFF000) != 0 )
            v40 = (v10 & 0xFFFFF000) + 4092;
          v41 = 0;
          v42 = v10 << 10;
          v43 = (_DWORD *)v10;
          if ( v10 > v40 )
          {
LABEL_95:
            if ( v51 )
            {
              MiFreeWsleList((int)v11, v67, 0);
              v51 = 0;
              v67[0] = 0;
            }
            goto LABEL_24;
          }
          while ( 2 )
          {
            if ( (*v43 & 2) == 0
              || (v44 = (unsigned int *)(MmPfnDatabase + 24 * (*v43 >> 12)), (*(_DWORD *)(a1 + 28) & 7) == 6)
              && MiRotatedToFrameBuffer(v10) == 1
              || (v44[5] & 0x8000000) != 0 )
            {
LABEL_94:
              v12 = v56;
              goto LABEL_95;
            }
            v45 = MiLocateWsle(v42, (int)v11, *v44);
            if ( v45 < MEMORY[0xC0402004] )
            {
              v41 = 1;
              *v59 = 1;
              v46 = v51;
              goto LABEL_89;
            }
            v67[v51 + 1] = v45;
            v51 = ++v67[0];
            v46 = v67[0];
            if ( v67[0] == 32 )
            {
LABEL_89:
              if ( v46 )
              {
                MiFreeWsleList((int)v11, v67, 0);
                v51 = 0;
                v67[0] = 0;
              }
              if ( v41 == 1 )
              {
                MiUnlockVa((int)v11, v42);
                v41 = 0;
              }
            }
            ++v43;
            v42 += 4096;
            if ( (unsigned int)v43 > v40 )
              goto LABEL_94;
            continue;
          }
        }
        v25 = MiUpdatePfnProtection(v18, v24, a4);
        a4 = v25;
      }
      if ( (v25 & 2) != 0 && (BYTE2(MiFlags) & 3u) > 1 )
      {
        v47 = 0;
        if ( (*(_BYTE *)(v24 + 23) & 7) != 3 )
          v47 = 2;
        if ( (v25 & 4) != 0 && (v25 & 5) != 5 )
          v47 |= 1u;
        if ( v47 )
          MiMarkPfnVerified(v24, v47);
      }
      MiRevertValidPte(v18, v10, v25, v23, &v60);
    }
    else
    {
      if ( (v22 & 0x400) != 0 )
      {
        MiFlushTbList(&v60);
        v10 = (unsigned int)MiMakeProtoLeafValid((_DWORD *)v10, 1, v12, v39);
LABEL_78:
        v20 = 1;
        v49 = 1;
        goto LABEL_25;
      }
      if ( (v22 & 0x800) != 0 )
      {
        if ( MiSetProtectionOnTransitionPte(v18, v10, a4, 1) )
          goto LABEL_24;
      }
      else
      {
        if ( v22 )
        {
          v26 = (v22 >> 5) & 0x1F;
        }
        else
        {
          MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * (((v10 >> 12) & 0x3FF) - 534769440)), 1u);
          v26 = (unsigned __int8)*(_DWORD *)(v18 + 28) >> 3;
        }
        v27 = MiSanitizePfnProtection(v18, v26, a4);
        v28 = v22 ^ ((unsigned __int16)v22 ^ (unsigned __int16)(32 * v27)) & 0x3E0;
        a4 = v27;
        if ( v10 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v10 = v28;
        }
        else
        {
          v29 = *(_DWORD *)v10;
          v30 = 0;
          __dmb(0xBu);
          *(_DWORD *)v10 = v28;
          if ( (v29 & 2) == 0 && (v28 & 2) != 0 )
            v30 = 1;
          if ( v10 >= 0xC0300000 && v10 <= 0xC0300FFF )
          {
            v48 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v48, (_DWORD *)(v48 + 4 * (v10 & 0xFFF)), v28);
          }
          if ( v30 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
      }
    }
    v10 += 4;
LABEL_24:
    v20 = v49;
LABEL_25:
    v17 = v50;
LABEL_26:
    v18 = a1;
  }
  MiFlushTbList(&v60);
  MiUnlockWorkingSetExclusive(v11, v12);
  if ( v17 )
    MiReturnFullProcessCommitment(v54, v17);
  return 0;
}
