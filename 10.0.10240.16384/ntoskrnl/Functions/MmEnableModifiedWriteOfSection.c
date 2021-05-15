// MmEnableModifiedWriteOfSection 
 
int __fastcall MmEnableModifiedWriteOfSection(int a1)
{
  int v1; // r0
  int v2; // r4
  int v4; // r3
  int v5; // r10
  int v6; // r2
  int v7; // r3
  _DWORD *v8; // r6
  int v9; // r0
  unsigned int *v10; // r1
  int *v11; // r0
  int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r0
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  int v17; // r0
  unsigned int *v18; // r1
  int *v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r0
  unsigned int *v23; // r1
  int *v24; // r0
  unsigned int *v25; // r2
  unsigned int v26; // r0
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int v29; // r2
  char v30[8]; // [sp+0h] [bp-30h] BYREF
  int v31; // [sp+8h] [bp-28h] BYREF
  unsigned int *v32; // [sp+Ch] [bp-24h]
  int vars4; // [sp+34h] [bp+4h]

  v1 = MiLockSectionControlArea(a1, 1, v30);
  v2 = v1;
  if ( !v1 )
    return sub_523B44();
  v4 = *(_DWORD *)(v1 + 28);
  if ( (v4 & 8) == 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v1 + 36);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v1 + 36) = 0;
    }
    v12 = (unsigned __int8)v30[0];
    goto LABEL_18;
  }
  *(_DWORD *)(v1 + 28) = v4 & 0xFFFFFFF7;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v1 + 36);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v1 + 36) = 0;
  }
  KfLowerIrql((unsigned __int8)v30[0]);
  if ( dword_640708 == 0xFFFFF )
    return 1;
  v5 = KfRaiseIrql(2);
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640710, &v31, v6, 4112);
  v7 = dword_640708;
  if ( dword_640708 != 0xFFFFF )
  {
    while ( 1 )
    {
      v8 = (_DWORD *)(MmPfnDatabase + 24 * v7);
      if ( v2 == *(_DWORD *)(v8[2] & 0xFFFFF800 | (2 * (v8[2] & 0x3FC))) )
        break;
      v7 = *v8;
LABEL_10:
      if ( v7 == 0xFFFFF )
        goto LABEL_11;
    }
    v15 = (unsigned __int8 *)v8 + 15;
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 0x80, v15) );
    __dmb(0xBu);
    if ( v16 >> 7 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(&v31, vars4);
      }
      else
      {
        v17 = v31;
        if ( !v31 )
        {
          v18 = v32;
          __dmb(0xBu);
          do
            v19 = (int *)__ldrex(v18);
          while ( v19 == &v31 && __strex(0, v18) );
          if ( v19 == &v31 )
            goto LABEL_55;
          v17 = KxWaitForLockChainValid(&v31);
        }
        v31 = 0;
        __dmb(0xBu);
        v20 = (unsigned int *)(v17 + 4);
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 ^ 1, v20) );
      }
LABEL_55:
      KfLowerIrql(v5);
      v5 = KfRaiseIrql(2);
      KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640710, &v31, v29, 4112);
      v7 = dword_640708;
      goto LABEL_10;
    }
    MiUnlinkPageFromList(v8, 1);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v31, vars4);
    }
    else
    {
      v22 = v31;
      if ( !v31 )
      {
        v23 = v32;
        __dmb(0xBu);
        do
          v24 = (int *)__ldrex(v23);
        while ( v24 == &v31 && __strex(0, v23) );
        if ( v24 == &v31 )
          goto LABEL_53;
        v22 = KxWaitForLockChainValid(&v31);
      }
      v31 = 0;
      __dmb(0xBu);
      v25 = (unsigned int *)(v22 + 4);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 ^ 1, v25) );
    }
LABEL_53:
    MiInsertPageInList(v8, 8);
    __dmb(0xBu);
    v27 = v8 + 3;
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 & 0x7FFFFFFF, v27) );
    goto LABEL_55;
  }
LABEL_11:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v31, vars4);
  }
  else
  {
    v9 = v31;
    if ( !v31 )
    {
      v10 = v32;
      __dmb(0xBu);
      do
        v11 = (int *)__ldrex(v10);
      while ( v11 == &v31 && __strex(0, v10) );
      if ( v11 == &v31 )
        goto LABEL_17;
      v9 = KxWaitForLockChainValid(&v31);
    }
    v31 = 0;
    __dmb(0xBu);
    v13 = (unsigned int *)(v9 + 4);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 ^ 1, v13) );
  }
LABEL_17:
  v12 = v5;
LABEL_18:
  KfLowerIrql(v12);
  return 1;
}
