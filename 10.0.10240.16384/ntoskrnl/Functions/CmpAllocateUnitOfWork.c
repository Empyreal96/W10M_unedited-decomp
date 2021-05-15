// CmpAllocateUnitOfWork 
 
_DWORD *CmpAllocateUnitOfWork()
{
  _BYTE *v0; // r0
  _DWORD *v1; // r4

  v0 = (_BYTE *)ExAllocatePoolWithTag(1, 56, 2002079043);
  v1 = v0;
  if ( v0 )
  {
    memset(v0, 0, 56);
    *v1 = v1;
    v1[1] = v1;
    v1[4] = v1 + 4;
    v1[5] = v1 + 4;
    v1[2] = 0;
    v1[3] = 0;
    v1[6] = 0;
    v1[7] = 0;
    v1[8] = 0;
    v1[9] = 14;
  }
  return v1;
}
