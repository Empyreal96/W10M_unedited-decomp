// MiCombineCompare 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiCombineCompare(int a1, _DWORD *a2)
{
  unsigned int v2; // r3 OVERLAPPED
  unsigned int v3; // r4 OVERLAPPED
  unsigned int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r0
  unsigned int v8; // r3

  *(_QWORD *)&v2 = *(_QWORD *)(a1 + 16);
  v4 = a2[5];
  v5 = *(_DWORD *)(a1 + 28);
  v6 = a2[4];
  if ( v3 < v4 )
    return -1;
  if ( v3 > v4 || v2 > v6 )
    return 1;
  if ( __PAIR64__(v3, v2) < __PAIR64__(v4, v6) )
    return -1;
  v8 = a2[7];
  if ( v5 > v8 )
    return 1;
  if ( v5 < v8 )
    return -1;
  return 0;
}
