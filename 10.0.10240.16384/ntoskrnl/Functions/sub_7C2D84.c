// sub_7C2D84 
 
void __fastcall sub_7C2D84(int a1, int a2, int a3)
{
  _DWORD *v3; // r4
  int v4; // r3
  int v5; // r2
  unsigned int v6; // r3
  unsigned int v7; // r5
  int v8; // r3

  v4 = v3[144];
  __dmb(0xBu);
  ExAcquireResourceExclusiveLite(v4 + 32, 1, a3, v4);
  v6 = v3[147];
  if ( v6 > 2 )
  {
    v7 = v6 - 2;
    do
    {
      v8 = *(_DWORD *)(v3[148] + 4 * v7 - 4);
      ExAcquireResourceExclusiveLite(v8 + 32, 1, v5, v8);
      --v7;
    }
    while ( v7 );
  }
  JUMPOUT(0x6B0738);
}
