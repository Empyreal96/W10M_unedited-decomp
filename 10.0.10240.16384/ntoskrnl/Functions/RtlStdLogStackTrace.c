// RtlStdLogStackTrace 
 
int __fastcall RtlStdLogStackTrace(int a1)
{
  int v2; // r0
  int result; // r0
  int v4; // [sp+0h] [bp-98h] BYREF
  char v5[10]; // [sp+8h] [bp-90h] BYREF
  __int16 v6; // [sp+12h] [bp-86h]
  char v7[132]; // [sp+14h] [bp-84h] BYREF

  v2 = RtlCaptureStackBackTrace(2u, 0x20u, (int)v7, (int)&v4);
  v6 = v2;
  if ( v2 )
    result = RtlpStdLogCapturedStackTrace(a1, v5, v4);
  else
    result = 0;
  return result;
}
