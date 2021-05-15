// RtlpFindEntry 
 
int __fastcall RtlpFindEntry(int a1, unsigned int a2)
{
  _DWORD *v2; // r4
  unsigned int i; // r3
  _DWORD *v5; // r3
  int j; // r3
  int result; // r0

  v2 = *(_DWORD **)(a1 + 180);
  for ( i = v2[1]; a2 >= i; i = v5[1] )
  {
    v5 = (_DWORD *)*v2;
    if ( !*v2 )
    {
      j = v2[1] - 1;
      break;
    }
    v2 = (_DWORD *)*v2;
  }
  for ( j = a2; ; j = v2[5] )
  {
    result = RtlpHeapFindListLookupEntry(a1, v2, 1, j);
    if ( result )
      break;
    v2 = (_DWORD *)*v2;
  }
  return result;
}
