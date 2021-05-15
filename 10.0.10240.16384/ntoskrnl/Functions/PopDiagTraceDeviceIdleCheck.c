// PopDiagTraceDeviceIdleCheck 
 
int PopDiagTraceDeviceIdleCheck(int result, ...)
{
  int *v1; // r5
  int v2; // r1
  int v3; // r2
  char v4; // [sp+8h] [bp-C8h] BYREF
  char v5; // [sp+9h] [bp-C7h] BYREF
  __int16 v6; // [sp+Ah] [bp-C6h] BYREF
  int varC4[50]; // [sp+Ch] [bp-C4h] BYREF
  int varg_r1; // [sp+DCh] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+DCh] [bp+Ch]
  va_list varg_r2; // [sp+E0h] [bp+10h] BYREF

  va_start(varg_r2, result);
  va_start(varg_r1a, result);
  varg_r1 = va_arg(varg_r2, _DWORD);
  varC4[0] = 0;
  v1 = (int *)result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_IDLE_CHECK);
    if ( result )
    {
      result = IoGetDeviceAttachmentBaseRef(v1[6]);
      varC4[0] = result;
      if ( result )
      {
        v2 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
        if ( v2 )
        {
          v6 = *(_WORD *)(v2 + 20) >> 1;
          v4 = v1[10] - 1;
          v5 = v1[11] - 1;
          varC4[1] = (int)(v1 + 6);
          varC4[2] = 0;
          varC4[3] = 4;
          varC4[4] = 0;
          varC4[5] = (int)varC4;
          varC4[6] = 0;
          varC4[7] = 4;
          varC4[8] = 0;
          varC4[9] = (int)&v6;
          varC4[10] = 0;
          varC4[11] = 2;
          varC4[12] = 0;
          v3 = *(unsigned __int16 *)(v2 + 20);
          varC4[13] = *(_DWORD *)(v2 + 24);
          varC4[14] = 0;
          varC4[15] = v3;
          varC4[16] = 0;
          varC4[17] = (int)(v1 + 4);
          varC4[18] = 0;
          varC4[19] = 4;
          varC4[20] = 0;
          varC4[21] = (int)(v1 + 5);
          varC4[22] = 0;
          varC4[23] = 4;
          varC4[24] = 0;
          va_copy((va_list)&varC4[25], varg_r1a);
          varC4[26] = 0;
          varC4[27] = 4;
          varC4[28] = 0;
          va_copy((va_list)&varC4[29], varg_r2);
          varC4[30] = 0;
          varC4[31] = 4;
          varC4[32] = 0;
          varC4[33] = (int)(v1 + 3);
          varC4[34] = 0;
          varC4[35] = 4;
          varC4[36] = 0;
          varC4[37] = (int)&v4;
          varC4[38] = 0;
          varC4[39] = 1;
          varC4[40] = 0;
          varC4[41] = (int)&v5;
          varC4[42] = 0;
          varC4[43] = 1;
          varC4[44] = 0;
          EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_IDLE_CHECK, 0);
          result = varC4[0];
        }
        if ( result )
          result = ObfDereferenceObjectWithTag(result);
      }
    }
  }
  return result;
}
