// sub_7DD348 
 
void __fastcall sub_7DD348(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r1
  int v5; // r3
  int v6; // r2

  if ( a3 == 2051 )
  {
    v4 = *(_DWORD *)(v3 + 8);
    v5 = *(_DWORD *)(v4 + 8);
    v6 = v4;
    while ( v5 != v3 )
    {
      v6 = *(_DWORD *)(v6 + 8);
      v5 = *(_DWORD *)(v6 + 8);
    }
    *(_DWORD *)(v6 + 8) = v4;
  }
  JUMPOUT(0x6E9C5E);
}
