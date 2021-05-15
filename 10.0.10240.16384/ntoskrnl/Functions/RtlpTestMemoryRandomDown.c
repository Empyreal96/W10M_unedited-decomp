// RtlpTestMemoryRandomDown 
 
int __fastcall RtlpTestMemoryRandomDown(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  int v6; // r5
  int v7; // t1
  _DWORD *v8; // r4

  v6 = a1 + 4096;
  while ( *(_DWORD *)(v6 - 4) == a4 )
  {
    v7 = *(_DWORD *)(v6 - 8);
    v6 -= 8;
    if ( v7 != a3 )
      break;
    v8 = (_DWORD *)(a5 + 8 * (a3 & 0xF));
    a3 = *v8 ^ ((a4 << 28) | (a3 >> 4));
    a4 = v8[1] ^ (a4 >> 4);
    if ( v6 == a1 )
      return 1;
  }
  return 0;
}
