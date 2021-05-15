// ObSetCurrentProcessDeviceMap 
 
int __fastcall ObSetCurrentProcessDeviceMap(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v5; // r5
  int v6; // r10
  int v7; // r0
  int v8; // r8
  int v10; // r6
  int v11; // r9
  unsigned int v12; // r2
  unsigned __int8 *v13; // r4
  int v14; // r0
  int v15; // r7
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r1
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r2
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28[8]; // [sp+0h] [bp-20h] BYREF

  v28[0] = a4;
  v4 = 0;
  v5 = 0;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v7 = PsReferencePrimaryToken(v6);
  v8 = v7;
  if ( !v7 )
    return sub_7E89B4();
  v10 = 0;
  if ( *(_QWORD *)(v7 + 24) == 999i64 )
  {
    PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v28);
    v5 = v28[0];
    v11 = *(_DWORD *)v28[0];
  }
  else
  {
    v10 = SeGetTokenDeviceMap((_DWORD *)v7, v28);
    if ( v10 < 0 )
      goto LABEL_35;
    v11 = v28[0];
  }
  if ( v11 )
  {
    if ( !v5 )
    {
      PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v28);
      v5 = v28[0];
    }
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v12 + 310);
    v13 = (unsigned __int8 *)(v5 + 112);
    v14 = KeAbPreAcquire(v5 + 112, 0, 0);
    v15 = v14;
    do
      v16 = __ldrex(v13);
    while ( __strex(v16 | 1, v13) );
    __dmb(0xBu);
    if ( (v16 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 112), v14, v5 + 112);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    v4 = *(_DWORD *)(v6 + 344);
    *(_DWORD *)(v6 + 344) = v11;
    __dmb(0xBu);
    v17 = (unsigned int *)(v11 + 12);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 + 1, v17) );
    __dmb(0xBu);
    __pld(v13);
    v19 = *(_DWORD *)v13;
    if ( (*(_DWORD *)v13 & 0xFFFFFFF0) > 0x10 )
      v20 = v19 - 16;
    else
      v20 = 0;
    if ( (v19 & 2) != 0 )
      goto LABEL_34;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v13);
    while ( v21 == v19 && __strex(v20, (unsigned int *)v13) );
    if ( v21 != v19 )
LABEL_34:
      ExfReleasePushLock((_DWORD *)(v5 + 112), v19);
    v22 = KeAbPostRelease(v5 + 112);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x136) + 1;
    *(_WORD *)(v23 + 310) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 )
      KiCheckForKernelApcDelivery(v22);
    goto LABEL_26;
  }
LABEL_35:
  v10 = -1073741767;
LABEL_26:
  if ( v5 )
    PsDereferenceMonitorContextServerSilo(v5);
  ObfDereferenceObject(v8);
  if ( v4 )
    ObfDereferenceDeviceMap(v4, v25, v26, v27);
  return v10;
}
