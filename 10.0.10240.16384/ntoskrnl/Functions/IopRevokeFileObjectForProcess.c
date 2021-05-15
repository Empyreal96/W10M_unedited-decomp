// IopRevokeFileObjectForProcess 
 
int __fastcall IopRevokeFileObjectForProcess(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v8; // [sp+0h] [bp-18h]
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v6 = IopAllocateFileObjectExtension(a1, v9);
  if ( v6 >= 0 )
  {
    v6 = 0;
    *(_DWORD *)v9[0] |= 4u;
  }
  if ( v6 == -1073741670 )
    *(_DWORD *)(a1 + 124) = IopRevocationExtension;
  IopCancelIrpsInFileObjectList(a1, a2, 0, 0, 0, 0);
  IopCancelIrpsInThreadListForCurrentProcess(a1, 0);
  return v8;
}
