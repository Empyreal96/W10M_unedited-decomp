// ExpSaAllocatorOptimizeList 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall ExpSaAllocatorOptimizeList(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r5
  _DWORD *v3; // r7
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED
  _DWORD *v8; // r1

  v1 = result;
  v2 = result[9];
  if ( (v2 & 2) != 0 )
  {
    result = (_DWORD *)result[1];
    if ( result != v1 + 1 )
    {
      do
      {
        v3 = (_DWORD *)*result;
        if ( result[5] == 1024 )
        {
          *(_QWORD *)&v4 = *(_QWORD *)result;
          if ( *(_DWORD **)(*result + 4) != result || (_DWORD *)*v5 != result )
            __fastfail(3u);
          *v5 = v4;
          *(_DWORD *)(v4 + 4) = v5;
          ExpSaPageGroupDescriptorFree();
        }
        else if ( !result[5] )
        {
          *(_QWORD *)&v6 = *(_QWORD *)result;
          result[6] = 1;
          if ( *(_DWORD **)(v6 + 4) != result || (_DWORD *)*v7 != result )
            __fastfail(3u);
          *v7 = v6;
          *(_DWORD *)(v6 + 4) = v7;
          v8 = (_DWORD *)v1[4];
          *result = v1 + 3;
          result[1] = v8;
          if ( (_DWORD *)*v8 != v1 + 3 )
            __fastfail(3u);
          *v8 = result;
          v1[4] = result;
        }
        result = v3;
      }
      while ( v3 != v1 + 1 );
    }
    v1[9] = v2 & 0xFFFFFFFD;
  }
  return result;
}
