// KiInsertTimer2WithCollectionLockHeld 
 
int __fastcall KiInsertTimer2WithCollectionLockHeld(int a1, int a2, _BYTE *a3)
{
  int v3; // r8
  int i; // r5
  unsigned __int64 v6; // r4
  int **v8; // r7
  int *v9; // r1
  int v10; // r2
  int *v11; // r3
  unsigned __int64 v12; // kr08_8
  char *v13; // lr
  unsigned int v14; // r1
  unsigned int v15; // r2
  unsigned __int64 v16; // r6
  unsigned __int64 v17; // kr18_8
  unsigned __int64 v18; // r2
  unsigned __int64 v19; // r6
  unsigned __int64 v20; // kr28_8
  unsigned int v21; // r1
  unsigned int v22; // r8
  unsigned __int64 v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // lr
  unsigned __int64 v26; // r2

  *a3 = 0;
  v3 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( ((1 << i) & *(unsigned __int8 *)(a1 + 81)) != 0 )
    {
      v8 = (int **)&KiTimer2Collections[2 * i];
      if ( i != 3 )
        __asm { ADD             PC, R3 }
      v9 = *v8;
      v10 = 0;
      if ( *v8 )
      {
        while ( 1 )
        {
          if ( *(_QWORD *)(a1 + 40) >= *((_QWORD *)v9 + 3) )
          {
            v11 = (int *)v9[1];
            if ( !v11 )
            {
              v10 = 1;
              break;
            }
          }
          else
          {
            v11 = (int *)*v9;
            if ( !*v9 )
            {
              v10 = 0;
              break;
            }
          }
          v9 = v11;
        }
      }
      RtlRbInsertNodeEx(&KiTimer2Collections[6], v9, v10, a1 + 16);
      v12 = *(_QWORD *)(a1 + 40);
      if ( v12 < KiTimer2Collections[2 * i + 1] )
      {
        v13 = (char *)&KiTimer2Collections[2 * i + 1];
        v14 = *((_DWORD *)v13 + 1);
        v15 = *(_DWORD *)v13;
        do
        {
          v17 = __ldrexd((unsigned __int64 *)v13);
          v16 = __PAIR64__(v17, HIDWORD(v17));
        }
        while ( __PAIR64__(v17, HIDWORD(v17)) == __PAIR64__(v15, v14) && __strexd(v12, (unsigned __int64 *)v13) );
        if ( __PAIR64__(v17, HIDWORD(v17)) != __PAIR64__(v15, v14) )
        {
          do
          {
            v21 = HIDWORD(v16);
            v22 = v16;
            do
              v23 = __ldrexd((unsigned __int64 *)v13);
            while ( __PAIR64__(v23, HIDWORD(v23)) == v16 && __strexd(v12, (unsigned __int64 *)v13) );
            v16 = __PAIR64__(v23, HIDWORD(v23));
          }
          while ( v23 != __PAIR64__(v22, v21) );
        }
        v3 = 1;
      }
    }
  }
  v6 = *(_QWORD *)(a1 + 40);
  if ( v6 < KiNextTimer2DueTime )
  {
    v18 = __PAIR64__(KiNextTimer2DueTime, HIDWORD(KiNextTimer2DueTime));
    do
    {
      v20 = __ldrexd((unsigned __int64 *)&KiNextTimer2DueTime);
      v19 = __PAIR64__(v20, HIDWORD(v20));
    }
    while ( __PAIR64__(v20, HIDWORD(v20)) == v18 && __strexd(v6, (unsigned __int64 *)&KiNextTimer2DueTime) );
    if ( __PAIR64__(v20, HIDWORD(v20)) != v18 )
    {
      do
      {
        v24 = HIDWORD(v19);
        v25 = v19;
        do
          v26 = __ldrexd((unsigned __int64 *)&KiNextTimer2DueTime);
        while ( __PAIR64__(v26, HIDWORD(v26)) == v19 && __strexd(v6, (unsigned __int64 *)&KiNextTimer2DueTime) );
        v19 = __PAIR64__(v26, HIDWORD(v26));
      }
      while ( v26 != __PAIR64__(v25, v24) );
    }
  }
  if ( !v3 )
    return 1;
  __dmb(0xFu);
  if ( *(_QWORD *)(a1 + 40) > (unsigned __int64)KeQueryInterruptTime(&KiNextTimer2DueTime) )
    return 1;
  *a3 = 1;
  if ( a2 )
    return 1;
  KiRemoveTimer2(a1);
  return 0;
}
