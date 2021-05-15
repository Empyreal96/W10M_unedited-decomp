// SepTokenFromAccessInformation 
 
unsigned int __fastcall SepTokenFromAccessInformation(int a1, int a2)
{
  int v4; // r3
  int *v5; // r3
  int v6; // r5
  int *v7; // r1
  char v8; // r2
  int v9; // t1
  int v10; // r0
  int v11; // r6
  int v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r3
  unsigned int result; // r0
  unsigned int v18; // r2
  int v19; // r1

  memset((_BYTE *)a2, 0, 664);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a1 + 16);
  v4 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a2 + 168) = v4;
  if ( v4 == 2 )
    *(_DWORD *)(a2 + 172) = *(_DWORD *)(a1 + 24);
  v5 = *(int **)(a1 + 8);
  v6 = *v5;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  if ( v6 )
  {
    v7 = v5 + 1;
    do
    {
      v9 = *v7;
      v7 += 3;
      v8 = v9;
      if ( (unsigned int)(v9 - 2) <= 0x21 )
      {
        v10 = 1 << (v8 - 32);
        v11 = 1 << v8;
        v12 = *(_DWORD *)(a2 + 68);
        *(_DWORD *)(a2 + 64) |= 1 << v8;
        *(_DWORD *)(a2 + 68) = v12 | v10;
        if ( (*(v7 - 1) & 2) != 0 )
        {
          v13 = *(_DWORD *)(a2 + 76);
          *(_DWORD *)(a2 + 72) |= v11;
          *(_DWORD *)(a2 + 76) = v13 | v10;
        }
        if ( (*(v7 - 1) & 1) != 0 )
        {
          v14 = *(_DWORD *)(a2 + 84);
          *(_DWORD *)(a2 + 80) |= v11;
          *(_DWORD *)(a2 + 84) = v14 | v10;
        }
      }
      --v6;
    }
    while ( v6 );
  }
  *(_DWORD *)(a2 + 124) = **(_DWORD **)a1;
  *(_DWORD *)(a2 + 148) = *(_DWORD *)(*(_DWORD *)a1 + 4);
  RtlSidHashInitialize(*(int **)(*(_DWORD *)a1 + 4), **(_DWORD **)a1, a2 + 204);
  *(_DWORD *)(a2 + 128) = **(_DWORD **)(a1 + 4);
  *(_DWORD *)(a2 + 152) = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4);
  RtlSidHashInitialize(*(int **)(*(_DWORD *)(a1 + 4) + 4), **(_DWORD **)(a1 + 4), a2 + 340);
  *(_DWORD *)(a2 + 488) = **(_DWORD **)(a1 + 44);
  *(_DWORD *)(a2 + 484) = *(_DWORD *)(*(_DWORD *)(a1 + 44) + 4);
  RtlSidHashInitialize(*(int **)(*(_DWORD *)(a1 + 44) + 4), **(_DWORD **)(a1 + 44), a2 + 492);
  v15 = *(_DWORD *)(a1 + 40);
  if ( v15 )
    *(_DWORD *)(a2 + 480) = v15;
  v16 = *(_DWORD *)(a1 + 48);
  if ( v16 )
    *(_DWORD *)(a2 + 640) = v16;
  result = *(_DWORD *)(a2 + 124);
  *(_DWORD *)(a2 + 176) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a2 + 184) = -1;
  v18 = 0;
  *(_DWORD *)(a2 + 188) = *(_DWORD *)(a1 + 28);
  if ( result )
  {
    v19 = *(_DWORD *)(a2 + 148);
    do
    {
      if ( (*(_DWORD *)(v19 + 4) & 0x40) != 0 && *(_DWORD *)(a2 + 184) == -1 )
        *(_DWORD *)(a2 + 184) = v18;
      ++v18;
      v19 += 8;
    }
    while ( v18 < result );
  }
  *(_DWORD *)(a2 + 476) = *(_DWORD *)(a1 + 52);
  return result;
}
