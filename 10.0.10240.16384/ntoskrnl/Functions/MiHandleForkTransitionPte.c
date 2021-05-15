// MiHandleForkTransitionPte 
 
int __fastcall MiHandleForkTransitionPte(int a1, int a2, unsigned int a3, int *a4, unsigned int *a5, _DWORD *a6, unsigned int a7, int *a8, char a9, unsigned __int8 a10, int a11)
{
  unsigned int *v11; // r6
  int *v12; // r8
  unsigned int v13; // r9
  int v15; // r0
  int v16; // r5
  unsigned int v17; // r2
  unsigned int v18; // r0
  unsigned int *v19; // r2
  unsigned int v20; // r0
  unsigned int *v21; // r4
  int v22; // r9
  int v23; // r5
  int v24; // r2
  int v25; // r3
  int v26; // r8
  int v27; // r0
  int v28; // r1
  int v29; // r2
  unsigned __int8 *v30; // r3
  unsigned int v31; // r1
  unsigned int v32; // r0
  unsigned int v33; // r1
  int v35; // r4
  int v36; // r0
  int v37; // r2
  int v38; // r3
  int v39; // r1
  int v40; // r3
  unsigned int v41; // r3
  int v42; // r10
  int v43; // r1
  unsigned __int8 *v44; // r0
  unsigned int v45; // r2
  int v46; // r3
  unsigned int *v47; // r2
  unsigned int v48; // r0
  int v49; // r0
  unsigned int *v50; // r2
  unsigned int v51; // r5
  unsigned int v52; // r3
  int v53; // r0
  unsigned int *v54; // r2
  unsigned int v55; // r0
  int v56; // r4
  unsigned __int8 *v57; // r1
  unsigned int v58; // r2
  int v59; // r3
  unsigned int *v60; // r2
  unsigned int v61; // r4
  unsigned int *v62; // r2
  unsigned int v63; // r0
  unsigned int *v64; // r4
  unsigned __int8 *v65; // r3
  unsigned int v66; // r1
  unsigned int v67; // r0
  unsigned int v68; // r1
  int v69; // [sp+8h] [bp-48h]
  unsigned int v71; // [sp+10h] [bp-40h]
  int v72; // [sp+14h] [bp-3Ch]
  int *v73; // [sp+1Ch] [bp-34h]
  _WORD *v74; // [sp+28h] [bp-28h] BYREF
  unsigned __int16 v75; // [sp+2Ch] [bp-24h]
  unsigned __int16 v76; // [sp+2Eh] [bp-22h]

  v11 = a5;
  v73 = a4;
  v12 = a4;
  v13 = (unsigned __int16)a5 & 0x1FC | (4 * ((unsigned int)a5 & 0xFFFFFE00 | 0x100));
  v71 = 0;
  v69 = a10;
  while ( 1 )
  {
    v15 = MiLockTransitionLeafPage((unsigned int *)a3, 0);
    v16 = v15;
    if ( !v15 )
      return 0;
    v17 = *(_DWORD *)a3;
    v72 = (*(_DWORD *)a3 >> 5) & 0x1F;
    if ( !*(_WORD *)(v15 + 16) && ((*(_DWORD *)a3 >> 5) & 0x18) != 16 )
    {
      *v11 = 0;
      if ( (unsigned int)(v11 + 0x10000000) > 0x3FFFFF )
      {
        *v11 = v17;
      }
      else
      {
        v35 = 0;
        __dmb(0xBu);
        *v11 = v17;
        if ( (v17 & 2) != 0 )
          v35 = 1;
        if ( (unsigned int)(v11 + 267649024) <= 0xFFF )
        {
          v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v36, (_DWORD *)(v36 + 4 * ((unsigned __int16)v11 & 0xFFF)), v17);
        }
        if ( v35 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      if ( (*v11 & 0x80) != 0 )
        *v11 |= 0x20u;
      v11[3] = 2;
      v11[2] = (a9 & 1) != 0;
      v11[2] = v11[2] & 0x7FFFFFF | (v72 << 27);
      if ( (*(_DWORD *)(v16 + 8) & 8) != 0 )
      {
        v71 = *(_DWORD *)(v16 + 8);
        if ( (*(_BYTE *)(v16 + 18) & 7) == 3 )
        {
          MiUnlinkPageFromList(v16, 0);
          v37 = 1;
        }
        else
        {
          v37 = 0;
        }
        *(_DWORD *)(v16 + 8) &= 0xFFFFFFF7;
        if ( v37 )
          MiInsertPageInList(v16, 8, v37);
      }
      v38 = *(_DWORD *)(v16 + 20);
      *(_DWORD *)(v16 + 4) = v11;
      v39 = v38 | 0x8000000;
      v40 = *(_DWORD *)(v16 + 8);
      *(_DWORD *)(v16 + 20) = v39;
      if ( (v40 & 0x80) != 0 )
        *(_DWORD *)(v16 + 8) = v40 | 0x20;
      v41 = *(_DWORD *)((((unsigned int)v11 >> 10) & 0x3FFFFC) - 0x40000000);
      *(_DWORD *)(v16 + 20) = v39 & 0xFFF00000 | (v41 >> 12);
      v42 = v39 & 0xFFFFF;
      v43 = MmPfnDatabase + 24 * (v41 >> 12);
      v44 = (unsigned __int8 *)(v43 + 15);
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 | 0x80, v44) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v45 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v46 = *(_DWORD *)(v43 + 12);
          __dmb(0xBu);
        }
        while ( (v46 & 0x80000000) != 0 );
        do
          v45 = __ldrex(v44);
        while ( __strex(v45 | 0x80, v44) );
      }
      *(_DWORD *)(v43 + 12) = *(_DWORD *)(v43 + 12) & 0xC0000000 | (*(_DWORD *)(v43 + 12) + 1) & 0x3FFFFFFF;
      __dmb(0xBu);
      v47 = (unsigned int *)(v43 + 12);
      do
        v48 = __ldrex(v47);
      while ( __strex(v48 & 0x7FFFFFFF, v47) );
      if ( a3 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)a3 = v13;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)a3 = v13;
        if ( a3 + 1070596096 <= 0xFFF )
        {
          v49 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v49, (_DWORD *)(v49 + 4 * (a3 & 0xFFF)), v13);
        }
      }
      __dmb(0xBu);
      v50 = (unsigned int *)(v16 + 12);
      do
        v51 = __ldrex(v50);
      while ( __strex(v51 & 0x7FFFFFFF, v50) );
      v52 = v71;
      if ( v71 )
      {
        if ( (v71 & 0x10) != 0 )
          v52 = v71 & 0xFFFFFFEF;
        MiReleasePageFileInfo((int)MiSystemPartition, v52, 1, v52);
      }
      if ( (a9 & 1) != 0 )
      {
        if ( v72 != 24 )
          v13 |= 0x200u;
        ++*(_DWORD *)(a11 + 4);
      }
      if ( (unsigned int)(v12 + 0x10000000) > 0x3FFFFF )
      {
        *v12 = v13;
      }
      else
      {
        __dmb(0xBu);
        *v12 = v13;
        if ( (unsigned int)(v12 + 267649024) <= 0xFFF )
        {
          v53 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v53, (_DWORD *)(v53 + 4 * ((unsigned __int16)v12 & 0xFFF)), v13);
        }
      }
      MiLockAndDecrementShareCount(MmPfnDatabase + 24 * v42, 0);
      v54 = (unsigned int *)(a1 + 276);
      do
        v55 = __ldrex(v54);
      while ( __strex(v55 - 1, v54) );
      return 2;
    }
    v18 = *(unsigned __int8 *)(v15 + 18);
    __mrc(15, 0, 13, 0, 3);
    if ( *a8 != -1 )
      break;
    __dmb(0xBu);
    v19 = (unsigned int *)(v16 + 12);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 & 0x7FFFFFFF, v19) );
    v21 = (unsigned int *)(a1 + 492);
    MI_INITIALIZE_COLOR_BASE(a1 + 492, 0, (int)&v74);
    v22 = v76;
    v23 = v69;
    v24 = (unsigned __int16)(*v74 + 1);
    v25 = v75;
    *v74 = v24;
    v26 = v24 & v25;
    while ( 1 )
    {
      v27 = MiGetPage((int)MiSystemPartition, v26 | v22, 0);
      *a8 = v27;
      if ( v27 != -1 )
        break;
      MiFlushTbList(a7, v28);
      MiUnlockWorkingSetExclusive((int)v21, v23);
      MiWaitForFreePage((int)MiSystemPartition);
      v23 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v21);
      }
      else
      {
        v30 = (unsigned __int8 *)(a1 + 495);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 | 0x80, v30) );
        __dmb(0xBu);
        if ( v31 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v21);
        v29 = 0x80000000;
        while ( 1 )
        {
          v32 = *v21;
          if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v32 & 0x40000000) == 0 )
          {
            do
              v33 = __ldrex(v21);
            while ( v33 == v32 && __strex(v32 | 0x40000000, v21) );
            __dmb(0xBu);
            v29 = 0x80000000;
          }
          __dmb(0xAu);
          __yield();
        }
      }
      MiMakeSystemAddressValid(a3, 0, v29, v23, 1);
    }
    v69 = v23;
    v11 = a5;
    v12 = v73;
    v13 = (unsigned __int16)a5 & 0x1FC | (4 * ((unsigned int)a5 & 0xFFFFFE00 | 0x100));
    if ( (*(_DWORD *)a3 & 0x402) != 0 )
      return 0;
  }
  v56 = MmPfnDatabase + 24 * *a8;
  v57 = (unsigned __int8 *)(v56 + 15);
  do
    v58 = __ldrex(v57);
  while ( __strex(v58 | 0x80, v57) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v58 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v59 = *(_DWORD *)(v56 + 12);
      __dmb(0xBu);
    }
    while ( (v59 & 0x80000000) != 0 );
    do
      v58 = __ldrex(v57);
    while ( __strex(v58 | 0x80, v57) );
  }
  MiFinalizePageAttribute(v56, v18 >> 6, 1);
  __dmb(0xBu);
  v60 = (unsigned int *)(v56 + 12);
  do
    v61 = __ldrex(v60);
  while ( __strex(v61 & 0x7FFFFFFF, v60) );
  if ( (*(_BYTE *)(v16 + 18) & 0x20) != 0 )
  {
    MiFlushTbList(a7, v61 & 0x7FFFFFFF);
    if ( (*(_BYTE *)(v16 + 18) & 8) != 0 )
    {
      __dmb(0xBu);
      v62 = (unsigned int *)(v16 + 12);
      do
        v63 = __ldrex(v62);
      while ( __strex(v63 & 0x7FFFFFFF, v62) );
      v64 = (unsigned int *)(a1 + 492);
      MiUnlockWorkingSetExclusive(a1 + 492, v69);
      KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v64);
      }
      else
      {
        v65 = (unsigned __int8 *)(a1 + 495);
        do
          v66 = __ldrex(v65);
        while ( __strex(v66 | 0x80, v65) );
        __dmb(0xBu);
        if ( v66 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v64);
        while ( 1 )
        {
          v67 = *v64;
          if ( (*v64 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v67 & 0x40000000) == 0 )
          {
            do
              v68 = __ldrex(v64);
            while ( v68 == v67 && __strex(v67 | 0x40000000, v64) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      return 0;
    }
  }
  if ( !MiDuplicateCloneLeaf((unsigned int *)a3, v12, *a8, v69, 2u) )
    return 0;
  *a8 = -1;
  ++*a6;
  return 1;
}
