// VfFailDriver 
 
int __fastcall VfFailDriver(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+10h] [bp+8h]

  varg_r0 = result;
  if ( ViDdiInitialized )
    result = VerifierBugCheckIfAppropriate(result, a2, 0);
  return result;
}
