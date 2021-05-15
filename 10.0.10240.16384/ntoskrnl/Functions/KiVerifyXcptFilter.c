// KiVerifyXcptFilter 
 
int __fastcall KiVerifyXcptFilter(int a1)
{
  if ( *(_DWORD *)(a1 + 12) )
    return sub_9653D8();
  *(_DWORD *)(a1 + 12) = 1;
  return 1;
}
