// CmpIsLockAllowedByIndex 
 
int __fastcall CmpIsLockAllowedByIndex(int a1, unsigned int a2, int a3, unsigned int a4, _BYTE *a5)
{
  unsigned int v5; // r0
  unsigned int v6; // r2

  v5 = *(_DWORD *)(a1 + 1860);
  v6 = *(_DWORD *)(a3 + 1860);
  *a5 = 0;
  if ( v5 < v6 )
    return 1;
  if ( v5 <= v6 )
  {
    if ( a2 < a4 )
      return 1;
    if ( a2 == a4 )
    {
      *a5 = 1;
      return 1;
    }
  }
  return 0;
}
