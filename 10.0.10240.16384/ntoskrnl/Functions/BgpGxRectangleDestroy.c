// BgpGxRectangleDestroy 
 
int __fastcall BgpGxRectangleDestroy(int a1)
{
  if ( a1 && (*(_DWORD *)(a1 + 16) & 1) == 0 )
    BgpFwFreeMemory(a1);
  return 0;
}
