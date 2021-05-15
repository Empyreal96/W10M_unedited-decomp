// IopSymlinkApplyToOpenedName 
 
int __fastcall IopSymlinkApplyToOpenedName(int a1, int a2, unsigned __int16 *a3, int a4, unsigned int a5, __int16 a6)
{
  unsigned int v8; // r10
  int v11; // r0
  int v12; // r8
  int v13; // r5
  unsigned int v14; // r1
  __int16 v15; // r3

  v8 = *(_DWORD *)(a1 + 52);
  v11 = ExAllocatePoolWithTag(1, *(unsigned __int16 *)(a2 + 12), 1665560393);
  v12 = v11;
  if ( !v11 )
    return -1073741670;
  v14 = *(unsigned __int16 *)(a1 + 48);
  if ( v14 > 2 && *(_WORD *)(*(_DWORD *)(a1 + 52) + 2 * (v14 >> 1) - 2) == 92 )
  {
    if ( a3[3] < 2u )
    {
      ExFreePoolWithTag(v11);
      return -1073741811;
    }
    *(_WORD *)(a1 + 48) = v14 - 2;
    a3[3] -= 2;
  }
  memmove(a5, *(_DWORD *)(a2 + 16), *(unsigned __int16 *)(a2 + 4));
  memmove(
    v12,
    *(unsigned __int16 *)(a2 + 4) + *(_DWORD *)(a2 + 16),
    *(unsigned __int16 *)(a2 + 12) - *(unsigned __int16 *)(a2 + 4));
  *(_DWORD *)(a1 + 52) = v12;
  v15 = *(_WORD *)(a2 + 12) - *(_WORD *)(a2 + 4);
  *(_WORD *)(a1 + 50) = v15;
  *(_WORD *)(a1 + 48) = v15;
  ExFreePoolWithTag(v8);
  v13 = IopReplaceSymlinkPath(
          a5,
          *(unsigned __int16 *)(a2 + 4) >> 1,
          a1,
          a3,
          *(unsigned __int16 *)(a2 + 4) >> 1,
          *(_WORD *)(a2 + 4),
          a6);
  if ( v13 >= 0 )
    return IopSymlinkUpdateECP(
             a4,
             a2,
             0,
             (unsigned __int16 *)(a1 + 48),
             *(_WORD *)(a2 + 4),
             *(_WORD *)(a2 + 2) & 0xFFFE);
  ExFreePoolWithTag(a5);
  return v13;
}
