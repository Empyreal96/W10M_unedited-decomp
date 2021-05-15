// PopDiagTraceDriverVeto 
 
int __fastcall PopDiagTraceDriverVeto(int result, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r1
  unsigned int v6; // r5
  int v7; // r2
  int *v8; // r1
  int v9; // r2
  int *v10; // r1
  __int16 v11; // [sp+8h] [bp-A8h] BYREF
  __int16 v12; // [sp+Ah] [bp-A6h] BYREF
  unsigned __int16 v13; // [sp+10h] [bp-A0h] BYREF
  int v14; // [sp+14h] [bp-9Ch]
  int v15[16]; // [sp+18h] [bp-98h] BYREF
  unsigned __int16 v16[44]; // [sp+58h] [bp-58h] BYREF

  v3 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DRIVERVETO);
    if ( result )
    {
      if ( PopDiagGetDriverName(v3, v16, 0x40u) < 0 )
      {
        RtlInitUnicodeString((unsigned int)&v13, (unsigned __int16 *)&dword_6A1AE0);
        v4 = v13;
        v5 = 0;
      }
      else
      {
        RtlInitUnicodeString((unsigned int)&v13, v16);
        v4 = v13;
        v5 = v13 >> 1;
      }
      v15[0] = (int)&v11;
      v6 = *(unsigned __int16 *)(a2 - 64);
      v15[1] = 0;
      v15[2] = 2;
      v7 = 1;
      v15[3] = 0;
      v11 = v5;
      v12 = v6 >> 1;
      if ( v5 )
      {
        v15[6] = v4;
        v15[4] = v14;
        v15[5] = 0;
        v15[7] = 0;
        v7 = 2;
      }
      v8 = &v15[4 * v7];
      *v8 = (int)&v12;
      v9 = v7 + 1;
      v8[1] = 0;
      v8[2] = 2;
      v8[3] = 0;
      if ( v6 >> 1 )
      {
        v10 = &v15[4 * v9];
        *v10 = *(_DWORD *)(a2 - 60);
        v10[1] = 0;
        v10[2] = v6;
        v10[3] = 0;
      }
      result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DRIVERVETO, 0);
    }
  }
  return result;
}
