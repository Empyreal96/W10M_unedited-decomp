// IopLegacyResourceAllocation 
 
int __fastcall IopLegacyResourceAllocation(int a1, int a2, int a3, int a4, int *a5)
{
  int v5; // r8
  unsigned int v7; // r5
  int v8; // r0
  _DWORD *v9; // r4
  int v11; // r5
  int v12; // r7
  int v13; // r0
  unsigned int v14; // r1
  int v15; // r3
  int *v16; // r0
  int v17; // r6
  int v18; // r1
  unsigned int v19; // r2
  unsigned __int8 v20; // r6
  unsigned int v21; // r1
  int v22; // r5
  int v23; // r8
  unsigned int v24; // r2
  unsigned __int8 v25; // r5
  unsigned int v26; // r1
  int *v27; // r0
  unsigned int v28; // r4
  int v29; // r0
  int v30; // [sp+10h] [bp-60h]
  int v32; // [sp+18h] [bp-58h]
  int v33; // [sp+1Ch] [bp-54h]
  _DWORD v36[18]; // [sp+28h] [bp-48h] BYREF

  v5 = a4;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
  if ( !a3 )
    JUMPOUT(0x80CF7E);
  v9 = *(_DWORD **)(*(_DWORD *)(a3 + 176) + 20);
  if ( !v9 )
    return sub_80CF48(v8);
  v11 = 0;
  v12 = 0;
  if ( v9[2] )
  {
LABEL_5:
    if ( v5 )
      goto LABEL_21;
    goto LABEL_6;
  }
  if ( v5 )
  {
    if ( *(_DWORD *)(v5 + 4) == -1 )
      *(_DWORD *)(v5 + 4) = PnpDefaultInterfaceType;
    v9[2] = IopRootDeviceNode;
    goto LABEL_5;
  }
LABEL_6:
  if ( v9[2] )
  {
LABEL_7:
    IopReleaseResources(v9);
    goto LABEL_8;
  }
LABEL_21:
  if ( v9[71] || v9[90] )
    goto LABEL_7;
LABEL_8:
  if ( v5 )
  {
    memset(v36, 0, 40);
    v36[2] = a1;
    v36[0] = a3;
    v36[1] = 128;
    v36[5] = v5;
    PnpAllocateResources(1, (int)v36, 1, 0);
    v11 = v36[9];
    if ( v36[9] >= 0 )
    {
      v16 = (int *)*a5;
      if ( !*a5 )
        v16 = (int *)v36[7];
      v33 = PnpDetermineResourceListSize(v16);
      v30 = ExAllocatePoolWithTag(1, v33, 538996816);
      if ( v30 )
      {
        if ( *a5 )
          ExFreePoolWithTag(v36[7]);
        else
          *a5 = v36[7];
        v17 = KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
        v18 = KfRaiseIrql(1);
        v32 = v18;
        do
          v19 = __ldrex((unsigned __int8 *)&PiResourceListLock);
        while ( __strex(v19 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
        __dmb(0xBu);
        if ( (v19 & 1) == 0 )
        {
          ExpAcquireFastMutexContended((int)&PiResourceListLock, v17);
          v18 = v32;
        }
        if ( v17 )
          *(_BYTE *)(v17 + 14) |= 1u;
        dword_630824 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        dword_63083C = v18;
        v9[71] = v30;
        memmove(v30, *a5, v33);
        v9[72] = v36[8];
        dword_630824 = 0;
        v20 = dword_63083C;
        __dmb(0xBu);
        do
          v21 = __ldrex(&PiResourceListLock);
        while ( !v21 && __strex(1u, &PiResourceListLock) );
        if ( v21 )
          ExpReleaseFastMutexContended(&PiResourceListLock, v21);
        KfLowerIrql(v20);
        KeAbPostRelease((unsigned int)&PiResourceListLock);
        v12 = v9[88];
      }
      else
      {
        v22 = KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
        v23 = KfRaiseIrql(1);
        do
          v24 = __ldrex((unsigned __int8 *)&PiResourceListLock);
        while ( __strex(v24 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
        __dmb(0xBu);
        if ( (v24 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&PiResourceListLock, v22);
        if ( v22 )
          *(_BYTE *)(v22 + 14) |= 1u;
        __mrc(15, 0, 13, 0, 3);
        dword_63083C = v23;
        v9[71] = v36[7];
        v9[72] = v36[8];
        dword_630824 = 0;
        v25 = dword_63083C;
        __dmb(0xBu);
        do
          v26 = __ldrex(&PiResourceListLock);
        while ( !v26 && __strex(1u, &PiResourceListLock) );
        if ( v26 )
          ExpReleaseFastMutexContended(&PiResourceListLock, v26);
        KfLowerIrql(v25);
        KeAbPostRelease((unsigned int)&PiResourceListLock);
        IopReleaseResources(v9);
        v11 = -1073741670;
      }
      if ( v11 >= 0 )
        goto LABEL_11;
    }
  }
  else
  {
    v12 = v9[88];
  }
  IopRemoveLegacyDeviceNode(a3, v9);
  if ( v11 >= 0 )
  {
LABEL_11:
    if ( v12 )
    {
      v27 = (int *)IopCombineLegacyResources(v12);
      v28 = (unsigned int)v27;
      if ( v27 )
      {
        v29 = PnpDetermineResourceListSize(v27);
        IopWriteAllocatedResourcesToRegistry(v12, v28, v29);
        ExFreePoolWithTag(v28);
      }
    }
    if ( a1 != 3 && a4 )
      IopSetLegacyResourcesFlag(a2);
  }
  v13 = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v11;
}
