// SeAssignSecurity 
 
int __fastcall SeAssignSecurity(int a1, int a2, int *a3, unsigned __int8 a4, int *a5, int a6)
{
  int v6; // r5

  v6 = 0;
  if ( a1 )
  {
    if ( (!a2 || (*(_WORD *)(a2 + 2) & 4) == 0) && (*(_WORD *)(a1 + 2) & 0x400) != 0 )
      v6 = 1;
    if ( (!a2 || (*(_WORD *)(a2 + 2) & 0x10) == 0) && (*(_WORD *)(a1 + 2) & 0x800) != 0 )
      v6 |= 2u;
  }
  return RtlpNewSecurityObject(a1, a2, a3, 0, 0, a4, v6, a5, a6, 0);
}
