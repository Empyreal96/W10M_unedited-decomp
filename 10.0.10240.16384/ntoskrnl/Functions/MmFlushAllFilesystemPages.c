// MmFlushAllFilesystemPages 
 
int *__fastcall MmFlushAllFilesystemPages(int a1)
{
  int (*v2)(); // r4
  int *result; // r0
  unsigned int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r1
  unsigned int v7; // r1
  int v8; // r8
  unsigned int i; // r5
  unsigned int v10; // r1

  v2 = *(int (**)())((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x39C);
  result = (int *)KeGetCurrentIrql(a1);
  if ( (unsigned int)result <= 1
    && v2 != KeBalanceSetManager
    && (char *)v2 != (char *)MiModifiedPageWriter
    && (char *)v2 != (char *)MiMappedPageWriter )
  {
    if ( a1 == 1 )
    {
      result = MiState;
      do
      {
        v4 = __ldrex(&dword_634354);
        v5 = v4 + 1;
      }
      while ( __strex(v5, &dword_634354) );
      __dmb(0xBu);
      if ( v5 != 1 )
        return result;
      if ( byte_634C8C )
      {
        ++*(_DWORD *)(dword_6404B8 + 20);
        result = (int *)MiQueueWorkingSetRequest(MiSystemPartition, 4);
      }
    }
    do
      v6 = __ldrex(&dword_63F8C0);
    while ( __strex(v6 + 1, &dword_63F8C0) );
    __dmb(0xBu);
    if ( dword_640680 == dword_640718 )
    {
      __dmb(0xBu);
      do
        v7 = __ldrex(&dword_63F8C0);
      while ( __strex(v7 - 1, &dword_63F8C0) );
    }
    else
    {
      v8 = dword_63F888;
      for ( i = 0; i < 0xFF; ++i )
      {
        KeSetEvent((int)&unk_63F8C4, 0, 0);
        result = (int *)CcNotifyWriteBehind(2);
        if ( dword_640680 == dword_640718 )
          break;
        result = (int *)KeDelayExecutionThread(0, 0, (unsigned int *)Mi30Milliseconds);
        if ( v8 != dword_63F888 )
        {
          v8 = dword_63F888;
          i = -1;
        }
      }
      __dmb(0xBu);
      do
        v10 = __ldrex(&dword_63F8C0);
      while ( __strex(v10 - 1, &dword_63F8C0) );
    }
  }
  return result;
}
