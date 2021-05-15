// KeZeroSinglePage 
 
_DWORD *__fastcall KeZeroSinglePage(_DWORD *a1)
{
  return KeZeroPages(a1, 0x1000u);
}
