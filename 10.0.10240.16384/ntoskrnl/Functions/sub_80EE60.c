// sub_80EE60 
 
void __fastcall sub_80EE60(int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r7
  int v5; // r3
  unsigned int v6; // r2

  v5 = v4 + 8 * *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v5 + 16) = a1;
  *(_DWORD *)(v5 + 20) = a3;
  v6 = *(_DWORD *)(v4 + 4) + 1;
  *(_DWORD *)(v4 + 4) = v6;
  if ( v6 >= *(_DWORD *)(v3 + 16) )
    JUMPOUT(0x79913C);
  JUMPOUT(0x799132);
}
