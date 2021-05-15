// ViErrorFinishReport 
 
int __fastcall __spoils<R0,R2,R3,R12> ViErrorFinishReport(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0

  VfUtilDbgPrint((int)"************************************************************\n\n");
  result = ViErrorIsBreakDisabled(a1);
  if ( !result )
  {
    if ( KdDebuggerEnabled )
    {
      if ( !KdDebuggerNotPresent )
      {
        VfErrorStoreTriageInformation(201, a1, a2, a3, a4);
        __debugbreak();
      }
    }
    result = VerifierBugCheckIfAppropriate(201, a1, a2, a3, a4);
  }
  return result;
}
