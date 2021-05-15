// PfpCopyEvent 
 
int __fastcall PfpCopyEvent(int a1)
{
  int v2; // r2
  unsigned __int8 v3; // r3
  int v4; // r1
  __int64 v5; // kr00_8
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r2
  int v9; // r0
  _DWORD *v11; // r5
  int v12; // r0
  unsigned int v13; // r4
  int v14; // r3
  int v15; // r5
  int v16; // r0
  int v17[2]; // [sp+8h] [bp-18h] BYREF
  int v18[4]; // [sp+10h] [bp-10h] BYREF

  if ( (*(_DWORD *)a1 & 0x1F000) == 40960 )
  {
    v2 = *(_DWORD *)(a1 + 16);
    v3 = v2;
    if ( (v2 & 0x7FFFFFFFu) >= 0xFF )
      v3 = -1;
    v4 = 2;
    if ( v2 >= 0 )
      v4 = 4098;
    v5 = *(_QWORD *)(a1 + 20);
    v6 = *(unsigned __int8 *)(a1 + 27);
    v17[1] = v3 | (HIDWORD(v5) << 8);
    v7 = v4 & 0xFFFFFF | (v6 << 24);
    v8 = *(_DWORD *)(a1 + 12);
    v17[0] = v7;
    v18[1] = v8 >> 20;
    v18[0] = (v8 << 12) | 1;
    v9 = PfpLogPageAccess(v5, v18, v17, a1 + 12, 1);
    if ( !v9 )
      return -1073741432;
    v11 = (_DWORD *)(((dword_643938 + 35) & 0xFFFFFFFC)
                   + 20 * (*(unsigned __int16 *)(v9 + 6) - *(unsigned __int16 *)(dword_643938 + 28)));
    if ( (v11[1] & 4) != 0 && PsLookupProcessByProcessId(*(_DWORD *)(a1 + 28), v17) >= 0 )
    {
      v12 = v17[0];
      if ( ((*(_DWORD *)(v17[0] + 204) ^ *(_DWORD *)(v17[0] + 200) ^ v17[0]) & 0x1FFFFFFF ^ (*(_DWORD *)(v17[0] + 200) >> 3) & 0x1C000000) == *(_DWORD *)(a1 + 20)
        && *(_DWORD *)(v17[0] + 176) )
      {
        if ( *(_QWORD *)(v17[0] + 200) )
        {
          v13 = v11[1] & 0xFFFFFFF8 | 1;
          v11[1] = v13;
          v11[1] = v13 & 7 | (*(_DWORD *)(v12 + 200) & 0xE0000007 ^ (8 * (v12 ^ *(_DWORD *)(v12 + 204)))) & 0xFFFFFFF8 ^ (8 * *(_DWORD *)(v12 + 200));
          v11[4] = *(_DWORD *)(v12 + 408);
          v14 = *(_DWORD *)(v12 + 176);
          v11[2] = v12;
          v11[3] = v14;
        }
      }
      ObfDereferenceObjectWithTag(v12);
    }
  }
  else
  {
    v15 = (*(_DWORD *)a1 >> 2) & 0x3FF;
    v16 = PfTAcquireLogEntry((int)&algn_64390C[4], v17, v15);
    if ( !v16 )
      return -1073741670;
    memmove(((v16 + 19) & 0xFFFFFFFC) + 8 * v17[0], a1, 8 * v15);
  }
  return 0;
}
