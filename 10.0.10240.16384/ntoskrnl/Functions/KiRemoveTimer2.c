// KiRemoveTimer2 
 
__int64 *__fastcall KiRemoveTimer2(int a1)
{
  int v1; // r4
  int v2; // r9
  __int64 *result; // r0
  int v5; // r2
  unsigned __int64 v6; // kr00_8
  __int64 v7; // kr08_8
  unsigned __int64 v8; // kr10_8
  int v9; // r4
  unsigned __int64 v10; // r2
  unsigned int v11; // r5
  unsigned int v12; // r6
  unsigned __int64 v13; // kr40_8
  unsigned __int64 *v14; // lr
  unsigned __int64 v15; // kr48_8
  unsigned int v16; // r0
  unsigned int v17; // r6
  unsigned __int64 v18; // kr50_8
  unsigned int v19; // r1
  unsigned int v20; // r8
  unsigned __int64 v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r7
  unsigned __int64 v24; // r2

  v1 = 0;
  v2 = -1;
  do
  {
    if ( ((1 << v1) & *(unsigned __int8 *)(a1 + 81)) != 0 )
    {
      if ( v1 != 3 )
        __asm { ADD             PC, R3 }
      RtlRbRemoveNode(&KiTimer2Collections[6], a1 + 16);
      if ( *(_QWORD *)(a1 + 40) == KiTimer2Collections[7] )
      {
        v5 = HIDWORD(KiTimer2Collections[2 * v1]);
        if ( v5 )
        {
          v6 = *(_QWORD *)(v5 + 24);
          v7 = KiTimer2Collections[7];
          do
            v8 = __ldrexd(&KiTimer2Collections[7]);
          while ( v8 == v7 && __strexd(v6, &KiTimer2Collections[7]) );
          if ( v8 != v7 )
            return (__int64 *)sub_530E5C();
          v2 = -1;
        }
        else
        {
          v14 = &KiTimer2Collections[2 * v1 + 1];
          v15 = *v14;
          do
          {
            v18 = __ldrexd(v14);
            v16 = HIDWORD(v18);
            v17 = v18;
          }
          while ( v18 == v15 && __strexd(0xFFFFFFFFFFFFFFFFui64, v14) );
          if ( v18 != v15 )
          {
            do
            {
              v19 = v17;
              v20 = v16;
              do
                v21 = __ldrexd(v14);
              while ( v21 == __PAIR64__(v16, v17) && __strexd(0xFFFFFFFFFFFFFFFFui64, v14) );
              v16 = HIDWORD(v21);
              v17 = v21;
            }
            while ( v21 != __PAIR64__(v20, v19) );
          }
        }
      }
    }
    ++v1;
  }
  while ( v1 < 5 );
  result = &KiNextTimer2DueTime;
  if ( KiNextTimer2DueTime == *(_QWORD *)(a1 + 40) )
  {
    v9 = -1;
    if ( HIDWORD(KiTimer2Collections[1]) != -1 || LODWORD(KiTimer2Collections[1]) != -1 )
    {
      v9 = HIDWORD(KiTimer2Collections[1]);
      v2 = KiTimer2Collections[1];
    }
    if ( KiTimer2Collections[3] < __PAIR64__(v9, v2) )
    {
      v9 = HIDWORD(KiTimer2Collections[3]);
      v2 = KiTimer2Collections[3];
    }
    if ( KiTimer2Collections[5] < __PAIR64__(v9, v2) )
    {
      v9 = HIDWORD(KiTimer2Collections[5]);
      v2 = KiTimer2Collections[5];
    }
    if ( KiTimer2Collections[7] < __PAIR64__(v9, v2) )
    {
      v9 = HIDWORD(KiTimer2Collections[7]);
      v2 = KiTimer2Collections[7];
    }
    v10 = __PAIR64__(KiNextTimer2DueTime, HIDWORD(KiNextTimer2DueTime));
    do
    {
      v13 = __ldrexd((unsigned __int64 *)&KiNextTimer2DueTime);
      v11 = HIDWORD(v13);
      v12 = v13;
    }
    while ( __PAIR64__(v13, HIDWORD(v13)) == v10
         && __strexd(__PAIR64__(v9, v2), (unsigned __int64 *)&KiNextTimer2DueTime) );
    if ( __PAIR64__(v13, HIDWORD(v13)) != v10 )
    {
      do
      {
        v22 = v12;
        v23 = v11;
        do
          v24 = __ldrexd((unsigned __int64 *)&KiNextTimer2DueTime);
        while ( v24 == __PAIR64__(v11, v12) && __strexd(__PAIR64__(v9, v2), (unsigned __int64 *)&KiNextTimer2DueTime) );
        v11 = HIDWORD(v24);
        v12 = v24;
      }
      while ( v24 != __PAIR64__(v23, v22) );
    }
  }
  return result;
}
