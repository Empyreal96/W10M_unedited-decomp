// sub_524A80 
 
void sub_524A80(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r6
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  SymCryptWipeAsm((_BYTE *)(a3 + v4 + 24), 64 - a3);
  SymCryptSha256AppendBlocks_ul1((int *)(v4 + 88), (unsigned int *)(v4 + 24), 0x40u, (unsigned int *)va);
  JUMPOUT(0x45D80C);
}
