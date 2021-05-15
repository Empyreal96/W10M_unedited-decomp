// ViErrorReportDirect 
 
int __fastcall ViErrorReportDirect(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = ViErrorIsBreakDisabled(a1);
  if ( !result )
    result = VerifierBugCheckIfAppropriate(201, a1, a2, a3, a4);
  return result;
}
