// ViHalPreprocessOptions 
 
int *ViHalPreprocessOptions(int *result, const char *a2, unsigned int a3, int a4, int a5, ...)
{
  int v5; // r4
  int v8; // r3

  if ( (a3 & 0x10000000) == 0 )
    v5 = 0;
  if ( (a3 & 0x10000000) != 0 )
  {
    v5 = 1;
    a3 &= 0xEFFFFFFF;
  }
  if ( *result == -1 )
  {
    if ( a3 >= 0x26 )
      v8 = 4;
    else
      v8 = ViHalDefaultActions[a3];
    *result = v8;
  }
  if ( *result )
  {
    if ( (*result & 0x10) != 0 )
      *result = 0;
    VfUtilDbgPrint((int)"**************** HAL Verifier Detected Violation ****************\n");
    VfUtilDbgPrint((int)"**\n");
    VfUtilDbgPrint((int)"** VF: ");
    if ( v5 )
      DbgPrintEx(101, 0, (int)a2, a5);
    else
      DbgPrintEx(101, 0, (int)a2, a4);
    VfUtilDbgPrint((int)"\n");
    VfUtilDbgPrint((int)"**\n");
    result = (int *)VfUtilDbgPrint((int)"*****************************************************************\n");
  }
  return result;
}
