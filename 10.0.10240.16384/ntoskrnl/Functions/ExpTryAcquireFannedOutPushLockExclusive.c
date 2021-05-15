// ExpTryAcquireFannedOutPushLockExclusive 
 
int __fastcall ExpTryAcquireFannedOutPushLockExclusive(unsigned int a1, int a2)
{
  unsigned int v3; // r0
  int v4; // r4
  int v5; // r6
  unsigned int v6; // r7
  int v7; // r8
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  int v10; // r5
  unsigned int v12; // r7
  unsigned int *v13; // r0
  unsigned int v14; // r1

  v3 = KeQueryMaximumProcessorCountEx(0xFFFFu, a2);
  v4 = 0;
  if ( !v3 )
    return 1;
  v5 = (a1 >> 13) & 0x3FFFF;
  v6 = __clz(v5);
  v7 = (a1 >> 3) & 0x3FF;
  while ( 1 )
  {
    v8 = (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ExSaPageArrays + 4 * v4) + 4 * (29 - v6))
                                       + 4 * ((1 << (31 - v6)) ^ v5)
                                       + 4)
                           + 4 * v7);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 1, v8) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      break;
    if ( ++v4 >= v3 )
      return 1;
  }
  v10 = 0;
  if ( v4 )
  {
    v12 = __clz(v5);
    do
    {
      v13 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ExSaPageArrays + 4 * v4 - 4) + 4 * (29 - v12))
                                       + 4 * ((1 << (31 - v12)) ^ v5)
                                       + 4)
                           + 4 * v7);
      __dmb(0xBu);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 - 1, v13) );
      if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
        ExfTryToWakePushLock(v13);
      --v4;
    }
    while ( v4 );
  }
  return v10;
}
