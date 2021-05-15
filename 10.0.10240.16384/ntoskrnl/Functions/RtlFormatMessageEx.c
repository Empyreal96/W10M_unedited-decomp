// RtlFormatMessageEx 
 
int __fastcall RtlFormatMessageEx(unsigned __int16 *a1, unsigned int a2, int a3, int a4, char a5, int *a6, int a7, unsigned int a8, int a9)
{
  int *v9; // lr
  unsigned int v11; // r9
  int v12; // r5
  unsigned int v13; // r7
  unsigned __int16 *v14; // r4
  int v15; // r10
  unsigned __int16 *v16; // r6
  int v17; // r2
  unsigned int v18; // r3
  int v19; // r2
  unsigned int v20; // r2
  unsigned int v21; // t1
  unsigned int v22; // r6
  unsigned int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r10
  unsigned int v26; // r6
  int v27; // r2
  unsigned __int16 *v28; // r8
  int v29; // t1
  int v30; // r0
  char *i; // r1
  bool v32; // cc
  int v33; // r9
  char *v34; // r2
  int v35; // r0
  int v36; // r2
  int v37; // r3
  const __int16 *v38; // r2
  int v39; // r3
  __int16 v40; // r3
  unsigned int v41; // lr
  int *v42; // r10
  _DWORD *v43; // r1
  int v44; // r3
  int v45; // r2
  int v46; // r2
  int *v47; // r2
  int *v48; // r3
  int *v49; // r3
  int v50; // r3
  int v51; // r3
  unsigned __int16 *v52; // r1
  int v53; // r3
  int v54; // r3
  unsigned int v55; // r3
  _DWORD *v57; // r10
  unsigned __int16 *v58; // [sp+18h] [bp-6E8h]
  int v59; // [sp+1Ch] [bp-6E4h]
  int *v60; // [sp+20h] [bp-6E0h]
  unsigned __int16 *v61; // [sp+24h] [bp-6DCh]
  unsigned int v62; // [sp+28h] [bp-6D8h]
  unsigned int v63; // [sp+2Ch] [bp-6D4h]
  int v64; // [sp+30h] [bp-6D0h] BYREF
  char *v65; // [sp+34h] [bp-6CCh] BYREF
  unsigned __int16 *v66; // [sp+38h] [bp-6C8h]
  int v67; // [sp+3Ch] [bp-6C4h]
  unsigned int v68; // [sp+40h] [bp-6C0h]
  unsigned int v69; // [sp+44h] [bp-6BCh]
  int v70; // [sp+48h] [bp-6B8h]
  _DWORD *v71; // [sp+4Ch] [bp-6B4h]
  unsigned __int16 *v72; // [sp+50h] [bp-6B0h]
  int v73; // [sp+54h] [bp-6ACh]
  _QWORD v74[200]; // [sp+58h] [bp-6A8h] BYREF
  __int16 v75; // [sp+698h] [bp-68h] BYREF
  char v76; // [sp+69Ah] [bp-66h] BYREF
  char v77[54]; // [sp+6A0h] [bp-60h] BYREF
  char v78; // [sp+6D6h] [bp-2Ah] BYREF

  v9 = a6;
  v60 = a6;
  v11 = a7;
  v12 = a8 >> 1;
  v13 = 0;
  v70 = a4;
  v71 = (_DWORD *)a9;
  v73 = a7;
  v14 = (unsigned __int16 *)a7;
  v67 = a3;
  v69 = a2;
  v62 = 0;
  v63 = 0;
  v59 = a8 >> 1;
  v15 = a3;
LABEL_2:
  v16 = 0;
  v61 = 0;
  v58 = v14;
  while ( 1 )
  {
    v17 = *a1;
    if ( !*a1 )
      break;
    if ( v17 == 37 )
    {
      v18 = a1[1];
      v19 = (int)v14;
      v72 = v14;
      if ( v18 >= 0x31 && v18 <= 0x39 )
      {
        v21 = a1[2];
        a1 += 2;
        v20 = v21;
        v22 = v18 - 48;
        v66 = a1;
        if ( v21 >= 0x30 && v20 <= 0x39 )
        {
          ++a1;
          v23 = v20 + 10 * v22;
          v20 = *a1;
          v22 = v23 - 48;
          v66 = a1;
          if ( v20 >= 0x30 && v20 <= 0x39 )
          {
            ++a1;
            v24 = v20 + 10 * v22;
            v20 = *a1;
            v22 = v24 - 48;
            v66 = a1;
            if ( v20 >= 0x30 && v20 <= 0x39 )
              return -1073741811;
          }
        }
        v25 = 0;
        v26 = v22 - 1;
        v68 = 0;
        if ( v20 == 33 )
        {
          v75 = 37;
          v29 = a1[1];
          v28 = a1 + 1;
          v27 = v29;
          v30 = 0;
          for ( i = &v76; ; i += 2 )
          {
            v65 = i;
            if ( v27 == 33 )
              break;
            if ( !v27 )
              return -1073741811;
            if ( i >= &v78 )
              return -1073741811;
            if ( v27 == 42 )
            {
              v32 = v25++ > 1;
              v68 = v25;
              if ( v32 )
                return -1073741811;
            }
            ++v28;
            *(_WORD *)i = v27;
            v27 = *v28;
          }
          *(_WORD *)i = 0;
          v33 = 0;
          a1 = v28 + 1;
          v66 = a1;
          if ( v77 <= i )
          {
            v34 = v77;
            do
            {
              if ( v33 )
                break;
              if ( *((_WORD *)v34 - 3) == 73 && *((_WORD *)v34 - 2) == 54 && *((_WORD *)v34 - 1) == 52 )
                v33 = 1;
              v34 += 2;
            }
            while ( v34 <= i );
          }
        }
        else
        {
          RtlStringCbCopyExW(&v75, 0x40u, L"%s", &v65, 0, 0);
          v9 = v60;
          i = v65;
          v30 = 1;
          v33 = 0;
        }
        if ( v67 )
        {
          if ( v30 == 1 || !wcscmp((char *)&v75, (char *)L"%s") )
            v35 = RtlStringCchPrintfExW((int)v14, v12, &v64, 0, 0, L"%%%u");
          else
            v35 = RtlStringCchPrintfExW((int)v14, v12, &v64, 0, 0, L"%%%u!%s!");
          if ( v35 < 0 )
            return -2147483643;
          goto LABEL_78;
        }
        if ( !v9 || v25 + v26 >= 0xC8 )
          return -1073741811;
        if ( v70 )
        {
          v36 = *((unsigned __int16 *)i - 1);
          if ( v36 == 99 )
          {
            v37 = *((unsigned __int16 *)i - 2);
            if ( v37 != 104 && v37 != 119 && v37 != 108 )
            {
              v38 = L"hc";
              goto LABEL_51;
            }
          }
          if ( v36 != 115 || (v39 = *((unsigned __int16 *)i - 2), v39 == 104) || v39 == 119 || v39 == 108 )
          {
            if ( v36 == 83 )
            {
              v40 = 115;
            }
            else
            {
              if ( v36 != 67 )
                goto LABEL_57;
              v40 = 99;
            }
            *((_WORD *)i - 1) = v40;
          }
          else
          {
            v38 = L"hs";
LABEL_51:
            RtlStringCchCopyW((_WORD *)i - 1, 3u, (int)v38);
          }
        }
LABEL_57:
        v41 = v63;
        if ( v26 >= v63 )
        {
          v42 = v60;
          v43 = &v74[v63];
          while ( !a5 )
          {
            v45 = *v42;
            if ( !v33 )
            {
              *v42 = (-v45 & 3) + v45 + 4;
              v44 = *(_DWORD *)((-v45 & 3) + v45);
              goto LABEL_64;
            }
            v46 = (-v45 & 7) + v45 + 8;
            *v42 = v46;
            *v43 = *(_DWORD *)(v46 - 8);
            v43[1] = *(_DWORD *)(v46 - 4);
LABEL_65:
            ++v41;
            v43 += 2;
            if ( v41 > v26 )
            {
              v14 = v58;
              v12 = v59;
              a1 = v66;
              v60 = v42;
              v25 = v68;
              v63 = v41;
              goto LABEL_67;
            }
          }
          v44 = *v42++;
LABEL_64:
          *v43 = v44;
          v43[1] = 0;
          goto LABEL_65;
        }
LABEL_67:
        v65 = (char *)v74[v26];
        if ( v25 )
        {
          if ( a5 )
          {
            v47 = v60 + 1;
            v48 = (int *)&v74[v41++];
            *v48 = *v60;
            v48[1] = 0;
            v14 = v58;
            v63 = v41;
            ++v60;
          }
          else
          {
            v47 = v60;
            *v60 += (-*v60 & 3) + 4;
          }
          if ( v25 > 1 )
          {
            if ( a5 )
            {
              v49 = (int *)&v74[v41];
              v63 = v41 + 1;
              *v49 = *v47;
              v49[1] = 0;
              v60 = v47 + 1;
            }
            else
            {
              v50 = (-*v47 & 3) + *v47 + 4;
              *v60 = v50;
              v63 = v41 + 1;
              v74[v41] = *(unsigned int *)(v50 - 4);
            }
          }
        }
        if ( RtlStringCchPrintfExW((int)v14, v12, &v64, 0, 0, &v75) < 0 )
          return -2147483643;
        v13 = v62;
LABEL_78:
        v51 = (v64 - (int)v14) >> 1;
        v12 -= v51;
        v59 = v12;
        if ( v12 < 0 )
          return -2147483643;
        v9 = v60;
        v16 = v61;
        v19 = (int)v72;
        v11 = v73;
        a2 = v69;
        v15 = v67;
        v14 += v51;
LABEL_104:
        v58 = v14;
        if ( v19 )
        {
          v13 += ((int)v14 - v19) >> 1;
          goto LABEL_124;
        }
LABEL_105:
        v16 = 0;
        v61 = 0;
        v13 = 0;
        goto LABEL_124;
      }
      switch ( v18 )
      {
        case 0x30u:
          goto LABEL_147;
        case 0u:
          return -1073741811;
        case 0x72u:
          v59 = --v12;
          if ( v12 < 0 )
            return -2147483643;
          *v14++ = 13;
LABEL_85:
          v58 = v14;
          a1 += 2;
          goto LABEL_105;
        case 0x6Eu:
          v12 -= 2;
          v59 = v12;
          if ( v12 < 0 )
            return -2147483643;
          *v14 = 13;
          v14[1] = 10;
          v14 += 2;
          goto LABEL_85;
        case 0x74u:
          v59 = --v12;
          if ( v12 < 0 )
            return -2147483643;
          if ( (v13 & 7) != 0 )
            v13 = (v13 + 7) & 0xFFFFFFF8;
          else
            v13 += 8;
          v16 = v14;
          v61 = v14;
          LOWORD(v18) = 9;
          goto LABEL_102;
        case 0x62u:
          v59 = --v12;
          if ( v12 < 0 )
            return -2147483643;
          v16 = v14;
          v61 = v14;
          LOWORD(v18) = 32;
          goto LABEL_102;
      }
      if ( v15 )
      {
        v12 -= 2;
        v59 = v12;
        if ( v12 < 0 )
          return -2147483643;
        *v14 = 37;
        v14[1] = a1[1];
        v14 += 2;
      }
      else
      {
        v59 = --v12;
        if ( v12 < 0 )
          return -2147483643;
LABEL_102:
        *v14++ = v18;
      }
      a1 += 2;
      goto LABEL_104;
    }
    ++a1;
    if ( v17 != 13 && v17 != 10 )
      goto LABEL_120;
    if ( v17 == 10 && *a1 == 13 || v17 == 13 && *a1 == 10 )
      ++a1;
    if ( a2 )
    {
      v16 = v14;
      v61 = v14;
      v17 = 32;
    }
    else
    {
      v17 = 10;
    }
    if ( v17 == 10 )
    {
      v12 -= 2;
      v59 = v12;
      if ( v12 < 0 )
        return -2147483643;
      *v14 = 13;
      v14[1] = 10;
      v14 += 2;
      v16 = 0;
      v58 = v14;
      v61 = 0;
      v13 = 0;
    }
    else
    {
LABEL_120:
      v59 = --v12;
      if ( v12 < 0 )
        return -2147483643;
      if ( v17 == 32 )
      {
        v16 = v14;
        v61 = v14;
      }
      *v14++ = v17;
      ++v13;
      v58 = v14;
    }
LABEL_124:
    v62 = v13;
    if ( a2 && a2 != -1 && v13 >= a2 )
    {
      if ( v16 )
      {
        v52 = v16;
        do
        {
          v53 = *v52;
          if ( v53 != 32 && v53 != 9 )
            break;
          ++v52;
        }
        while ( v52 != v14 );
        while ( (unsigned int)v16 > v11 )
        {
          v54 = *(v16 - 1);
          if ( v54 != 32 && v54 != 9 )
            break;
          --v16;
        }
        v55 = v52 - v16;
        if ( v55 == 1 )
        {
          v59 = --v12;
          if ( v12 >= 0 )
            goto LABEL_142;
          return -2147483643;
        }
        if ( v55 > 2 )
        {
          v12 = v55 + v12 - 2;
          v59 = v12;
        }
LABEL_142:
        v13 = v14 - v52;
        v62 = v13;
        memmove((int)(v16 + 2), (int)v52, 2 * v13);
        *v16 = 13;
        v16[1] = 10;
        a2 = v69;
        v14 = &v16[v13 + 2];
      }
      else
      {
        v12 -= 2;
        v59 = v12;
        if ( v12 < 0 )
          return -2147483643;
        *v14 = 13;
        v14[1] = 10;
        v14 += 2;
        v13 = 0;
        v62 = 0;
      }
      v9 = v60;
      goto LABEL_2;
    }
  }
LABEL_147:
  if ( v12 < 1 )
    return -2147483643;
  v57 = v71;
  *v14 = 0;
  if ( v57 )
    *v57 = 2 * ((int)((int)v14 - v11 + 2) >> 1);
  return 0;
}
