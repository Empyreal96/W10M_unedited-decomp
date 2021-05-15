// SepInitializeSessionLowboxStructures 
 
__int64 SepInitializeSessionLowboxStructures()
{
  int *v0; // r3
  int v1; // r2
  __int64 result; // r0

  v0 = &g_SessionLowboxArray;
  v1 = 5;
  HIDWORD(result) = 0;
  do
  {
    *((_BYTE *)v0 + 16) = 0;
    v0[3] = 0;
    *v0 = 0;
    v0 += 5;
    --v1;
  }
  while ( v1 );
  LowboxSessionMapLock = 0;
  g_SessionLowboxMap = 0;
  return result;
}
