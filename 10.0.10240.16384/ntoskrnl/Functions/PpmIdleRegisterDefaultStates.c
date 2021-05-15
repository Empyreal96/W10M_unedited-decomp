// PpmIdleRegisterDefaultStates 
 
int __fastcall PpmIdleRegisterDefaultStates(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // r0
  unsigned int v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r2
  int v11; // r7
  int v12; // r0
  int v13; // r1
  unsigned int v14; // r6
  unsigned int v15; // r2
  int v16; // r0
  __int16 v17; // r3
  int v18; // [sp+0h] [bp-20h] BYREF
  _DWORD v19[7]; // [sp+4h] [bp-1Ch] BYREF

  v18 = a2;
  v19[0] = a3;
  v19[1] = a4;
  if ( off_617B54(38, 4, &v18, v19) >= 0 && (v18 & 1) != 0 )
    return sub_7F2148();
  v5 = (_BYTE *)ExAllocatePoolWithTag(512, 88, 1766674512);
  v6 = (unsigned int)v5;
  if ( !v5 )
    return -1073741670;
  memset(v5, 0, 88);
  *(_BYTE *)(v6 + 14) = 1;
  *(_DWORD *)(v6 + 60) = 1;
  *(_DWORD *)(v6 + 64) = *(_DWORD *)(v6 + 64) & 0x7FFFFF00 | 0x8F;
  RtlInitUnicodeString(v6 + 80, L"WFI");
  *(_DWORD *)(v6 + 28) = xHalTimerWatchdogStop;
  *(_DWORD *)(v6 + 40) = PpmIdleDefaultExecute;
  *(_DWORD *)(v6 + 44) = PopPoCoalescinCallback;
  *(_DWORD *)(v6 + 48) = xHalTimerWatchdogStop;
  *(_DWORD *)(v6 + 52) = xHalTimerWatchdogStop;
  *(_BYTE *)(v6 + 12) = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v10 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PpmIdlePolicyLock, v8, (unsigned int)&PpmIdlePolicyLock);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = PopExecuteOnTargetProcessors((int)&KeActiveProcessors, (int)PpmIdleInstallDefaultStates, v6, 1);
  dword_61E89C = 0;
  __pld(&PpmIdlePolicyLock);
  v11 = v12;
  v13 = PpmIdlePolicyLock;
  v14 = PpmIdlePolicyLock - 16;
  if ( (PpmIdlePolicyLock & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  if ( (PpmIdlePolicyLock & 2) != 0 )
    goto LABEL_20;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( v15 == v13 && __strex(v14, (unsigned int *)&PpmIdlePolicyLock) );
  if ( v15 != v13 )
LABEL_20:
    ExfReleasePushLock(&PpmIdlePolicyLock, v13);
  KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v16);
  ExFreePoolWithTag(v6);
  return v11;
}
