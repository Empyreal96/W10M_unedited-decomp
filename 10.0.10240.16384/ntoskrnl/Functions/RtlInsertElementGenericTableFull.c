// RtlInsertElementGenericTableFull 
 
_DWORD *__fastcall RtlInsertElementGenericTableFull(int a1, int a2, unsigned int a3, bool *a4, _DWORD *a5, int a6)
{
  _DWORD *v10; // r4
  int v12; // r0
  _QWORD *v13; // r2
  __int64 v14; // r0

  if ( a6 == 1 )
  {
    v10 = a5;
LABEL_3:
    *(_DWORD *)a1 = RtlSplay(v10);
    if ( a4 )
      *a4 = a6 != 1;
    return v10 + 6;
  }
  if ( a3 + 24 >= a3 )
  {
    v12 = (*(int (__fastcall **)(int))(a1 + 28))(a1);
    v10 = (_DWORD *)v12;
    if ( v12 )
    {
      v13 = (_QWORD *)(v12 + 12);
      LODWORD(v14) = a1 + 4;
      v10[1] = 0;
      v10[2] = 0;
      *v10 = v10;
      HIDWORD(v14) = *(_DWORD *)(a1 + 8);
      *v13 = v14;
      if ( *(_DWORD *)HIDWORD(v14) != a1 + 4 )
        sub_51E330();
      *(_DWORD *)HIDWORD(v14) = v13;
      *(_DWORD *)(a1 + 8) = v13;
      ++*(_DWORD *)(a1 + 20);
      if ( a6 )
      {
        if ( a6 == 2 )
          a5[1] = v10;
        else
          a5[2] = v10;
        *v10 = a5;
      }
      else
      {
        *(_DWORD *)a1 = v10;
      }
      memmove((int)(v10 + 6), a2, a3);
      goto LABEL_3;
    }
  }
  if ( a4 )
    *a4 = 0;
  return 0;
}
