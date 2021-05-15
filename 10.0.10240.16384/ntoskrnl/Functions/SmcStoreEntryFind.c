// SmcStoreEntryFind 
 
_DWORD *__fastcall SmcStoreEntryFind(int a1, int a2, int a3)
{
  _DWORD *result; // r0
  _DWORD *v4; // r4

  result = (_DWORD *)(a1 + 124);
  v4 = result + 64;
  while ( result < v4 )
  {
    if ( *result != -1 && *result == a2 && (result[1] & 3) == a3 )
      return result;
    result += 4;
  }
  return 0;
}
