// PopThermalUpdateTelemetryClientCount 
 
int __fastcall PopThermalUpdateTelemetryClientCount(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r2
  int result; // r0
  int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  __int16 v10; // r3
  _DWORD v11[8]; // [sp+10h] [bp-20h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopThermalTelemetryLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&PopThermalTelemetryLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&PopThermalTelemetryLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_528E54(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_61E61C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 )
  {
    if ( ++PopThermalTelemetryClientCount == 1 )
    {
      v11[0] = 0;
      v11[1] = 0;
      v11[2] = -1;
      v11[3] = -1;
      KeSetTimer2(PopThermalTelemetryTimer, -864000000000i64, 0i64, (int)v11);
    }
  }
  else if ( !--PopThermalTelemetryClientCount )
  {
    KeCancelTimer2((int)PopThermalTelemetryTimer);
  }
  dword_61E61C = 0;
  __pld(&PopThermalTelemetryLock);
  v6 = PopThermalTelemetryLock;
  if ( (PopThermalTelemetryLock & 0xFFFFFFF0) > 0x10 )
    v7 = PopThermalTelemetryLock - 16;
  else
    v7 = 0;
  if ( (PopThermalTelemetryLock & 2) != 0 )
    goto LABEL_23;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopThermalTelemetryLock);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&PopThermalTelemetryLock) );
  if ( v8 != v6 )
LABEL_23:
    ExfReleasePushLock(&PopThermalTelemetryLock, v6);
  result = KeAbPostRelease((unsigned int)&PopThermalTelemetryLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
