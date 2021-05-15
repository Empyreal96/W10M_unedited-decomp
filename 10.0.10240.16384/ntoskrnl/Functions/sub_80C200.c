// sub_80C200 
 
void __fastcall sub_80C200(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  unsigned int v5; // r1
  int v6; // r3
  int *v7; // r0
  int **v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r3
  int v12; // r5
  int v13; // r6
  int v14; // r7
  int v15; // r0
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // r2
  int v24; // r3

  if ( !ExAcquireResourceExclusiveLite(a1, 0, a3, a4) )
  {
    v15 = IopGetFsRegistrationInProgress();
    if ( v15 )
    {
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(_WORD *)(v18 + 0x134) + 1;
      *(_WORD *)(v18 + 308) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
        KiCheckForKernelApcDelivery(v15);
      goto LABEL_37;
    }
    ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 1, v16, v17);
  }
  if ( (int *)IopFsNotifyChangeQueueHead != &IopFsNotifyChangeQueueHead
    && *(_DWORD *)(dword_6318BC + 8) == v12
    && *(_DWORD *)(dword_6318BC + 12) == v14 )
  {
    v4 = ExReleaseResourceLite((int)&IopDatabaseResource);
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = (__int16)(*(_WORD *)(v5 + 0x134) + 1);
    *(_WORD *)(v5 + 308) = v6;
    if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
      KiCheckForKernelApcDelivery(v4);
  }
  else
  {
    v7 = (int *)ExAllocatePoolWithTag(257, 16, 1933995849);
    if ( v7 )
    {
      v7[2] = v12;
      v7[3] = v14;
      v8 = (int **)dword_6318BC;
      *v7 = (int)&IopFsNotifyChangeQueueHead;
      v7[1] = (int)v8;
      if ( *v8 != &IopFsNotifyChangeQueueHead )
        __fastfail(3u);
      *v8 = v7;
      dword_6318BC = (int)v7;
      if ( v13 == 1 && IopMountsInProgress )
      {
        do
        {
          ++IopMountCompletionWaiters;
          ExReleaseResourceLite((int)&IopDatabaseResource);
          KeWaitForSingleObject((unsigned int)&IopMountCompletionEvent, 0, 0, 0, 0);
          ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 1, v23, v24);
          if ( --IopMountCompletionWaiters && !IopMountsInProgress )
            break;
          KeResetEvent((int)&IopMountCompletionEvent);
        }
        while ( IopMountsInProgress );
      }
      IopNotifyAlreadyRegisteredFileSystems(&IopNetworkFileSystemQueueHead, v14, 0);
      IopNotifyAlreadyRegisteredFileSystems(&IopCdRomFileSystemQueueHead, v14, 1);
      IopNotifyAlreadyRegisteredFileSystems(&IopDiskFileSystemQueueHead, v14, 1);
      IopNotifyAlreadyRegisteredFileSystems(&IopTapeFileSystemQueueHead, v14, 1);
      v9 = ExReleaseResourceLite((int)&IopDatabaseResource);
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v11 = (__int16)(*(_WORD *)(v10 + 0x134) + 1);
      *(_WORD *)(v10 + 308) = v11;
      if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
        KiCheckForKernelApcDelivery(v9);
      ObfReferenceObject(v12);
    }
    else
    {
      v20 = ExReleaseResourceLite((int)&IopDatabaseResource);
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v22 = *(_WORD *)(v21 + 0x134) + 1;
      *(_WORD *)(v21 + 308) = v22;
      if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
        KiCheckForKernelApcDelivery(v20);
    }
  }
LABEL_37:
  JUMPOUT(0x792CE0);
}
