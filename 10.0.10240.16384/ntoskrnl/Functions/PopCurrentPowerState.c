// PopCurrentPowerState 
 
int __fastcall PopCurrentPowerState(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r7
  unsigned int v5; // r2
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r7
  unsigned int v9; // r2
  int result; // r0
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r2
  unsigned int v20; // r1
  __int16 v21; // r3

  memset((_BYTE *)a1, 0, 32);
  *(_BYTE *)(a1 + 7) = dword_61EDBC;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v5 )
    ExfAcquirePushLockSharedEx(&PopPolicyDeviceLock, v3, (unsigned int)&PopPolicyDeviceLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)&PopCB, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned int *)&PopCB);
  while ( !v9 && __strex(0x11u, (unsigned int *)&PopCB) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(&PopCB, v7, (unsigned int)&PopCB);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( dword_61ED6C )
  {
    if ( (dword_61ED84 & 1) != 0 )
      return sub_7F29DC();
    *(_BYTE *)a1 = 0;
    *(_BYTE *)(a1 + 1) = 1;
    *(_BYTE *)(a1 + 2) = (dword_61ED84 & 4) != 0;
    *(_BYTE *)(a1 + 3) = (dword_61ED84 & 2) != 0;
    *(_DWORD *)(a1 + 8) = dword_61EDA8;
    *(_DWORD *)(a1 + 12) = dword_61ED88;
    *(_DWORD *)(a1 + 16) = dword_61ED90;
    *(_DWORD *)(a1 + 20) = dword_61ED94;
    *(_DWORD *)(a1 + 24) = dword_61EDAC;
    *(_DWORD *)(a1 + 28) = dword_61EDB0;
  }
  else
  {
    *(_BYTE *)a1 = dword_61EC0C == 0;
  }
  dword_61ED64 = 0;
  __pld(&PopCB);
  v11 = PopCB;
  if ( (PopCB & 0xFFFFFFF0) > 0x10 )
    v12 = PopCB - 16;
  else
    v12 = 0;
  if ( (PopCB & 2) != 0 )
    goto LABEL_46;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&PopCB);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&PopCB) );
  if ( v13 != v11 )
LABEL_46:
    ExfReleasePushLock(&PopCB, v11);
  v14 = KeAbPostRelease((unsigned int)&PopCB);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v17 = PopPolicyDeviceLock;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) > 0x10 )
    v18 = PopPolicyDeviceLock - 16;
  else
    v18 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_44;
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v19 == v17 && __strex(v18, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v19 != v17 )
LABEL_44:
    ExfReleasePushLock(&PopPolicyDeviceLock, v17);
  result = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
