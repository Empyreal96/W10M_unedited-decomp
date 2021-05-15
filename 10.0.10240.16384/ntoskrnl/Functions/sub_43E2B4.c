// sub_43E2B4 
 
int __fastcall sub_43E2B4(_WORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r5
  int result; // r0
  int v6; // r4
  int v7; // r6

  v4 = 0;
  if ( !a2 )
    return sub_50A5DC();
  v6 = 2147483646;
  v7 = a4 - (_DWORD)a1;
  while ( v6 && *(_WORD *)((char *)a1 + v7) )
  {
    *a1 = *(_WORD *)((char *)a1 + v7);
    --a2;
    ++a1;
    --v6;
    ++v4;
    if ( !a2 )
      return sub_50A5DC();
  }
  *a1 = 0;
  result = 0;
  if ( a3 )
    *a3 = v4;
  return result;
}
