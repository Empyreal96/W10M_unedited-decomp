// MiProtectSystemImage 
 
char *__fastcall MiProtectSystemImage(char *result)
{
  unsigned int v1; // r4
  int v2; // r9
  int v3; // r0
  int v4; // r1
  int v5; // r0
  int v6; // r1
  int v7; // r8
  unsigned int v8; // r2
  char *v9; // r5
  int v10; // r7
  unsigned int v11; // r6
  unsigned int v12; // r3
  unsigned int v13; // r1
  char *v14; // lr
  unsigned int v15; // r7
  int v16; // r8
  unsigned int v17; // r10
  unsigned int v18; // r6
  int v19; // r1
  unsigned int v20; // r7
  int v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // [sp+0h] [bp-70h]
  int v28; // [sp+4h] [bp-6Ch]
  int v29; // [sp+8h] [bp-68h]
  unsigned int v30; // [sp+Ch] [bp-64h]
  unsigned int v31; // [sp+14h] [bp-5Ch]
  unsigned int v32; // [sp+18h] [bp-58h]
  int v33; // [sp+1Ch] [bp-54h]
  char *v34; // [sp+24h] [bp-4Ch]
  char v35[36]; // [sp+28h] [bp-48h] BYREF
  int v36; // [sp+4Ch] [bp-24h]

  v1 = *((_DWORD *)result + 6);
  v33 = (int)result;
  if ( (*(_DWORD *)(((v1 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return result;
  v2 = RtlImageNtHeader(v1);
  if ( v1 >= dword_63389C )
  {
    v3 = MiGetSystemRegionIndex(v1);
    if ( *(_BYTE *)(v3 + v4 + 9692) == 1 )
      return (char *)sub_80EAF8();
    v5 = MiGetSystemRegionIndex(v1);
    if ( *(_BYTE *)(v5 + v6 + 9692) == 11 )
      return (char *)sub_80EAF8();
  }
  v7 = *(unsigned __int16 *)(v2 + 6);
  v8 = v1;
  v9 = (char *)(*(unsigned __int16 *)(v2 + 20) + v2 + 24);
  result = v9;
  v10 = v7;
  if ( !*(_WORD *)(v2 + 6) )
  {
LABEL_11:
    v13 = (unsigned int)&v9[40 * v7 - 1];
    result = (char *)(((v1 >> 10) & 0x3FFFFC) - 0x40000000);
    v14 = &result[4 * ((*(_DWORD *)(v2 + 80) & 0xFFF) != 0) + 4 * (*(_DWORD *)(v2 + 80) >> 12)];
    v15 = 0;
    v34 = v14;
    v29 = 0x40000000;
    v30 = v13;
    v27 = (unsigned int)result;
    v28 = 0;
    v32 = 0;
    v16 = v7 + 1;
    if ( !v16 )
      return result;
    while ( 1 )
    {
      if ( v16 == 1 )
      {
        v36 = 0;
        v31 = 0;
        v17 = 0;
        v9 = v35;
        v18 = ((v13 >> 10) & 0x3FFFFC) - 1073741820;
      }
      else
      {
        v17 = *((_DWORD *)v9 + 4);
        if ( v17 < *((_DWORD *)v9 + 2) )
          v17 = *((_DWORD *)v9 + 2);
        v18 = (((*((_DWORD *)v9 + 3) + v1) >> 10) & 0x3FFFFC) - 0x40000000;
        v31 = *((_DWORD *)v9 + 3) + v1;
      }
      if ( v15 && v18 > v15 )
      {
        v26 = MiComputeDriverProtection(0, v28);
        MiSetSystemCodeProtection(v33, v15, v15, v26);
        result = (char *)v27;
        if ( v15 == v27 )
        {
          result = (char *)(v27 + 4);
          v27 += 4;
        }
        v14 = v34;
        v32 = 0;
        v28 = 0;
      }
      if ( v18 >= (unsigned int)v14 && v9 != v35 )
        return result;
      v19 = v29;
      v20 = *((_DWORD *)v9 + 9) & 0xE0000000;
      if ( v20 != v29 )
        goto LABEL_19;
      v25 = *(_DWORD *)(v2 + 56);
      if ( v25 > 0x1000 )
        break;
LABEL_24:
      v15 = v32;
      --v16;
      v13 = ((v25 + v17 + v31 - 1) & ~(v25 - 1)) - 1;
      v9 += 40;
      v30 = v13;
      if ( !v16 )
        return result;
    }
    v19 = v29;
LABEL_19:
    v21 = (v30 >> 10) & 0x3FFFFC;
    v22 = v21 - 0x40000000;
    if ( v21 - 0x40000000 == v18 )
    {
      v22 = v21 - 1073741828;
      v32 = v18;
      v19 = v29;
      v28 |= v20 | v29;
    }
    if ( v22 >= (unsigned int)result )
    {
      v23 = MiComputeDriverProtection(0, v19);
      MiSetSystemCodeProtection(v33, v27, v24, v23);
      v14 = v34;
    }
    result = (char *)v18;
    v25 = *(_DWORD *)(v2 + 56);
    v27 = v18;
    v29 = v20;
    goto LABEL_24;
  }
  while ( 1 )
  {
    v11 = *((_DWORD *)result + 3) + v1;
    if ( v11 < v8 )
      return result;
    v12 = *((_DWORD *)result + 4);
    if ( v12 < *((_DWORD *)result + 2) )
      v12 = *((_DWORD *)result + 2);
    --v10;
    result += 40;
    v8 = (v12 + *(_DWORD *)(v2 + 56) + v11 - 1) & ~(*(_DWORD *)(v2 + 56) - 1);
    if ( !v10 )
      goto LABEL_11;
  }
}
