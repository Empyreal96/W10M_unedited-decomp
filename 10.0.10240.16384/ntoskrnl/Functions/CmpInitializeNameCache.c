// CmpInitializeNameCache 
 
_BYTE *CmpInitializeNameCache()
{
  _BYTE *v0; // r0
  _DWORD *v1; // r4
  _BYTE *result; // r0
  int v3; // r3

  v0 = (_BYTE *)ExAllocatePoolWithTag(1, 0x4000, 1631800643);
  v1 = v0;
  CmpNameCacheTable = (int)v0;
  if ( !v0 )
    sub_81608C();
  result = memset(v0, 0, 0x4000);
  v3 = 2048;
  do
  {
    *v1 = 0;
    v1 += 2;
    --v3;
  }
  while ( v3 );
  return result;
}
