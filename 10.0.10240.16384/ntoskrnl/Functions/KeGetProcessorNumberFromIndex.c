// KeGetProcessorNumberFromIndex 
 
int __fastcall KeGetProcessorNumberFromIndex(unsigned int a1, int a2)
{
  unsigned int v2; // r2
  char v3; // r3
  int result; // r0

  if ( a1 )
  {
    if ( a1 >= 0x20 )
      return -1073741811;
    v2 = KiProcessorIndexToNumberMappingTable[a1];
    if ( !v2 )
      return -1073741811;
    *(_BYTE *)(a2 + 3) = 0;
    *(_WORD *)a2 = v2 >> 6;
    v3 = v2 & 0x3F;
  }
  else
  {
    v3 = 0;
    *(_BYTE *)(a2 + 3) = 0;
    *(_WORD *)a2 = 0;
  }
  result = 0;
  *(_BYTE *)(a2 + 2) = v3;
  return result;
}
