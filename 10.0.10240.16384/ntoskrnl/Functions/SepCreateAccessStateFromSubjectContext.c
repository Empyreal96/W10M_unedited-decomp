// SepCreateAccessStateFromSubjectContext 
 
int __fastcall SepCreateAccessStateFromSubjectContext(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r8
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // lr
  unsigned __int64 v16; // r0
  unsigned int v17; // r2
  unsigned int v18; // r8
  unsigned __int64 v19; // kr08_8
  int v20; // r1
  int v21; // r2
  int v22; // r3
  unsigned __int64 v24; // r0
  unsigned __int64 v25; // kr10_8
  int v26[8]; // [sp+0h] [bp-20h] BYREF

  v5 = a4;
  v26[0] = a4;
  if ( (a4 & 0xF0000000) != 0 && a5 )
  {
    RtlMapGenericMask(v26, a5);
    v5 = v26[0];
  }
  memset((_BYTE *)a2, 0, 116);
  memset((_BYTE *)a3, 0, 196);
  *(_DWORD *)(a2 + 48) = a3;
  v9 = a1[1];
  v10 = a1[2];
  v11 = a1[3];
  *(_DWORD *)(a2 + 28) = *a1;
  *(_DWORD *)(a2 + 32) = v9;
  *(_DWORD *)(a2 + 36) = v10;
  *(_DWORD *)(a2 + 40) = v11;
  v12 = *(_DWORD *)(a2 + 28);
  if ( v12 )
    v13 = *(_DWORD *)(a2 + 28);
  else
    v13 = *(_DWORD *)(a2 + 36);
  if ( (*(_DWORD *)(v13 + 72) & 0x800000) != 0 )
    *(_DWORD *)(a2 + 12) = 1;
  if ( !v12 )
    v12 = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a2 + 12) |= *(_DWORD *)(v12 + 176) & 0x810;
  *(_DWORD *)(a2 + 16) = v5;
  *(_DWORD *)(a2 + 24) = v5;
  *(_DWORD *)a3 = a2 + 52;
  v14 = unk_616394;
  v15 = ExpLuid;
  v16 = *(_QWORD *)&ExpLuidIncrement + ExpLuid;
  __dmb(0xBu);
  do
  {
    v19 = __ldrexd(&ExpLuid);
    v18 = HIDWORD(v19);
    v17 = v19;
  }
  while ( v19 == __PAIR64__(v14, v15) && __strexd(v16, &ExpLuid) );
  __dmb(0xBu);
  if ( __PAIR64__(v14, v15) != v19 )
  {
    do
    {
      v15 = v17;
      v14 = v18;
      v24 = __PAIR64__(v18, v17) + 1;
      __dmb(0xBu);
      do
      {
        v25 = __ldrexd(&ExpLuid);
        v18 = HIDWORD(v25);
        v17 = v25;
      }
      while ( v25 == __PAIR64__(v14, v15) && __strexd(v24, &ExpLuid) );
      __dmb(0xBu);
    }
    while ( __PAIR64__(v14, v15) != v25 );
  }
  *(_DWORD *)a2 = v15;
  *(_DWORD *)(a2 + 4) = v14;
  if ( a5 )
  {
    v20 = a5[1];
    v21 = a5[2];
    v22 = a5[3];
    *(_DWORD *)(a3 + 4) = *a5;
    *(_DWORD *)(a3 + 8) = v20;
    *(_DWORD *)(a3 + 12) = v21;
    *(_DWORD *)(a3 + 16) = v22;
  }
  return 0;
}
