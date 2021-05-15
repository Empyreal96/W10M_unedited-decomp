// VfXdvDriverCaptureIoCallbacks 
 
int __fastcall VfXdvDriverCaptureIoCallbacks(int a1)
{
  int result; // r0

  if ( KernelVerifier || !MmIsDriverVerifying(a1) )
    result = 0;
  else
    result = sub_8E5230();
  return result;
}
