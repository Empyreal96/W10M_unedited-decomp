// KiAbProcessContextSwitch 
 
unsigned int __fastcall KiAbProcessContextSwitch(unsigned int result, int a2)
{
  int v2; // r4
  int v3; // r2
  _DWORD *v4; // r5
  unsigned int v5; // r9
  int v6; // r2
  int v7; // r2
  int v8; // r8
  int v9; // r9
  int v10; // r4
  unsigned int v11; // r6
  int v12; // r3
  int v13; // r0
  int v14; // r5
  char v15; // r3
  int v16; // r3
  char v17; // r2
  char v18; // r3
  int v19; // r0
  unsigned int *v20; // r1
  int *v21; // r0
  int v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r0
  int v26; // r10
  int v27; // r6
  int v28; // r0
  unsigned int *v29; // r1
  int *v30; // r0
  int v31; // r1
  int v32; // r0
  int v33; // r2
  unsigned int *v34; // r1
  int *v35; // r0
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int *v38; // r2
  unsigned int v39; // r0
  int v40; // r9
  _DWORD *v41; // r3
  _DWORD *v42; // r5
  unsigned __int16 *v43; // r2
  unsigned int v44; // r1
  int v45; // [sp+10h] [bp-48h] BYREF
  unsigned int v46; // [sp+14h] [bp-44h] BYREF
  _DWORD *v47; // [sp+18h] [bp-40h] BYREF
  int v48; // [sp+1Ch] [bp-3Ch]
  unsigned int v49; // [sp+20h] [bp-38h]
  unsigned int v50; // [sp+24h] [bp-34h]
  int v51; // [sp+28h] [bp-30h]
  int v52; // [sp+30h] [bp-28h] BYREF
  unsigned int *v53; // [sp+34h] [bp-24h]

  v2 = a2;
  v3 = *(char *)(result + 484);
  v51 = a2;
  __dmb(0xBu);
  if ( (*(char *)(result + 810) | v3) == 63 || !KiAbEnabled )
    return result;
  v4 = 0;
  v46 = 0;
  v47 = 0;
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v6 = *(char *)(result + 484);
  v48 = v5 + 18816;
  v49 = v5;
  __dmb(0xBu);
  if ( (v6 | *(char *)(result + 810)) == 63 )
    goto LABEL_31;
  v7 = *(char *)(result + 484);
  v45 = result + 488;
  __dmb(0xBu);
  v8 = (v7 | *(char *)(result + 810)) ^ 0x3F;
  result = __clz(__rbit(v8));
  v50 = result;
  if ( 1 == (unsigned __int8)(result >> 5) )
    goto LABEL_31;
  v9 = v45;
  v10 = v48;
  do
  {
    v8 &= v8 - 1;
    v11 = v9 + 48 * result;
    v12 = *(_DWORD *)(v11 + 16);
    if ( !v12 || (v12 & 2) != 0 || (v12 & 1) != 0 )
      goto LABEL_28;
    if ( *(int *)(v11 + 16) < 0 )
    {
      if ( (*(_BYTE *)(v11 + 15) & 1) != 0 )
        goto LABEL_28;
      v25 = v9 + 48 * result;
      if ( (*(_BYTE *)(v11 + 13) & 1) != 0 )
      {
        if ( KiAbWaiterComputeCpuPriorityKey(v25) == *(char *)(v11 + 24) )
          goto LABEL_28;
      }
      else if ( KiAbOwnerComputeCpuPriorityKey(v25) == *(char *)(v11 + 24) )
      {
        goto LABEL_28;
      }
    }
    v13 = KiAbEntryGetLockedHeadEntry(v11, 1, &v52);
    v14 = v13;
    if ( !v13 )
      goto LABEL_28;
    if ( (*(_BYTE *)(v11 + 13) & 1) != 0 )
    {
      if ( v11 != v13 )
        KiAbEntryUpdateWaiterTreePosition(v11, v13);
      KiAbDetermineMinOwnerPriority(v14, &v45);
      v26 = KiAbTryIncrementIoWaiterCount(v11, v14);
      v27 = KiAbEntryGetCpuPriorityKey(v11);
      if ( (char)v45 < v27 )
      {
        if ( !v26 )
          goto LABEL_47;
      }
      else if ( !v26 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
LABEL_83:
          KiReleaseQueuedSpinLockInstrumented(&v52);
          goto LABEL_28;
        }
        v19 = v52;
        if ( v52 )
          goto LABEL_73;
        v34 = v53;
        __dmb(0xBu);
        do
          v35 = (int *)__ldrex(v34);
        while ( v35 == &v52 && __strex(0, v34) );
        if ( v35 != &v52 )
        {
          v22 = KxWaitForLockChainValid(&v52);
          v52 = 0;
          __dmb(0xBu);
          v23 = (unsigned int *)(v22 + 4);
          do
            v24 = __ldrex(v23);
          while ( __strex(v24 ^ 1, v23) );
        }
        goto LABEL_28;
      }
      KiAbIoBoostOwners(v14, &v47, &v46, v10);
LABEL_47:
      KiAbCpuBoostOwners(v14, v27, &v47, &v46, v10);
      goto LABEL_48;
    }
    if ( v11 != v13 )
      KiAbEntryUpdateOwnerTreePosition(v11, v13);
    if ( *(_WORD *)(v14 + 46) )
      v15 = 2;
    else
      v15 = 0;
    BYTE1(v45) = v15;
    v16 = *(_DWORD *)(v14 + 36);
    if ( v16 )
      v17 = *(_BYTE *)(v16 + 24);
    else
      v17 = 0;
    v18 = *(_BYTE *)(v14 + 13);
    LOBYTE(v45) = v17;
    if ( (v18 & 1) != 0 )
    {
      v32 = KiAbWaiterComputeCpuPriorityKey(v14);
      if ( v32 > v33 )
        LOBYTE(v45) = v32;
    }
    if ( !(_WORD)v45 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
        return sub_50D740();
      v19 = v52;
      if ( v52 )
        goto LABEL_73;
      v20 = v53;
      __dmb(0xBu);
      do
        v21 = (int *)__ldrex(v20);
      while ( v21 == &v52 && __strex(0, v20) );
      if ( v21 != &v52 )
      {
        v19 = KxWaitForLockChainValid(&v52);
LABEL_73:
        v52 = 0;
        __dmb(0xBu);
        v36 = (unsigned int *)(v19 + 4);
        do
          v37 = __ldrex(v36);
        while ( __strex(v37 ^ 1, v36) );
        goto LABEL_28;
      }
      goto LABEL_28;
    }
    if ( KiAbSetMinimumThreadPriority(v11, &v45, &v47, &v46, v10) && v11 != v14 )
      KiAbEntryUpdateOwnerTreePosition(v11, v14);
LABEL_48:
    if ( (dword_682604 & 0x10000) != 0 )
      goto LABEL_83;
    v28 = v52;
    if ( v52 )
      goto LABEL_78;
    v29 = v53;
    __dmb(0xBu);
    do
      v30 = (int *)__ldrex(v29);
    while ( v30 == &v52 && __strex(0, v29) );
    if ( v30 != &v52 )
    {
      v28 = KxWaitForLockChainValid(&v52);
LABEL_78:
      v52 = 0;
      __dmb(0xBu);
      v38 = (unsigned int *)(v28 + 4);
      do
        v39 = __ldrex(v38);
      while ( __strex(v39 ^ 1, v38) );
    }
LABEL_28:
    result = __clz(__rbit(v8));
    v50 = result;
  }
  while ( 1 != (unsigned __int8)(result >> 5) );
  result = v46;
  v2 = v51;
  v5 = v49;
  if ( v46 )
  {
    v40 = v48;
    do
    {
      v41 = (_DWORD *)result;
      if ( result )
      {
        result = *(_DWORD *)result;
        v46 = result;
      }
      v42 = v41 - 194;
      *v41 = 1;
      __dmb(0xFu);
      if ( *((_BYTE *)v41 - 291) )
      {
        KiAbProcessThreadLocks(v42, 0, 1, 0, &v47, &v46, v40);
        result = v46;
      }
      __dmb(0xBu);
      v43 = (unsigned __int16 *)(v42 + 202);
      do
        v44 = __ldrex(v43);
      while ( __strex(v44 - 1, v43) );
      __dmb(0xBu);
    }
    while ( result );
    v5 = v49;
  }
  v4 = v47;
LABEL_31:
  while ( v4 )
  {
    v31 = (int)(v4 - 36);
    v4 = (_DWORD *)*v4;
    result = KiDeferredReadyThread(v5 + 1408, v31);
  }
  if ( v2 && *(_DWORD *)(v5 + 1416) && !*(_BYTE *)(v5 + 3162) )
    result = HalRequestSoftwareInterrupt(2);
  return result;
}
