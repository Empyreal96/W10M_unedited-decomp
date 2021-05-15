// PfSnScanCommandLine 
 
int __fastcall PfSnScanCommandLine(int *a1, int a2)
{
  int v4; // r4
  int v5; // r0
  int result; // r0
  int v7[2]; // [sp+0h] [bp-20h] BYREF
  char v8[24]; // [sp+8h] [bp-18h] BYREF

  v4 = 0;
  v5 = PfSnGetUnsafeProcessParameters();
  if ( !v5 )
    return -1073741431;
  result = PfSnCaptureParamBlockString(v5, v5 + 64, v8);
  if ( result >= 0 )
  {
    if ( PfSnParsePrefetchParam(v8, v7) >= 0 )
      v4 = v7[0];
    if ( !a2 )
      goto LABEL_6;
    result = PfSnHashUnsafeUnicodeString(v8, v7);
    if ( result >= 0 )
    {
      v4 += v7[0];
LABEL_6:
      *a1 = v4;
      return 0;
    }
  }
  return result;
}
