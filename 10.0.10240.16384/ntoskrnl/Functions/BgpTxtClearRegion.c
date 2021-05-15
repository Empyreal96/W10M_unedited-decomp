// BgpTxtClearRegion 
 
int __fastcall BgpTxtClearRegion(int a1)
{
  int result; // r0

  if ( a1 && (*(_DWORD *)(a1 + 48) & 1) != 0 )
    result = BgpGxDrawRectangle(*(char **)(a1 + 20), a1);
  else
    result = -1073741811;
  return result;
}
