// WdipSemFreePool 
 
int __fastcall WdipSemFreePool(int a1, int a2)
{
  if ( *(int **)(WdipSemPool + 4) != &WdipSemPool )
    JUMPOUT(0x7D0DC8);
  return sub_7D0DC0(WdipSemPool, a2, *(_DWORD *)WdipSemPool);
}
