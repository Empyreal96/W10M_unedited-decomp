// sub_965C30 
 
void __fastcall sub_965C30(int a1, int a2)
{
  int v2; // r5
  int v3; // r6
  int v4; // r2
  int v5; // r1

  if ( ViVerifierEnabled )
  {
    v4 = *(_DWORD *)(v2 + 8) | 0x40;
    *(_DWORD *)(v2 + 8) = v4;
  }
  else
  {
    v4 = *(_DWORD *)(v2 + 8);
  }
  if ( a2 )
  {
    v4 |= 0x100u;
    *(_DWORD *)(v2 + 8) = v4;
  }
  v5 = *(_DWORD *)(v3 + 132);
  if ( !*(_DWORD *)(v5 + 40) || !*(_DWORD *)(v5 + 44) )
    *(_DWORD *)(v2 + 8) = v4 | 0x80;
  JUMPOUT(0x9490B8);
}
