// ObQueryNameInfo 
 
int __fastcall ObQueryNameInfo(int a1)
{
  int result; // r0

  if ( (*(_BYTE *)(a1 - 10) & 2) != 0 )
    result = a1 - 24 - ObpInfoMaskToOffset[*(_BYTE *)(a1 - 10) & 3];
  else
    result = 0;
  return result;
}
