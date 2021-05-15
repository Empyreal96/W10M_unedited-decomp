// RtlpFreeHeapInternal 
 
int __fastcall RtlpFreeHeapInternal(_DWORD *a1, unsigned int a2, int a3)
{
  unsigned __int16 *v6; // r5
  int v7; // r0
  int v8; // r2
  int v10; // r2
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r3
  int v16; // r0
  int v17; // [sp+8h] [bp-20h]
  int v18; // [sp+8h] [bp-20h]

  if ( (a1[18] & 1) != 0 )
  {
    v6 = (unsigned __int16 *)RtlpProbeUserBufferSafe(a1, a2);
  }
  else
  {
    if ( (a2 & 7) != 0 )
    {
      v7 = 9;
      v8 = a2;
      goto LABEL_8;
    }
    v6 = (unsigned __int16 *)(a2 - 8);
    if ( *(_BYTE *)(a2 - 1) == 5 )
      v6 -= 4 * *(unsigned __int8 *)(a2 - 2);
    if ( (*((_BYTE *)v6 + 7) & 0x3F) == 0 )
    {
      v7 = 8;
      v8 = (int)v6;
LABEL_8:
      RtlpLogHeapFailure(v7, (int)a1, v8, 0, 0);
      v6 = 0;
      goto LABEL_10;
    }
  }
LABEL_10:
  if ( !v6 )
    return 0;
  if ( *(_BYTE *)(a2 - 1) == 5 )
  {
    if ( a1[19]
      && (unsigned int)(a1[20] ^ *(_DWORD *)v6) >> 24 != ((unsigned __int8)((unsigned __int16)(*((_WORD *)a1 + 40) ^ *v6) >> 8) ^ (unsigned __int8)(*((_BYTE *)a1 + 80) ^ *(_BYTE *)v6) ^ (unsigned __int8)((unsigned int)(a1[20] ^ *(_DWORD *)v6) >> 16)) )
    {
      goto LABEL_29;
    }
    v10 = a1[19];
    if ( v10 )
    {
      v10 = a1[19];
      v17 = *(_DWORD *)v6;
      if ( (v10 & *(_DWORD *)v6) != 0 )
        v17 = a1[20] ^ *(_DWORD *)v6;
      v11 = (unsigned __int16)v17;
    }
    else
    {
      v11 = *v6;
    }
    if ( *((_BYTE *)v6 + 7) == 4 )
    {
      if ( v10 )
      {
        v18 = *(_DWORD *)v6;
        if ( (a1[19] & *(_DWORD *)v6) != 0 )
          v18 = a1[20] ^ *(_DWORD *)v6;
        v12 = (unsigned __int16)v18;
      }
      else
      {
        v12 = *v6;
      }
      v13 = *((_DWORD *)v6 - 2) - v12 + v11;
    }
    else
    {
      v13 = 8 * v11;
    }
    if ( (unsigned int)v6 + v13 < a2 )
    {
LABEL_29:
      RtlpLogHeapFailure(3, (int)a1, (int)v6, a2, 0);
      return 0;
    }
    v14 = *(_DWORD *)(a2 - 8);
    if ( (a3 & 0x3C000102) == 0 )
    {
      v15 = *(_BYTE *)(a2 - 1) == 5 ? a2 - 8 * *(unsigned __int8 *)(a2 - 2) : 0;
      v16 = v14 && (_WORD)v14 == 1 ? MEMORY[0](a1, a2, 3, v15) : -1073741823;
      if ( v16 < 0 )
        return 0;
    }
  }
  return (unsigned __int8)RtlpFreeHeap((int)a1, a3 | 2, (int)v6, a2);
}
