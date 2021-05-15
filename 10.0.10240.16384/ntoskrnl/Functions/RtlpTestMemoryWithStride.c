// RtlpTestMemoryWithStride 
 
int __fastcall RtlpTestMemoryWithStride(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r2
  int v5; // r2
  _DWORD *i; // r2

  v4 = (a4 >> 2) - 12 * ((unsigned int)((2863311531u * (unsigned __int64)(a4 >> 2)) >> 32) >> 3);
  if ( v4 > 2 * a2 )
    v5 = 2 * a2 - v4 + 12;
  else
    v5 = 2 * a2 - v4;
  for ( i = (_DWORD *)(a4 + 4 * v5); ; i += 12 )
  {
    if ( (unsigned int)i >= a4 + 4096 )
      return 1;
    if ( *i != a1 || i[1] != a1 )
      break;
  }
  return 0;
}
