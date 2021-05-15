// KdpSysGetVersion 
 
int __fastcall KdpSysGetVersion(int a1)
{
  return memmove(a1, (int)&KdVersionBlock, 0x28u);
}
