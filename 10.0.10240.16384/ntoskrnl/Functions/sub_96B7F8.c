// sub_96B7F8 
 
void sub_96B7F8()
{
  int v0; // r5
  int v1; // r7

  MxZeroPageTablePfns((_BYTE *)(v0 << 10), (v0 << 10) + 4092, v1 - 1);
  JUMPOUT(0x9572CC);
}
