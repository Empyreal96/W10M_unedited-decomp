// CmRmIsKCBDeleted 
 
int __fastcall CmRmIsKCBDeleted(int a1, int a2)
{
  if ( (*(_DWORD *)(a1 + 4) & 0x20000) != 0 )
    return 1;
  if ( a2 )
    return sub_7FDD40();
  return 0;
}
