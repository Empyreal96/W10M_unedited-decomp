// PopGetIoLocation 
 
_DWORD *__fastcall PopGetIoLocation(_DWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  unsigned int v4; // lr
  unsigned __int64 v6; // r6
  unsigned int v7; // r2
  _QWORD *v8; // r0
  unsigned int v9; // r5
  unsigned int v10; // lr
  unsigned int v11; // r3
  unsigned int v12; // r4
  unsigned __int64 v13; // kr10_8
  unsigned int v14; // r3
  __int64 v15; // kr20_8
  unsigned int *v16; // r1
  unsigned int v17; // r3
  unsigned int v18; // r2
  bool v19; // cf
  unsigned int v20; // r3

  v4 = a2[3];
  v6 = a3;
  LODWORD(a3) = a2[2];
  *a4 = 0;
  a4[1] = 0;
  *a1 = 0;
  a1[1] = 0;
  if ( HIDWORD(a3) < v4 )
    goto LABEL_6;
  if ( (HIDWORD(a3) > v4 || (unsigned int)v6 >= v7) && v6 < *(_QWORD *)a2[1] + __PAIR64__(v4, v7) )
    goto LABEL_12;
  if ( v6 < __PAIR64__(v4, v7) )
  {
LABEL_6:
    a2[1] = *a2;
    a2[2] = 0;
    a2[3] = 0;
  }
  v9 = a2[2];
  v8 = (_QWORD *)a2[1];
  v10 = a2[3];
  v11 = (*v8 + __PAIR64__(v10, v9)) >> 32;
  v12 = *(_DWORD *)v8 + v9;
  if ( HIDWORD(v6) >= v11 )
  {
    if ( HIDWORD(v6) <= v11 )
      goto LABEL_11;
    do
    {
      do
      {
        v13 = *v8 + __PAIR64__(v10, v9);
        v8 += 2;
        a2[1] = v8;
        *((_QWORD *)a2 + 1) = v13;
        v10 = HIDWORD(v13);
        v9 = v13;
        v14 = (*v8 + v13) >> 32;
        v12 = *(_DWORD *)v8 + v13;
      }
      while ( HIDWORD(v6) > v14 );
      if ( HIDWORD(v6) < v14 )
        break;
LABEL_11:
      ;
    }
    while ( (unsigned int)v6 >= v12 );
  }
LABEL_12:
  v15 = *((_QWORD *)a2 + 1);
  v16 = (unsigned int *)a2[1];
  v17 = v16[2];
  v18 = v16[3];
  v19 = __CFADD__(v17, v6 - v15);
  *a1 = v17 + v6 - v15;
  v20 = *v16;
  a1[1] = ((v6 - v15) >> 32) + v19 + v18;
  *(_QWORD *)a4 = __PAIR64__(v16[1], v20) - (v6 - v15);
  return a1;
}
