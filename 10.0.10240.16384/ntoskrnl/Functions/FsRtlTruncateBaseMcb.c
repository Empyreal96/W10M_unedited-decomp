// FsRtlTruncateBaseMcb 
 
int __fastcall FsRtlTruncateBaseMcb(int result, int a2, unsigned int a3, int a4)
{
  _DWORD *v5; // r4
  unsigned int v6; // r2
  unsigned int *v7; // r1
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a4;
  v5 = (_DWORD *)result;
  if ( a3 )
  {
    if ( *(_DWORD *)(result + 4) )
    {
      result = FsRtlFindLargeIndex(result, a3 - 1, v8);
      if ( result )
      {
        v6 = v8[0];
        v7 = (unsigned int *)(v5[3] + 8 * v8[0]);
        if ( v7[1] == -1 )
        {
          v5[1] = v8[0];
        }
        else
        {
          v5[1] = v8[0] + 1;
          if ( v6 < v6 + 1 && v6 != -1 && *v7 > a3 )
            *v7 = a3;
        }
      }
    }
  }
  else
  {
    *(_DWORD *)(result + 4) = 0;
  }
  if ( *v5 > 0xFu && v5[1] < *v5 >> 2 )
    result = sub_520290();
  return result;
}
