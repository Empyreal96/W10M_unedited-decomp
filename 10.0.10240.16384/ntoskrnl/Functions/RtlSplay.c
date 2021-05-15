// RtlSplay 
 
int __fastcall RtlSplay(__int64 a1)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r3
  _DWORD *v3; // r3
  int v4; // r4
  _DWORD *v5; // r3
  _DWORD *v6; // r3
  _DWORD *v7; // r3
  int v8; // r4
  _DWORD *v9; // r3
  _DWORD *v10; // r3
  _DWORD *v11; // r3
  _DWORD *v12; // r3
  _DWORD *v13; // r3
  _DWORD *v14; // r3
  int v15; // r4
  _DWORD *v16; // r3
  int v17; // r4

  while ( *(_DWORD *)a1 != (_DWORD)a1 )
  {
    v1 = *(_DWORD **)a1;
    HIDWORD(a1) = **(_DWORD **)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 4) == (_DWORD)a1 )
    {
      if ( (_DWORD *)HIDWORD(a1) == v1 )
      {
        v9 = *(_DWORD **)(a1 + 8);
        v1[1] = v9;
        if ( v9 )
          *v9 = v1;
        *(_DWORD *)(a1 + 8) = v1;
        *v1 = a1;
        *(_DWORD *)a1 = a1;
      }
      else if ( *(_DWORD **)(HIDWORD(a1) + 4) == v1 )
      {
        v2 = *(_DWORD **)(a1 + 8);
        v1[1] = v2;
        if ( v2 )
          *v2 = v1;
        v3 = (_DWORD *)v1[2];
        *(_DWORD *)(HIDWORD(a1) + 4) = v3;
        if ( v3 )
          *v3 = HIDWORD(a1);
        if ( *(_DWORD *)HIDWORD(a1) == HIDWORD(a1) )
        {
          *(_DWORD *)a1 = a1;
          *(_DWORD *)(a1 + 8) = v1;
          *v1 = a1;
          v1[2] = HIDWORD(a1);
          *(_DWORD *)HIDWORD(a1) = v1;
        }
        else
        {
          *(_DWORD *)a1 = *(_DWORD *)HIDWORD(a1);
          v4 = *(_DWORD *)HIDWORD(a1);
          if ( *(_DWORD *)(*(_DWORD *)HIDWORD(a1) + 4) == HIDWORD(a1) )
            v5 = (_DWORD *)(v4 + 4);
          else
            v5 = (_DWORD *)(v4 + 8);
          *v5 = a1;
          *(_DWORD *)(a1 + 8) = v1;
          *v1 = a1;
          v1[2] = HIDWORD(a1);
          *(_DWORD *)HIDWORD(a1) = v1;
        }
      }
      else
      {
        v10 = *(_DWORD **)(a1 + 4);
        *(_DWORD *)(HIDWORD(a1) + 8) = v10;
        if ( v10 )
          *v10 = HIDWORD(a1);
        v11 = *(_DWORD **)(a1 + 8);
        v1[1] = v11;
        if ( v11 )
          *v11 = v1;
        if ( *(_DWORD *)HIDWORD(a1) == HIDWORD(a1) )
        {
          *(_DWORD *)a1 = a1;
        }
        else
        {
          *(_DWORD *)a1 = *(_DWORD *)HIDWORD(a1);
          v17 = *(_DWORD *)HIDWORD(a1);
          if ( *(_DWORD *)(*(_DWORD *)HIDWORD(a1) + 4) == HIDWORD(a1) )
            *(_DWORD *)(v17 + 4) = a1;
          else
            *(_DWORD *)(v17 + 8) = a1;
        }
        *(_DWORD *)(a1 + 4) = HIDWORD(a1);
        *(_DWORD *)HIDWORD(a1) = a1;
        *(_DWORD *)(a1 + 8) = v1;
        *v1 = a1;
      }
    }
    else if ( (_DWORD *)HIDWORD(a1) == v1 )
    {
      v12 = *(_DWORD **)(a1 + 4);
      v1[2] = v12;
      if ( v12 )
        *v12 = v1;
      *(_DWORD *)(a1 + 4) = v1;
      *v1 = a1;
      *(_DWORD *)a1 = a1;
    }
    else if ( *(_DWORD **)(HIDWORD(a1) + 8) == v1 )
    {
      v6 = (_DWORD *)v1[1];
      *(_DWORD *)(HIDWORD(a1) + 8) = v6;
      if ( v6 )
        *v6 = HIDWORD(a1);
      v7 = *(_DWORD **)(a1 + 4);
      v1[2] = v7;
      if ( v7 )
        *v7 = v1;
      if ( *(_DWORD *)HIDWORD(a1) == HIDWORD(a1) )
      {
        *(_DWORD *)a1 = a1;
        *(_DWORD *)(a1 + 4) = v1;
        *(_QWORD *)v1 = a1;
        *(_DWORD *)HIDWORD(a1) = v1;
      }
      else
      {
        *(_DWORD *)a1 = *(_DWORD *)HIDWORD(a1);
        v8 = *(_DWORD *)HIDWORD(a1);
        if ( *(_DWORD *)(*(_DWORD *)HIDWORD(a1) + 4) == HIDWORD(a1) )
          *(_DWORD *)(v8 + 4) = a1;
        else
          *(_DWORD *)(v8 + 8) = a1;
        *(_DWORD *)(a1 + 4) = v1;
        *(_QWORD *)v1 = a1;
        *(_DWORD *)HIDWORD(a1) = v1;
      }
    }
    else
    {
      v13 = *(_DWORD **)(a1 + 4);
      v1[2] = v13;
      if ( v13 )
        *v13 = v1;
      v14 = *(_DWORD **)(a1 + 8);
      *(_DWORD *)(HIDWORD(a1) + 4) = v14;
      if ( v14 )
        *v14 = HIDWORD(a1);
      if ( *(_DWORD *)HIDWORD(a1) == HIDWORD(a1) )
      {
        *(_DWORD *)a1 = a1;
        *(_DWORD *)(a1 + 4) = v1;
        *v1 = a1;
        *(_DWORD *)(a1 + 8) = HIDWORD(a1);
        *(_DWORD *)HIDWORD(a1) = a1;
      }
      else
      {
        *(_DWORD *)a1 = *(_DWORD *)HIDWORD(a1);
        v15 = *(_DWORD *)HIDWORD(a1);
        if ( *(_DWORD *)(*(_DWORD *)HIDWORD(a1) + 4) == HIDWORD(a1) )
          v16 = (_DWORD *)(v15 + 4);
        else
          v16 = (_DWORD *)(v15 + 8);
        *v16 = a1;
        *(_DWORD *)(a1 + 4) = v1;
        *v1 = a1;
        *(_DWORD *)(a1 + 8) = HIDWORD(a1);
        *(_DWORD *)HIDWORD(a1) = a1;
      }
    }
  }
  return a1;
}
