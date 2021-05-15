// sub_7CE18C 
 
void __fastcall sub_7CE18C(int a1, int a2, int a3)
{
  int v3; // r4
  unsigned int v4; // r0
  unsigned int v5; // r0
  int v6; // r0

  if ( *(_DWORD *)(a3 + 8) == 1 )
  {
    v4 = *(_DWORD *)(a3 + 4);
    if ( v4 )
      ExFreePoolWithTag(v4);
    v5 = *(_DWORD *)(v3 + 1332);
    if ( v5 )
      ExFreePoolWithTag(v5);
    v6 = *(_DWORD *)(v3 + 1336);
    *(_DWORD *)(v3 + 1332) = 0;
    if ( v6 )
    {
      AslHashFree();
      *(_DWORD *)(v3 + 1336) = 0;
    }
  }
  JUMPOUT(0x773830);
}
