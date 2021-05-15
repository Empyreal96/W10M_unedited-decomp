// BvgaGetResourceAddress 
 
int __fastcall BvgaGetResourceAddress(unsigned int a1)
{
  int result; // r0

  if ( a1 > ResourceCount )
    result = 0;
  else
    result = ResourceList[a1 - 1];
  return result;
}
