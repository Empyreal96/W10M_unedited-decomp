// KiAbEntryRemoveFromTree 
 
int __fastcall KiAbEntryRemoveFromTree(int a1)
{
  int v2; // r2
  int v3; // r10
  BOOL i; // r2
  unsigned int *v5; // lr
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int *v9; // lr
  int v10; // r4
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r0
  unsigned int *v16; // r1
  int *v17; // r0
  int v18; // r2
  unsigned __int8 *v19; // r2
  unsigned int v20; // r0
  unsigned int *v22; // r0
  unsigned int v23; // r6
  int v24; // r2
  int v25; // r3
  int v26; // r0
  unsigned int *v27; // r1
  int *v28; // r0
  int v29; // r0
  unsigned int v30; // r1
  unsigned int v31; // r1
  unsigned int v32; // r2
  int v33; // r6
  int v34; // r0
  unsigned int *v35; // r1
  int *v36; // r0
  unsigned int *v37; // r2
  unsigned int v38; // r0
  unsigned int *v39; // r2
  unsigned int v40; // r0
  unsigned int v41; // r1
  unsigned int v42; // r2
  int v43; // r0
  unsigned int *v44; // r1
  int *v45; // r0
  unsigned int v46; // r1
  unsigned int *v47; // r2
  unsigned int v48; // r0
  unsigned int *v49; // r2
  unsigned int v50; // r0
  unsigned int *v51; // [sp+0h] [bp-50h]
  unsigned int *v52; // [sp+4h] [bp-4Ch]
  BOOL v53; // [sp+8h] [bp-48h]
  unsigned int v54; // [sp+10h] [bp-40h]
  unsigned int v55; // [sp+14h] [bp-3Ch]
  int v56; // [sp+18h] [bp-38h] BYREF
  unsigned int *v57; // [sp+1Ch] [bp-34h]
  int var28[11]; // [sp+28h] [bp-28h] BYREF

  v55 = *(_DWORD *)(a1 + 20);
  v54 = *(_DWORD *)(a1 + 16) & 0x7FFFFFFC;
  v2 = (v54 >> 3) & 3;
  v51 = (unsigned int *)&dword_646D88[32 * v2];
  v52 = (unsigned int *)((char *)&KiAbTreeArray + 128 * v2);
  v3 = KfRaiseIrql(2);
  for ( i = (*(_BYTE *)(a1 + 15) & 1) != 0; ; i = 1 )
  {
    v53 = i;
    if ( i )
    {
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v51);
      }
      else
      {
        v5 = v51;
        v6 = (unsigned __int8 *)v51 + 3;
        do
          v7 = __ldrex(v6);
        while ( __strex(v7 | 0x80, v6) );
        __dmb(0xBu);
        if ( v7 >> 7 )
        {
          ExpWaitForSpinLockExclusiveAndAcquire(v51);
          v5 = v51;
        }
        while ( 1 )
        {
          v8 = *v5;
          if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v8 & 0x40000000) == 0 )
          {
            do
              v46 = __ldrex(v5);
            while ( v46 == v8 && __strex(v8 | 0x40000000, v5) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    else
    {
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_50D7E0();
      v29 = *v51 & 0x7FFFFFFF;
      do
        v30 = __ldrex(v51);
      while ( v30 == v29 && __strex(v29 + 1, v51) );
      __dmb(0xBu);
      if ( v30 != v29 )
        ExpWaitForSpinLockSharedAndAcquire(v51);
    }
    v9 = v52;
    v10 = *v52;
    if ( *v52 )
    {
      do
      {
        v11 = *(_DWORD *)(v10 + 16) & 0x7FFFFFFC;
        if ( v11 > v54 )
          goto LABEL_35;
        if ( v11 < v54 )
          goto LABEL_38;
        v12 = *(_DWORD *)(v10 + 20);
        if ( v12 == v55 )
          break;
        if ( v12 < v55 )
LABEL_38:
          v10 = *(_DWORD *)(v10 + 4);
        else
LABEL_35:
          v10 = *(_DWORD *)v10;
      }
      while ( v10 );
    }
    v13 = (unsigned int *)(v10 + 40);
    v56 = 0;
    v57 = (unsigned int *)(v10 + 40);
    __dmb(0xBu);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireQueuedSpinLockInstrumented(&v56, v13);
      goto LABEL_85;
    }
    do
      v14 = __ldrex(v13);
    while ( __strex((unsigned int)&v56, v13) );
    __dmb(0xBu);
    if ( v14 )
    {
      KxWaitForLockOwnerShip(&v56);
LABEL_85:
      v9 = v52;
    }
    if ( v10 != a1 )
    {
      if ( v53 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v51);
        }
        else
        {
          __dmb(0xBu);
          *v51 = 0;
        }
      }
      else if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v51);
      }
      else
      {
        __dmb(0xBu);
        do
          v31 = __ldrex(v51);
        while ( __strex(v31 & 0xBFFFFFFF, v51) );
        __dmb(0xBu);
        do
          v32 = __ldrex(v51);
        while ( __strex(v32 - 1, v51) );
      }
      *(_BYTE *)(a1 + 19) &= 0x7Fu;
      if ( (*(_BYTE *)(a1 + 13) & 1) != 0 )
      {
        v33 = v10 + 32;
        KiAbTryDecrementIoWaiterCount(a1, v10);
      }
      else
      {
        v33 = v10 + 24;
      }
      RtlRbRemoveNode(v33, a1);
      if ( (dword_682604 & 0x10000) == 0 )
      {
        v34 = v56;
        if ( !v56 )
        {
          v35 = v57;
          __dmb(0xBu);
          do
            v36 = (int *)__ldrex(v35);
          while ( v36 == &v56 && __strex(0, v35) );
          if ( v36 == &v56 )
            goto LABEL_30;
          v34 = KxWaitForLockChainValid(&v56);
        }
        v56 = 0;
        __dmb(0xBu);
        v37 = (unsigned int *)(v34 + 4);
        do
          v38 = __ldrex(v37);
        while ( __strex(v38 ^ 1, v37) );
        goto LABEL_30;
      }
LABEL_118:
      KiReleaseQueuedSpinLockInstrumented(&v56);
      goto LABEL_30;
    }
    if ( v53 )
      break;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v51);
    }
    else
    {
      __dmb(0xBu);
      do
        v41 = __ldrex(v51);
      while ( __strex(v41 & 0xBFFFFFFF, v51) );
      __dmb(0xBu);
      do
        v42 = __ldrex(v51);
      while ( __strex(v42 - 1, v51) );
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v56);
      continue;
    }
    v43 = v56;
    if ( v56 )
      goto LABEL_106;
    v44 = v57;
    __dmb(0xBu);
    do
      v45 = (int *)__ldrex(v44);
    while ( v45 == &v56 && __strex(0, v44) );
    if ( v45 != &v56 )
    {
      v43 = KxWaitForLockChainValid(&v56);
LABEL_106:
      v56 = 0;
      __dmb(0xBu);
      v49 = (unsigned int *)(v43 + 4);
      do
        v50 = __ldrex(v49);
      while ( __strex(v50 ^ 1, v49) );
      continue;
    }
  }
  if ( *(_DWORD *)(v10 + 32) )
  {
    v22 = (unsigned int *)(v10 + 32);
    goto LABEL_41;
  }
  if ( *(_DWORD *)(v10 + 24) )
  {
    v22 = (unsigned int *)(v10 + 24);
LABEL_41:
    if ( !v22 )
      goto LABEL_20;
    v23 = *v22;
    RtlRbRemoveNode(v22, *v22);
    RtlRbReplaceNode(v52, (_DWORD *)v10, v23);
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v23 + 40, var28, v24, v25);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v51);
    }
    else
    {
      __dmb(0xBu);
      *v51 = 0;
    }
    *(_DWORD *)(v23 + 24) = *(_DWORD *)(v10 + 24);
    *(_DWORD *)(v23 + 28) = *(_DWORD *)(v10 + 28);
    *(_DWORD *)(v23 + 32) = *(_DWORD *)(v10 + 32);
    *(_DWORD *)(v23 + 36) = *(_DWORD *)(v10 + 36);
    *(_WORD *)(v23 + 46) = *(_WORD *)(v10 + 46);
    KiAbTryDecrementIoWaiterCount(v10, v23);
    *(_BYTE *)(v23 + 15) |= 1u;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(var28);
      goto LABEL_24;
    }
    v26 = var28[0];
    if ( !var28[0] )
    {
      v27 = (unsigned int *)var28[1];
      __dmb(0xBu);
      do
        v28 = (int *)__ldrex(v27);
      while ( v28 == var28 && __strex(0, v27) );
      if ( v28 == var28 )
        goto LABEL_24;
      v26 = KxWaitForLockChainValid(var28);
    }
    var28[0] = 0;
    __dmb(0xBu);
    v47 = (unsigned int *)(v26 + 4);
    do
      v48 = __ldrex(v47);
    while ( __strex(v48 ^ 1, v47) );
    goto LABEL_24;
  }
LABEL_20:
  RtlRbRemoveNode(v9, v10);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v51);
  }
  else
  {
    __dmb(0xBu);
    *v51 = 0;
  }
  if ( (*(_BYTE *)(v10 + 15) & 2) != 0 )
    *(_BYTE *)(v10 + 15) &= 0xFDu;
LABEL_24:
  *(_BYTE *)(v10 + 19) &= 0x7Fu;
  *(_BYTE *)(v10 + 15) &= 0xFEu;
  if ( (dword_682604 & 0x10000) != 0 )
    goto LABEL_118;
  v15 = v56;
  if ( !v56 )
  {
    v16 = v57;
    __dmb(0xBu);
    do
      v17 = (int *)__ldrex(v16);
    while ( v17 == &v56 && __strex(0, v16) );
    if ( v17 == &v56 )
      goto LABEL_30;
    v15 = KxWaitForLockChainValid(&v56);
  }
  v56 = 0;
  __dmb(0xBu);
  v39 = (unsigned int *)(v15 + 4);
  do
    v40 = __ldrex(v39);
  while ( __strex(v40 ^ 1, v39) );
LABEL_30:
  v18 = a1 - 8 * *(unsigned __int8 *)(a1 + 12);
  if ( (*(_BYTE *)(a1 + 13) & 1) != 0 )
  {
    --*(_BYTE *)(v18 + 485);
  }
  else
  {
    __dmb(0xBu);
    v19 = (unsigned __int8 *)(v18 + 811);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 - 1, v19) );
    __dmb(0xBu);
  }
  return KfLowerIrql(v3);
}
