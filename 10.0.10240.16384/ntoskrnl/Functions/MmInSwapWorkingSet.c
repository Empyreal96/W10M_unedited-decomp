// MmInSwapWorkingSet 
 
int __fastcall MmInSwapWorkingSet(int a1)
{
  int v2; // r9
  int *v3; // r6
  int v4; // r6
  unsigned int v5; // r1
  int v6; // r6
  unsigned int v7; // r0
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r6
  unsigned int v11; // r0
  int v12; // r3
  int var38[15]; // [sp+0h] [bp-38h] BYREF
  int vars4; // [sp+3Ch] [bp+4h]

  var38[0] = 0;
  EtwTraceWorkingSetSwap(a1, 3, var38, 0);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_63F990);
  }
  else
  {
    do
      v5 = __ldrex((unsigned __int8 *)&dword_63F990 + 3);
    while ( __strex(v5 | 0x80, (unsigned __int8 *)&dword_63F990 + 3) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F990);
    while ( 1 )
    {
      v6 = dword_63F990;
      if ( (dword_63F990 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_63F990 & 0x40000000) == 0 )
      {
        do
          v7 = __ldrex((unsigned int *)&dword_63F990);
        while ( v7 == v6 && __strex(v6 | 0x40000000, (unsigned int *)&dword_63F990) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v3 = *(int **)(a1 + 612);
  if ( v3 )
  {
    if ( v3 == (int *)1 )
    {
      v4 = -1073740682;
    }
    else if ( v3 == (int *)2 )
    {
      v4 = -1073741558;
    }
    else
    {
      *(_DWORD *)(a1 + 612) = 1;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F990, vars4);
      }
      else
      {
        __dmb(0xBu);
        dword_63F990 = 0;
      }
      KfLowerIrql(v2);
      if ( dword_63F9A0 )
      {
        MiInSwapStore(a1);
        SmStoreSetProcessVaRanges(0, 0);
      }
      MiProcessWsInSwapSupport(*v3, 0);
      v8 = v3[7];
      if ( v8 )
        MiProcessWsInSwapSupport(v8, 1);
      if ( v3[1] )
      {
        v3[4] = (int)MiInSwapSharedWorkingSetWorker;
        v3[5] = (int)v3;
        v3[2] = 0;
        ObfReferenceObjectWithTag(a1);
        v3[6] = a1;
        ExQueueWorkItem(v3 + 2, 3);
      }
      else
      {
        MiFreeWorkingSetSwapContext(MiSystemPartition, v3);
      }
      v2 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_63F990);
      }
      else
      {
        do
          v9 = __ldrex((unsigned __int8 *)&dword_63F990 + 3);
        while ( __strex(v9 | 0x80, (unsigned __int8 *)&dword_63F990 + 3) );
        __dmb(0xBu);
        if ( v9 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F990);
        while ( 1 )
        {
          v10 = dword_63F990;
          if ( (dword_63F990 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (dword_63F990 & 0x40000000) == 0 )
          {
            do
              v11 = __ldrex((unsigned int *)&dword_63F990);
            while ( v11 == v10 && __strex(v10 | 0x40000000, (unsigned int *)&dword_63F990) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      if ( *(_DWORD *)(a1 + 612) == 1 )
        *(_DWORD *)(a1 + 612) = 0;
      v4 = 0;
    }
  }
  else
  {
    v4 = -1073741275;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F990, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_63F990 = 0;
  }
  KfLowerIrql(v2);
  MiContractWsSwapPageFile(MiSystemPartition);
  var38[4] = v4;
  EtwTraceWorkingSetSwap(a1, 1, var38, v12);
  return v4;
}
