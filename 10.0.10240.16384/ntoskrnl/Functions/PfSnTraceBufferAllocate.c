// PfSnTraceBufferAllocate 
 
_BYTE *PfSnTraceBufferAllocate()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r4

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 69632, 1112564547);
  v1 = v0;
  if ( !v0 )
    return 0;
  memset(v0, 0, 69632);
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 8702;
  return v1;
}
