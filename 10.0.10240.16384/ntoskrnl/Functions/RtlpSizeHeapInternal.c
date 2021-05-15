// RtlpSizeHeapInternal 
 
int __fastcall RtlpSizeHeapInternal(int a1, int a2, int a3)
{
  unsigned __int16 *v4; // r0
  int result; // r0
  int v6; // r2
  int v7; // r2
  int v8; // r1
  int v9; // r3
  int v10; // r3
  bool v11; // zf
  int v12; // r3
  int v13; // [sp+8h] [bp-10h]
  int v14; // [sp+8h] [bp-10h]
  int v15; // [sp+8h] [bp-10h]

  if ( (*(_DWORD *)(a1 + 72) & 1) != 0 )
  {
    v4 = (unsigned __int16 *)RtlpProbeUserBufferSafe(a1, a3);
  }
  else
  {
    if ( (a3 & 7) != 0 )
    {
      RtlpLogHeapFailure(9, a1, a3, 0, 0);
      goto LABEL_8;
    }
    v4 = (unsigned __int16 *)(a3 - 8);
    if ( *(_BYTE *)(a3 - 1) == 5 )
      v4 -= 4 * *(unsigned __int8 *)(a3 - 2);
    if ( (*((_BYTE *)v4 + 7) & 0x3F) == 0 )
    {
      RtlpLogHeapFailure(8, a1, (int)v4, 0, 0);
LABEL_8:
      v4 = 0;
      goto LABEL_10;
    }
  }
LABEL_10:
  if ( !v4 )
    return -1;
  if ( *((_BYTE *)v4 + 7) == 4 )
  {
    if ( *(_DWORD *)(a1 + 76) )
    {
      v13 = *(_DWORD *)v4;
      if ( (*(_DWORD *)(a1 + 76) & *(_DWORD *)v4) != 0 )
        v13 = *(_DWORD *)(a1 + 80) ^ *(_DWORD *)v4;
      v6 = (unsigned __int16)v13;
    }
    else
    {
      v6 = *v4;
    }
    result = *((_DWORD *)v4 - 2) - v6;
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 76);
    if ( v7 )
    {
      v7 = *(_DWORD *)(a1 + 76);
      v14 = *(_DWORD *)v4;
      if ( (v7 & *(_DWORD *)v4) != 0 )
        v14 = *(_DWORD *)(a1 + 80) ^ *(_DWORD *)v4;
      v8 = (unsigned __int16)v14;
    }
    else
    {
      v8 = *v4;
    }
    v9 = *((unsigned __int8 *)v4 + 7);
    if ( v9 == 5 )
    {
      v10 = v4[2] ^ *(unsigned __int16 *)(a1 + 84);
    }
    else
    {
      v11 = (v9 & 0x40) == 0;
      v10 = v9 & 0x3F;
      if ( v11 )
      {
        if ( v10 == 63 )
        {
          if ( v7 )
          {
            v15 = *(_DWORD *)v4;
            if ( (*(_DWORD *)(a1 + 76) & *(_DWORD *)v4) != 0 )
              v15 = *(_DWORD *)(a1 + 80) ^ *(_DWORD *)v4;
            v12 = (unsigned __int16)v15;
          }
          else
          {
            v12 = *v4;
          }
          v10 = *(_DWORD *)&v4[4 * v12 - 2];
        }
      }
      else
      {
        v10 = v4[4 * v10 + 2];
      }
    }
    result = 8 * v8 - v10;
  }
  return result;
}
