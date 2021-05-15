// ObfDereferenceDeviceMap 
 
int __fastcall ObfDereferenceDeviceMap(int result, int a2, int a3, int a4)
{
  unsigned int *v4; // r7
  int v5; // r1
  int *v6; // r6
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r8
  unsigned __int8 *v10; // r4
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r2
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // r3
  int v27[6]; // [sp+0h] [bp-18h] BYREF

  v27[0] = a4;
  v4 = (unsigned int *)(result + 12);
  v5 = *(_DWORD *)(result + 12);
  v6 = (int *)result;
  if ( v5 == 1 )
  {
    PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v27);
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 310);
    v9 = v27[0];
    v10 = (unsigned __int8 *)(v27[0] + 112);
    v11 = KeAbPreAcquire(v27[0] + 112, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v10);
    while ( __strex(v13 | 1, v10) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v10, v11, (unsigned int)v10);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    __dmb(0xBu);
    do
    {
      v14 = __ldrex(v4);
      v15 = v14 - 1;
    }
    while ( __strex(v15, v4) );
    __dmb(0xBu);
    v7 = v15 + 1;
    __pld(v10);
    if ( v15 )
    {
      v22 = *(_DWORD *)v10;
      if ( (*(_DWORD *)v10 & 0xFFFFFFF0) <= 0x10 )
        v23 = 0;
      else
        v23 = v22 - 16;
      if ( (v22 & 2) != 0 )
        goto LABEL_42;
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)v10);
      while ( v24 == v22 && __strex(v23, (unsigned int *)v10) );
      if ( v24 != v22 )
LABEL_42:
        ExfReleasePushLock(v10, v22);
      result = KeAbPostRelease((unsigned int)v10);
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = (__int16)(*(_WORD *)(v25 + 0x136) + 1);
      *(_WORD *)(v25 + 310) = v26;
      if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 )
        result = KiCheckForKernelApcDelivery(result);
    }
    else
    {
      *(_DWORD *)(*v6 + 152) = 0;
      v16 = *(_DWORD *)v10;
      if ( (*(_DWORD *)v10 & 0xFFFFFFF0) > 0x10 )
        v17 = v16 - 16;
      else
        v17 = 0;
      if ( (v16 & 2) != 0 )
        goto LABEL_31;
      __dmb(0xBu);
      do
        v18 = __ldrex((unsigned int *)v10);
      while ( v18 == v16 && __strex(v17, (unsigned int *)v10) );
      if ( v18 != v16 )
LABEL_31:
        ExfReleasePushLock(v10, v16);
      v19 = KeAbPostRelease((unsigned int)v10);
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = *(_WORD *)(v20 + 0x136) + 1;
      *(_WORD *)(v20 + 310) = v21;
      if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 )
        KiCheckForKernelApcDelivery(v19);
      ZwClose();
      ObfDereferenceObject(*v6);
      result = ExFreePoolWithTag((unsigned int)v6);
    }
    if ( v9 )
      result = PsDereferenceMonitorContextServerSilo(v9);
  }
  else
  {
    __dmb(0xBu);
    do
      v7 = __ldrex(v4);
    while ( v7 == v5 && __strex(v5 - 1, v4) );
    __dmb(0xBu);
    if ( v7 != v5 )
      return sub_7C4360();
  }
  if ( v7 <= 0 )
    __fastfail(0xEu);
  return result;
}
