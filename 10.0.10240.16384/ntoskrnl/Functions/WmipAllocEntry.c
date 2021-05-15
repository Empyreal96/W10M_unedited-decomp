// WmipAllocEntry 
 
_DWORD *__fastcall WmipAllocEntry(int *a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r4

  v2 = (_BYTE *)ExAllocateFromPagedLookasideList(*a1);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, a1[1]);
    __dmb(0xBu);
    v3[3] = 1;
    v3[2] = a1[3];
    v3[4] = a1[4];
  }
  return v3;
}
