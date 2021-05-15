// PiUEventEstimateRequiredClientBufferSize 
 
int __fastcall PiUEventEstimateRequiredClientBufferSize(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r1
  int result; // r0
  int v6[2]; // [sp+0h] [bp-8h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  v4 = *(_DWORD *)(a1 + 72);
  v6[0] = 0;
  if ( RtlULongLongToULong(4160 * v4, (4160 * (unsigned __int64)v4) >> 32, v6) < 0 )
    result = -1;
  else
    result = v6[0];
  return result;
}
