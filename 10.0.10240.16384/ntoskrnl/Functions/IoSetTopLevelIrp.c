// IoSetTopLevelIrp 
 
int __fastcall IoSetTopLevelIrp(int result)
{
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = result;
  return result;
}
