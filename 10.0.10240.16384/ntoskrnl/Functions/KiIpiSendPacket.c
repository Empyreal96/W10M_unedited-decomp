// KiIpiSendPacket 
 
int __fastcall KiIpiSendPacket(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7[6]; // [sp+8h] [bp-18h] BYREF

  v7[0] = a4;
  v7[1] = a5;
  v7[2] = a6;
  v7[3] = a3;
  return ((int (__fastcall *)(unsigned int, int, int, int *, _DWORD, int))KiIpiSendRequest)(
           ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408,
           a1,
           a2,
           v7,
           0,
           6);
}
