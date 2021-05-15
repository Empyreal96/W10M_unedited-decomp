// KiAsidAlloc 
 
int __fastcall KiAsidAlloc(int result)
{
  int v1; // r9
  unsigned int v2; // r6
  unsigned int v3; // r2
  int v4; // r2
  int v5; // r5
  unsigned int *v6; // lr
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int *v9; // lr
  int v10; // r2
  unsigned int v11; // r1

  v1 = result;
  v2 = *(_DWORD *)(result + 28) & 0xFFFFC000;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50A014();
  do
    v3 = __ldrex((unsigned int *)&KiAsidLock);
  while ( __strex(1u, (unsigned int *)&KiAsidLock) );
  __dmb(0xBu);
  if ( v3 )
    result = KxWaitForSpinLockAndAcquire(&KiAsidLock);
  if ( (KiAsidTable[32 * *(_DWORD *)(v1 + 36)] & 0xFFFFC000) != v2 )
  {
    do
    {
      v4 = KiAsidNext;
      do
      {
        v5 = v4;
        if ( v4 == 254 )
          v4 = 0;
        else
          ++v4;
        v6 = (unsigned int *)&KiAsidTable[32 * v5];
        v7 = *v6;
        KiAsidNext = v4;
      }
      while ( (v7 & 0x3FFF) != 0 );
      do
        v8 = __ldrex(v6);
      while ( v8 == v7 && __strex(0, v6) );
    }
    while ( v8 != v7 );
    KiTbFlushAsid(v5, &KiAsidNext);
    v9 = (unsigned int *)&KiAsidTable[32 * v5];
    do
    {
      result = *v9;
      v10 = *v9 & 0x3FFF | v2;
      do
        v11 = __ldrex(v9);
      while ( v11 == result && __strex(v10, v9) );
    }
    while ( v11 != result );
    *(_DWORD *)(v1 + 36) = v5;
  }
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseSpinLockInstrumented(&KiAsidLock);
  __dmb(0xBu);
  KiAsidLock = 0;
  return result;
}
