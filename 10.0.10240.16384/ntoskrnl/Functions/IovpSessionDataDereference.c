// IovpSessionDataDereference 
 
int __fastcall IovpSessionDataDereference(int result)
{
  _DWORD *v1; // r4
  __int64 v2; // kr00_8
  _DWORD *v4; // r2
  __int64 v5; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1

  v1 = (_DWORD *)result;
  v2 = *(_QWORD *)result;
  if ( (*(_DWORD *)(result + 4))-- == 1 )
  {
    v4 = (_DWORD *)(result + 8);
    v5 = *(_QWORD *)(result + 8);
    if ( *(_DWORD **)(v5 + 4) != v4 || *(_DWORD **)HIDWORD(v5) != v4 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v5) = v5;
    *(_DWORD *)(v5 + 4) = HIDWORD(v5);
    *v4 = v4;
    v4[1] = v4;
    __dmb(0xBu);
    v6 = (unsigned int *)(v2 + 12);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 - 1, v6) );
    __dmb(0xBu);
    if ( (v1[4] & 4) != 0 )
      result = ExFreeToNPagedLookasideList((int)&ViSessionDataLookaside, v1);
    else
      result = VfPoolDelayFreeIfPossible((int)v1, 0);
  }
  return result;
}
