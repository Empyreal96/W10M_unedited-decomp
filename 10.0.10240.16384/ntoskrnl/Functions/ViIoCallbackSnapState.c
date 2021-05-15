// ViIoCallbackSnapState 
 
_BYTE *ViIoCallbackSnapState()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r4

  v0 = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&ViIoCallbackStateLookaside);
  v1 = v0;
  if ( v0 )
  {
    *v0 = KeGetCurrentIrql(v0);
    *((_DWORD *)v1 + 1) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134);
  }
  return v1;
}
