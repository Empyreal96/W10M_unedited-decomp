// VfReportIssueWithOptions 
 
int __fastcall VfReportIssueWithOptions(int result, int a2, int a3, int a4, int a5, int *a6)
{
  int v6; // r5

  v6 = *a6;
  if ( *a6 && (v6 & 2) == 0 )
  {
    if ( (v6 & 8) != 0 || (VfOptionFlags & 0x200) != 0 || !KdDebuggerEnabled )
    {
      result = VerifierBugCheckIfAppropriate(result, a2, a3);
    }
    else if ( (v6 & 4) != 0 )
    {
      VfUtilDbgPrint((int)"\n*** Verifier assertion failed ***\n");
      DbgPrompt((unsigned int)"(B)reak, (I)gnore, (W)arn only, (R)emove assert? ");
    }
  }
  return result;
}
