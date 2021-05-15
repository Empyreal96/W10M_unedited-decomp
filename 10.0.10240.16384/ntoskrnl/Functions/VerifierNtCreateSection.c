// VerifierNtCreateSection 
 
int __fastcall VerifierNtCreateSection(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v12; // [sp+Ch] [bp-1Ch]
  int vars4; // [sp+2Ch] [bp+4h]

  v12 = a4;
  VfCheckPageProtection(a5, vars4);
  return pXdvNtCreateSection(a1, a2, a3, a4, a5, a6, a7, v12);
}
