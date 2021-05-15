// IopAddRemoveReqDescs 
 
int __fastcall IopAddRemoveReqDescs(__int64 a1, _DWORD *a2, int a3)
{
  _DWORD **v3; // r9
  unsigned int v4; // r8
  int *v5; // r10
  unsigned int i; // r7
  int v7; // r5
  int v8; // t1
  int v9; // r4

  v3 = (_DWORD **)a2;
  v4 = HIDWORD(a1);
  v5 = (int *)a1;
  if ( HIDWORD(a1) )
  {
    for ( i = 0; i < v4; ++i )
    {
      v8 = *v5++;
      v7 = v8;
      if ( *(_BYTE *)(v8 + 8) )
      {
        v9 = *(_DWORD *)(v7 + 176);
        if ( (*(_BYTE *)(v9 + 52) & 1) != 0 )
        {
          LODWORD(a1) = sub_80E0E0(a1, HIDWORD(a1), a2, 1);
          return a1;
        }
        *(_BYTE *)(v9 + 53) = 1;
        a2 = (_DWORD *)(*(_DWORD *)(v7 + 20) + 24);
        if ( a3 )
        {
          *a2 = a2;
          a2[1] = a2;
          LODWORD(a1) = *(_DWORD *)(v9 + 24);
          *a2 = v9 + 20;
          a2[1] = a1;
          if ( *(_DWORD *)a1 != v9 + 20 )
            __fastfail(3u);
          *(_DWORD *)a1 = a2;
          *(_DWORD *)(v9 + 24) = a2;
          HIDWORD(a1) = v9 + 44;
          if ( *(_DWORD *)(v9 + 44) == v9 + 44 )
          {
            a2 = *v3;
            if ( *v3 != v3 )
            {
              LODWORD(a1) = *(_DWORD *)(*(_DWORD *)(v9 + 16) + 76);
              do
              {
                if ( *(_DWORD *)(*(a2 - 7) + 76) >= (unsigned int)a1 )
                  break;
                a2 = (_DWORD *)*a2;
              }
              while ( a2 != v3 );
            }
            *(_DWORD *)(v9 + 44) = a2;
            *(_DWORD *)(v9 + 48) = a2[1];
            *(_DWORD *)a2[1] = HIDWORD(a1);
            a2[1] = HIDWORD(a1);
          }
        }
        else
        {
          a1 = *(_QWORD *)a2;
          if ( *(_DWORD **)(*a2 + 4) != a2 || *(_DWORD **)HIDWORD(a1) != a2 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(a1) = a1;
          *(_DWORD *)(a1 + 4) = HIDWORD(a1);
          *a2 = a2;
          a2[1] = a2;
          a2 = (_DWORD *)(v9 + 20);
          if ( *(_DWORD *)(v9 + 20) == v9 + 20 )
          {
            a2 = (_DWORD *)(v9 + 44);
            a1 = *(_QWORD *)(v9 + 44);
            if ( *(_DWORD *)(a1 + 4) != v9 + 44 || *(_DWORD **)HIDWORD(a1) != a2 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(a1) = a1;
            *(_DWORD *)(a1 + 4) = HIDWORD(a1);
            *a2 = a2;
            *(_DWORD *)(v9 + 48) = v9 + 44;
          }
        }
      }
    }
  }
  return a1;
}
