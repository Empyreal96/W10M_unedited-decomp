// sub_7DFAA0 
 
void __fastcall sub_7DFAA0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  int v6; // r6
  int v7; // r7

  if ( v5 <= *(_DWORD *)(a5 + 4) )
    v5 = *(_DWORD *)(a5 + 4);
  *(_DWORD *)(a5 + 4) = v5;
  if ( v7 == 1 )
  {
    ++*(_DWORD *)(*(_DWORD *)v6 + 8);
    *(_DWORD *)(a5 + 12) |= 1u;
  }
  JUMPOUT(0x775B10);
}
