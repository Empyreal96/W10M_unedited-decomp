// ExpAcquireFannedOutPushLockExclusive 
 
unsigned __int8 *__fastcall ExpAcquireFannedOutPushLockExclusive(unsigned int a1, int a2, unsigned int a3)
{
  int v3; // r8
  unsigned int v4; // r3
  int v5; // r9
  unsigned __int8 *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r4
  unsigned __int8 *result; // r0
  unsigned int v12; // r5
  unsigned int v13; // r3
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r3
  unsigned int v17; // r2

  v3 = (a1 >> 13) & 0x3FFFF;
  v4 = __clz(v3);
  v5 = (a1 >> 3) & 0x3FF;
  v8 = (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)ExSaPageArrays + 4 * (29 - v4))
                                     + 4 * ((1 << (31 - v4)) ^ v3)
                                     + 4)
                         + 4 * v5);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 1, v8) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v8, a2, a3);
  v10 = 1;
  result = (unsigned __int8 *)KeQueryMaximumProcessorCountEx(0xFFFFu, a2);
  v12 = (unsigned int)result;
  if ( (unsigned int)result > 1 )
  {
    do
    {
      v13 = __clz(v3);
      v14 = (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ExSaPageArrays + 4 * v10) + 4 * (29 - v13))
                                          + 4 * ((1 << (31 - v13)) ^ v3)
                                          + 4)
                              + 4 * v5);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 1, v14) );
      __dmb(0xBu);
      if ( (v15 & 1) != 0 )
      {
        v16 = __clz(v3);
        --v12;
        result = (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ExSaPageArrays + 4 * v12) + 4 * (29 - v16))
                                               + 4 * ((1 << (31 - v16)) ^ v3)
                                               + 4)
                                   + 4 * v5);
        do
          v17 = __ldrex(result);
        while ( __strex(v17 | 1, result) );
        __dmb(0xBu);
        if ( (v17 & 1) != 0 )
          result = (unsigned __int8 *)ExfAcquirePushLockExclusiveEx(result, a2, a3);
      }
      else
      {
        ++v10;
      }
    }
    while ( v10 < v12 );
  }
  return result;
}
