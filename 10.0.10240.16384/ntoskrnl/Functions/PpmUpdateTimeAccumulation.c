// PpmUpdateTimeAccumulation 
 
int __fastcall PpmUpdateTimeAccumulation(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  int v7; // r8
  unsigned __int64 v8; // r0
  unsigned __int64 v9; // kr00_8
  unsigned __int64 *v10; // r4
  unsigned __int64 v11; // kr08_8
  unsigned __int64 v12; // r4

  v7 = a1 + 3008;
  LODWORD(v8) = ReadTimeStampCounter();
  if ( a5 )
  {
    v9 = __PAIR64__(a4, a3) - *(_QWORD *)(v7 + 32);
    __dmb(0xBu);
    v10 = (unsigned __int64 *)(v7 + 48);
    do
      v11 = __ldrexd(v10);
    while ( __strexd(v11 + v9, v10) );
    __dmb(0xBu);
  }
  *(_DWORD *)(v7 + 32) = a3;
  *(_DWORD *)(v7 + 36) = a4;
  if ( a5 )
  {
    v12 = *(_QWORD *)(v7 + 8);
    if ( v8 > v12 )
      *(_QWORD *)(v7 + 16) = *(_QWORD *)(v7 + 16) - v12 + v8;
  }
  *(_QWORD *)(v7 + 8) = v8;
  return v8;
}
