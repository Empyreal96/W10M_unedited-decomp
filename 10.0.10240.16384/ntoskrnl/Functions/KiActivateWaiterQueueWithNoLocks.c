// KiActivateWaiterQueueWithNoLocks 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiActivateWaiterQueueWithNoLocks(int a1, unsigned int a2, int a3)
{
  unsigned int *v3; // r5
  int result; // r0
  unsigned int v7; // r1
  unsigned __int8 *v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r1 OVERLAPPED
  _DWORD *v15; // r2 OVERLAPPED
  unsigned int *v16; // r0
  unsigned int v17; // r2
  int v18; // r2
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1

  v3 = (unsigned int *)((char *)&KiObjectRundownLocks + 128 * ((a2 >> 4) & 0x3F));
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_515618();
  result = *v3 & 0x7FFFFFFF;
  do
    v7 = __ldrex(v3);
  while ( v7 == result && __strex(result + 1, v3) );
  __dmb(0xBu);
  if ( v7 != result )
    result = ExpWaitForSpinLockSharedAndAcquire(v3, v7);
  v8 = *(unsigned __int8 **)(a1 + 152);
  if ( v8 )
  {
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v9 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)v8 & 0x80) != 0 );
      do
        v9 = __ldrex(v8);
      while ( __strex(v9 | 0x80, v8) );
    }
    if ( !*(_DWORD *)(a1 + 152) )
    {
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)v8);
      while ( __strex(v21 & 0xFFFFFF7F, (unsigned int *)v8) );
      v8 = 0;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    do
      v10 = __ldrex(v3);
    while ( __strex(v10 & 0xBFFFFFFF, v3) );
    __dmb(0xBu);
    do
      v11 = __ldrex(v3);
    while ( __strex(v11 - 1, v3) );
  }
  if ( v8 )
  {
    if ( a3 )
    {
      if ( (*v8 & 0x7F) == 21 )
      {
        v16 = (unsigned int *)(a1 + 44);
        while ( 1 )
        {
          do
            v17 = __ldrex(v16);
          while ( __strex(1u, v16) );
          __dmb(0xBu);
          if ( !v17 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v16 );
        }
        v18 = *(unsigned __int8 *)(a1 + 332);
        *(_DWORD *)(a1 + 332) = v18 | 0x100;
        __dmb(0xBu);
        v19 = (unsigned int *)&v8[4 * v18 + 272];
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 - 1, v19) );
        __dmb(0xBu);
        *v16 = 0;
      }
      else
      {
        __dmb(0xBu);
        v12 = (unsigned int *)(v8 + 24);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 - 1, v12) );
        __dmb(0xBu);
      }
      *(_QWORD *)&v14 = *(_QWORD *)a3;
      if ( *(_DWORD *)(*(_DWORD *)a3 + 4) != a3 || *v15 != a3 )
        __fastfail(3u);
      *v15 = v14;
      *(_DWORD *)(v14 + 4) = v15;
      *(_DWORD *)(a1 + 152) = 0;
    }
    if ( (*v8 & 0x7F) == 21 )
      result = KiActivateWaiterPriQueue(v8);
    else
      result = KiActivateWaiterKQueue(v8);
  }
  return result;
}
