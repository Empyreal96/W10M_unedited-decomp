// PoSetThermalActiveCooling 
 
int __fastcall PoSetThermalActiveCooling(int a1, int a2)
{
  int v4; // r5
  int v5; // r8
  int v6; // r7
  unsigned __int8 *v7; // r4
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3

  if ( !PoGetThermalRequestSupport(a1, 1) )
    return -1073741637;
  v5 = *(_DWORD *)(a1 + 16);
  v6 = a2 != 0;
  v7 = (unsigned __int8 *)(v5 + 16);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(v5 + 16, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v7);
  while ( __strex(v11 | 1, v7) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 16), v9, v5 + 16);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  *(_DWORD *)(v5 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(a1 + 10) )
  {
    if ( *(unsigned __int8 *)(a1 + 9) != v6 )
    {
      *(_BYTE *)(a1 + 9) = v6;
      PopDiagTraceThermalRequestActiveUpdate(a1);
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
  __pld(v7);
  v12 = *(_DWORD *)v7;
  v13 = *(_DWORD *)v7 - 16;
  if ( (*(_DWORD *)v7 & 0xFFFFFFF0) <= 0x10 )
    v13 = 0;
  if ( (v12 & 2) != 0 )
    goto LABEL_23;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)v7);
  while ( v14 == v12 && __strex(v13, (unsigned int *)v7) );
  if ( v14 != v12 )
LABEL_23:
    ExfReleasePushLock((_DWORD *)(v5 + 16), v12);
  v15 = KeAbPostRelease(v5 + 16);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v4;
}
