// AlpcGetHeaderSize 
 
int __fastcall AlpcGetHeaderSize(int a1)
{
  int result; // r0

  result = 8;
  if ( a1 < 0 )
    result = 20;
  if ( (a1 & 0x40000000) != 0 )
    result += 16;
  if ( (a1 & 0x20000000) != 0 )
    result += 20;
  if ( (a1 & 0x10000000) != 0 )
    result += 16;
  if ( (a1 & 0x8000000) != 0 )
    result += 24;
  if ( (a1 & 0x4000000) != 0 )
    result += 4;
  return result;
}
