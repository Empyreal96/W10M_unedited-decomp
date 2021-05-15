// MmChangeSectionBackingFile 
 
int __fastcall MmChangeSectionBackingFile(unsigned int a1, int a2, int a3)
{
  char v3; // r8
  unsigned int v7; // r2
  int v8; // r4
  _DWORD *v9; // r3
  _DWORD *v10; // r4
  unsigned int v11; // r5
  unsigned int v12; // r0
  int v13; // r1
  unsigned int v14; // r0
  int *v15; // r0
  int v16; // [sp+0h] [bp-20h]

  v3 = a3;
  if ( (a3 & 0xFFFFFFFC) != 0 || a3 == 3 )
    return sub_524E58();
  if ( a1 && *(_DWORD *)(a1 + 20) != *(_DWORD *)(a2 + 20) )
    return -1073741584;
  while ( 1 )
  {
    v16 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632E00);
    }
    else
    {
      do
        v7 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
      while ( __strex(v7 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
      __dmb(0xBu);
      if ( v7 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
      while ( 1 )
      {
        v8 = dword_632E00;
        if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632E00 & 0x40000000) == 0 )
        {
          v13 = dword_632E00 | 0x40000000;
          do
            v14 = __ldrex((unsigned int *)&dword_632E00);
          while ( v14 == v8 && __strex(v13, (unsigned int *)&dword_632E00) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v9 = *(_DWORD **)(a2 + 20);
    v10 = (_DWORD *)((v3 & 1) != 0 ? *v9 : v9[2]);
    if ( !v10 )
      break;
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v10 + 9) )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      }
      else
      {
        __dmb(0xBu);
        dword_632E00 = 0;
      }
      if ( (v10[7] & 1) == 0 )
      {
        if ( a1 )
        {
          if ( (v10[8] & 0xFFFFFFF8) == a1 )
          {
            ObFastReplaceObject(v10 + 8, a2);
            ObfReferenceObjectWithTag(a2, 1953261124);
            v12 = a1;
LABEL_20:
            ObDereferenceObjectDeferDeleteWithTag(v12, 1953261124);
          }
        }
        else
        {
          v11 = v10[8] & 0xFFFFFFF8;
          if ( v11 )
          {
            ObFastReplaceObject(v10 + 8, a2);
            ObfReferenceObjectWithTag(a2, 1953261124);
            v12 = v11;
            goto LABEL_20;
          }
        }
      }
      if ( (v10[7] & 0x200) != 0 && (*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C8) & 0x40) == 0 )
        v10[7] &= 0xFFFFFDFF;
      if ( (dword_682604 & 0x10000) == 0 )
      {
        __dmb(0xBu);
        v10[9] = 0;
        goto LABEL_26;
      }
      v15 = v10 + 9;
LABEL_47:
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v15);
      goto LABEL_26;
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
    KfLowerIrql(v16);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v15 = &dword_632E00;
    goto LABEL_47;
  }
  __dmb(0xBu);
  dword_632E00 = 0;
LABEL_26:
  KfLowerIrql(v16);
  return 0;
}
