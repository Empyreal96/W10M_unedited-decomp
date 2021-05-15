// PopIdleDetection 
 
int PopIdleDetection()
{
  int result; // r0

  if ( PsWin32CalloutsEstablished )
    result = PopScanIdleList();
  return result;
}
