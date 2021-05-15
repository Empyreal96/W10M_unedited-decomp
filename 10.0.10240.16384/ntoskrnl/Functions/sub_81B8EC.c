// sub_81B8EC 
 
void __fastcall sub_81B8EC(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5

  PiHotSwapGetDetachableNode(v5, &a5);
  if ( a5 )
  {
    if ( (*(_DWORD *)(a5 + 368) & 8) != 0 )
      JUMPOUT(0x7BB65A);
  }
  JUMPOUT(0x7BB64A);
}
