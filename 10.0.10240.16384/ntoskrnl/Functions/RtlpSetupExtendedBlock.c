// RtlpSetupExtendedBlock 
 
int __fastcall RtlpSetupExtendedBlock(int a1, int a2, int a3, int a4, unsigned __int16 a5, int a6)
{
  unsigned __int8 *v6; // r4
  int v8; // r6
  int v9; // r3
  int v10; // r8
  int v11; // r3
  __int16 v12; // r3
  int v13; // r0
  int v14; // r1
  int v15; // r3
  int v17; // [sp+0h] [bp-20h]

  v6 = (unsigned __int8 *)(a3 - 8);
  v8 = a5 + a3 - 8;
  v9 = *(unsigned __int8 *)(a3 - 1);
  v10 = 0;
  if ( v9 == 4 )
  {
    v11 = *(_DWORD *)(a1 + 68) | a2;
    if ( (v11 & 1) == 0 )
    {
      ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 200), 1, a3, v11);
      v10 = 1;
    }
    if ( *(_DWORD *)(a1 + 76) )
    {
      *(_DWORD *)v6 ^= *(_DWORD *)(a1 + 80);
      if ( v6[3] != (v6[2] ^ v6[1] ^ *v6) )
        RtlpAnalyzeHeapFailure(a1, v6);
    }
    v12 = *(_WORD *)v6;
    v13 = a5 >> 3;
    v6[6] = v13;
    LOWORD(v14) = v12 + a5;
    *(_WORD *)v6 = v12 + a5;
    if ( *(_DWORD *)(a1 + 76) )
    {
      v6[3] = *v6 ^ v6[2] ^ v6[1];
      *(_DWORD *)v6 ^= *(_DWORD *)(a1 + 80);
    }
    *(_BYTE *)(v8 + 6) = v13;
  }
  else
  {
    if ( v9 == 5 )
    {
      LOWORD(v14) = *(_WORD *)(a3 - 4) ^ *(_WORD *)(a1 + 84);
    }
    else if ( (v9 & 0x40) != 0 )
    {
      LOWORD(v14) = *(_WORD *)&v6[8 * (v9 & 0x3F) + 4];
    }
    else
    {
      LOWORD(v14) = v9 & 0x3F;
      if ( (v9 & 0x3F) == 63 )
      {
        if ( *(_DWORD *)(a1 + 76) )
        {
          v17 = *(_DWORD *)v6;
          if ( (*(_DWORD *)(a1 + 76) & *(_DWORD *)v6) != 0 )
            v17 = *(_DWORD *)(a1 + 80) ^ *(_DWORD *)v6;
          v15 = (unsigned __int16)v17;
        }
        else
        {
          v15 = *(unsigned __int16 *)v6;
        }
        v14 = *(_DWORD *)&v6[8 * v15 - 4];
      }
    }
    *(_BYTE *)(a5 + a3 - 2) = a5 >> 3;
    *(_BYTE *)(a3 - 1) = *(_BYTE *)(a3 - 1) & 0x80 | (a5 >> 3) | 0x40;
  }
  *(_BYTE *)(v8 + 7) = 5;
  *(_WORD *)(v8 + 4) = a5 + v14;
  *(_DWORD *)v8 = a6;
  if ( v10 )
    ExpReleaseResourceForThreadLite(*(_DWORD *)(a1 + 200), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  return v8 + 8;
}
