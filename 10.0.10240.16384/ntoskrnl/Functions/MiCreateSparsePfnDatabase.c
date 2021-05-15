// MiCreateSparsePfnDatabase 
 
int __fastcall MiCreateSparsePfnDatabase(int a1)
{
  int *v1; // r4
  int *v2; // r8
  int v3; // r5
  __int64 v4; // r6
  int v5; // r1
  int v7; // r1
  int v8; // r2
  int v9; // r3

  v1 = *(int **)(a1 + 24);
  v2 = (int *)(a1 + 24);
  v3 = 3;
  v4 = 0xFFFFFFFFi64;
  if ( v1 == (int *)(a1 + 24) )
    goto LABEL_21;
  do
  {
    v5 = v1[2];
    if ( v5 == 6 || v5 == 32 || v5 == 31 || v5 == 30 || v5 == 23 || v5 == 3 || v5 == 22 )
    {
      if ( (_DWORD)v4 == -1 )
        goto LABEL_18;
    }
    else
    {
      if ( (_DWORD)v4 == -1 )
      {
        v4 = *(_QWORD *)(v1 + 3);
        v3 = v1[2];
        goto LABEL_18;
      }
      if ( HIDWORD(v4) + (_DWORD)v4 == v1[3] )
      {
        if ( (v3 == 2 || v3 == 24) && (v5 == 2 || v5 == 24) )
        {
LABEL_17:
          HIDWORD(v4) += v1[4];
          goto LABEL_18;
        }
        if ( v3 == 2 )
        {
LABEL_37:
          v8 = 0;
          goto LABEL_28;
        }
        if ( v5 != 2 && v3 != 24 && v5 != 24 )
          goto LABEL_17;
      }
    }
    if ( v3 == 2 || v3 == 24 )
      goto LABEL_37;
    v8 = 1;
LABEL_28:
    if ( !MxMapPfnRange(v4, HIDWORD(v4), v8) )
      return 0;
    v9 = v1[2];
    if ( v9 == 31 || v9 == 6 || v9 == 32 || v9 == 30 || v9 == 23 || v9 == 3 || v9 == 22 )
    {
      LODWORD(v4) = -1;
    }
    else
    {
      v4 = *(_QWORD *)(v1 + 3);
      v3 = v1[2];
    }
LABEL_18:
    v1 = (int *)*v1;
  }
  while ( v1 != v2 );
  if ( (_DWORD)v4 != -1 )
    return sub_96B5D0();
LABEL_21:
  v7 = dword_633850;
  if ( dword_634690 == dword_633850 + 1 )
  {
LABEL_22:
    if ( MxMapPfnRange(v7 + 1, -1, 1) )
      return 1;
  }
  else if ( MxMapPfnRange(dword_634690, 2048, 1) )
  {
    v7 = dword_633850;
    goto LABEL_22;
  }
  return 0;
}
