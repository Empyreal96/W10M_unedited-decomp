// ObDereferenceDeviceMap 
 
int __fastcall ObDereferenceDeviceMap(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r2
  int v6; // r7
  unsigned __int8 *v7; // r4
  int v8; // r0
  unsigned int v9; // r2
  int v10; // r5
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int result; // r0
  int v18[6]; // [sp+0h] [bp-18h] BYREF

  v18[0] = a3;
  v18[1] = a4;
  PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v18);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 310);
  v6 = v18[0];
  v7 = (unsigned __int8 *)(v18[0] + 112);
  v8 = KeAbPreAcquire(v18[0] + 112, 0, 0);
  do
    v9 = __ldrex(v7);
  while ( __strex(v9 | 1, v7) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    return sub_7C0568(v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = *(_DWORD *)(a1 + 344);
  __pld(v7);
  *(_DWORD *)(a1 + 344) = 0;
  v11 = *(_DWORD *)v7;
  if ( (*(_DWORD *)v7 & 0xFFFFFFF0) > 0x10 )
    v12 = v11 - 16;
  else
    v12 = 0;
  if ( (v11 & 2) != 0 )
    goto LABEL_20;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)v7);
  while ( v13 == v11 && __strex(v12, (unsigned int *)v7) );
  if ( v13 != v11 )
LABEL_20:
    ExfReleasePushLock(v7, v11);
  v14 = KeAbPostRelease((unsigned int)v7);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x136) + 1;
  *(_WORD *)(v15 + 310) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
    KiCheckForKernelApcDelivery(v14);
  result = PsDereferenceMonitorContextServerSilo(v6);
  if ( v10 )
    result = ObfDereferenceDeviceMap(v10);
  return result;
}
