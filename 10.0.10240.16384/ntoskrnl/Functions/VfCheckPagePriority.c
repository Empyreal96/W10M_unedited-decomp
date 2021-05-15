// VfCheckPagePriority 
 
int __fastcall VfCheckPagePriority(int result, int a2)
{
  int v3; // r6
  unsigned int v4; // r1

  v3 = result;
  if ( (MmVerifierData & 0x2000000) != 0 && (result & 0x40000000) == 0 )
  {
    ViCiPreprocessOptions(
      &dword_61870C,
      "The caller 0x%p specified an executable MDL mapping (priority 0x%x).",
      (const void *)0x2002,
      a2);
    result = VfReportIssueWithOptions(196, 8194, a2, v3, 0, &dword_61870C);
    if ( (MmVerifierData & 0x1000) != 0 )
      result = ViTargetIncrementCounter(a2);
    do
      v4 = __ldrex(&dword_620E00);
    while ( __strex(v4 + 1, &dword_620E00) );
  }
  return result;
}
