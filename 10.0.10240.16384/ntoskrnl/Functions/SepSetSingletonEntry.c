// SepSetSingletonEntry 
 
int __fastcall SepSetSingletonEntry(unsigned int a1, int *a2, int a3)
{
  int v5; // r5
  int v6; // r4
  int v7; // r6
  _DWORD *v8; // r0
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  _DWORD *v13; // r3
  _DWORD *v14; // r3
  int vars4; // [sp+24h] [bp+4h]

  v5 = 0;
  v6 = SepGetSingletonEntryFromIndexNumber(a1);
  if ( v6 )
  {
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)v6);
    }
    else
    {
      v9 = (unsigned __int8 *)(v6 + 3);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 0x80, v9) );
      __dmb(0xBu);
      if ( v10 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v6);
      while ( 1 )
      {
        v11 = *(_DWORD *)v6;
        if ( (*(_DWORD *)v6 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v11 & 0x40000000) == 0 )
        {
          do
            v12 = __ldrex((unsigned int *)v6);
          while ( v12 == v11 && __strex(v11 | 0x40000000, (unsigned int *)v6) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( !*(_DWORD *)(v6 + 16) )
    {
      v8 = (_DWORD *)ExAllocatePoolWithTag(512, 24);
      *(_DWORD *)(v6 + 16) = v8;
      if ( !v8 )
      {
        v5 = -1073741801;
        if ( (dword_682604 & 0x10000) == 0 )
          goto LABEL_21;
        goto LABEL_20;
      }
      *v8 = 0;
      *(_DWORD *)(*(_DWORD *)(v6 + 16) + 12) = 0;
      v13 = (_DWORD *)(*(_DWORD *)(v6 + 16) + 4);
      *v13 = v13;
      v13[1] = v13;
      v14 = (_DWORD *)(*(_DWORD *)(v6 + 16) + 16);
      *v14 = v14;
      v14[1] = v14;
    }
    v5 = AuthzBasepSetSecurityAttributesToken(*(_DWORD *)(v6 + 16), a2, a3);
    SepSingletonGlobal[3] |= 1u;
    if ( (dword_682604 & 0x10000) == 0 )
    {
LABEL_21:
      __dmb(0xBu);
      *(_DWORD *)v6 = 0;
      goto LABEL_22;
    }
LABEL_20:
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)v6, vars4);
LABEL_22:
    KfLowerIrql(v7);
  }
  return v5;
}
