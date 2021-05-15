// sub_7E7914 
 
void __fastcall sub_7E7914(int a1)
{
  if ( (*(_DWORD *)(a1 - 80) & 0x2000) != 0 )
    IopDropIrp((_DWORD *)(a1 - 88), *(_DWORD *)(a1 + 12));
  else
    IoFreeIrp(a1 - 88);
  JUMPOUT(0x6F74E0);
}
