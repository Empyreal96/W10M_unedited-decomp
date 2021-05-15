// sub_7EA704 
 
void __fastcall sub_7EA704(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r7

  if ( v3 )
  {
    if ( (*(_DWORD *)(a3 + 176) & 0x4000) != 0 )
      RtlIsParentOfChildAppContainer(*(_DWORD *)(a3 + 480), v4);
  }
  JUMPOUT(0x705922);
}
