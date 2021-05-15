// PopThermalPowerSettingCallback 
 
int __fastcall PopThermalPowerSettingCallback(unsigned int a1, int *a2, int a3)
{
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r4
  int v10; // r2
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire(&PopThermalLock, 0, 0);
  do
    v8 = __ldrex((unsigned __int8 *)&PopThermalLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&PopThermalLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_5294C8(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_61E70C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !memcmp((unsigned int)&GUID_SYSTEM_COOLING_POLICY, a1, 16) && a3 == 4 )
  {
    v10 = *a2;
    dword_61EC48 = *a2;
  }
  else
  {
    v10 = dword_61EC48;
  }
  if ( PopPlatformAoAc && !PopConsoleDisplayState )
    v10 = 1;
  if ( v10 != PopCoolingMode )
  {
    PopCoolingMode = v10;
    PopThermalZoneUpdateCoolingPolicy();
  }
  dword_61E70C = 0;
  __pld(&PopThermalLock);
  v11 = PopThermalLock;
  if ( (PopThermalLock & 0xFFFFFFF0) > 0x10 )
    v12 = PopThermalLock - 16;
  else
    v12 = 0;
  if ( (PopThermalLock & 2) != 0 )
    goto LABEL_29;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&PopThermalLock);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&PopThermalLock) );
  if ( v13 != v11 )
LABEL_29:
    ExfReleasePushLock(&PopThermalLock);
  v14 = KeAbPostRelease(&PopThermalLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return 0;
}
