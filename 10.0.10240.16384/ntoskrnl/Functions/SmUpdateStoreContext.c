// SmUpdateStoreContext 
 
int __fastcall SmUpdateStoreContext(int a1, char a2, int a3)
{
  unsigned int v3; // r1

  v3 = a1 & 0xFFFFF860 | ((a2 & 7) << 8) | 0x60;
  return ((unsigned __int16)v3 ^ ((a3 != 0) << 12)) & 0x1000 ^ v3;
}
