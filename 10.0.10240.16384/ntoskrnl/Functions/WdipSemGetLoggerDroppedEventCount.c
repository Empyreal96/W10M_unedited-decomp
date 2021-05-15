// WdipSemGetLoggerDroppedEventCount 
 
int __fastcall WdipSemGetLoggerDroppedEventCount(unsigned int a1, _DWORD *a2)
{
  int result; // r0
  int v4; // [sp+8h] [bp-8h] BYREF
  unsigned int vars8[2]; // [sp+18h] [bp+8h] BYREF

  vars8[1] = (unsigned int)a2;
  vars8[0] = a1;
  v4 = 0;
  if ( !a2 || !a1 )
    return -1073741811;
  result = WmiQueryTraceInformation(8, &v4, 4u, 0, vars8);
  if ( result >= 0 )
    *a2 = v4;
  return result;
}
