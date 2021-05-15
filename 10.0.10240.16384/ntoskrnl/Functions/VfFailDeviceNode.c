// VfFailDeviceNode 
 
int __fastcall VfFailDeviceNode(int result, int a2, int a3, int a4)
{
  int v6; // r2
  int varg_r0; // [sp+18h] [bp+8h]
  int varg_r1; // [sp+1Ch] [bp+Ch]
  int varg_r2; // [sp+20h] [bp+10h]

  varg_r0 = result;
  varg_r1 = a2;
  varg_r2 = a3;
  if ( ViDdiInitialized && MmVerifierData < 0 )
  {
    result = PpvUtilIsHardwareBeingVerified(result);
    if ( result )
      result = VerifierBugCheckIfAppropriate(a2, a3, v6);
  }
  return result;
}
