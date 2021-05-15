// MiFlowThroughInsertNode 
 
int __fastcall MiFlowThroughInsertNode(int a1, _DWORD *a2)
{
  int v5; // r2
  int v6; // r5
  int v7; // r1
  _DWORD *v8; // r0
  int v9; // [sp+0h] [bp-20h]

  v9 = a1;
  if ( (a2[2] & 0x400) == 0 )
    return sub_528D08();
  *(_DWORD *)(a1 + 188) = 0;
  v5 = a1 + 8;
  *(_BYTE *)(a1 + 113) |= 8u;
  v6 = *a2 - 16;
  v7 = *a2 - 8;
  v8 = *(_DWORD **)(*a2 - 4);
  *(_DWORD *)(a1 + 8) = v7;
  *(_DWORD *)(a1 + 12) = v8;
  if ( *v8 != v7 )
    __fastfail(3u);
  *v8 = v5;
  *(_DWORD *)(v7 + 4) = v5;
  *(_DWORD *)(a1 + 184) = v6;
  return v9;
}
