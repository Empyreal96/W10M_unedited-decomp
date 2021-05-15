// sub_8042DC 
 
void __fastcall sub_8042DC(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r7
  unsigned int v6; // r10

  if ( v5 == 1 || a4 == 1 && v6 >= *(_DWORD *)(v4 + 2564) )
    JUMPOUT(0x749DD2);
  JUMPOUT(0x749E18);
}
