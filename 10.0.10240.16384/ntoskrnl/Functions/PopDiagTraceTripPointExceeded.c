// PopDiagTraceTripPointExceeded 
 
int __fastcall PopDiagTraceTripPointExceeded(int result, int a2, int a3, int a4)
{
  int v6; // r6
  _DWORD var60[25]; // [sp+8h] [bp-60h] BYREF
  int varg_r0[2]; // [sp+70h] [bp+8h] BYREF
  int varg_r2[2]; // [sp+78h] [bp+10h] BYREF

  varg_r0[1] = a2;
  varg_r2[0] = a3;
  varg_r2[1] = a4;
  v6 = result;
  varg_r0[0] = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, a4);
    if ( result )
    {
      var60[3] = 0;
      var60[4] = 2;
      var60[5] = 0;
      var60[6] = a2;
      var60[7] = 0;
      var60[8] = 2 * v6;
      var60[9] = 0;
      var60[0] = 0;
      var60[1] = 0;
      var60[2] = varg_r0;
      KeQuerySystemTime(var60);
      var60[10] = var60;
      var60[11] = 0;
      var60[12] = 8;
      var60[13] = 0;
      var60[14] = varg_r2;
      var60[15] = 0;
      var60[16] = 4;
      var60[17] = 0;
      result = EtwWrite(PopDiagHandle, dword_61E154, a4, 0);
    }
  }
  return result;
}
