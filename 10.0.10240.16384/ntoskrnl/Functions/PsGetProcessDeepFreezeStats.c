// PsGetProcessDeepFreezeStats 
 
int __fastcall PsGetProcessDeepFreezeStats(_DWORD *a1, int a2)
{
  unsigned int v4; // r7
  unsigned int *v5; // r6
  int v6; // r0
  unsigned int v7; // r2
  __int64 v8; // kr00_8
  __int64 v9; // r0
  unsigned int v10; // r2
  int v11; // r0
  __int16 v12; // r3
  __int64 v13; // r0
  unsigned __int64 v14; // kr08_8
  int v15; // r3
  int v16; // r2

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = a1 + 42;
  v6 = KeAbPreAcquire((unsigned int)(a1 + 42), 0, 0);
  do
    v7 = __ldrex(v5);
  while ( !v7 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v7 )
  {
    LODWORD(v13) = sub_7C372C(v6, 17);
  }
  else
  {
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    *(_DWORD *)(a2 + 16) = a1[210];
    *(_DWORD *)(a2 + 20) = a1[211];
    *(_DWORD *)(a2 + 24) = a1[192];
    *(_DWORD *)(a2 + 28) = a1[193];
    do
    {
      v8 = MEMORY[0xFFFF93B0];
      LODWORD(v9) = KeQueryInterruptTime();
      *(_QWORD *)a2 = v9;
    }
    while ( v8 != MEMORY[0xFFFF93B0] );
    __dmb(0xBu);
    do
      v10 = __ldrex(v5);
    while ( v10 == 17 && __strex(0, v5) );
    if ( v10 != 17 )
      ExfReleasePushLockShared(v5);
    v11 = KeAbPostRelease((unsigned int)v5);
    v12 = *(_WORD *)(v4 + 308) + 1;
    *(_WORD *)(v4 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(v11);
    LODWORD(v13) = *(_DWORD *)(a2 + 28);
    HIDWORD(v13) = *(_DWORD *)(a2 + 24);
    *(_QWORD *)(a2 + 8) = *(_QWORD *)a2 - v8;
    if ( v13 )
    {
      v15 = *(_DWORD *)(a2 + 8);
      v14 = *(_QWORD *)(a2 + 16) - __PAIR64__(v13, HIDWORD(v13));
      LODWORD(v13) = HIDWORD(v14);
      HIDWORD(v13) = v14;
      v16 = *(_DWORD *)(a2 + 12);
      *(_DWORD *)(a2 + 16) = v15 + HIDWORD(v13);
      *(_DWORD *)(a2 + 20) = v13 + __CFADD__(v15, HIDWORD(v13)) + v16;
    }
  }
  return v13;
}
