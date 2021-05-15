// sub_7F45F4 
 
void __fastcall sub_7F45F4(int a1, int a2, int a3)
{
  _DWORD *v3; // r4
  int v4; // r7
  int v5; // r9

  if ( *(_DWORD *)(v5 + 72) )
  {
    v3[2] = a3;
    v3[4] = *(_DWORD *)(*(_DWORD *)(v5 + 72) + 4);
    v3[1] |= v4;
  }
  JUMPOUT(0x71325C);
}
