// CmpReparseToVirtualPath 
 
int __fastcall CmpReparseToVirtualPath(int a1, int a2, _DWORD *a3)
{
  if ( (*(_WORD *)(a1 + 106) & 0x80) != 0 && CmRealKCBToVirtualPath(a1, 0, (int)a3) >= 0 )
  {
    if ( CmpVirtualPathPresent(a3) )
      return 1;
    RtlFreeAnsiString(a3);
  }
  return 0;
}
