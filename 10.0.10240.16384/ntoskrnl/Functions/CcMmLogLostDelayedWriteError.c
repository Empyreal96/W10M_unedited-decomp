// CcMmLogLostDelayedWriteError 
 
BOOL __fastcall CcMmLogLostDelayedWriteError(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r5
  bool v7; // zf
  int v8; // r0
  int v9; // r4
  int v11[6]; // [sp+8h] [bp-18h] BYREF

  v11[1] = a4;
  v11[0] = 0;
  v5 = IoQueryFileDosDeviceName(a1, v11);
  v6 = v11[0];
  v7 = v5 == 0;
  v8 = a1 + 48;
  if ( v7 )
    v8 = v11[0];
  v9 = FsRtlLogCcFlushError(v8);
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v9 == 0;
}
