// LdrpCompareResourceNames_U 
 
int __fastcall LdrpCompareResourceNames_U(unsigned __int16 *a1, int a2, int *a3)
{
  int v3; // r3
  int v5; // r4
  unsigned __int16 *v7; // r3
  int v8; // r6

  v3 = *a3;
  if ( ((unsigned int)a1 & 0xFFFF0000) == 0 )
  {
    if ( v3 >= 0 )
      return (int)a1 - v3;
    return 1;
  }
  if ( v3 >= 0 )
    return -1;
  v7 = (unsigned __int16 *)((v3 & 0x7FFFFFFF) + a2);
  v8 = *v7;
  v5 = wcsncmp(a1, v7 + 1, v8);
  if ( !v5 && wcslen(a1) != v8 )
    return 1;
  return v5;
}
