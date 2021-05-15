// PoRegisterSystemState 
 
_DWORD *__fastcall PoRegisterSystemState(int a1, int a2)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r5
  int v6; // r8
  int v7; // r0
  int v8; // r0
  char v9; // r0
  char v10; // r1
  int v11; // r3
  _DWORD *v13; // [sp+8h] [bp-20h] BYREF
  int v14[7]; // [sp+Ch] [bp-1Ch] BYREF

  v3 = 0;
  v4 = 0;
  v14[0] = 0;
  v6 = 0;
  if ( (a2 & 0x7FFFFFF8) == 0 )
  {
    if ( a2 && a2 >= 0 )
    {
      PoSetSystemState(a2);
    }
    else
    {
      PopDiagTraceRegisterSystemState(a2, a1);
      v4 = (_DWORD *)a1;
      v13 = (_DWORD *)a1;
      if ( !a1
        && ((v7 = PoCaptureReasonContext(0, 0, 0, 1, 0, v14), v3 = (_DWORD *)v14[0], v7 < 0)
         || (v8 = PopCreateKernelPowerRequest(&v13, v14[0]), v4 = v13, v6 = v8, v8 < 0))
        || (v9 = PopGetLegacyPowerRequestFlags(v4, a2, 0), PopApplyLegacyPowerRequestFlags((int)v4, v10, v9, v11),
                                                           v6 < 0) )
      {
        if ( v3 )
          PoDestroyReasonContext(v3);
      }
    }
  }
  return v4;
}
