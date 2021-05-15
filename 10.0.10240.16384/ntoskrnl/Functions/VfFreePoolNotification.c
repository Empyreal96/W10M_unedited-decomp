// VfFreePoolNotification 
 
int __fastcall VfFreePoolNotification(int result, int a2, int a3)
{
  int v4; // r5
  BOOL v5; // r3

  v4 = result;
  v5 = (MmVerifierData & 8) == 0 && VfVerifyMode == 2;
  if ( a2 )
  {
    if ( !v5 && VfPoolTraces )
      ViPoolLogStackTrace(result, a2, a3);
    result = VfFreeMemoryNotification(v4, a2);
  }
  else if ( v5 )
  {
    if ( VfPoolTraces )
      result = ViPoolLogStackTrace(result, 8, a3);
  }
  return result;
}
