// FsRtlFindExtraCreateParameter 
 
int __fastcall FsRtlFindExtraCreateParameter(int a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v7; // r4
  _DWORD *v8; // r7

  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  v7 = *(_DWORD **)(a1 + 8);
  v8 = (_DWORD *)(a1 + 8);
  if ( v7 == (_DWORD *)(a1 + 8) )
    return -1073741275;
  while ( memcmp((unsigned int)(v7 + 2), a2, 16) )
  {
    v7 = (_DWORD *)*v7;
    if ( v7 == v8 )
      return -1073741275;
  }
  v7[7] |= 4u;
  if ( a3 )
    *a3 = v7 + 11;
  if ( a4 )
    *a4 = v7[8] - 52;
  return 0;
}
