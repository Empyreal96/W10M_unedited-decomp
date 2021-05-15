// sub_54FEF0 
 
void __fastcall sub_54FEF0(unsigned int a1, int a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r6
  unsigned int v4; // r7
  int v5; // r9
  unsigned int v6; // r4
  int v7; // r5
  char v8; // r3
  _DWORD *v9; // r1

  if ( a1 > v2 )
    a1 = v2;
  v6 = 0;
  if ( a1 )
  {
    v7 = *(_DWORD *)(a2 + 4);
    do
    {
      v8 = *(_BYTE *)(v6 + v5);
      ++v6;
      v9 = (_DWORD *)(v7 + 8 * (unsigned __int8)(v8 ^ v4));
      v4 = *v9 ^ ((v3 << 24) | (v4 >> 8));
      v3 = v9[1] ^ (v3 >> 8);
    }
    while ( v6 < a1 );
  }
  JUMPOUT(0x4EB288);
}
