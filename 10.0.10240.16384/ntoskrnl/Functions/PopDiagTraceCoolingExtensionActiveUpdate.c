// PopDiagTraceCoolingExtensionActiveUpdate 
 
int __fastcall PopDiagTraceCoolingExtensionActiveUpdate(int result)
{
  int v1; // r4
  __int64 v2; // kr00_8
  BOOL v3; // [sp+8h] [bp-38h] BYREF
  _DWORD v4[13]; // [sp+Ch] [bp-34h] BYREF

  v1 = result;
  if ( PopDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COOLING_EXTENSION_ACTIVE_UPDATE);
    if ( result )
    {
      v3 = *(_BYTE *)(v1 + 33) != 0;
      v4[0] = v1;
      v4[1] = &v3;
      v4[2] = 0;
      v4[3] = 4;
      v4[4] = 0;
      v4[5] = v4;
      v4[6] = 0;
      v4[7] = 4;
      v4[8] = 0;
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_ETW_EVENT_COOLING_EXTENSION_ACTIVE_UPDATE, 0);
    }
  }
  return result;
}
