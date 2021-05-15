// PopCheckConsoleTimeouts 
 
int PopCheckConsoleTimeouts()
{
  int v0; // r8
  int result; // r0
  int v2; // r6
  int v3; // r5
  int v4; // r3
  int v5; // r3

  PopPrintEx(3);
  v0 = PopConsoleContext;
  result = PopGetDisplayTimeout(PopConsoleContext);
  v2 = result;
  v3 = PopInputTimeout;
  if ( BYTE1(dword_61DE48) && PopInputTimeout )
    goto LABEL_6;
  if ( PopInputTimeout )
  {
    if ( PopInputTimeout == dword_61DE44 )
      goto LABEL_6;
  }
  else
  {
    BYTE1(dword_61DE48) = 0;
  }
  PopPrintEx(3);
  dword_61DE44 = v3;
  result = PopDiagTraceInputTimeout(v3, BYTE1(dword_61DE48), (unsigned __int8)dword_61DE48, v4);
  byte_61DE64 = v3 != 0;
  dword_61DE08 = v3;
  byte_61DE10 = 1;
  if ( !v3 )
    result = PopInputDisabled(v0, 1, 0);
LABEL_6:
  if ( (_BYTE)dword_61DE50 )
    return sub_7F15EC(result);
  if ( v2 != dword_61DE4C )
  {
    PopPrintEx(3);
    dword_61DE4C = v2;
    result = PopDiagTraceDisplayTimeout(v2, BYTE1(dword_61DE50), (unsigned __int8)dword_61DE50, v5);
    dword_61DE0C = v2;
    byte_61DE11 = 1;
  }
  return result;
}
