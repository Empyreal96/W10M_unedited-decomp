// KeGetNextClockTickDuration 
 
int KeGetNextClockTickDuration()
{
  int v0; // r5
  unsigned int v1; // r10
  int v2; // r7
  unsigned int v4; // r4
  int v5; // r1
  int v6; // r1
  unsigned int v7; // r7
  int v8; // r0
  unsigned int v9; // r4
  __int64 v10; // r2
  unsigned int v11; // [sp+0h] [bp-40h]
  int v12; // [sp+4h] [bp-3Ch]
  unsigned int v13; // [sp+8h] [bp-38h]
  unsigned int v14; // [sp+Ch] [bp-34h]
  int v15; // [sp+10h] [bp-30h]
  unsigned int v16; // [sp+14h] [bp-2Ch]
  int v17[10]; // [sp+18h] [bp-28h] BYREF

  v0 = 0;
  v1 = 0;
  while ( 1 )
  {
    v2 = MEMORY[0xFFFF9340];
    v12 = MEMORY[0xFFFF9344];
    __dmb(0xBu);
    if ( (v2 & 1) != 0 )
      return sub_547B24();
    v11 = MEMORY[0xFFFF9350];
    v13 = MEMORY[0xFFFF9354];
    v15 = MEMORY[0xFFFF9008];
    v16 = MEMORY[0xFFFF900C];
    KeQueryPerformanceCounter(v17, 0);
    v4 = v17[0];
    v14 = v17[1];
    if ( RtlTryEndReadTickLock(-27840, v5, v2, v12) )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( v14 >= v13 && (v14 > v13 || v4 > v11) )
  {
    v7 = (__PAIR64__(v14, v4) - __PAIR64__(v13, v11) - 1) >> 32;
    v6 = v4 - v11 - 1;
    if ( MEMORY[0xFFFF9369] )
    {
      v7 = __PAIR64__(v7, v6) << MEMORY[0xFFFF9369] >> 32;
      v6 <<= MEMORY[0xFFFF9369];
    }
    v9 = (MEMORY[0xFFFF9364] * (unsigned __int64)(unsigned int)v6) >> 32;
    v8 = MEMORY[0xFFFF9364] * v6;
    if ( v7 )
    {
      HIDWORD(v10) = (v7 * (unsigned __int64)MEMORY[0xFFFF9364]
                    + __PAIR64__(
                        MEMORY[0xFFFF9360] * (unsigned __int64)v7 + __PAIR64__(v9, v8) < __PAIR64__(v9, v8),
                        (MEMORY[0xFFFF9360] * (unsigned __int64)v7 + __PAIR64__(v9, v8)) >> 32)) >> 32;
      v1 = v7 * MEMORY[0xFFFF9364] + ((MEMORY[0xFFFF9360] * (unsigned __int64)v7 + __PAIR64__(v9, v8)) >> 32);
      goto LABEL_13;
    }
    v17[0] = (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v6) >> 32;
    v1 = (__PAIR64__(v9, (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v6) >> 32) + (unsigned int)v8) >> 32;
  }
  HIDWORD(v10) = 0;
LABEL_13:
  LODWORD(v10) = v15;
  if ( KiClockTimerNextTickTime > v10 + __PAIR64__(v16, v1) )
    v0 = KiClockTimerNextTickTime - (v15 + v1);
  return v0;
}
