// ObNormalizeHandleValue 
 
unsigned int __fastcall ObNormalizeHandleValue(int a1)
{
  if ( a1 < 0 && a1 != -2 && a1 != -1 )
    a1 ^= 0x80000000;
  return a1 & 0xFFFFFFFC;
}
