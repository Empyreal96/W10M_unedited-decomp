// VF_ASSERT_MAX_IRQL 
 
unsigned int __fastcall VF_ASSERT_MAX_IRQL(int a1)
{
  unsigned int result; // r0
  int v2; // r5

  result = KeGetCurrentIrql(a1);
  v2 = result;
  if ( result > 2 )
  {
    ViHalPreprocessOptions(&dword_618758, "Bad IRQL -- needed %x or less, got %x.", 268435475, 2);
    result = VfReportIssueWithOptions(230, 19, 2, 2, v2, &dword_618758);
  }
  return result;
}
