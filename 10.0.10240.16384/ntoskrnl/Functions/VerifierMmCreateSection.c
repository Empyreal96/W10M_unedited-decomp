// VerifierMmCreateSection 
 
int __fastcall VerifierMmCreateSection(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int vars4; // [sp+2Ch] [bp+4h]

  VfCheckPageProtection(a5, vars4);
  return pXdvMmCreateSection(a1, a2, a3, a4, a5, a6, a7, a8);
}
