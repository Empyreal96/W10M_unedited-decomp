// KiFlushReadyLists 
 
int __fastcall KiFlushReadyLists(int result, unsigned int *a2, _DWORD *a3)
{
  unsigned int v3; // r5
  _DWORD *v5; // r4
  __int64 v6; // kr00_8
  _DWORD *v7; // lr
  _DWORD *v8; // r2

  v3 = *a2;
  if ( *a2 )
  {
    do
    {
      v5 = (_DWORD *)(result + 8 * __clz(__rbit(v3)));
      v6 = *(_QWORD *)v5;
      v3 &= v3 - 1;
      v7 = (_DWORD *)*v5;
      if ( *(_DWORD **)(*v5 + 4) != v5 || *(_DWORD **)HIDWORD(v6) != v5 )
        sub_52B660();
      *(_DWORD *)HIDWORD(v6) = v6;
      *(_DWORD *)(v6 + 4) = HIDWORD(v6);
      *v5 = v5;
      v5[1] = v5;
      do
      {
        v8 = v7 - 36;
        v8[19] = *(v7 - 17) | 2;
        v7 = (_DWORD *)*v7;
        *((_BYTE *)v8 + 132) = 7;
        v8[36] = *a3;
        *a3 = v8 + 36;
      }
      while ( v7 != (_DWORD *)v6 );
    }
    while ( v3 );
    *a2 = 0;
  }
  return result;
}
