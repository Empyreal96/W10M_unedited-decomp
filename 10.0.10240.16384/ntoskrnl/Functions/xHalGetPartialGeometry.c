// xHalGetPartialGeometry 
 
int __fastcall xHalGetPartialGeometry(int a1, _DWORD *a2)
{
  int result; // r0
  char v5[4]; // [sp+18h] [bp-40h] BYREF
  int v6; // [sp+1Ch] [bp-3Ch]
  int v7[4]; // [sp+20h] [bp-38h] BYREF
  int v8[10]; // [sp+30h] [bp-28h] BYREF

  v5[0] = 0;
  v5[1] = 0;
  v5[2] = 4;
  v6 = 0;
  v7[1] = (int)v7;
  v7[0] = (int)v7;
  *a2 = 0;
  result = IoBuildDeviceIoControlRequest(458752, a1, 0, 0, (int)v8, 24);
  if ( result )
  {
    result = IofCallDriver(a1, result);
    if ( result == 259 )
    {
      KeWaitForSingleObject((unsigned int)v5, 0, 0, 0, 0);
      result = v7[2];
    }
    if ( result >= 0 )
      *a2 = v8[0];
  }
  return result;
}
