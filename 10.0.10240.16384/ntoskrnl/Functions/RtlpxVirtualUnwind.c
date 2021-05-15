// RtlpxVirtualUnwind 
 
int __fastcall RtlpxVirtualUnwind(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, int a8, int a9, int a10, _DWORD *a11)
{
  int result; // r0
  _DWORD v12[8]; // [sp+18h] [bp-20h] BYREF

  v12[0] = a3 & 0xFFFFFFFE;
  v12[1] = a9;
  v12[2] = a10;
  v12[3] = a8;
  if ( (a4[1] & 3) != 0 )
    result = RtlpUnwindFunctionCompact(a3 - a2, a4, a5, a7, a11, a6, (int)v12);
  else
    result = RtlpUnwindFunctionFull(a3 - a2, a2, a4, a5, a7, a11, a6, v12);
  return result;
}
