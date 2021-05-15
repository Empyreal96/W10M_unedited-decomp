// sub_7D29C0 
 
void __fastcall sub_7D29C0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r6
  int v7; // r10
  int v8; // r5

  v8 = *(_DWORD *)(v6 + v7);
  *(_DWORD *)(a6 + 4) = v8;
  *(_DWORD *)(a6 + 8) = v6 + v7;
  if ( *(_DWORD *)(v8 + 4) != v6 + v7 )
    __fastfail(3u);
  JUMPOUT(0x6D2338);
}
