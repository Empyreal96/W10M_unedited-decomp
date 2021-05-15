// PopTraceSystemIdleUpdate 
 
int __fastcall PopTraceSystemIdleUpdate(int a1, int a2, int a3, int a4, char a5, char a6, char a7, char a8, char a9, char a10, char a11)
{
  int result; // r0
  __int64 v15; // kr00_8
  unsigned int v16; // r2
  int v17; // r2
  int v18; // r2
  int v19; // r2
  int v20; // [sp+8h] [bp-80h] BYREF
  _DWORD var7C[32]; // [sp+Ch] [bp-7Ch] BYREF
  int varg_r0[4]; // [sp+90h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  result = (unsigned __int8)PopDiagHandleRegistered;
  if ( PopDiagHandleRegistered )
  {
    v15 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SYSTEM_IDLE_UPDATE);
    if ( result )
    {
      v16 = (v20 & 0xFFFFFFFE | (a3 != 0)) ^ ((v20 & 0xFE | (a3 != 0)) ^ (unsigned __int8)(2 * (a4 != 0))) & 2;
      v17 = v16 ^ ((unsigned __int8)v16 ^ (unsigned __int8)(4 * (a5 != 0))) & 4;
      v18 = v17 ^ ((unsigned __int8)v17 ^ (unsigned __int8)(8 * (a6 != 0))) & 8;
      v19 = v18 ^ ((unsigned __int8)v18 ^ (unsigned __int8)(16 * (a8 != 0))) & 0x10;
      v20 = ((unsigned __int8)v19 ^ (unsigned __int8)(32 * (a9 != 0))) & 0x20 ^ v19;
      var7C[0] = a2;
      var7C[1] = varg_r0;
      var7C[2] = 0;
      var7C[3] = 4;
      var7C[4] = 0;
      var7C[5] = var7C;
      var7C[6] = 0;
      var7C[7] = 4;
      var7C[8] = 0;
      var7C[9] = &v20;
      var7C[10] = 0;
      var7C[11] = 4;
      var7C[12] = 0;
      var7C[13] = &a10;
      var7C[14] = 0;
      var7C[15] = 4;
      var7C[16] = 0;
      var7C[17] = &a11;
      var7C[18] = 0;
      var7C[19] = 4;
      var7C[20] = 0;
      var7C[21] = &a7;
      var7C[22] = 0;
      var7C[23] = 4;
      var7C[24] = 0;
      result = EtwWrite(v15, SHIDWORD(v15), (int)POP_ETW_EVENT_SYSTEM_IDLE_UPDATE, 0);
    }
  }
  return result;
}
