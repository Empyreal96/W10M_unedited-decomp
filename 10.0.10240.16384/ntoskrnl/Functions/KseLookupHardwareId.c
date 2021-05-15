// KseLookupHardwareId 
 
int __fastcall KseLookupHardwareId(unsigned __int16 *a1)
{
  int v1; // r7
  int v2; // r4
  int v3; // r8
  unsigned __int16 *v4; // r2
  unsigned __int16 *v5; // r9
  int i; // r3
  int v7; // t1
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r2
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  unsigned int v17; // r2
  int v18; // r0
  int v19; // r5
  unsigned int v20; // r2
  _DWORD *v21; // r5
  _WORD *v22; // r1
  int v23; // [sp+0h] [bp-38h] BYREF
  char v24[36]; // [sp+14h] [bp-24h] BYREF

  v1 = -1073741275;
  v2 = dword_6416FC;
  v3 = 0;
  v4 = a1;
  v5 = a1;
  if ( *a1 == 42 )
  {
    v4 = a1 + 1;
    v5 = a1 + 1;
    v3 = 1;
  }
  for ( i = *v4; i; i = v7 )
  {
    if ( i == 42 || i == 63 )
    {
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v17 + 308);
      v18 = KeAbPreAcquire(v2, 0, 0);
      v19 = v18;
      do
        v20 = __ldrex((unsigned __int8 *)v2);
      while ( __strex(v20 | 1, (unsigned __int8 *)v2) );
      __dmb(0xBu);
      if ( (v20 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)v2, v18, v2);
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
      v21 = *(_DWORD **)(v2 + 20);
      while ( 2 )
      {
        if ( v21 == (_DWORD *)(v2 + 20) )
        {
LABEL_41:
          __dmb(0xBu);
          do
            v12 = __ldrex((unsigned int *)v2);
          while ( __strex(v12 - 1, (unsigned int *)v2) );
          goto LABEL_18;
        }
        v22 = (_WORD *)v21[3];
        if ( v3 )
        {
          if ( *v22 == 42 )
          {
            ++v22;
            goto LABEL_36;
          }
        }
        else
        {
LABEL_36:
          if ( AslStringPatternMatchW(v5, v22) )
          {
            v1 = 0;
            goto LABEL_41;
          }
        }
        v21 = (_DWORD *)*v21;
        continue;
      }
    }
    v7 = v4[1];
    ++v4;
  }
  RtlInitUnicodeString((unsigned int)v24, a1);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(v2, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v11 | 1, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v2, v9, v2);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( KsepCacheLookup(v2, (int)&v23) )
    v1 = 0;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v2);
  while ( __strex(v12 - 1, (unsigned int *)v2) );
LABEL_18:
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v2);
  v13 = KeAbPostRelease(v2);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v1;
}
