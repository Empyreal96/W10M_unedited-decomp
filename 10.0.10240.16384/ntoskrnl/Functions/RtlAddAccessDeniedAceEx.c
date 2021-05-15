// RtlAddAccessDeniedAceEx 
 
int __fastcall RtlAddAccessDeniedAceEx(unsigned __int8 *a1, unsigned int a2, int a3, int a4, _BYTE *a5)
{
  return RtlpAddKnownAce(a1, a2, a3, a4, a5, 1u);
}
