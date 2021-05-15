// ObpReferenceDeviceMap 
 
int __fastcall ObpReferenceDeviceMap(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r7
  int v7; // r3
  int *v8; // r8
  unsigned int *v9; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r1
  int v25[7]; // [sp+4h] [bp-1Ch] BYREF

  v25[0] = a3;
  v25[1] = a4;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 8) == 0
    || a1
    || (v22 = PsReferenceImpersonationToken(), (v6 = v22) == 0) )
  {
LABEL_2:
    if ( !*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 344)
      && ObSetCurrentProcessDeviceMap() < 0 )
    {
      goto LABEL_27;
    }
    goto LABEL_3;
  }
  if ( *(_QWORD *)(v22 + 24) != 999i64 )
  {
    if ( SeGetTokenDeviceMap((_DWORD *)v22, v25) >= 0 )
    {
      v4 = v25[0];
      if ( v25[0] )
      {
        __dmb(0xBu);
        v23 = (unsigned int *)(v4 + 12);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 + 1, v23) );
        __dmb(0xBu);
        goto LABEL_27;
      }
    }
    goto LABEL_2;
  }
  v5 = 1;
LABEL_3:
  PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v25);
  v7 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x136);
  v8 = (int *)v25[0];
  v9 = (unsigned int *)(v25[0] + 112);
  v10 = KeAbPreAcquire(v25[0] + 112, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( !v12 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(v9, v10, (unsigned int)v9);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  if ( v5 == 1 )
    v4 = *v8;
  else
    v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 344);
  if ( v4 )
  {
    __dmb(0xBu);
    v13 = (unsigned int *)(v4 + 12);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 + 1, v13) );
    __dmb(0xBu);
  }
  __pld(v9);
  v15 = *v9;
  if ( (*v9 & 0xFFFFFFF0) > 0x10 )
    v16 = v15 - 16;
  else
    v16 = 0;
  if ( (v15 & 2) != 0 )
    goto LABEL_43;
  __dmb(0xBu);
  do
    v17 = __ldrex(v9);
  while ( v17 == v15 && __strex(v16, v9) );
  if ( v17 != v15 )
LABEL_43:
    ExfReleasePushLock(v9, v15);
  v18 = KeAbPostRelease((unsigned int)v9);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x136) + 1;
  *(_WORD *)(v19 + 310) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
    KiCheckForKernelApcDelivery(v18);
  PsDereferenceMonitorContextServerSilo((int)v8);
LABEL_27:
  if ( v6 )
    ObfDereferenceObject(v6);
  return v4;
}
