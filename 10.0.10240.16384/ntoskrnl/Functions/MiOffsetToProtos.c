// MiOffsetToProtos 
 
unsigned int *__fastcall MiOffsetToProtos(_DWORD *a1, unsigned __int64 a2, int a3)
{
  int v4; // r8
  int v5; // r9
  unsigned __int64 v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r6
  int v10; // r0
  _DWORD *v11; // r4
  unsigned int v13; // r3

  *(_QWORD *)a3 = a2 >> 12;
  v4 = HIDWORD(a2);
  v5 = a2;
  LODWORD(v7) = MiGetControlAreaPtes();
  v8 = *(_DWORD *)(a3 + 4);
  v9 = *(_DWORD *)a3;
  if ( *(_QWORD *)a3 >= v7 )
    return 0;
  if ( !a1[8] )
    return MiLocatePagefileSubsection(a1 + 20, a3);
  if ( (a1[7] & 0x20) != 0 )
  {
    v11 = a1 + 20;
    v13 = a1[27];
    if ( __PAIR64__(v8, v9) >= v13 )
    {
      do
      {
        do
        {
          v8 = (__PAIR64__(v8, v9) - v13) >> 32;
          *(_QWORD *)a3 = __PAIR64__(v8, v9 - v13);
          v11 = (_DWORD *)v11[2];
          v9 = *(_DWORD *)a3;
          v13 = v11[7];
        }
        while ( v8 );
      }
      while ( v9 >= v13 );
    }
  }
  else
  {
    v10 = MiLocateSubsectionNode(a1, 0, v5, v4);
    v11 = (_DWORD *)v10;
    *(_QWORD *)a3 -= __PAIR64__(*(unsigned __int16 *)(v10 + 16) >> 6, *(_DWORD *)(v10 + 20));
  }
  return v11;
}
