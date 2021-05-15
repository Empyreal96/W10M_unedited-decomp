// EtwpAcquireLoggerContext 
 
int __fastcall EtwpAcquireLoggerContext(int a1, _DWORD *a2, int a3, int a4)
{
  unsigned int v6; // r4
  int v7; // r0
  bool v8; // zf
  int result; // r0
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a3;
  v10[2] = a4;
  v6 = -1;
  *a2 = 0;
  if ( !memcmp(a1 + 24, (unsigned int)SystemTraceControlGuid, 16) )
    v6 = (unsigned __int16)EtwpSystemLogger[0];
  if ( v6 != (unsigned __int16)EtwpSystemLogger[0] && *(_WORD *)(a1 + 144) )
  {
    result = EtwpCaptureString((unsigned __int16 *)(a1 + 144), (unsigned int)v10);
    if ( result < 0 )
      return result;
    *a2 = EtwpAcquireLoggerContextByLoggerName((unsigned __int16 *)v10, 1);
    RtlFreeAnsiString(v10);
    v8 = *a2 == 0;
  }
  else
  {
    if ( v6 == -1 )
    {
      v6 = *(unsigned __int16 *)(a1 + 8);
      if ( v6 == 0xFFFF )
        v6 = (unsigned __int16)EtwpSystemLogger[0];
      if ( v6 >= 0x40 )
        return -1073741816;
    }
    v7 = EtwpAcquireLoggerContextByLoggerId(v6, 1);
    *a2 = v7;
    v8 = v7 == 0;
  }
  if ( v8 )
    result = -1073741162;
  else
    result = 0;
  return result;
}
