// PoThermalCounterSetCallback 
 
int __fastcall PoThermalCounterSetCallback(int a1, _DWORD *a2)
{
  int v4; // r9
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  int v8; // r1
  unsigned int v9; // r2
  int v10; // r5
  int v11; // r4
  int v12; // r0
  int v13; // r6
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  _DWORD v21[12]; // [sp+10h] [bp-30h] BYREF

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  v7 = v6;
  v8 = 17;
  do
    v9 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v9 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(&PopPolicyDeviceLock, v6, (unsigned int)&PopPolicyDeviceLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( a1 == 2 || a1 == 3 )
  {
    v10 = PopThermal;
    if ( (int *)PopThermal != &PopThermal )
    {
      v11 = a2[5];
      do
      {
        if ( (*(_BYTE *)(v10 + 33) & 2) != 0 )
        {
          v21[0] = 0;
          v21[1] = 0;
          v21[2] = 0;
          if ( a1 == 3 )
          {
            v4 = PopThermalReadCounters(v10, v8, *a2, a2[1], v21);
            if ( v4 < 0 )
              break;
          }
          v12 = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(v10 + 24));
          v13 = v12;
          if ( v12 )
            v8 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
          else
            v8 = 0;
          if ( v8 )
            v4 = PcwAddInstance(v11, v8 + 160, *(_DWORD *)(v10 + 360), 1);
          if ( v13 )
            ObfDereferenceObject(v13);
          if ( v4 < 0 )
            break;
        }
        v10 = *(_DWORD *)v10;
      }
      while ( (int *)v10 != &PopThermal );
    }
  }
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v14 = PopPolicyDeviceLock;
  v15 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v15 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_31;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v16 == v14 && __strex(v15, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v16 != v14 )
LABEL_31:
    ExfReleasePushLock(&PopPolicyDeviceLock, v14);
  v17 = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v4;
}
