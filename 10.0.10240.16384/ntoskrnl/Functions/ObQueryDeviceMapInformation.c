// ObQueryDeviceMapInformation 
 
int __fastcall ObQueryDeviceMapInformation(int a1, int *a2, int a3)
{
  int result; // r0
  BOOL v5; // r5
  int v6; // r8
  unsigned int v7; // r2
  int *v8; // r10
  unsigned int *v9; // r9
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r10
  int v20; // r3
  int v21; // r3
  int v22; // r0
  unsigned int v23; // r1
  int v24; // r6
  int v25; // r4
  int v26; // r6
  unsigned int *v27; // r5
  int v28; // r1
  unsigned int v29; // r0
  unsigned int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int *v34; // r0
  int v35; // [sp+0h] [bp-50h]
  _DWORD *v36; // [sp+4h] [bp-4Ch] BYREF
  int v37; // [sp+8h] [bp-48h]
  int *v38; // [sp+Ch] [bp-44h]
  _DWORD v39[16]; // [sp+10h] [bp-40h] BYREF

  v38 = a2;
  v37 = 0;
  if ( (a3 & 0xFFFFFFFE) != 0 )
    return -1073741811;
  v5 = (a3 & 1) == 0;
  if ( a1 )
  {
    if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
      return -1073741811;
  }
  v6 = ObpReferenceDeviceMap(0);
  v35 = v6;
  PsGetMonitorContextServerSilo(ObSiloMonitor, -1, &v36);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 310);
  v8 = v36;
  v9 = v36 + 28;
  v10 = KeAbPreAcquire((unsigned int)(v36 + 28), 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( !v12 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(v8 + 28, v10, (unsigned int)(v8 + 28));
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  if ( v6 )
  {
    v37 = 1;
  }
  else if ( a1 )
  {
    v6 = *(_DWORD *)(a1 + 344);
    v35 = v6;
  }
  else
  {
    v6 = *v8;
    v35 = *v8;
  }
  if ( v6 )
  {
    v19 = v6;
    v20 = *(_DWORD *)(v6 + 4);
    if ( v20 )
    {
      v21 = *(_DWORD *)(v20 + 152);
      if ( v21 )
        v19 = v21;
    }
    v39[0] = *(_DWORD *)(v6 + 16);
    v22 = 1;
    v23 = 0;
    v24 = v39[0];
    do
    {
      *((_BYTE *)&v39[1] + v23) = *(_BYTE *)(v23 + v6 + 20);
      if ( (v24 & v22) != 0 || !v5 )
      {
        v25 = v39[0];
      }
      else
      {
        *((_BYTE *)&v39[1] + v23) = *((_BYTE *)&v39[5] + v23 + v19 - (_DWORD)v39);
        v25 = *(_DWORD *)(v19 + 16) & v22 | v39[0];
        v39[0] = v25;
      }
      ++v23;
      v22 *= 2;
    }
    while ( v23 < 0x20 );
    v26 = (int)v36;
    v27 = v36 + 28;
    __pld(v36 + 28);
    v28 = *v27;
    if ( (*v27 & 0xFFFFFFF0) <= 0x10 )
      v29 = 0;
    else
      v29 = v28 - 16;
    if ( (v28 & 2) != 0 )
      goto LABEL_48;
    __dmb(0xBu);
    do
      v30 = __ldrex(v27);
    while ( v30 == v28 && __strex(v29, v27) );
    if ( v30 != v28 )
LABEL_48:
      ExfReleasePushLock((_DWORD *)(v26 + 112), v28);
    v31 = KeAbPostRelease(v26 + 112);
    v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v33 = *(_WORD *)(v32 + 0x136) + 1;
    *(_WORD *)(v32 + 310) = v33;
    if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 )
      KiCheckForKernelApcDelivery(v31);
    PsDereferenceMonitorContextServerSilo(v26);
    if ( v37 == 1 )
      ObfDereferenceDeviceMap(v35);
    v34 = v38;
    *v38 = v25;
    v34[1] = v39[1];
    v34[2] = v39[2];
    v34[3] = v39[3];
    v34[4] = v39[4];
    v34[5] = v39[5];
    v34[6] = v39[6];
    v34[7] = v39[7];
    v34[8] = v39[8];
    result = 0;
  }
  else
  {
    __pld(v9);
    v13 = *v9;
    if ( (*v9 & 0xFFFFFFF0) <= 0x10 )
      v14 = 0;
    else
      v14 = v13 - 16;
    if ( (v13 & 2) != 0 )
      goto LABEL_26;
    __dmb(0xBu);
    do
      v15 = __ldrex(v9);
    while ( v15 == v13 && __strex(v14, v9) );
    if ( v15 != v13 )
LABEL_26:
      ExfReleasePushLock(v8 + 28, v13);
    v16 = KeAbPostRelease((unsigned int)(v8 + 28));
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x136) + 1;
    *(_WORD *)(v17 + 310) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 )
      KiCheckForKernelApcDelivery(v16);
    PsDereferenceMonitorContextServerSilo((int)v8);
    result = -1073741807;
  }
  return result;
}
