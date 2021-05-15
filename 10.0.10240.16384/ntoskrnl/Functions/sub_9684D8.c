// sub_9684D8 
 
void __fastcall sub_9684D8(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  _DWORD *v3; // r6
  __int64 v4; // kr00_8
  _DWORD *i; // r2
  _DWORD *v6; // r0

  v4 = *(_QWORD *)a2;
  if ( *(_DWORD **)(*a2 + 4) == a2 && *(_DWORD **)HIDWORD(v4) == a2 )
  {
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
    for ( i = (_DWORD *)*v3; i != v2; i = (_DWORD *)*i )
    {
      if ( i[15] >= a2[15] )
        break;
    }
    v6 = (_DWORD *)i[1];
    *a2 = i;
    a2[1] = v6;
    if ( (_DWORD *)*v6 == i )
    {
      *v6 = a2;
      i[1] = a2;
      JUMPOUT(0x94F74A);
    }
    __fastfail(3u);
  }
  __fastfail(3u);
}
