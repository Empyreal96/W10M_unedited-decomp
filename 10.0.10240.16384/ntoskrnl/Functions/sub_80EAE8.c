// sub_80EAE8 
 
void __fastcall sub_80EAE8(int a1)
{
  if ( *(_DWORD *)(MiSectionControlArea(a1) + 88) )
    JUMPOUT(0x7983B8);
  JUMPOUT(0x7983B2);
}
