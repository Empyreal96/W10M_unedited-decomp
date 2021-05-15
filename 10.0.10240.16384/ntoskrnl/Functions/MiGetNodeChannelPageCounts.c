// MiGetNodeChannelPageCounts 
 
int __fastcall MiGetNodeChannelPageCounts(int a1, int a2, _DWORD *a3, int *a4, _DWORD *a5)
{
  int v7; // r4
  unsigned int v8; // r5
  __int64 v9; // r0
  __int64 v10; // r2
  int v11; // r2
  int v12; // r3

  v7 = dword_63F718 + 104 * a1;
  if ( a2 == 1 )
    v8 = *(_DWORD *)(v7 + 68);
  else
    v8 = *(_DWORD *)(v7 + 4 * a2 + 64);
  v9 = *(_QWORD *)v7;
  v10 = *(_QWORD *)(v7 + 56);
  v11 = v10 + (*(_DWORD *)v7 << 10);
  v12 = HIDWORD(v10) + (*(_DWORD *)(v7 + 4) << 10);
  while ( v12 + v11 > v8 )
    ;
  *a4 = v12;
  *a3 = v11;
  *a5 = -1;
  return v9;
}
