// MiInsertViewOfPhysicalSection 
 
int __fastcall MiInsertViewOfPhysicalSection(int a1, int a2)
{
  int v2; // r3
  unsigned int v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r7
  int v7; // r2
  _DWORD *v8; // r1
  int v9; // r8
  int v10; // r2
  int v11; // r9
  int v12; // r3
  unsigned int v13; // r4
  _WORD *v14; // r2
  int v15; // r5
  int v16; // r8
  unsigned int v17; // r4
  int v18; // r5
  unsigned int *v19; // lr
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r1
  int v24; // r0
  unsigned __int16 v25; // r3
  int v26; // r3
  unsigned int v27; // lr
  unsigned int v28; // r3
  int v29; // r5
  int v30; // r0
  unsigned __int8 *v31; // r3
  unsigned int v32; // r1
  unsigned __int8 *v33; // r1
  int v34; // r3
  unsigned int v35; // r2
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int *v38; // r4
  int v39; // r5
  unsigned __int8 *v40; // r3
  unsigned int v41; // r1
  unsigned int v42; // r0
  unsigned int v43; // r1
  unsigned int *v45; // [sp+Ch] [bp-54h]
  unsigned int v46; // [sp+10h] [bp-50h]
  int v47; // [sp+14h] [bp-4Ch]
  __int16 v48; // [sp+18h] [bp-48h]
  int v49; // [sp+1Ch] [bp-44h]
  int v50; // [sp+20h] [bp-40h]
  int v51; // [sp+24h] [bp-3Ch]
  int v52; // [sp+28h] [bp-38h]
  int v54; // [sp+34h] [bp-2Ch]
  int v55; // [sp+38h] [bp-28h]
  int v56; // [sp+3Ch] [bp-24h]
  int vars4; // [sp+64h] [bp+4h]

  v2 = *(_DWORD *)(a2 + 12);
  v3 = *(_DWORD *)(a2 + 48);
  v4 = v2 << 12;
  v5 = (unsigned __int8)*(_DWORD *)(a2 + 28) >> 3;
  v45 = (unsigned int *)(((4 * v2) & 0x3FFFFC) - 0x40000000);
  v51 = (*(_DWORD *)(a2 + 16) & 0xFFFFF) - 0x10000000;
  v48 = (LOWORD(MmProtectToPteMask[v5]) | ((_WORD)v3 << 12)) & 0xFBFF | 0x832;
  if ( ((LOBYTE(MmProtectToPteMask[v5]) | 0x32) & 0x80) != 0 )
    v48 = ((LOWORD(MmProtectToPteMask[v5]) | ((_WORD)v3 << 12)) & 0xFBFF | 0x832) & 0xFDFF;
  v7 = 1;
  if ( v5 >> 3 == 3 && (v5 & 7) != 0 )
  {
    v7 = 2;
  }
  else if ( v5 >> 3 == 1 )
  {
    v7 = 0;
  }
  v49 = MiPlatformCacheAttributes[v7];
  v54 = **(_DWORD **)(a2 + 44);
  v56 = __mrc(15, 0, 13, 0, 3);
  MiLockVad(v56 & 0xFFFFFFC0, a2);
  v55 = a1 + 492;
  v47 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(a1 + 492));
  }
  else
  {
    v19 = (unsigned int *)(a1 + 492);
    v20 = (unsigned __int8 *)(a1 + 495);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 | 0x80, v20) );
    __dmb(0xBu);
    if ( v21 >> 7 )
    {
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 492));
      v19 = (unsigned int *)(a1 + 492);
    }
    while ( 1 )
    {
      v22 = *v19;
      if ( (*v19 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v22 & 0x40000000) == 0 )
      {
        do
          v23 = __ldrex(v19);
        while ( v23 == v22 && __strex(v22 | 0x40000000, v19) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v8 = (_DWORD *)a1;
  v9 = a2;
  MiInsertVad(a2, v8);
  MiMakeSystemAddressValid((unsigned int)v45, 0, v10, v47, 1);
  v11 = MmPfnDatabase + 24 * (*(_DWORD *)(((v4 >> 20) & 0xFFC) - 1070596096) >> 12);
  v12 = (v4 >> 22) - 534769440;
  v13 = (unsigned int)v45;
  v14 = (_WORD *)(2 * v12);
  v52 = 2 * v12;
  if ( (unsigned int)v45 <= 4 * v51 )
  {
    v46 = (unsigned int)(v45 + 267649024);
    v15 = 24 * v3;
    v50 = 24 * v3;
    while ( 1 )
    {
      v16 = v13 & 0xFFF;
      if ( (v13 & 0xFFF) == 0 )
      {
        MiMakeSystemAddressValid(v13, 0, (int)v14, v47, 1);
        v11 = MmPfnDatabase + 24 * (*(_DWORD *)(((v13 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
        v14 = (_WORD *)(2 * (((v13 >> 12) & 0x3FF) - 534769440));
        v52 = (int)v14;
      }
      MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(v14, 1u);
      if ( MI_IS_PFN(v3) )
      {
        v17 = v48 & 0xFFF | (v3 << 12);
        v18 = v15 + MmPfnDatabase;
        if ( !*(_WORD *)(v18 + 16) )
          MiShowBadMapper(v3, 0);
        if ( (*(_BYTE *)(v18 + 18) & 0xC0) == 192 )
          MiAssignInitialPageAttribute(v18, v49);
        if ( *(unsigned __int8 *)(v18 + 18) >> 6 == v49 )
          goto LABEL_38;
        v5 = MiMakeProtectionPfnCompatible(v5, v18);
      }
      else
      {
        v24 = MiLookupIoPageNode(v3);
        if ( !v24 )
          KeBugCheckEx(26, 399689, v3, 1, 0);
        v25 = *(_WORD *)(*(_DWORD *)(v24 + 24) + 2 * (v3 - *(_DWORD *)(v24 + 20)));
        __dmb(0xBu);
        v5 &= 7u;
        v26 = v25 >> 14;
        if ( v26 )
        {
          if ( v26 == 2 )
            v5 |= 0x38u;
        }
        else
        {
          v5 |= 0x28u;
        }
      }
      v17 = (MmProtectToPteMask[v5] | (v3 << 12)) & 0xFFFFFBFF | 0x832;
      if ( ((LOBYTE(MmProtectToPteMask[v5]) | 0x32) & 0x80) != 0 )
        v17 &= 0xFFFFFDFF;
LABEL_38:
      v27 = v46;
      if ( v46 + 3145728 > 0x3FFFFF )
      {
        *v45 = v17;
      }
      else
      {
        v28 = *v45;
        v29 = 0;
        __dmb(0xBu);
        if ( (v28 & 2) == 0 )
          v29 = 1;
        *v45 = v17;
        if ( v46 <= 0xFFF )
        {
          v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v30, (_DWORD *)(v30 + 4 * v16), v17);
          v27 = v46;
        }
        if ( v29 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v31 = (unsigned __int8 *)(v11 + 15);
      do
        v32 = __ldrex(v31);
      while ( __strex(v32 | 0x80, v31) );
      __dmb(0xBu);
      if ( v32 >> 7 )
      {
        v33 = (unsigned __int8 *)(v11 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v34 = *(_DWORD *)(v11 + 12);
            __dmb(0xBu);
          }
          while ( (v34 & 0x80000000) != 0 );
          do
            v35 = __ldrex(v33);
          while ( __strex(v35 | 0x80, v33) );
          __dmb(0xBu);
        }
        while ( v35 >> 7 );
      }
      *(_DWORD *)(v11 + 12) = *(_DWORD *)(v11 + 12) & 0xC0000000 | (*(_DWORD *)(v11 + 12) + 1) & 0x3FFFFFFF;
      __dmb(0xBu);
      v36 = (unsigned int *)(v11 + 12);
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 & 0x7FFFFFFF, v36) );
      v13 = (unsigned int)(v45 + 1);
      v15 = v50 + 24;
      v14 = (_WORD *)v52;
      ++v3;
      v45 = (unsigned int *)v13;
      v46 = v27 + 4;
      v50 += 24;
      if ( v13 > 4 * v51 )
      {
        v9 = a2;
        break;
      }
    }
  }
  v38 = (unsigned int *)(v54 + 36);
  v39 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v38);
  }
  else
  {
    v40 = (unsigned __int8 *)(v54 + 39);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 | 0x80, v40) );
    __dmb(0xBu);
    if ( v41 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v38);
    while ( 1 )
    {
      v42 = *v38;
      if ( (*v38 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v42 & 0x40000000) == 0 )
      {
        do
          v43 = __ldrex(v38);
        while ( v43 == v42 && __strex(v42 | 0x40000000, v38) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  ++*(_DWORD *)(v54 + 20);
  ++*(_DWORD *)(v54 + 24);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v38, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v38 = 0;
  }
  KfLowerIrql(v39);
  ++MEMORY[0xC0402124];
  MiUnlockWorkingSetExclusive(v55, v47);
  return MiUnlockVad(v56 & 0xFFFFFFC0, v9);
}
