// VF_ASSERT_IRQL 
 
int __fastcall VF_ASSERT_IRQL(int a1)
{
  int result; // r0
  int v3; // r6

  result = KeGetCurrentIrql(a1);
  v3 = result;
  if ( result != a1 )
  {
    ViHalPreprocessOptions(&dword_618760, "Bad IRQL -- needed %x, got %x.", 268435475, 1);
    result = VfReportIssueWithOptions(230, 19, 1, a1, v3, &dword_618760);
  }
  return result;
}
