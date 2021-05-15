// NormBuffer__Insert 
 
BOOL __fastcall NormBuffer__Insert(int a1, int a2, __int16 *a3)
{
  __int16 *v4; // r7
  BOOL v6; // r4
  int v7; // r4
  BOOL result; // r0
  __int16 v9; // r1
  __int16 v10; // r2
  __int16 v11; // r3

  v4 = *(__int16 **)(a1 + 20);
  v6 = *(_DWORD *)(a1 + 36) == (_DWORD)(v4 - 1);
  if ( a2 < 0x10000 )
  {
    if ( NormBuffer__CheckBufferSpace(a1) )
    {
      v10 = v9;
      while ( a3 != v4 )
      {
        v11 = *a3;
        *a3++ = v10;
        v10 = v11;
      }
      *(_DWORD *)(a1 + 20) = v4 + 1;
      *v4 = v10;
      if ( v6 )
        *(_DWORD *)(a1 + 36) = v4;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v7 = (a2 - 0x10000) / 1024;
    result = NormBuffer__Insert(a1, (unsigned __int16)((a2 - 0x10000) % 1024 - 9216))
          && NormBuffer__Insert(a1, (unsigned __int16)(v7 - 10240));
  }
  return result;
}
