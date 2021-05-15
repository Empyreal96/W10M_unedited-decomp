// VfPowerTestStartedPdoStack 
 
_BYTE *__fastcall VfPowerTestStartedPdoStack(int a1)
{
  _BYTE *result; // r0
  char v3[48]; // [sp+10h] [bp-30h] BYREF

  result = memset(v3, 0, 40);
  if ( (MmVerifierData & 0x10) != 0 )
  {
    v3[0] = 22;
    v3[1] = -1;
    result = (_BYTE *)VfIrpSendSynchronousIrp(a1, (int)v3, 1, -1073741637, 0, 0, 0);
  }
  return result;
}
