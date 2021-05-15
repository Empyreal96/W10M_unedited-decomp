// ObpGetShadowDirectory 
 
int __fastcall ObpGetShadowDirectory(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r7
  unsigned int v6; // r3
  int v7; // r8
  unsigned int *v8; // r5
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v20[6]; // [sp+0h] [bp-18h] BYREF

  v20[0] = a4;
  v4 = 0;
  if ( (a1[42] & 4) != 0 )
    return a1[39];
  PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v20);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 310);
  v7 = v20[0];
  v8 = (unsigned int *)(v20[0] + 112);
  v9 = KeAbPreAcquire(v20[0] + 112, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( !v11 && __strex(0x11u, v8) );
  __dmb(0xBu);
  if ( v11 )
    ExfAcquirePushLockSharedEx(v8, v9, (unsigned int)v8);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = a1[38];
  if ( v12 )
    v4 = *(_DWORD *)(v12 + 4);
  __pld(v8);
  v13 = *v8;
  if ( (*v8 & 0xFFFFFFF0) > 0x10 )
    v14 = v13 - 16;
  else
    v14 = 0;
  if ( (v13 & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v15 = __ldrex(v8);
  while ( v15 == v13 && __strex(v14, v8) );
  if ( v15 != v13 )
LABEL_24:
    ExfReleasePushLock(v8, v13);
  v16 = KeAbPostRelease((unsigned int)v8);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x136) + 1;
  *(_WORD *)(v17 + 310) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 )
    KiCheckForKernelApcDelivery(v16);
  PsDereferenceMonitorContextServerSilo(v7);
  return v4;
}
