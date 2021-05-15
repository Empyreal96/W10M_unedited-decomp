// RtlGetCallersAddress 
 
unsigned int __fastcall RtlGetCallersAddress(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  unsigned int result; // r0
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]

  v7 = a3;
  v8 = a4;
  result = RtlCaptureStackBackTrace(2, 2, &v7, 0);
  if ( result )
    *a1 = v7;
  else
    *a1 = 0;
  if ( result < 2 )
    *a2 = 0;
  else
    *a2 = v8;
  return result;
}
