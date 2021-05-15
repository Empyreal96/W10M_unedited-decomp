// IopRearrangeReqList 
 
unsigned int __fastcall IopRearrangeReqList(int a1)
{
  int v1; // r4
  _DWORD **v2; // r2
  unsigned int result; // r0
  unsigned int v4; // r2
  int v5; // r1
  int v6; // r3

  v1 = a1;
  if ( *(_DWORD *)(a1 + 20) > 1u )
  {
    v4 = 0;
    v5 = a1;
    do
    {
      v6 = *(_DWORD *)(v5 + 24);
      v5 += 4;
      *(_DWORD *)(v6 + 4) = v4++;
    }
    while ( v4 < *(_DWORD *)(a1 + 20) );
    qsort(
      a1 + 24,
      *(_DWORD *)(a1 + 20),
      4u,
      (int (__fastcall *)(unsigned int, _BYTE *))IopCompareReqAlternativePriority);
  }
  v2 = (_DWORD **)(v1 + 24);
  result = v1 + 24 + 4 * *(_DWORD *)(v1 + 20);
  if ( v1 + 24 < result )
  {
    do
    {
      if ( **v2 > 0x7FFFu )
        break;
      ++v2;
    }
    while ( (unsigned int)v2 < result );
  }
  if ( v2 == (_DWORD **)(v1 + 24) )
    return sub_818690();
  *(_DWORD *)(v1 + 16) = v2;
  return result;
}
