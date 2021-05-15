// SepInitializeLowBoxNumberTable 
 
int __fastcall SepInitializeLowBoxNumberTable(int a1)
{
  int v2; // r5
  int v3; // r0

  *(_DWORD *)(a1 + 12) = 0;
  v2 = 0;
  if ( !RtlCreateHashTable(a1 + 12, 0, 0) )
    return -1073741670;
  v3 = ExAllocatePoolWithTag(1, 128, 1934386515);
  if ( !v3 )
    return sub_8114A0();
  *(_DWORD *)(a1 + 4) = 1024;
  *(_DWORD *)(a1 + 8) = v3;
  RtlClearAllBits(a1 + 4);
  *(_BYTE *)(a1 + 16) = 1;
  return v2;
}
