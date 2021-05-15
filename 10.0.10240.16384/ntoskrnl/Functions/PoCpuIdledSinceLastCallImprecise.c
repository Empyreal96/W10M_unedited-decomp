// PoCpuIdledSinceLastCallImprecise 
 
// local variable allocation has failed, the output may be wrong!
BOOL __fastcall PoCpuIdledSinceLastCallImprecise(int a1, unsigned __int64 *a2)
{
  int v2; // r4
  BOOL v3; // r3
  unsigned int v4; // r5 OVERLAPPED
  unsigned int v5; // r6 OVERLAPPED
  unsigned __int64 *v6; // r3
  unsigned __int64 v7; // kr00_8
  __int64 v8; // r2

  v2 = (int)*(&KiProcessorBlock + a1);
  v3 = 1;
  if ( v2 )
  {
    *(_QWORD *)&v4 = *a2;
    v6 = (unsigned __int64 *)(v2 + 2960);
    do
      v7 = __ldrexd(v6);
    while ( !v7 && __strexd(0i64, v6) );
    *a2 = v7;
    LODWORD(v8) = *(_DWORD *)(v2 + 2972);
    HIDWORD(v8) = *(_DWORD *)(v2 + 2968);
    __dmb(0xBu);
    v3 = v8 || *a2 > __PAIR64__(v5, v4);
  }
  return v3;
}
