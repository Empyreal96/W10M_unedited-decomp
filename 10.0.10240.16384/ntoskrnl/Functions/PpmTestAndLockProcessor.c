// PpmTestAndLockProcessor 
 
int __fastcall PpmTestAndLockProcessor(_DWORD *a1, int a2, unsigned int *a3)
{
  int v5; // r4
  int *v6; // r8
  unsigned int v7; // r7
  unsigned int v8; // r5
  _BYTE *v9; // r0
  int result; // r0
  unsigned int v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r4
  unsigned int *v18; // r7
  unsigned int v19; // r1
  int v20; // r2
  unsigned int v21; // r4
  int v23[8]; // [sp+8h] [bp-40h] BYREF

  v5 = (int)a1;
  v6 = a1 + 736;
  v7 = a1[750];
  v8 = 0;
  v9 = memset(v23, 0, sizeof(v23));
  v23[4] = v5;
  LOBYTE(v23[6]) = 1;
  v23[2] = PopIdleTransitionTimeout;
  v23[3] = MEMORY[0x6824EC];
  if ( (v7 & 0xFF000000) == 0x2000000 )
    return sub_522F24(v9);
  v11 = HIBYTE(v7);
  result = -1073741782;
  if ( HIBYTE(v7) == 4 || v11 == 3 || v11 == 5 )
  {
    if ( a3 )
    {
      v12 = *a3;
      v13 = 0;
      if ( *a3 )
      {
        v14 = a3[1];
        do
        {
          v8 = v14;
          if ( *(_DWORD *)(v14 + 4) == v6[11] )
            break;
          ++v13;
          v14 += 16;
        }
        while ( v13 < v12 );
      }
      if ( v13 == v12 || !*(_BYTE *)(v8 + 2) )
        return result;
      if ( !*(_BYTE *)v8 )
        return 0;
    }
    if ( ((*(_DWORD *)(a2 + 8) >> a1[5]) & 1) != 0 )
      return 0;
    v15 = *v6;
    v16 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    __dmb(0xBu);
    v17 = 1 << v16;
    v18 = (unsigned int *)(v15 + 64);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | v17, v18) );
    __dmb(0xBu);
    result = PpmIdleLockProcessor(v6 + 14);
    if ( result < 0 )
    {
      __dmb(0xBu);
      v20 = ~v17;
      do
        v21 = __ldrex(v18);
      while ( __strex(v21 & v20, v18) );
      __dmb(0xBu);
    }
    else
    {
      *(_DWORD *)(a2 + 8) |= 1 << a1[5];
      if ( !a3 || *(_DWORD *)(v8 + 4) == v6[11] )
        return 0;
    }
  }
  return result;
}
