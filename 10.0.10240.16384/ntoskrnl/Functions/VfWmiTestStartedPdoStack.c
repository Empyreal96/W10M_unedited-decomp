// VfWmiTestStartedPdoStack 
 
_BYTE *__fastcall VfWmiTestStartedPdoStack(int a1)
{
  _BYTE *result; // r0
  int v3[12]; // [sp+10h] [bp-30h] BYREF

  result = memset(v3, 0, 40);
  if ( (MmVerifierData & 0x10) != 0 )
  {
    LOWORD(v3[0]) = -233;
    v3[2] = a1;
    result = (_BYTE *)VfIrpSendSynchronousIrp(a1, (int)v3, 1, -1073741637, 0, 0, 0);
  }
  return result;
}
