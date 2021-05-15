// KiInitializeTimer2Data 
 
unsigned __int64 KiInitializeTimer2Data()
{
  unsigned __int64 result; // r0
  _DWORD *v1; // r3
  int v2; // r2

  result = 0xFFFFFFFF00000000ui64;
  v1 = KiTimer2Collections;
  v2 = 5;
  do
  {
    *v1 = 0;
    v1[1] = 0;
    v1[2] = -1;
    v1[3] = -1;
    v1 += 4;
    --v2;
  }
  while ( v2 );
  KiNextTimer2DueTime = -1i64;
  return result;
}
