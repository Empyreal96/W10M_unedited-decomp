// PnpProcessRebalance 
 
int __fastcall PnpProcessRebalance(int a1)
{
  int v2; // r0
  int v3; // r5
  int v4; // r2
  int v5; // r7
  unsigned int v6; // r1
  int v7; // r5
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  int v12; // [sp+10h] [bp-20h] BYREF
  char v13; // [sp+14h] [bp-1Ch]

  v2 = *(_DWORD *)(a1 + 8);
  if ( v2 )
    v3 = *(_DWORD *)(*(_DWORD *)(v2 + 176) + 20);
  else
    v3 = IopRootDeviceNode;
  v4 = *(_DWORD *)(v3 + 172);
  v5 = (unsigned __int8)*(_DWORD *)(a1 + 20);
  if ( v4 == 787 || v4 == 788 )
  {
    ObfDereferenceObject(v2);
    v7 = -1073741738;
  }
  else
  {
    if ( !*(_BYTE *)(a1 + 16) && (unsigned __int8)*(_DWORD *)(a1 + 20) && PiCollapseRebalanceRequests((_DWORD *)a1) )
      v3 = IopRootDeviceNode;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
    v7 = PnpRebalance(v3, 0, 0, v5);
    v8 = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v8);
    if ( v7 >= 0 )
    {
      v12 = 3;
      v13 = PnPBootDriversInitialized;
      ObfReferenceObject(*(_DWORD *)(IopRootDeviceNode + 16));
      v7 = PipProcessDevNodeTree(IopRootDeviceNode, a1, &v12, 0, 0, 1, 0);
    }
  }
  return v7;
}
