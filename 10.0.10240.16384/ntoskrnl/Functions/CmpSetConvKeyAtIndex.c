// CmpSetConvKeyAtIndex 
 
int __fastcall CmpSetConvKeyAtIndex(int result, int a2, unsigned int a3, int a4)
{
  if ( a3 >= 8 )
    *(_DWORD *)(a2 + 4 * a3 - 32) = a4;
  else
    *(_DWORD *)(result + 4 * a3) = a4;
  return result;
}
