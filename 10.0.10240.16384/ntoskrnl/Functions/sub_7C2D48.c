// sub_7C2D48 
 
void __fastcall sub_7C2D48(int a1, int a2, int a3, unsigned int a4)
{
  _DWORD *v4; // r5
  unsigned int v5; // r6
  int v6; // r3

  if ( a4 > 2 )
  {
    v5 = 0;
    do
      ExReleaseResourceLite(*(_DWORD *)(v4[148] + 4 * v5++) + 32);
    while ( v5 < v4[147] - 2 );
  }
  v6 = v4[144];
  __dmb(0xBu);
  ExReleaseResourceLite(v6 + 32);
  JUMPOUT(0x6B06CC);
}
