// ObSetDeviceMap 
 
int __fastcall ObSetDeviceMap(int a1, int a2)
{
  int v2; // r9
  int v3; // r10
  char v4; // r3
  int v5; // r5
  int v6; // r6
  int *v8; // r0
  int *v9; // r4
  unsigned int v10; // r2
  unsigned __int8 *v11; // r7
  int v12; // r0
  int v13; // r8
  unsigned int v14; // r2
  int v15; // r3
  int **v16; // r3
  unsigned int v17; // r9
  int v18; // r3
  int v19; // r8
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r1
  int v32[8]; // [sp+10h] [bp-20h] BYREF

  v2 = a1;
  v3 = a1;
  if ( !a1 )
    v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v4 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v5 = ObReferenceObjectByHandle(a2, 2, ObpDirectoryObjectType, v4, (int)v32, 0);
  if ( v5 >= 0 )
  {
    v6 = v32[0];
    if ( (*(_DWORD *)(v32[0] + 168) & 4) != 0 )
      return sub_8198B4();
    v8 = (int *)ExAllocatePoolWithTag(1, 52, 1833198159);
    v9 = v8;
    if ( !v8 )
      JUMPOUT(0x8198B8);
    memset(v8, 0, 52);
    v9[3] = 1;
    *v9 = v6;
    v29 = ObOpenObjectByPointer(v6, 512, 0, 983055, ObpDirectoryObjectType, 0, v9 + 2);
    v5 = v29;
    if ( v29 >= 0 )
    {
      PsGetMonitorContextServerSilo(ObSiloMonitor, -1, v32);
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v10 + 310);
      v11 = (unsigned __int8 *)(v32[0] + 112);
      v12 = KeAbPreAcquire(v32[0] + 112, 0, 0);
      v13 = v12;
      do
        v14 = __ldrex(v11);
      while ( __strex(v14 | 1, v11) );
      __dmb(0xBu);
      if ( (v14 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v11, v12, (unsigned int)v11);
      if ( v13 )
        *(_BYTE *)(v13 + 14) |= 1u;
      v15 = *(_DWORD *)(v6 + 152);
      if ( v15 )
      {
        v17 = (unsigned int)v9;
        v9 = *(int **)(v6 + 152);
        __dmb(0xBu);
        v30 = (unsigned int *)(v15 + 12);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 + 1, v30) );
        __dmb(0xBu);
      }
      else
      {
        v16 = (int **)v32[0];
        if ( !v2 )
          *(_DWORD *)v32[0] = v9;
        *(_DWORD *)(v6 + 152) = v9;
        v17 = 0;
        v18 = **v16;
        if ( v6 != v18 )
          v9[1] = v18;
      }
      v19 = *(_DWORD *)(v3 + 344);
      __pld(v11);
      *(_DWORD *)(v3 + 344) = v9;
      v20 = *(_DWORD *)v11;
      if ( (*(_DWORD *)v11 & 0xFFFFFFF0) > 0x10 )
        v21 = v20 - 16;
      else
        v21 = 0;
      if ( (v20 & 2) != 0 )
        goto LABEL_33;
      __dmb(0xBu);
      do
        v22 = __ldrex((unsigned int *)v11);
      while ( v22 == v20 && __strex(v21, (unsigned int *)v11) );
      if ( v22 != v20 )
LABEL_33:
        ExfReleasePushLock(v11, v20);
      v23 = KeAbPostRelease((unsigned int)v11);
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = (__int16)(*(_WORD *)(v24 + 0x136) + 1);
      *(_WORD *)(v24 + 310) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 )
        KiCheckForKernelApcDelivery(v23);
      PsDereferenceMonitorContextServerSilo(v32[0]);
      if ( v17 )
      {
        v5 = ObpCloseHandle(*(_DWORD *)(v17 + 8), 0, v27, v28);
        ObfDereferenceObject(v6);
        ExFreePoolWithTag(v17);
      }
      if ( v19 )
        ObfDereferenceDeviceMap(v19, v26, v27, v28);
    }
    else
    {
      ObfDereferenceObject(v6);
      ExFreePoolWithTag((unsigned int)v9);
    }
  }
  return v5;
}
