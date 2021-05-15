// sub_524AA4 
 
void sub_524AA4(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  unsigned int v5; // r5
  int v6; // r6
  int v7; // r8
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( v5 >= 64 - v4 )
  {
    memmove(v4 + v6 + 24, v7, 64 - v4);
    SymCryptSha256AppendBlocks_ul1((int *)(v6 + 88), (unsigned int *)(v6 + 24), 0x40u, (unsigned int *)va);
  }
  JUMPOUT(0x45D894);
}
