// sub_52852C 
 
void __fastcall sub_52852C(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // r4
  int v8; // r5
  int v9; // r6
  unsigned int v10; // r9
  int v11; // r1

  v11 = a7 + 4 * v8;
  if ( v9 )
  {
    ++v7[21];
    MiReturnSystemVa(v10, v11 << 10, 1, 0);
    ++v7[12];
    ++*(_DWORD *)(v9 + 56);
  }
  else
  {
    ++v7[20];
    MiReturnSystemVa(v10, v11 << 10, 6, 0);
    ++v7[9];
  }
  JUMPOUT(0x4DDE9A);
}
