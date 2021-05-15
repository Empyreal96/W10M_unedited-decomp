// SdbpGetTagHeadSize 
 
int __fastcall SdbpGetTagHeadSize(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  if ( !SdbpReadMappedData(a1, a2, v5, 2) )
    return sub_7CCC3C();
  result = 2;
  if ( (v5[0] & 0xF000u) >= 0x7000 )
    result = 6;
  return result;
}
