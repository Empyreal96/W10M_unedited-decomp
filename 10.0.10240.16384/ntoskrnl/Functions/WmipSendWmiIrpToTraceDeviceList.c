// WmipSendWmiIrpToTraceDeviceList 
 
int __fastcall WmipSendWmiIrpToTraceDeviceList(int *a1, int a2, int a3, int a4, int a5)
{
  char v7; // r4
  int v8; // r5
  int v9; // r4
  int v10; // r2
  int v11; // t1

  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v7 = *(_BYTE *)(WmipServiceDeviceObject + 48) + 1;
  KeReleaseMutex((int)&WmipSMMutex);
  v8 = IoAllocateIrp(v7, 0);
  if ( !v8 )
    return -1073741670;
  for ( ; a2; --a2 )
  {
    IoInitializeIrp(v8, 40 * v7 + 112, v7);
    --*(_BYTE *)(v8 + 35);
    v10 = *(_DWORD *)(v8 + 96) - 40;
    *(_DWORD *)(v8 + 96) = v10;
    *(_DWORD *)(v10 + 24) = WmipServiceDeviceObject;
    *(_DWORD *)(v8 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *a1;
    a1 += 2;
    WmipForwardWmiIrp((_DWORD *)v8, a3, *(_DWORD *)(v11 + 8), 0, a4, a5);
  }
  v9 = 0;
  IoFreeIrp(v8);
  return v9;
}
