// KeAbInitialize 
 
__int64 KeAbInitialize()
{
  _DWORD *v0; // r3
  int v1; // r2
  __int64 result; // r0

  v0 = &KiAbTreeArray;
  v1 = 4;
  HIDWORD(result) = 0;
  do
  {
    *v0 = 0;
    v0[1] = 0;
    v0[2] = 0;
    v0 += 32;
    --v1;
  }
  while ( v1 );
  if ( !KiAbForceDisable )
    KiAbEnabled = 1;
  return result;
}
