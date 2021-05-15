// VfCheckPoolType 
 
int __fastcall VfCheckPoolType(int result, int a2, int a3)
{
  int v5; // r5
  unsigned int v6; // r1

  v5 = result;
  if ( (MmVerifierData & 0x2000000) != 0 && (result & 1) == 0 && (result & 0x200) == 0 )
  {
    if ( a3 )
      ViCiPreprocessOptions(
        &dword_618718,
        "The caller 0x%p specified an executable pool type 0x%x (tag 0x%x).",
        0x2000,
        a2,
        result);
    else
      ViCiPreprocessOptions(&dword_618718, "The caller 0x%p specified an executable pool type 0x%x.", 0x2000, a2);
    result = VfReportIssueWithOptions(196, 0x2000, a2, v5, a3, &dword_618718);
    if ( (MmVerifierData & 0x1000) != 0 )
      result = ViTargetIncrementCounter(a2);
    do
      v6 = __ldrex(&dword_620DF8);
    while ( __strex(v6 + 1, &dword_620DF8) );
  }
  return result;
}
