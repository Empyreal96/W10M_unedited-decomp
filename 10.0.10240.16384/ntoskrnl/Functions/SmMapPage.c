// SmMapPage 
 
int __fastcall SmMapPage(int a1, _DWORD *a2)
{
  int result; // r0

  if ( (*(_WORD *)(a1 + 6) & 5) != 0 )
    result = *(_DWORD *)(a1 + 12);
  else
    result = MmMapLockedPagesSpecifyCache(a1, 0, 1, 0, 0, 1073741840);
  if ( result )
    *a2 = *(_DWORD *)(a1 + 20);
  return result;
}
