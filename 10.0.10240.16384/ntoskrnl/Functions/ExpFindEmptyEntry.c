// ExpFindEmptyEntry 
 
_DWORD *__fastcall ExpFindEmptyEntry(int a1, int a2)
{
  int v3; // r0
  _DWORD *v4; // r4
  _DWORD *result; // r0

  v3 = *(_DWORD *)(a1 + 8);
  if ( v3 )
  {
    v4 = (_DWORD *)(v3 + 8 * *(_DWORD *)(v3 + 4));
    result = (_DWORD *)(v3 + 8);
    while ( *result )
    {
      result += 2;
      if ( result == v4 )
        goto LABEL_6;
    }
    *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x191) = ((int)result - *(_DWORD *)(a1 + 8)) >> 3;
  }
  else
  {
LABEL_6:
    ExpExpandResourceOwnerTable(a1, a2);
    result = 0;
  }
  return result;
}
