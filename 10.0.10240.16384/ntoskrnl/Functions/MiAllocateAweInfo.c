// MiAllocateAweInfo 
 
_BYTE *MiAllocateAweInfo()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r4

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 20, 2000776525);
  v1 = v0;
  if ( v0 )
  {
    memset(v0, 0, 20);
    ExInitializeAutoExpandPushLock((_DWORD *)v1 + 1, 1);
  }
  return v1;
}
