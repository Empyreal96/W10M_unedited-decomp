// PopDiagTraceSetThreadExecutionState 
 
int __fastcall PopDiagTraceSetThreadExecutionState(int result, int a2)
{
  _DWORD *v2; // r6
  __int64 v3; // kr00_8
  int *v4; // r2
  unsigned __int16 *v5; // r1
  int v6; // r3
  int *v7; // r2
  __int16 v8; // [sp+8h] [bp-70h] BYREF
  int v9; // [sp+Ch] [bp-6Ch] BYREF
  int v10[10]; // [sp+10h] [bp-68h] BYREF
  int v11[4]; // [sp+38h] [bp-40h] BYREF
  char v12; // [sp+48h] [bp-30h] BYREF
  int anonymous0; // [sp+80h] [bp+8h]
  int varsC; // [sp+84h] [bp+Ch] BYREF

  anonymous0 = result;
  varsC = a2;
  v2 = (_DWORD *)result;
  if ( PopDiagHandleRegistered )
  {
    v3 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_STES);
    if ( result )
    {
      v4 = v11;
      v9 = v2[219];
      v10[0] = v2[220];
      v5 = *(unsigned __int16 **)(v2[84] + 380);
      v8 = *v5 >> 1;
      v10[2] = (int)&varsC;
      v10[3] = 0;
      v10[4] = 4;
      v10[5] = 0;
      v10[6] = (int)&v8;
      v10[7] = 0;
      v10[8] = 2;
      v10[9] = 0;
      if ( *v5 )
      {
        v6 = *((_DWORD *)v5 + 1);
        v11[2] = *v5;
        v11[0] = v6;
        v11[1] = 0;
        v11[3] = 0;
        v4 = (int *)&v12;
      }
      *v4 = (int)&v9;
      *(_QWORD *)(v4 + 1) = 0x400000000i64;
      v4[3] = 0;
      v4[4] = (int)v10;
      v4[5] = 0;
      v7 = v4 + 4;
      v7[2] = 4;
      v7[3] = 0;
      result = EtwWrite(v3, SHIDWORD(v3), (int)POP_ETW_EVENT_STES, 0);
    }
  }
  return result;
}
