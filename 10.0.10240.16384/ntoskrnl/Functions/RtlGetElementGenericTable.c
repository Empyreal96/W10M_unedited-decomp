// RtlGetElementGenericTable 
 
int __fastcall RtlGetElementGenericTable(int a1, int a2)
{
  unsigned int v2; // r4
  __int64 v3; // kr00_8
  _DWORD *v4; // r2
  int v6; // r1
  unsigned int v7; // r3

  v2 = a2 + 1;
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(_DWORD **)(a1 + 12);
  if ( a2 == -1 || v2 > HIDWORD(v3) )
    return 0;
  if ( (_DWORD)v3 == v2 )
    return (int)(v4 + 3);
  if ( (unsigned int)v3 <= v2 )
  {
    v6 = v2 - v3;
    v7 = HIDWORD(v3) - v2 + 1;
    if ( v2 - (unsigned int)v3 > v7 )
    {
      v4 = (_DWORD *)(a1 + 4);
      if ( HIDWORD(v3) - v2 != -1 )
      {
        do
        {
          v4 = (_DWORD *)v4[1];
          --v7;
        }
        while ( v7 );
      }
    }
    else
    {
      for ( ; v6; --v6 )
        v4 = (_DWORD *)*v4;
    }
    *(_DWORD *)(a1 + 12) = v4;
    *(_DWORD *)(a1 + 16) = v2;
    return (int)(v4 + 3);
  }
  return sub_52153C(a1);
}
