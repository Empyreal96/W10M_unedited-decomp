// sub_547284 
 
void __fastcall sub_547284(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, unsigned int *a10, int a11)
{
  int v11; // r5
  int v12; // r7
  int v13; // r6
  int v14; // r2
  int v15; // r9
  int v16; // r10
  unsigned int *v17; // r4
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r1
  int v21; // r3

  v13 = 32 * a2;
  __mrc(14, 7, 2, 2, 7);
  __mrc(14, 7, 2, 2, 7);
  __mrc(14, 7, 2, 2, 7);
  __mrc(14, 7, 2, 2, 7);
  if ( *(unsigned __int16 *)(*(_DWORD *)(v11 + 16) + 18) > (unsigned int)*(unsigned __int16 *)(*(_DWORD *)(v11 + 16) + 16) )
  {
    PfpRpFileKeyUpdate(&unk_6372E0);
    if ( *(_DWORD *)(v12 + 372) >= *(_DWORD *)(v12 + 376) )
      JUMPOUT(0x4C3822);
    v14 = *(_DWORD *)(v11 + 16);
    v15 = *(unsigned __int16 *)(v14 + 16);
    a11 = *(_DWORD *)(v14 + 12);
    v16 = *(unsigned __int16 *)(v14 + 18) - v15;
    if ( PfFbLogEntryReserve(v12 + 160, &a9, &a10, (2 * v16 + 41) & 0xFFFFFFF8) < 0 )
    {
      if ( a9 )
        ((void (*)(void))PfFbLogEntryComplete)();
      JUMPOUT(0x4C3A4E);
    }
    v17 = a10;
    v18 = (int)(a10 + 8);
    *a10 = *a10 & 0x80000000 | (8 * ((2 * v16 + 41) & 0xFFFFFF8));
    v17[1] = *(_DWORD *)(*(_DWORD *)(v11 + 16) + 24);
    v17[2] = *(_DWORD *)(*(_DWORD *)(v11 + 16) + 28);
    v17[5] = *(_DWORD *)(*(_DWORD *)(v11 + 16) + 4);
    v17[6] = *(_DWORD *)(*(_DWORD *)(v11 + 16) + 32);
    v17[4] = *(_DWORD *)(*(_DWORD *)(v11 + 16) + 8);
    v19 = v17[7] & 0xFFFFFFFE | *(_DWORD *)(*(_DWORD *)(v11 + 16) + 20) & 1;
    v17[7] = v19;
    v20 = v19 ^ ((unsigned __int8)v19 ^ (unsigned __int8)(*(_DWORD *)(*(_DWORD *)(v11 + 16) + 20) >> 3)) & 2;
    v17[7] = v20;
    v17[7] = (v20 ^ (2 * *(_DWORD *)(*(_DWORD *)(v11 + 16) + 20))) & v13 ^ v20;
    v21 = a11;
    *((_WORD *)v17 + 15) = v16;
    memmove(v18, v21 + 2 * v15, 2 * v16);
    *((_WORD *)v17 + *((unsigned __int16 *)v17 + 15) + 16) = 0;
    wcsupr((unsigned __int16 *)v17 + 16);
    PfFbLogEntryComplete(a9);
  }
  JUMPOUT(0x4C385C);
}
