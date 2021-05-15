// KsepDsEventIoCreateDevice 
 
int __fastcall KsepDsEventIoCreateDevice(int result, int a2, int a3, int a4, unsigned __int8 a5, char a6)
{
  __int64 v6; // r4
  int var78[31]; // [sp+8h] [bp-78h] BYREF
  int varg_r0; // [sp+88h] [bp+8h] BYREF
  int varg_r1; // [sp+8Ch] [bp+Ch] BYREF
  int varg_r2; // [sp+90h] [bp+10h] BYREF
  int varg_r3; // [sp+94h] [bp+14h] BYREF

  varg_r0 = result;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  var78[0] = a5;
  v6 = KseEtwHandle;
  if ( KseEtwHandle )
  {
    result = EtwEventEnabled(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseDsEventCreateDevice);
    if ( result )
    {
      var78[2] = (int)&varg_r0;
      var78[3] = 0;
      var78[4] = 4;
      var78[5] = 0;
      var78[6] = (int)&varg_r1;
      var78[7] = 0;
      var78[8] = 4;
      var78[9] = 0;
      var78[10] = (int)&varg_r2;
      var78[11] = 0;
      var78[12] = 4;
      var78[13] = 0;
      var78[14] = (int)&varg_r3;
      var78[15] = 0;
      var78[16] = 4;
      var78[17] = 0;
      var78[18] = (int)var78;
      var78[19] = 0;
      var78[20] = 4;
      var78[21] = 0;
      var78[22] = (int)&a6;
      var78[23] = 0;
      var78[24] = 4;
      var78[25] = 0;
      result = EtwWrite(v6, SHIDWORD(v6), (int)KseDsEventCreateDevice, 0);
    }
  }
  return result;
}
