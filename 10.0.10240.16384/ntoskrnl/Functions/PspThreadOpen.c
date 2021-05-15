// PspThreadOpen 
 
int __fastcall PspThreadOpen(int a1, char a2, int a3, int a4, _DWORD *a5)
{
  unsigned int v5; // r4

  v5 = *(unsigned __int8 *)(*(_DWORD *)(a4 + 336) + 734);
  if ( PspCheckForInvalidAccessByProtection(a2, *(unsigned __int8 *)(a3 + 734), v5)
    && (RtlProtectedAccess[3 * (v5 >> 4) + 2] & *a5) != 0 )
  {
    return -1073741790;
  }
  if ( (*a5 & 0x40) != 0 )
    *a5 |= 0x800u;
  if ( (*a5 & 0x20) != 0 )
    *a5 |= 0x400u;
  if ( (*a5 & 2) != 0 )
    *a5 |= 0x1000u;
  return 0;
}
