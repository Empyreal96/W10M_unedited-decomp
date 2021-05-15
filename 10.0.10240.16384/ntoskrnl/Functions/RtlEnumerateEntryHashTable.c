// RtlEnumerateEntryHashTable 
 
_DWORD *__fastcall RtlEnumerateEntryHashTable(_DWORD *a1, _DWORD *a2)
{
  unsigned int v3; // r4
  unsigned int v4; // lr
  _DWORD *result; // r0
  _DWORD *v7; // r2
  __int64 v8; // kr00_8
  _DWORD *v9; // r1
  _DWORD *v10; // r2

  v3 = a2[4];
  v4 = a1[2];
  if ( v3 >= v4 )
    return 0;
  while ( 1 )
  {
    if ( v3 == a2[4] )
    {
      v7 = (_DWORD *)a2[3];
      result = a2;
    }
    else
    {
      if ( a1[2] > 0x80u )
        return (_DWORD *)sub_51F850();
      v7 = (_DWORD *)(a1[8] + 8 * (v3 & 0x7F));
      result = v7;
    }
    if ( (_DWORD *)*result != v7 )
      break;
LABEL_7:
    if ( ++v3 >= v4 )
      return 0;
  }
  while ( 1 )
  {
    result = (_DWORD *)*result;
    if ( result[2] )
      break;
    if ( (_DWORD *)*result == v7 )
      goto LABEL_7;
  }
  v8 = *(_QWORD *)a2;
  if ( *(_DWORD **)(*a2 + 4) != a2 || *(_DWORD **)HIDWORD(v8) != a2 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v8) = v8;
  *(_DWORD *)(v8 + 4) = HIDWORD(v8);
  v9 = (_DWORD *)a2[3];
  if ( v9 != v7 )
  {
    if ( (_DWORD *)*v9 == v9 )
      --a1[6];
    if ( (_DWORD *)*v7 == v7 )
      ++a1[6];
  }
  a2[3] = v7;
  a2[4] = v3;
  v10 = (_DWORD *)*result;
  *a2 = *result;
  a2[1] = result;
  if ( (_DWORD *)v10[1] != result )
    __fastfail(3u);
  v10[1] = a2;
  *result = a2;
  return result;
}
