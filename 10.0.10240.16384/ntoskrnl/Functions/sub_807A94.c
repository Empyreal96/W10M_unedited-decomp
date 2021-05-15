// sub_807A94 
 
void __fastcall sub_807A94(int a1, int a2, int a3, int a4, int a5)
{
  int *v5; // r6
  int v6; // r3

  if ( EtwpAllocDataBlock(0x78u, 0, &a5) >= 0 )
  {
    v6 = a5;
    *(_DWORD *)(a5 + 8) = 1;
    *(_DWORD *)(v6 + 4) = 120;
    *v5 = v6;
  }
  JUMPOUT(0x75940C);
}
