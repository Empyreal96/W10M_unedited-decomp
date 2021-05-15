// RtlpFillMemoryRandomDown 
 
int __fastcall RtlpFillMemoryRandomDown(int result, int a2, unsigned int a3, unsigned int a4, int a5)
{
  int v6; // r5
  _DWORD *v7; // r4

  v6 = result + 4096;
  do
  {
    *(_DWORD *)(v6 - 8) = a3;
    *(_DWORD *)(v6 - 4) = a4;
    v6 -= 8;
    v7 = (_DWORD *)(a5 + 8 * (a3 & 0xF));
    a3 = *v7 ^ ((a4 << 28) | (a3 >> 4));
    a4 = v7[1] ^ (a4 >> 4);
  }
  while ( v6 != result );
  return result;
}
