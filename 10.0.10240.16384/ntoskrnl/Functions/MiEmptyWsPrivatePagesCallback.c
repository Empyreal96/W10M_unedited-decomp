// MiEmptyWsPrivatePagesCallback 
 
int __fastcall MiEmptyWsPrivatePagesCallback(int a1, _DWORD *a2, unsigned int a3)
{
  unsigned int v4; // r5
  unsigned int *i; // r8
  unsigned int v7; // r3
  unsigned int *v8; // r1
  int result; // r0
  unsigned int v10; // r4
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r0
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r4
  unsigned int v17; // r1

  v4 = (unsigned int)a2;
  for ( i = *(unsigned int **)a1; v4 <= a3; v4 += 4 )
  {
    v7 = *(_DWORD *)v4;
    if ( (*(_DWORD *)v4 & 2) != 0 )
    {
      v10 = v7 >> 12;
      if ( MI_IS_PFN(v7 >> 12) )
      {
        v11 = (unsigned int *)(MmPfnDatabase + 24 * v10);
        if ( (v11[5] & 0x8000000) == 0 && (v11[1] | 0x80000000) == v4 )
        {
          v12 = MiLocateWsle(v4 << 10, (int)i, *v11);
          if ( v12 >= *(_DWORD *)(i[23] + 4) )
            MiEmptyWorkingSetHelper(i, v4, v12, *(_DWORD *)(a1 + 8));
        }
      }
    }
  }
  v8 = *(unsigned int **)(a1 + 8);
  if ( *v8 )
  {
    MiFreeWsleList((int)i, v8, 0);
    **(_DWORD **)(a1 + 8) = 0;
  }
  if ( ExSpinLockIsContended(i) || (result = KeShouldYieldProcessor()) != 0 )
  {
    MiUnlockWorkingSetExclusive(i, *(unsigned __int8 *)(a1 + 4));
    v13 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_53DEA4(v13);
    }
    else
    {
      v14 = (unsigned __int8 *)i + 3;
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(i);
      result = 0x40000000;
      while ( 1 )
      {
        v16 = *i;
        if ( (*i & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v16 & 0x40000000) == 0 )
        {
          do
            v17 = __ldrex(i);
          while ( v17 == v16 && __strex(v16 | 0x40000000, i) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  return result;
}
