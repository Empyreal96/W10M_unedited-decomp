// ObpCreateSymbolicLinkName 
 
int __fastcall ObpCreateSymbolicLinkName(int result)
{
  if ( (*(_BYTE *)(result - 10) & 2) != 0 )
    result = sub_7DD684();
  return result;
}
