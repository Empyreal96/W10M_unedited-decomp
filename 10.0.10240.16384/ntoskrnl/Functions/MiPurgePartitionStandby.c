// MiPurgePartitionStandby 
 
int __fastcall MiPurgePartitionStandby(int a1, int a2)
{
  int result; // r0
  int i; // r6
  int v6; // r5
  int v7; // r10
  unsigned __int8 *v8; // r3
  unsigned int v9; // r4
  unsigned __int8 *v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r0

  result = MiRemoveLowestPriorityStandbyPage(a1, a2);
  for ( i = result; result != -1; i = result )
  {
    v6 = MmPfnDatabase + 24 * i;
    v7 = KfRaiseIrql(2);
    v8 = (unsigned __int8 *)(v6 + 15);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
    {
      v10 = (unsigned __int8 *)(v6 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v11 = *(_DWORD *)(v6 + 12);
          __dmb(0xBu);
        }
        while ( v11 < 0 );
        do
          v12 = __ldrex(v10);
        while ( __strex(v12 | 0x80, v10) );
        __dmb(0xBu);
      }
      while ( v12 >> 7 );
    }
    *(_DWORD *)(v6 + 12) |= 0x40000000u;
    MiInsertPageInFreeOrZeroedList(i, 2);
    __dmb(0xBu);
    v13 = (unsigned int *)(v6 + 12);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 & 0x7FFFFFFF, v13) );
    KfLowerIrql(v7);
    result = MiRemoveLowestPriorityStandbyPage(a1, a2);
  }
  return result;
}
