// MiCopyHeaderIfResident 
 
int __fastcall MiCopyHeaderIfResident(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  unsigned int v6; // r2
  int v7; // r4
  _DWORD *v8; // r3
  _DWORD *v9; // r4
  unsigned int *v10; // r6
  int v11; // r10
  int v12; // r5
  int v13; // r3
  unsigned int v14; // r0
  BOOL v15; // r6
  int v16; // lr
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r0
  int v23; // r1
  unsigned int v24; // r0
  int *v25; // r0
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // [sp+0h] [bp-28h] BYREF
  int v29; // [sp+4h] [bp-24h]
  int v30; // [sp+8h] [bp-20h]

  v30 = a4;
  v28 = a1;
  v29 = a2;
  while ( 1 )
  {
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_51A510();
    do
      v6 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
    while ( __strex(v6 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
    while ( 1 )
    {
      v7 = dword_632E00;
      if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632E00 & 0x40000000) == 0 )
      {
        v23 = dword_632E00 | 0x40000000;
        do
          v24 = __ldrex((unsigned int *)&dword_632E00);
        while ( v24 == v7 && __strex(v23, (unsigned int *)&dword_632E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v8 = *(_DWORD **)(v28 + 20);
    if ( !v8 || (v9 = (_DWORD *)*v8) == 0 )
    {
      if ( (dword_682604 & 0x10000) == 0 )
      {
        __dmb(0xBu);
        dword_632E00 = 0;
LABEL_12:
        KfLowerIrql(v4);
        return 0;
      }
      v25 = &dword_632E00;
LABEL_65:
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v25);
      goto LABEL_12;
    }
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v9 + 9) )
      break;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
    }
    else
    {
      __dmb(0xBu);
      dword_632E00 = 0;
    }
    KfLowerIrql(v4);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
  }
  else
  {
    __dmb(0xBu);
    dword_632E00 = 0;
  }
  if ( (v9[7] & 3) != 0 || (v10 = (unsigned int *)v9[21]) == 0 )
  {
    if ( (dword_682604 & 0x10000) == 0 )
    {
      __dmb(0xBu);
      v9[9] = 0;
      goto LABEL_12;
    }
LABEL_55:
    v25 = v9 + 9;
    goto LABEL_65;
  }
  v11 = MiTryLockLeafAndContainingPagesAtDpc(v9[21], &v28, 0);
  if ( !v11 )
  {
    if ( (dword_682604 & 0x10000) == 0 )
    {
      __dmb(0xBu);
      v9[9] = 0;
      goto LABEL_12;
    }
    goto LABEL_55;
  }
  v12 = v28;
  if ( !v28 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v9 + 9);
    }
    else
    {
      __dmb(0xBu);
      v9[9] = 0;
    }
    KfLowerIrql(2);
    goto LABEL_39;
  }
  v13 = *(unsigned __int8 *)(v28 + 18);
  if ( (v13 & 0x20) != 0 )
    goto LABEL_58;
  if ( (v13 & 0xFFFFFFC0) != 64 )
    goto LABEL_58;
  if ( (*(_BYTE *)(v28 + 19) & 0x40) != 0 )
    goto LABEL_58;
  v14 = *v10;
  v15 = (*v10 & 2) == 0;
  v16 = v29;
  v29 = MmPfnDatabase + 24 * v29;
  v17 = (unsigned __int8 *)(v29 + 15);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 | 0x80, v17) );
  __dmb(0xBu);
  if ( v18 >> 7 )
  {
LABEL_58:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v9 + 9);
    }
    else
    {
      __dmb(0xBu);
      v9[9] = 0;
    }
    KfLowerIrql(2);
    __dmb(0xBu);
    v26 = (unsigned int *)(v12 + 12);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 & 0x7FFFFFFF, v26) );
LABEL_39:
    MiUnlockProtoPoolPage(v11, v4);
    return 0;
  }
  MiCopyPage(v16, v14 >> 12, 0, 4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v9 + 9);
  }
  else
  {
    __dmb(0xBu);
    v9[9] = 0;
  }
  KfLowerIrql(2);
  if ( v15 )
    MiUpdatePageAttributeStamp(v12);
  __dmb(0xBu);
  v19 = (unsigned int *)(v29 + 12);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 & 0x7FFFFFFF, v19) );
  __dmb(0xBu);
  v21 = (unsigned int *)(v12 + 12);
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 & 0x7FFFFFFF, v21) );
  MiUnlockProtoPoolPage(v11, v4);
  return 1;
}
