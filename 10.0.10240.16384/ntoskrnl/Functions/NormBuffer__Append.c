// NormBuffer__Append 
 
int __fastcall NormBuffer__Append(int a1, int a2)
{
  int v3; // r1
  int result; // r0
  _WORD *v5; // r2
  __int16 v6; // r1
  _WORD *v7; // r3

  if ( a2 >= 0x10000 )
  {
    if ( !((int (*)(void))NormBuffer__CheckBufferSpace)() )
      return 0;
    v5 = *(_WORD **)(a1 + 20);
    *v5 = (v3 - 0x10000) / 1024 - 10240;
    *(_DWORD *)(a1 + 20) = v5 + 1;
    a2 = (unsigned __int16)((v3 - 0x10000) % 1024 - 9216);
  }
  if ( !NormBuffer__CheckBufferSpace(a1, a2) )
    return 0;
  v7 = *(_WORD **)(a1 + 20);
  result = 1;
  *v7 = v6;
  *(_DWORD *)(a1 + 20) = v7 + 1;
  return result;
}
