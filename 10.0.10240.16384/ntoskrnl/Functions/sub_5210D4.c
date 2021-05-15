// sub_5210D4 
 
void __fastcall sub_5210D4(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r4

  a5 = v5 & 0xFFFFF000 | 1;
  VmFlushTb(1, &a5);
  JUMPOUT(0x45462E);
}
