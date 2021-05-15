// SepExpandSingletonArrays 
 
// local variable allocation has failed, the output may be wrong!
int SepExpandSingletonArrays()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r6
  unsigned int *v2; // r4
  int v3; // r8
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  int v7; // r0
  int v8; // r5
  int *v9; // r4
  int *v10; // r0
  int v11; // r4 OVERLAPPED
  int v12; // r3
  int result; // r0
  unsigned int v14; // r1

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 1536, 1950639443);
  v1 = v0;
  if ( !v0 )
    JUMPOUT(0x50FB20);
  memset(v0, 0, 1536);
  v2 = (unsigned int *)SepSingletonGlobal;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
  }
  else
  {
    v4 = (unsigned __int8 *)v2 + 3;
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v2);
    while ( 1 )
    {
      v6 = *v2;
      if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v6 & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex(v2);
        while ( v14 == v6 && __strex(v6 | 0x40000000, v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v7 = ExAllocatePoolWithTag(512, 4 * (SepSingletonGlobal[1] + 1), 1950639443);
  v8 = v7;
  if ( v7 )
  {
    v9 = SepSingletonGlobal;
    memmove(v7, SepSingletonGlobal[2], 4 * SepSingletonGlobal[1]);
    *(_DWORD *)(v8 + 4 * v9[1]) = v1;
    v10 = SepSingletonGlobal;
    *(_QWORD *)(&v11 - 1) = *(_QWORD *)(SepSingletonGlobal + 1);
    SepSingletonGlobal[2] = v8;
    v10[1] = v12 + 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10);
    }
    else
    {
      __dmb(0xBu);
      *v10 = 0;
    }
    KfLowerIrql(v3);
    ExFreePoolWithTag(v11, 1950639443);
    result = 0;
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(SepSingletonGlobal);
      JUMPOUT(0x50FB10);
    }
    result = sub_50FB08(SepSingletonGlobal);
  }
  return result;
}
