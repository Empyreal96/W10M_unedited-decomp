// IopLoadFileSystemDriver 
 
int __fastcall IopLoadFileSystemDriver(_DWORD *a1)
{
  _DWORD *v1; // r4
  int v2; // r3
  int v3; // r5
  int v4; // r0
  int v5; // r3
  char v7[32]; // [sp+20h] [bp-20h] BYREF

  v1 = a1;
  v2 = a1[4];
  v3 = (int)a1;
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 16);
  }
  KeInitializeEvent((int)v7, 0, 0);
  v4 = IoBuildDeviceIoControlRequest(14, v3, 0, 0, 0, 0);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 96);
    *(_BYTE *)(v5 - 40) = 13;
    *(_BYTE *)(v5 - 39) = 3;
    if ( IofCallDriver(v3, v4) == 259 )
      KeWaitForSingleObject((unsigned int)v7, 0, 0, 0, 0);
  }
  return IopDecrementDeviceObjectRef(v1, 1, 1);
}
