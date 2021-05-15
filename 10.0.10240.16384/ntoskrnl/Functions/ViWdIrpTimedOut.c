// ViWdIrpTimedOut 
 
int __fastcall ViWdIrpTimedOut(int result)
{
  int v1; // r3
  int v2; // r2
  int v3; // r1

  v1 = ViWdBreaksEnabled;
  __dmb(0xBu);
  if ( v1 )
  {
    v2 = *(_DWORD *)(result + 8);
    v3 = *(unsigned __int16 *)(result + 18);
    if ( KdDebuggerEnabled )
    {
      if ( !KdDebuggerNotPresent )
      {
        VfErrorStoreTriageInformation(196, 309, v2, 1000 * v3, 0);
        VfUtilDbgPrint((int)"Cancelled IRP %p didn't complete in due time.\n");
        __debugbreak();
      }
    }
    result = VerifierBugCheckIfAppropriate(196, 309, v2, 1000 * v3, 0);
  }
  return result;
}
