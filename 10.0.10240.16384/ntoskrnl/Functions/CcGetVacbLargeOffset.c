// CcGetVacbLargeOffset 
 
int __fastcall CcGetVacbLargeOffset(int a1, __int64 a2)
{
  int v3; // r10
  __int64 v4; // r6
  int v5; // r5
  int v6; // r4
  unsigned int v7; // r8
  unsigned int v8; // r9
  __int64 v9; // r0
  int v10; // r4
  int i; // r6

  v3 = *(_DWORD *)(a1 + 64);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = 0;
  v6 = 25;
  v7 = HIDWORD(a2);
  v8 = a2;
  do
  {
    v6 += 7;
    ++v5;
    LODWORD(v9) = 1 << v6;
    HIDWORD(v9) = 1 << (v6 - 32);
  }
  while ( v4 > v9 );
  v10 = v6 - 7;
  for ( i = *(_DWORD *)(v3 + 4 * (a2 >> v10)); i && v5; i = *(_DWORD *)(i + 4 * (__SPAIR64__(v7, v8) >> v10)) )
  {
    --v5;
    v7 &= (__PAIR64__(1 << (v10 - 32), 1 << v10) - 1) >> 32;
    v8 &= (1 << v10) - 1;
    v10 -= 7;
  }
  return i;
}
