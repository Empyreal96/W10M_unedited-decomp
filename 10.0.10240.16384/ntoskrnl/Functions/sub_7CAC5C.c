// sub_7CAC5C 
 
void __fastcall sub_7CAC5C(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r9
  int v6; // r0

  PipSetDevNodeProblem(v5, 9, v4, a4);
  v6 = *(_DWORD *)(v5 + 8);
  if ( (*(_DWORD *)(v6 + 268) & 0x200000) == 0 )
  {
    PipSetDevNodeFlags(v6, 0x200000);
    PnpSetInvalidIDEvent(*(_DWORD *)(v5 + 8) + 20);
  }
  JUMPOUT(0x76B614);
}
