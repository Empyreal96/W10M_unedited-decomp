// IopEjectDevice 
 
int __fastcall IopEjectDevice(int a1, int a2)
{
  int v4; // r3
  int v5; // r4
  int v6; // r7
  int v7; // r1
  int v8; // r8
  int v9; // r4
  int v10; // r1
  int v11; // r2

  v4 = *(_DWORD *)(a2 + 56);
  if ( *(_DWORD *)(a2 + 52) == 1 )
  {
    if ( v4 )
    {
      (*(void (__fastcall **)(_DWORD, int))(v4 + 16))(*(_DWORD *)(v4 + 4), 3);
      (*(void (__fastcall **)(_DWORD))(*(_DWORD *)(a2 + 56) + 20))(*(_DWORD *)(*(_DWORD *)(a2 + 56) + 4));
      if ( *(_BYTE *)(a2 + 49) )
        *(_BYTE *)(a2 + 49) = 0;
    }
    v6 = IoGetAttachedDeviceReference(a1);
    v8 = IoAllocateIrp(*(_BYTE *)(v6 + 48), 0);
    if ( v8 )
    {
      IovUtilWatermarkIrp();
      v9 = *(_DWORD *)(v8 + 96);
      *(_DWORD *)(v8 + 24) = -1073741637;
      *(_DWORD *)(v8 + 28) = 0;
      memset((_BYTE *)(v9 - 40), 0, 40);
      *(_BYTE *)(v9 - 40) = 27;
      *(_BYTE *)(v9 - 39) = 17;
      *(_DWORD *)(v8 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_BYTE *)(v8 + 32) = 0;
      *(_DWORD *)(v8 + 40) = 0;
      *(_DWORD *)(v8 + 44) = 0;
      *(_DWORD *)(a2 + 36) = v8;
      *(_DWORD *)(a2 + 40) = 0;
      PnpQueuePendingEject((int *)a2, v10);
      v11 = *(_DWORD *)(v8 + 96);
      *(_DWORD *)(v11 - 8) = IopDeviceEjectComplete;
      *(_DWORD *)(v11 - 4) = a2;
      *(_BYTE *)(v11 - 37) = -32;
      v5 = IofCallDriver(v6, v8);
    }
    else
    {
      *(_DWORD *)(a2 + 36) = 0;
      *(_DWORD *)a2 = a2;
      *(_DWORD *)(a2 + 4) = a2;
      PnpQueuePendingEject((int *)a2, v7);
      *(_DWORD *)(a2 + 16) = PnpProcessCompletedEject;
      *(_DWORD *)(a2 + 20) = a2;
      *(_DWORD *)(a2 + 8) = 0;
      ExQueueWorkItem((_DWORD *)(a2 + 8), 1);
      v5 = -1073741670;
    }
    ObfDereferenceObject(v6);
  }
  else
  {
    if ( v4 )
      (*(void (__fastcall **)(_DWORD, int))(v4 + 16))(*(_DWORD *)(v4 + 4), 4);
    *(_DWORD *)(a2 + 36) = 0;
    *(_DWORD *)a2 = a2;
    *(_DWORD *)(a2 + 4) = a2;
    PnpQueuePendingEject((int *)a2, a2);
    *(_DWORD *)(a2 + 16) = PnpProcessCompletedEject;
    *(_DWORD *)(a2 + 20) = a2;
    *(_DWORD *)(a2 + 8) = 0;
    ExQueueWorkItem((_DWORD *)(a2 + 8), 1);
    v5 = 0;
  }
  return v5;
}
