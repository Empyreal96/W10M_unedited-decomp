// VerifierMmProtectMdlSystemAddress 
 
int __fastcall VerifierMmProtectMdlSystemAddress(int a1, int a2)
{
  int vars4; // [sp+Ch] [bp+4h]

  VfCheckPageProtection(a2, vars4);
  return pXdvMmProtectMdlSystemAddress(a1, a2);
}
