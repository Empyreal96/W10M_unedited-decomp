// PfSnBuildDumpFromTrace 
 
int __fastcall PfSnBuildDumpFromTrace(int *a1, int a2)
{
  int *v2; // r7
  int v3; // r4
  int v6; // r2
  int v7; // r0
  unsigned int v8; // r8
  int v9; // r9
  int v10; // r2
  unsigned int v11; // r2
  int v12; // r10
  _DWORD *v13; // r5
  int v14; // r9
  int v15; // r4
  _DWORD *v16; // r3
  int v17; // r5
  __int64 v18; // kr00_8
  int v19; // r4

  v2 = a1;
  *a1 = 0;
  v3 = 0;
  if ( *(int *)(a2 + 248) < 32 )
    return sub_808EE0();
  if ( (*(_WORD *)(a2 + 344) & 2) != 0 )
    return -1072103399;
  v6 = *(_DWORD *)(a2 + 260);
  __dmb(0xBu);
  v7 = ExAllocatePoolWithTag(
         1,
         ((8 * (*(_DWORD *)(a2 + 92) + v6) + 211) & 0xFFFFFFFC) + 16 * *(_DWORD *)(a2 + 340) + 8,
         1146118979);
  v8 = v7;
  *v2 = v7;
  if ( !v7 )
    return -1073741670;
  v9 = v7 + 8;
  *(_DWORD *)(v7 + 8) = 30;
  *(_DWORD *)(v7 + 12) = 1128485697;
  memmove(v7 + 20, a2 + 12, 0x40u);
  v10 = *(_DWORD *)(v9 + 160);
  *(_DWORD *)(v9 + 76) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(v9 + 152) = *(_DWORD *)(a2 + 328);
  *(_DWORD *)(v9 + 156) = *(_DWORD *)(a2 + 332);
  *(_DWORD *)(v9 + 104) = *(_DWORD *)(a2 + 152);
  *(_DWORD *)(v9 + 108) = *(_DWORD *)(a2 + 156);
  v11 = v10 & 0xFFFFFFFE | *(_WORD *)(a2 + 344) & 1;
  *(_DWORD *)(v9 + 160) = v11;
  *(_DWORD *)(v9 + 160) = ((unsigned __int8)v11 ^ (unsigned __int8)(2 * *(_WORD *)(a2 + 346))) & 2 ^ v11;
  memset((_BYTE *)(v9 + 112), 0, 40);
  v12 = (v9 + 211) & 0xFFFFFFFC;
  *(_DWORD *)(v9 + 80) = v12 - v9;
  v13 = *(_DWORD **)(a2 + 84);
  if ( v13 != (_DWORD *)(a2 + 84) )
  {
    v14 = 0;
    do
    {
      v15 = v13[2];
      v16 = v13;
      v13 = (_DWORD *)*v13;
      memmove(v12, (int)(v16 + 4), 8 * v15);
      v12 += 8 * v15;
      v14 += v15;
    }
    while ( v13 != (_DWORD *)(a2 + 84) );
    v2 = a1;
    v3 = v14;
    v9 = v8 + 8;
  }
  *(_DWORD *)(v9 + 84) = v3;
  *(_DWORD *)(v9 + 88) = *(_DWORD *)(a2 + 248);
  *(_DWORD *)(v9 + 92) = *(_DWORD *)(a2 + 252);
  memmove(v9 + 112, a2 + 200, 0x28u);
  v17 = (v12 + 3) & 0xFFFFFFFC;
  *(_DWORD *)(v9 + 96) = v17 - v9;
  v18 = *(_QWORD *)(a2 + 336);
  memmove(v17, v18, 16 * HIDWORD(v18));
  *(_DWORD *)(v9 + 100) = *(_DWORD *)(a2 + 340);
  *(_DWORD *)(v9 + 8) = 16 * HIDWORD(v18) - v9 + v17;
  if ( PfVerifyTraceBuffer(v9) )
    return 0;
  v19 = -1073741823;
  ExFreePoolWithTag(v8);
  *v2 = 0;
  return v19;
}
