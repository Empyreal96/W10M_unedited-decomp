// PnpUnlinkDeviceRemovalRelations 
 
int __fastcall PnpUnlinkDeviceRemovalRelations(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r3
  int v7; // [sp+1Ch] [bp-3Ch] BYREF
  char v8[8]; // [sp+20h] [bp-38h] BYREF
  int v9[12]; // [sp+28h] [bp-30h] BYREF

  PpDevNodeLockTree(4, a2);
  if ( a2 && *(_BYTE *)(a2 + 4) )
  {
    v9[0] = 1;
    v9[1] = 0;
    while ( IopEnumerateRelations(a2, v9, &v7, v8, 0) )
    {
      v3 = *(_DWORD *)(*(_DWORD *)(v7 + 176) + 20);
      v4 = IopIsDescendantNode(a2, v7);
      v5 = *(_DWORD *)(v3 + 172);
      if ( v5 == 787 || v5 == 788 )
        return sub_7DFAF8(v4);
    }
  }
  return PpDevNodeUnlockTree(4);
}
