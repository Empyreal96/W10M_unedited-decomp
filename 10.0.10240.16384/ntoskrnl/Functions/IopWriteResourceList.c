// IopWriteResourceList 
 
int __fastcall IopWriteResourceList(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r5
  int v7; // r0
  int v9; // [sp+8h] [bp-20h] BYREF
  int v10[7]; // [sp+Ch] [bp-1Ch] BYREF

  v9 = a3;
  v10[0] = a4;
  v6 = IopCreateRegistryKeyEx(&v9, a1, a2, 131103, 1, 0);
  if ( v6 >= 0 )
  {
    v6 = IopCreateRegistryKeyEx(v10, v9, a3, 131103, 1, 0);
    ZwClose();
    if ( v6 >= 0 )
    {
      if ( *a5 )
        v7 = ZwSetValueKey();
      else
        v7 = ZwDeleteValueKey();
      v6 = v7;
      ZwClose();
    }
  }
  return v6;
}
