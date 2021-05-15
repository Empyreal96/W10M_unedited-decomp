// WmipSetTraceNotify 
 
int __fastcall WmipSetTraceNotify(int a1, int a2)
{
  int result; // r0
  char v4; // r4
  int v5; // r4
  int v6; // r2
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  result = EtwGetNotifyRoutine(a2);
  v7[0] = result;
  if ( result )
  {
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v4 = *(_BYTE *)(WmipServiceDeviceObject + 48) + 1;
    KeReleaseMutex((int)&WmipSMMutex);
    result = IoAllocateIrp(v4, 0);
    v5 = result;
    if ( result )
    {
      --*(_BYTE *)(result + 35);
      v6 = *(_DWORD *)(result + 96) - 40;
      *(_DWORD *)(result + 96) = v6;
      *(_DWORD *)(v6 + 24) = WmipServiceDeviceObject;
      WmipForwardWmiIrp((_DWORD *)result, 10, a1, 0, 4, (int)v7);
      result = IoFreeIrp(v5);
    }
  }
  return result;
}
