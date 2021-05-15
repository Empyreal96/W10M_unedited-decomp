// sub_521BD0 
 
void __fastcall sub_521BD0(int a1, int a2)
{
  if ( (*(_BYTE *)a1 != 1 || (*(_DWORD *)(a1 + 40) & 0x4000) == 0) && *(_DWORD *)(a2 + 544) >= *(_DWORD *)(a2 + 560) )
    JUMPOUT(0x456154);
  JUMPOUT(0x45613E);
}
