// PspProcessOpen 
 
int __fastcall PspProcessOpen(int a1, char a2, int a3, int a4, _DWORD *a5)
{
  unsigned int v5; // r4
  BOOL v6; // r3

  v5 = *(unsigned __int8 *)(a4 + 734);
  v6 = a2 && !RtlTestProtectedAccess(*(unsigned __int8 *)(a3 + 734), *(unsigned __int8 *)(a4 + 734));
  if ( v6 && (RtlProtectedAccess[3 * (v5 >> 4) + 1] & *a5) != 0 )
    return -1073741790;
  if ( (*a5 & 0x400) != 0 )
    *a5 |= 0x1000u;
  if ( (*a5 & 0x200) != 0 )
    *a5 |= 0x2000u;
  return 0;
}
