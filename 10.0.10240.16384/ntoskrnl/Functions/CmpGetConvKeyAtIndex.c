// CmpGetConvKeyAtIndex 
 
int __fastcall CmpGetConvKeyAtIndex(int a1, int a2, unsigned int a3)
{
  int result; // r0

  if ( a3 >= 8 )
    result = *(_DWORD *)(a2 + 4 * (a3 - 8));
  else
    result = *(_DWORD *)(a1 + 4 * a3);
  return result;
}
