// MiReservePageFileSpace 
 
_DWORD *__fastcall MiReservePageFileSpace(_DWORD *result, unsigned int a2, int a3)
{
  int v3; // r7
  int v4; // lr
  unsigned int v5; // r7
  int v6; // r8
  _DWORD *v7; // r5
  unsigned int v8; // r4
  unsigned int v9; // r6
  int v10; // r3
  int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r2
  int v14; // r3
  unsigned int v15; // r1
  int v16; // r2
  unsigned int v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int v20; // r3
  int v21; // r10
  unsigned int v22; // r5
  unsigned int v23; // r7
  int v24; // r9
  int v25; // r8
  unsigned int v26; // r2
  unsigned int v27; // r7
  unsigned int v28; // r4
  int v29; // r8
  unsigned int v30; // r6
  char v31; // r1
  __int16 v32; // r3
  unsigned int v33; // r3
  unsigned int v34; // r6
  unsigned int v35; // r5
  int v36; // r7
  int v37; // r8
  int v38; // r3
  unsigned int v39; // r4
  unsigned int v40; // [sp+8h] [bp-48h] BYREF
  int v41; // [sp+Ch] [bp-44h]
  _DWORD *v42; // [sp+10h] [bp-40h]
  int v43; // [sp+14h] [bp-3Ch]
  int v44; // [sp+18h] [bp-38h]
  int v45; // [sp+1Ch] [bp-34h] BYREF
  char v46[8]; // [sp+20h] [bp-30h] BYREF
  unsigned int v47; // [sp+28h] [bp-28h]
  unsigned int v48; // [sp+2Ch] [bp-24h]

  v3 = result[128];
  v4 = a3;
  v41 = a3;
  v42 = result;
  v45 = v3;
  v5 = v3 & 0x7FF;
  v6 = a2;
  v43 = a2;
  if ( v5 >= 0x10 )
  {
    v7 = 0;
    v44 = 0;
    if ( !a3 )
    {
      result = (_DWORD *)MiGetPageFileSectionForReservation(a2, (int)v46, 1);
      if ( !result )
        return result;
      v8 = v47;
      v9 = v48;
      v44 = 1;
      goto LABEL_17;
    }
    if ( (*(_BYTE *)(a3 + 112) & 7) != 0 )
    {
      v8 = a2 & 0xFFFFF000;
      v9 = (a2 & 0xFFFFF000) + 4092;
      goto LABEL_18;
    }
    result = MiLocateAddress(a2 << 10);
    v7 = result;
    if ( result )
    {
      v10 = result[7];
      if ( v10 >= 0 && (v10 & 0x8000) != 0 && (v10 & 7) == 0 )
      {
        v11 = result[3];
        v12 = (v6 << 10) & 0xFFC00000;
        if ( v12 >= v11 << 12 )
          v8 = ((v12 >> 10) & 0x3FFFFC) - 0x40000000;
        else
          v8 = 4 * ((v11 & 0xFFFFF) - 0x10000000);
        v13 = v12 + 4190208;
        v14 = result[4];
        if ( v13 <= v14 << 12 )
          v9 = ((v13 >> 10) & 0x3FFFFC) - 0x40000000;
        else
          v9 = 4 * ((v14 & 0xFFFFF) - 0x10000000);
LABEL_17:
        v4 = v41;
LABEL_18:
        v15 = ((int)(v9 - v8) >> 2) + 1;
        if ( v15 > v5 )
        {
          v16 = (int)(v6 - v8) >> 2;
          v17 = (int)(v9 - v6) >> 2;
          v18 = v15 - v5;
          if ( v17 < v18 )
          {
            v20 = v18 - v17;
            v19 = 0;
            v16 -= v20;
          }
          else
          {
            v19 = v17 - v18;
          }
          v8 = v6 - 4 * v16;
          v9 = v6 + 4 * v19;
        }
        v21 = ((v4 != 0) << 7) | 1;
        if ( v7 && (int)v7[8] < 0 )
          v21 = ((unsigned __int8)v21 ^ (unsigned __int8)(v7[7] >> 1)) & 0x7C ^ v21 | 2;
        v22 = 0;
        v23 = v6 - 4;
        v40 = 0;
        v24 = 0;
        if ( v6 - 4 >= v8 )
        {
          v25 = (int)v42;
          do
          {
            result = (_DWORD *)MiReservePageFileSpaceForPage(v25, v23, v21, &v40);
            if ( !result )
              break;
            v23 -= 4;
            ++v24;
          }
          while ( v23 >= v8 );
          v22 = v40;
          v6 = v43;
        }
        v26 = 0;
        v27 = v6 + 4;
        v28 = 0;
        v40 = 0;
        if ( v6 + 4 <= v9 )
        {
          v29 = (int)v42;
          do
          {
            result = (_DWORD *)MiReservePageFileSpaceForPage(v29, v27, v21, &v40);
            if ( !result )
              break;
            v27 += 4;
            ++v28;
          }
          while ( v27 <= v9 );
          v26 = v40;
          v6 = v43;
        }
        v30 = v28 + v24 + 1;
        v31 = 0;
        if ( !v22 )
        {
          if ( v26 && v30 < v26 >> 13 )
          {
            v22 = v26 - (v30 << 13);
          }
          else
          {
            if ( !(v28 + v24) )
              goto LABEL_56;
            v22 = 0;
            v31 = 8;
          }
        }
        v40 = v22;
        v32 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * ((v22 >> 2) & 1) + 1800] + 96);
        if ( (v32 & 0x10) != 0 || (v32 & 0x20) != 0 && (v22 & 8) != 0 )
        {
          v40 = 0;
          v31 = 8;
        }
        result = (_DWORD *)MiFindFreePageFileSpace((int)v42, &v40, v28 + v24 + 1, (int)&v45, v31 | 1);
        if ( result == (_DWORD *)v30 )
          goto LABEL_51;
        if ( result )
        {
          v33 = v30 - (_DWORD)result;
          if ( v28 < v30 - (unsigned int)result )
          {
            v24 -= v33 - v28;
            v28 = 0;
          }
          else
          {
            v28 -= v33;
          }
LABEL_51:
          v34 = v6 + 4 * v28;
          v35 = v6 - 4 * v24;
          if ( v35 <= v34 )
          {
            v36 = v41;
            v37 = (int)v42;
            do
            {
              result = (_DWORD *)MiReservePageFileSpaceForPage(v37, v35, v21 & 0xFFFFFFFE, &v40);
              v39 = v40;
              if ( !result )
                result = (_DWORD *)MiReleasePageFileInfo(v37, v40, v36 != 0, v38);
              v35 += 4;
              v40 = ((v39 & 0xFFFFE000) + 0x2000) ^ v39 & 0x1FFF;
            }
            while ( v35 <= v34 );
          }
        }
LABEL_56:
        if ( v44 )
          result = MiReleasePageFileSectionInfo((int)v46);
        return result;
      }
    }
  }
  return result;
}
