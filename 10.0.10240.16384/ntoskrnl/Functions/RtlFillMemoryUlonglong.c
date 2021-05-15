// RtlFillMemoryUlonglong 
 
_QWORD *__fastcall RtlFillMemoryUlonglong(_QWORD *result, unsigned int a2, __int64 a3)
{
  unsigned int v3; // r1
  unsigned int v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r1
  int v7; // t1

  v3 = a2 >> 3;
  if ( v3 )
  {
    *result = a3;
    v4 = (8 * v3 - 5) >> 2;
    v5 = result + 1;
    if ( v4 )
    {
      v6 = &v5[v4];
      do
      {
        v7 = *(_DWORD *)result;
        result = (_QWORD *)((char *)result + 4);
        *v5++ = v7;
      }
      while ( v5 != v6 );
    }
  }
  return result;
}
