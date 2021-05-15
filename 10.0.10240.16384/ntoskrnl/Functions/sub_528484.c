// sub_528484 
 
void __fastcall sub_528484(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r3

  if ( v4 == 88 )
  {
    *(_DWORD *)(a1 + 28) = a4;
    *(_DWORD *)(a1 + 40) = a2;
    v6 = KeMaximumIncrement;
    *(_DWORD *)(a1 + 24) = 1129270354;
    *(_DWORD *)(a1 + 52) = v5;
    *(_DWORD *)(a1 + 56) = v5;
    *(_DWORD *)(a1 + 80) = v5;
    *(_QWORD *)(a1 + 32) = 600000000 * (unsigned int)v6 * (unsigned __int64)a3;
    JUMPOUT(0x4DDB34);
  }
  JUMPOUT(0x4DDB4C);
}
