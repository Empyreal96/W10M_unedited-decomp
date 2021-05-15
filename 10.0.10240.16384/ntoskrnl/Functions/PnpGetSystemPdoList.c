// PnpGetSystemPdoList 
 
int __fastcall PnpGetSystemPdoList(int a1, int *a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v7; // r3
  unsigned int *v8; // r0
  int v10; // [sp+0h] [bp-10h] BYREF
  unsigned int *v11; // [sp+4h] [bp-Ch]

  v10 = a3;
  v11 = (unsigned int *)a4;
  if ( !a2 )
    return -1073741811;
  if ( a1 )
    v6 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v6 = IopRootDeviceNode;
  v10 = 0;
  v11 = 0;
  v5 = PipForDeviceNodeSubtree(v6, (int)PiPnpPdoDeviceListEnumCallback, (int)&v10, 0);
  if ( v5 < 0 )
  {
    v8 = v11;
  }
  else
  {
    v7 = (int)v11;
    v8 = 0;
    v11 = 0;
    *a2 = v7;
  }
  PiPnpFreePdoDeviceList(v8);
  return v5;
}
