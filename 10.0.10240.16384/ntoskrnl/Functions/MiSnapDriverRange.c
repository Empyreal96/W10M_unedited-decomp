// MiSnapDriverRange 
 
int __fastcall MiSnapDriverRange(int a1, unsigned int a2, char a3, int a4, unsigned int *a5, unsigned int *a6)
{
  int v6; // r7
  int v9; // r8
  int v10; // r8
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v14; // r9
  unsigned int v15; // r6
  unsigned int v16; // r7
  char *v17; // r5
  unsigned int v18; // r8
  int v19; // r0
  bool v20; // zf
  int v21; // r8
  unsigned int v22; // r4
  unsigned int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // r3
  int v27; // [sp+0h] [bp-78h]
  unsigned int v28; // [sp+4h] [bp-74h]
  unsigned int v29; // [sp+18h] [bp-60h]
  unsigned int v30; // [sp+1Ch] [bp-5Ch]
  int v32; // [sp+24h] [bp-54h]
  char v34; // [sp+30h] [bp-48h] BYREF
  char v35[39]; // [sp+31h] [bp-47h] BYREF

  v6 = a4;
  v9 = a1;
  v34 = 0;
  memset(v35, 0, sizeof(v35));
  *a5 = 0;
  *a6 = 0;
  v10 = *(_DWORD *)(v9 + 24);
  v27 = v10;
  v11 = RtlImageNtHeader(v10);
  v12 = *(_DWORD *)(v11 + 56);
  v29 = v6 - v10;
  v28 = v12;
  v32 = v11;
  if ( v12 > 0x1000 )
    return sub_7CDF24();
  v14 = *(unsigned __int16 *)(v11 + 6);
  if ( a2 <= v14 )
  {
    v15 = 0;
    *(_DWORD *)&v35[15] = *(unsigned __int16 *)(v11 + 20) + 40 * v14 + v11 + 24 - v10;
    *(_DWORD *)&v35[7] = *(_DWORD *)&v35[15];
    v16 = 0;
    v30 = ~(v12 - 1);
    while ( 1 )
    {
      if ( a2 )
        v17 = (char *)(*(unsigned __int16 *)(v11 + 20) + 40 * a2 + v11 - 16);
      else
        v17 = &v34;
      v18 = *((_DWORD *)v17 + 4);
      if ( v18 < *((_DWORD *)v17 + 2) )
        v18 = *((_DWORD *)v17 + 2);
      if ( a4 )
      {
        v26 = *((_DWORD *)v17 + 3);
        if ( v29 >= v26 && v29 < v26 + v18 )
        {
LABEL_25:
          if ( !v15 )
            v15 = (((unsigned int)(*((_DWORD *)v17 + 3) + v27 + 4095) >> 10) & 0x3FFFFC) - 0x40000000;
          v23 = *((_DWORD *)v17 + 3) + v18;
          v21 = v27;
          v16 = (((v23 + v12 + v27 - 1) >> 10) & (v30 >> 10) & 0x3FFFFC) - 0x40000000;
          if ( (a3 & 0xC) == 0 || v12 >= 0x1000 )
            v16 = (((v23 + v12 + v27 - 1) >> 10) & (v30 >> 10) & 0x3FFFFC) - 1073741828;
          goto LABEL_30;
        }
      }
      else
      {
        if ( (a3 & 8) != 0 )
          goto LABEL_25;
        if ( (a3 & 1) != 0 )
        {
          v19 = MmImageSectionPagable(v17);
          goto LABEL_16;
        }
        if ( (a3 & 4) != 0 )
        {
          v20 = MmImageSectionPagable(v17) == 0;
          v12 = v28;
          if ( v20 )
            goto LABEL_25;
        }
        else
        {
          if ( (a3 & 0x10) != 0 )
          {
            v19 = *((_DWORD *)v17 + 9) & 0x20000000;
            goto LABEL_16;
          }
          if ( (a3 & 0x20) == 0 )
          {
            v19 = *((_DWORD *)v17 + 9) & 0x2000000;
            if ( (*(_DWORD *)(a1 + 52) & 0x4000000) != 0 && *(_DWORD *)v17 == 1414090313 )
              v19 = 0;
LABEL_16:
            v20 = v19 == 0;
            v12 = v28;
            if ( !v20 )
              goto LABEL_25;
            goto LABEL_18;
          }
          if ( *v17 == 80 && v17[1] == 65 && v17[2] == 71 && v17[3] == 69 && v17[4] == 75 && v17[5] == 68 )
            goto LABEL_25;
        }
      }
LABEL_18:
      v21 = v27;
      if ( v15 )
      {
        if ( (a3 & 0xC) != 0 )
        {
          if ( v15 <= v16 )
            goto LABEL_21;
          v16 = v15;
        }
        if ( v15 <= v16 )
        {
LABEL_21:
          v22 = a2 + 1;
          *a5 = v15;
          *a6 = v16;
          if ( v22 <= v14 )
            return v22;
          return 0;
        }
        v15 = 0;
      }
LABEL_30:
      if ( ++a2 > v14 )
      {
        if ( v15 )
        {
          v24 = *((_DWORD *)v17 + 4);
          if ( v24 < *((_DWORD *)v17 + 2) )
            v24 = *((_DWORD *)v17 + 2);
          v25 = (((((*((_DWORD *)v17 + 3) + v24 + v12 + v21 - 1) & ~(v12 - 1)) + 4095) >> 10) & 0x3FFFFC) - 1073741828;
          if ( v15 <= v25 )
          {
            *a5 = v15;
            *a6 = v25;
          }
        }
        return 0;
      }
      v11 = v32;
    }
  }
  return 0;
}
