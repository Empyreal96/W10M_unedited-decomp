// ObSetDirectoryDeviceMap 
 
int __fastcall ObSetDirectoryDeviceMap(int **a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int *v5; // r0
  int *v6; // r4
  unsigned int v7; // r9
  unsigned int v8; // r2
  int **v9; // r10
  unsigned __int8 *v10; // r7
  int v11; // r0
  int v12; // r8
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r2
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int *v23; // r2
  unsigned int v24; // r1
  int v25; // [sp+10h] [bp-28h] BYREF
  int **v26; // [sp+14h] [bp-24h]

  v26 = a1;
  v2 = ObReferenceObjectByHandle(a2, 2, ObpDirectoryObjectType, 0, &v25);
  if ( v2 >= 0 )
  {
    v3 = v25;
    if ( (*(_DWORD *)(v25 + 168) & 4) != 0 )
      return sub_7EA440();
    v5 = (int *)ExAllocatePoolWithTag(1, 52, 1833198159);
    v6 = v5;
    if ( !v5 )
      JUMPOUT(0x7EA444);
    memset(v5, 0, 52);
    v6[3] = 1;
    *v6 = v3;
    v2 = ObOpenObjectByPointer(v3, 512, 0, 983055, ObpDirectoryObjectType, 0, v6 + 2);
    if ( v2 < 0 )
    {
      ObfDereferenceObject(v3);
      ExFreePoolWithTag((unsigned int)v6);
    }
    else
    {
      v7 = 0;
      PsGetMonitorContextServerSilo(ObSiloMonitor, -1, &v25);
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v8 + 310);
      v9 = (int **)v25;
      v10 = (unsigned __int8 *)(v25 + 112);
      v11 = KeAbPreAcquire(v25 + 112, 0, 0);
      v12 = v11;
      do
        v13 = __ldrex(v10);
      while ( __strex(v13 | 1, v10) );
      __dmb(0xBu);
      if ( (v13 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v10, v11, (unsigned int)v10);
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
      v14 = *(_DWORD *)(v3 + 152);
      if ( v14 )
      {
        v7 = (unsigned int)v6;
        v6 = *(int **)(v3 + 152);
        __dmb(0xBu);
        v23 = (unsigned int *)(v14 + 12);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 + 1, v23) );
        __dmb(0xBu);
      }
      else
      {
        *(_DWORD *)(v3 + 152) = v6;
        v15 = **v9;
        if ( v3 != v15 )
          v6[1] = v15;
      }
      v16 = **v9;
      if ( v3 != v16 )
        v6[1] = v16;
      __pld(v10);
      v17 = *(_DWORD *)v10;
      if ( (*(_DWORD *)v10 & 0xFFFFFFF0) > 0x10 )
        v18 = v17 - 16;
      else
        v18 = 0;
      if ( (v17 & 2) != 0 )
        goto LABEL_33;
      __dmb(0xBu);
      do
        v19 = __ldrex((unsigned int *)v10);
      while ( v19 == v17 && __strex(v18, (unsigned int *)v10) );
      if ( v19 != v17 )
LABEL_33:
        ExfReleasePushLock(v10, v17);
      v20 = KeAbPostRelease((unsigned int)v10);
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v22 = *(_WORD *)(v21 + 0x136) + 1;
      *(_WORD *)(v21 + 310) = v22;
      if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 )
        KiCheckForKernelApcDelivery(v20);
      PsDereferenceMonitorContextServerSilo((int)v9);
      if ( v7 )
      {
        v2 = ObpCloseHandle(*(_DWORD *)(v7 + 8), 0);
        ObfDereferenceObject(v3);
        ExFreePoolWithTag(v7);
      }
      if ( v26 )
        *v26 = v6;
    }
  }
  return v2;
}
