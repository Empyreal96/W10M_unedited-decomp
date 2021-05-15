// RtlAddAccessAllowedAceEx 
 
int __fastcall RtlAddAccessAllowedAceEx(int a1, int a2, int a3, int a4, int a5)
{
  return RtlpAddKnownAce(a1, a2, a3, a4, a5, 0);
}
