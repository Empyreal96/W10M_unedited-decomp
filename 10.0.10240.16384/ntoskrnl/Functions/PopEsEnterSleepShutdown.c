// PopEsEnterSleepShutdown 
 
int PopEsEnterSleepShutdown()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r2
  unsigned int v6; // r6
  unsigned __int64 v7; // kr08_8
  int v8; // r6
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int result; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  char v15[12]; // [sp+18h] [bp-40h] BYREF
  int v16; // [sp+24h] [bp-34h]

  PopCurrentPowerState((int)v15);
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopEsLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&PopEsLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&PopEsLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopEsLock, v1, (unsigned int)&PopEsLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61DED4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = MEMORY[0xFFFF9004];
  while ( 1 )
  {
    v5 = MEMORY[0xFFFF9324];
    __dmb(0xBu);
    v6 = MEMORY[0xFFFF9320];
    __dmb(0xBu);
    if ( v5 == MEMORY[0xFFFF9328] )
      break;
    __dmb(0xAu);
    __yield();
  }
  v7 = ((v6 * (unsigned __int64)v4) >> 24) + ((v5 * (unsigned __int64)v4) << 8);
  v8 = 0;
  if ( v15[1] )
    v8 = v16;
  if ( PopEsLastStateChangeTimeStamp )
    PopTraceEsState(
      PopEsReason,
      (int)&PopEsReason,
      v7 - PopEsLastStateChangeTimeStamp,
      (v7 - PopEsLastStateChangeTimeStamp) >> 32,
      v8 - PopEsLastBatteryCharge,
      PopEsAcOnline,
      PopEsMode,
      PopEsLastBatteryThreshold,
      PopEsLastUserAwaySetting);
  PopEsLastBatteryCharge = v8;
  PopEsAcOnline = v15[0];
  PopEsLastBatteryThreshold = dword_61EC50;
  PopEsLastUserAwaySetting = byte_61EC54;
  PopEsLastStateChangeTimeStamp = 0i64;
  dword_61DED4 = 0;
  __pld(&PopEsLock);
  v9 = PopEsLock;
  v10 = PopEsLock - 16;
  if ( (PopEsLock & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  if ( (PopEsLock & 2) != 0 )
    goto LABEL_21;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopEsLock);
  while ( v11 == v9 && __strex(v10, (unsigned int *)&PopEsLock) );
  if ( v11 != v9 )
LABEL_21:
    ExfReleasePushLock(&PopEsLock, v9);
  result = KeAbPostRelease((unsigned int)&PopEsLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
