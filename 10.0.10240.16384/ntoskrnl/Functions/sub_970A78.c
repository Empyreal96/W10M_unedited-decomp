// sub_970A78 
 
void __fastcall sub_970A78(int a1, int a2, int a3, int a4, unsigned int a5)
{
  if ( *(_DWORD *)(a5 + 12) == 4 )
    ExFreePoolWithTag(a5);
  JUMPOUT(0x96480C);
}
