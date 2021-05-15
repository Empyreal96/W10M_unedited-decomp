// WdipSemGetLoggerIds 
 
int __fastcall WdipSemGetLoggerIds(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int v6; // r1
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned int v10; // r4
  _DWORD v11[2]; // [sp+0h] [bp-18h] BYREF
  _DWORD v12[4]; // [sp+8h] [bp-10h] BYREF

  v11[0] = a1;
  v11[1] = a2;
  v12[0] = a3;
  v12[1] = a4;
  RtlInitUnicodeString((unsigned int)v11, L"DiagLog");
  v4 = EtwQueryTraceHandleByLoggerName(v11, v12);
  __dmb(0xBu);
  if ( v4 >= 0 )
    return sub_7D0E64();
  do
    v6 = __ldrex((unsigned int *)&WdipDiagLoggerId);
  while ( __strex(0, (unsigned int *)&WdipDiagLoggerId) );
  __dmb(0xBu);
  RtlInitUnicodeString((unsigned int)v11, L"WdiContextLog");
  v7 = EtwQueryTraceHandleByLoggerName(v11, v12);
  __dmb(0xBu);
  if ( v7 >= 0 )
  {
    v9 = LOWORD(v12[0]);
    do
      v10 = __ldrex((unsigned int *)&WdipContextLoggerId);
    while ( __strex(v9, (unsigned int *)&WdipContextLoggerId) );
  }
  else
  {
    do
      v8 = __ldrex((unsigned int *)&WdipContextLoggerId);
    while ( __strex(0, (unsigned int *)&WdipContextLoggerId) );
  }
  __dmb(0xBu);
  if ( v4 >= 0 )
    v4 = v7;
  return v4;
}
