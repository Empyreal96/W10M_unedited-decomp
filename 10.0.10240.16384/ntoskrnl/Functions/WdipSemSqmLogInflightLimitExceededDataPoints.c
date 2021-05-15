// WdipSemSqmLogInflightLimitExceededDataPoints 
 
int WdipSemSqmLogInflightLimitExceededDataPoints()
{
  int v0; // r5
  unsigned int v1; // r2
  int v2; // r0
  int v3; // r6
  int v4; // r1
  int v5; // r6
  int *v6; // r8
  int v7; // r5
  int v8; // t1
  unsigned int v9; // r8
  int *v10; // r6
  int v11; // r0
  unsigned int v12; // r6
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v17; // [sp+0h] [bp-30h] BYREF
  int v18[2]; // [sp+8h] [bp-28h] BYREF
  int v19; // [sp+10h] [bp-20h]

  v17 = 0;
  v0 = 0;
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = KeAbPreAcquire((unsigned int)&dword_61CAA4, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&dword_61CAA4);
  while ( __strex(v4 | 1, (unsigned __int8 *)&dword_61CAA4) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    v2 = ExfAcquirePushLockExclusiveEx(&dword_61CAA4, v2, (unsigned int)&dword_61CAA4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = dword_61CAA0;
  if ( dword_61CAA0 )
  {
    v0 = WdipSemSqmIncrementDword(v2, dword_61CAA0);
    if ( v0 < 0 )
      v0 = 0;
    if ( v5 )
    {
      v6 = WdipSemFrequentScenarioTable;
      do
      {
        v8 = *v6++;
        v7 = v8;
        if ( WdipSemGetGuidKey(v8, &v17) < 0
          || (v18[0] = v17,
              v18[1] = *(unsigned __int16 *)(v7 + 16),
              v19 = *(_DWORD *)(v7 + 20),
              v0 = WdipSemSqmAddToStream(1062, 3u, (int)v18, v19),
              v0 < 0) )
        {
          v0 = 0;
        }
        --v5;
      }
      while ( v5 );
    }
  }
  v9 = 0;
  if ( dword_61CAA0 )
  {
    v10 = WdipSemFrequentScenarioTable;
    do
    {
      WdipSemFastFree(5, (_DWORD *)*v10);
      *v10++ = 0;
      ++v9;
    }
    while ( v9 < dword_61CAA0 );
  }
  dword_61CAA0 = 0;
  __pld(&dword_61CAA4);
  v11 = dword_61CAA4;
  v12 = dword_61CAA4 - 16;
  if ( (dword_61CAA4 & 0xFFFFFFF0) <= 0x10 )
    v12 = 0;
  if ( (dword_61CAA4 & 2) != 0 )
    goto LABEL_26;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_61CAA4);
  while ( v4 == v11 && __strex(v12, (unsigned int *)&dword_61CAA4) );
  if ( v4 != v11 )
LABEL_26:
    ExfReleasePushLock(&dword_61CAA4, v4);
  v13 = KeAbPostRelease((unsigned int)&dword_61CAA4);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v0;
}
