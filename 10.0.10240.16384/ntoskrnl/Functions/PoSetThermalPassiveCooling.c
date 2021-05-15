// PoSetThermalPassiveCooling 
 
int __fastcall PoSetThermalPassiveCooling(int a1, unsigned int a2)
{
  int v4; // r5
  int v5; // r8
  unsigned __int8 *v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3

  if ( !PoGetThermalRequestSupport(a1, 0) )
    return -1073741637;
  if ( a2 > 0x64 )
    return -1073741811;
  v5 = *(_DWORD *)(a1 + 16);
  v6 = (unsigned __int8 *)(v5 + 16);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire(v5 + 16, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v6);
  while ( __strex(v10 | 1, v6) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 16), v8, v5 + 16);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_DWORD *)(v5 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(a1 + 10) )
  {
    v11 = *(unsigned __int8 *)(a1 + 8);
    if ( v11 != a2 )
    {
      PopThermalUpdatePassiveTimeTracking(a1 + 24, v11);
      *(_BYTE *)(a1 + 8) = a2;
      PopDiagTraceThermalRequestPassiveUpdate(a1);
      PopPropogateCoolingChange(v5);
    }
    v4 = 0;
  }
  else
  {
    v4 = -1073741431;
  }
  if ( *(_DWORD *)(v5 + 20) )
    *(_DWORD *)(v5 + 20) = 0;
  __pld(v6);
  v12 = *(_DWORD *)v6;
  v13 = *(_DWORD *)v6 - 16;
  if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
    v13 = 0;
  if ( (v12 & 2) != 0 )
    goto LABEL_25;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)v6);
  while ( v14 == v12 && __strex(v13, (unsigned int *)v6) );
  if ( v14 != v12 )
LABEL_25:
    ExfReleasePushLock((_DWORD *)(v5 + 16), v12);
  v15 = KeAbPostRelease(v5 + 16);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v4;
}
