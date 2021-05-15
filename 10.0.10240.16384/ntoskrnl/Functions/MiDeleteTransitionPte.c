// MiDeleteTransitionPte 
 
int __fastcall MiDeleteTransitionPte(_DWORD *a1, char a2, int a3)
{
  int v6; // r0
  unsigned int v7; // r2

  if ( (*a1 & 0x400) != 0 )
    return 1;
  if ( (a2 & 1) == 0 )
    return sub_537A8C();
  v6 = MiLockTransitionLeafPage(a1, 0, a3);
  if ( !v6 )
    return 1;
  if ( (a2 & 2) != 0 )
  {
    v7 = *(_DWORD *)(v6 + 4) | 0x80000000;
    if ( (v7 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 || v7 < 0xC0000000)
      && ((*(unsigned __int8 *)(v6 + 19) >> 5) & 1) != 0 )
    {
      v6 = MiDriverPageIsDangling();
      *(_BYTE *)(v6 + 19) &= 0xDFu;
    }
  }
  return MiDeleteLockedTransitionPte(a1, v6, 17, 1);
}
