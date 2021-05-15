// CcAdjustVacbLevelLockCount 
 
int __fastcall CcAdjustVacbLevelLockCount(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  int v6; // r6
  unsigned int v7; // lr
  unsigned int v9; // r3
  int v10; // r7
  int v12; // r5
  __int64 v13; // r0
  int v14; // r5
  unsigned __int64 v15; // kr00_8
  int v16; // r3
  int result; // r0
  __int64 v18; // kr08_8
  int v19; // r0

  v6 = a1[16];
  v7 = a1[6];
  v9 = a1[7];
  v10 = 0;
  v12 = 25;
  do
  {
    v12 += 7;
    ++v10;
    LODWORD(v13) = 1 << v12;
    HIDWORD(v13) = 1 << (v12 - 32);
  }
  while ( __SPAIR64__(v9, v7) > v13 );
  v14 = v12 - 7;
  do
  {
    --v10;
    v15 = __PAIR64__(1 << (v14 - 32), 1 << v14) - 1;
    v6 = *(_DWORD *)(v6 + 4 * (__SPAIR64__(a4, a3) >> v14));
    v14 -= 7;
    a4 &= HIDWORD(v15);
    a3 &= v15;
  }
  while ( v10 );
  ReferenceVacbLevel(a1, v6, 0, a5, 0);
  v16 = 512;
  if ( (a1[24] & 0x200) == 0 )
    v16 = 0;
  v18 = *(_QWORD *)(v16 + v6 + 512);
  result = HIDWORD(v18);
  if ( !v18 )
  {
    v19 = ReferenceVacbLevel(a1, v6, 0, 1, 1);
    result = CcSetVacbLargeOffset(v19);
  }
  return result;
}
