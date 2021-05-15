// MiConvertContiguousPages 
 
int __fastcall MiConvertContiguousPages(int result, int a2, int a3)
{
  _DWORD *v3; // r6
  _DWORD *v4; // r5
  _DWORD *v5; // r4
  _DWORD *v7; // r2

  v3 = (_DWORD *)(result + 24 * a2);
  v4 = (_DWORD *)result;
  v5 = 0;
  if ( (_DWORD *)result != v3 )
  {
    do
    {
      result = MiPageAttributeBatchChangeNeeded(v4, a3);
      if ( result )
      {
        if ( v4[2] )
          *v4 = 1;
        else
          *v4 = 0;
        v4[2] = v5;
        v5 = v4;
      }
      v4 += 6;
    }
    while ( v4 != v3 );
    if ( v5 )
    {
      result = MiChangePageAttributeBatch(v5, a3, -1);
      do
      {
        v7 = (_DWORD *)v5[2];
        if ( *v5 )
          v5[2] = 128;
        else
          v5[2] = 0;
        v5 = v7;
      }
      while ( v7 );
    }
  }
  return result;
}
