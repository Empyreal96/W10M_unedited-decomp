// sub_8110EC 
 
void __fastcall sub_8110EC(int a1, int a2, int a3)
{
  unsigned int v3; // r5

  if ( *(_DWORD *)(a3 + 4) )
  {
    if ( v3 > 0x400 )
      JUMPOUT(0x79F20C);
  }
  JUMPOUT(0x79F172);
}
