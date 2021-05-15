// MiInitializePfnsForValidMappings 
 
int __fastcall MiInitializePfnsForValidMappings(int a1)
{
  unsigned int v1; // r4
  int result; // r0

  v1 = (((((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC;
  MxZeroPageTablePfns(v1 - 0x40000000, -1070592004, 1, a1);
  result = MxCreatePfns(v1 - 0x40000000, -1070592004, 1, a1);
  __dsb(0xFu);
  __mcr(15, 0, 0, 8, 7, 0);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
