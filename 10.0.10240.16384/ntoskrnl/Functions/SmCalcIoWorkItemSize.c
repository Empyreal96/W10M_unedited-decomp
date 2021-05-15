// SmCalcIoWorkItemSize 
 
unsigned int __fastcall SmCalcIoWorkItemSize(_DWORD *a1, __int16 a2, int a3)
{
  unsigned int result; // r0

  if ( (*a1 & 0x2000) != 0 )
    result = 32;
  else
    result = 4 * ((((a2 & 0xFFFu) + a3 + 4095) >> 12) + 15);
  return result;
}
