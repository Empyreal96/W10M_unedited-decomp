// IopCopyOverNewPath 
 
unsigned int __fastcall IopCopyOverNewPath(int a1, int a2, unsigned int a3, int a4, unsigned __int16 a5)
{
  unsigned int v7; // r4
  _WORD *v8; // r5
  __int16 v9; // r9
  int v10; // r0
  int v11; // r1
  __int16 v12; // r2
  unsigned int result; // r0

  v7 = a1;
  v8 = (_WORD *)a1;
  v9 = 2;
  if ( a3 )
  {
    memmove(a1, a2, a3);
    v8 += a3 >> 1;
  }
  if ( a5 )
  {
    v10 = *(_DWORD *)(a4 + 52);
    v11 = *(unsigned __int16 *)(a4 + 48) - a5;
    if ( (unsigned int)v8 > v7 && *(v8 - 1) == 92 && *(_WORD *)(v11 + v10) == 92 )
    {
      --v8;
      v9 = 0;
    }
    memmove((int)v8, v11 + v10, a5);
    v8 += a5 >> 1;
  }
  v12 = v9 + a3 + a5;
  *(_WORD *)(a4 + 48) = v12 - 2;
  *(_WORD *)(a4 + 50) = v12;
  *v8 = 0;
  result = *(_DWORD *)(a4 + 52);
  if ( v7 != result )
  {
    if ( result )
      result = ExFreePoolWithTag(result);
    *(_DWORD *)(a4 + 52) = v7;
  }
  return result;
}
