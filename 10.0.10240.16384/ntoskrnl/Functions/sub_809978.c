// sub_809978 
 
void __fastcall sub_809978(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  int v4; // r6
  unsigned int v5; // r3

  v5 = *(_DWORD *)(v3 + 164) - v4 - 1;
  if ( a3 > v5 )
    *(_DWORD *)(v3 + 136) = v5;
  JUMPOUT(0x75E3BC);
}
