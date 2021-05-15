// IopAllocateFoExtensionsOnCreate 
 
int __fastcall IopAllocateFoExtensionsOnCreate(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v8[8]; // [sp+8h] [bp-20h] BYREF

  v8[0] = a4;
  v5 = -1073741811;
  if ( (*(_DWORD *)(a3 + 88) & 2) != 0 )
  {
    v5 = IopAllocateFileObjectExtension(a1, v8);
    if ( v5 < 0 )
      return v5;
    v5 = 0;
    *(_DWORD *)v8[0] |= 1u;
  }
  if ( (*(_DWORD *)(a3 + 88) & 1) != 0 )
  {
    v5 = IopGetSetSpecificExtension(a1, 1, 16, 1, v8, 0);
    if ( v5 < 0 )
      return v5;
    *(_DWORD *)v8[0] = *(_DWORD *)(a3 + 104);
  }
  if ( (*(_DWORD *)(a3 + 88) & 4) != 0 )
    return sub_7F3F88();
  return v5;
}
