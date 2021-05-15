// RtlAddAccessAllowedAce 
 
int __fastcall RtlAddAccessAllowedAce(int a1, int a2, int a3, int a4)
{
  return RtlpAddKnownAce(a1, a2, 0, a3, a4, 0);
}
