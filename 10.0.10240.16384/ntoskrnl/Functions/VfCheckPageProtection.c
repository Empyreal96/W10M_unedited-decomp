// VfCheckPageProtection 
 
int __fastcall VfCheckPageProtection(int result, int a2)
{
  int v3; // r6
  unsigned int v4; // r1

  v3 = result;
  if ( (MmVerifierData & 0x2000000) != 0 && (result & 0xF0) != 0 )
  {
    ViCiPreprocessOptions(
      &dword_618714,
      "The caller 0x%p specified an executable page protection 0x%x.",
      (const void *)0x2001,
      a2);
    result = VfReportIssueWithOptions(196, 8193, a2, v3, 0, &dword_618714);
    if ( (MmVerifierData & 0x1000) != 0 )
      result = ViTargetIncrementCounter(a2);
    do
      v4 = __ldrex(&dword_620DFC);
    while ( __strex(v4 + 1, &dword_620DFC) );
  }
  return result;
}
