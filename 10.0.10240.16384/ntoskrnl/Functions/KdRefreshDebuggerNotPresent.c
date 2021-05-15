// KdRefreshDebuggerNotPresent 
 
int __fastcall KdRefreshDebuggerNotPresent(int a1, int a2, int a3, const char *a4)
{
  int v4; // r4
  int v5; // r5
  int v7; // [sp+0h] [bp-10h] BYREF
  const char *v8; // [sp+4h] [bp-Ch]

  v7 = a3;
  v8 = a4;
  if ( KdPitchDebugger )
    return 1;
  v8 = "KDTARGET: Refreshing KD connection\n";
  LOWORD(v7) = (unsigned __int16)strlen((unsigned int)"KDTARGET: Refreshing KD connection\n");
  v4 = KdEnterDebugger(0, 0);
  KdpPrintString(&v7);
  v5 = (unsigned __int8)KdDebuggerNotPresent;
  KdExitDebugger(v4);
  return v5;
}
