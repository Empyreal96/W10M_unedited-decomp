// PopDiagTraceServiceNotification 
 
unsigned __int16 *__fastcall PopDiagTraceServiceNotification(unsigned __int16 *result)
{
  unsigned __int16 *v1; // r4
  int *v2; // r6
  __int64 v3; // kr00_8
  unsigned __int16 v4; // r0
  unsigned __int16 v5; // [sp+8h] [bp-40h] BYREF
  __int16 *v6; // [sp+10h] [bp-38h]
  int v7; // [sp+14h] [bp-34h]
  int v8; // [sp+18h] [bp-30h]
  int v9; // [sp+1Ch] [bp-2Ch]
  _DWORD *v10; // [sp+20h] [bp-28h]
  int v11; // [sp+24h] [bp-24h]
  int v12; // [sp+28h] [bp-20h]
  int v13; // [sp+2Ch] [bp-1Ch]

  v1 = result;
  if ( *(_DWORD *)result )
    v2 = POP_ETW_EVENT_SUSPENDSERVICE_END;
  else
    v2 = POP_ETW_EVENT_SUSPENDSERVICE;
  if ( PopDiagHandleRegistered )
  {
    v3 = *(_QWORD *)&PopDiagHandle;
    result = (unsigned __int16 *)EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v2);
    if ( result )
    {
      v4 = wcslen(v1 + 2);
      v6 = (__int16 *)&v5;
      v7 = 0;
      v8 = 2;
      v9 = 0;
      v10 = v1 + 2;
      v11 = 0;
      v12 = 2 * v4;
      v13 = 0;
      v5 = v4;
      result = (unsigned __int16 *)EtwWrite(v3, SHIDWORD(v3), (int)v2, 0);
    }
  }
  return result;
}
