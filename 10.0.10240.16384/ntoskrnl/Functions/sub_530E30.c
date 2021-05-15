// sub_530E30 
 
void __fastcall sub_530E30(int a1, int a2, char a3)
{
  int v3; // r1

  v3 = *(_DWORD *)(a1 + 44);
  if ( v3 && (a3 & 7) != 1 )
  {
    if ( !*(_DWORD *)(*(_DWORD *)v3 + 32) && (*(_DWORD *)(*(_DWORD *)v3 + 28) & 0x1000) != 0 )
      JUMPOUT(0x4879F8);
    JUMPOUT(0x487A08);
  }
  JUMPOUT(0x4879FA);
}
