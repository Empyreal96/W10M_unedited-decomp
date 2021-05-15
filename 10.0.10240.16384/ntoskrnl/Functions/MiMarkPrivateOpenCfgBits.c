// MiMarkPrivateOpenCfgBits 
 
int __fastcall MiMarkPrivateOpenCfgBits(int a1, int a2, int a3, int a4)
{
  return MiPopulateCfgBitMap(a1, a4 != 1, a2, (a3 + 4095) & 0xFFFFF000, 0);
}
