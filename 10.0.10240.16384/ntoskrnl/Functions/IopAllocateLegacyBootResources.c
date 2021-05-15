// IopAllocateLegacyBootResources 
 
int __fastcall IopAllocateLegacyBootResources(int a1, int a2, unsigned int *a3, unsigned int *a4)
{
  int v6; // r6
  unsigned int v8; // r4
  _DWORD *v9; // r6
  _DWORD *v10; // r4
  unsigned int v11; // r7
  unsigned int *v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  if ( IopInitHalDeviceNode )
  {
    if ( IopInitHalResources )
    {
      v12[0] = 0;
      v6 = IopCreateCmResourceList((unsigned int *)IopInitHalResources, a1, a2, v12);
      if ( v6 )
      {
        if ( v12[0] )
          return sub_9695C4();
        IopInitHalResources = 0;
        v8 = *(_DWORD *)(IopInitHalDeviceNode + 360);
        PipSetDevNodeFlags(IopInitHalDeviceNode, 64);
        IopAllocateBootResources(1, *(_DWORD *)(IopInitHalDeviceNode + 16), v6);
        *(_DWORD *)(IopInitHalDeviceNode + 360) = IopCombineCmResourceList(v8, v6);
        if ( v8 )
          ExFreePoolWithTag(v8);
      }
    }
  }
  v9 = 0;
LABEL_9:
  v10 = (_DWORD *)IopInitReservedResourceList;
  while ( v10 )
  {
    v11 = v10[2];
    if ( *(_DWORD *)(v11 + 4) == a1 && *(_DWORD *)(v11 + 8) == a2 )
    {
      IopAllocateBootResources(4, v10[1], v10[2]);
      if ( !v10[1] )
        ExFreePoolWithTag(v11);
      if ( v9 )
        *v9 = *v10;
      else
        IopInitReservedResourceList = *v10;
      ExFreePoolWithTag((unsigned int)v10);
      if ( !v9 )
        goto LABEL_9;
      v10 = (_DWORD *)*v9;
    }
    else
    {
      v9 = v10;
      v10 = (_DWORD *)*v10;
    }
  }
  return 0;
}
