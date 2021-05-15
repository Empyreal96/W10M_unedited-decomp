// VerifierNtMapViewOfSection 
 
int __fastcall VerifierNtMapViewOfSection(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int vars4; // [sp+34h] [bp+4h]

  VfCheckPageProtection(a10, vars4);
  return pXdvNtMapViewOfSection(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
