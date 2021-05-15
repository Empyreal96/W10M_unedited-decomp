// SepParseElamCertResources 
 
int __fastcall SepParseElamCertResources(unsigned __int16 *a1, int a2)
{
  int result; // r0
  unsigned int v4; // r6
  unsigned __int16 *v5; // r5
  unsigned int v6; // r10
  unsigned __int16 *v7; // r4
  char *v8; // r7
  unsigned int v9; // r9
  BOOL v10; // r0
  char *v11; // r1
  int v12; // r2
  char v13; // r3
  int v14; // t1
  int v15; // r2
  int v16; // r8
  int v17; // r6
  char *v18; // r4
  char *v19; // r0
  char *v20; // lr
  unsigned int v21; // r10
  _WORD *v22; // r9
  int v23; // r4
  unsigned int v24; // r2
  _WORD *v25; // r1
  __int16 v26; // t1
  char *v27; // r2
  unsigned int v28; // [sp+10h] [bp-218h]
  unsigned int v29; // [sp+14h] [bp-214h]
  char *v30; // [sp+18h] [bp-210h]
  unsigned __int16 *v31; // [sp+1Ch] [bp-20Ch]
  char *v32; // [sp+20h] [bp-208h]
  int v33; // [sp+24h] [bp-204h] BYREF
  unsigned int v34; // [sp+28h] [bp-200h]
  int v35; // [sp+2Ch] [bp-1FCh] BYREF
  char v36[24]; // [sp+30h] [bp-1F8h] BYREF
  char v37[64]; // [sp+48h] [bp-1E0h] BYREF
  _WORD v38[208]; // [sp+88h] [bp-1A0h] BYREF

  result = 0;
  if ( (unsigned int)(a2 - 2) <= 0xFFFD )
  {
    v4 = (unsigned int)a1 + a2;
    v5 = a1 + 1;
    v34 = *a1;
    v32 = (char *)a1 + a2;
    v6 = 0;
    v28 = 0;
    if ( !v34 )
      return result;
    while ( (unsigned int)(v5 + 1) <= v4 )
    {
      result = RtlStringCchLengthW(v5, (v4 - (unsigned int)v5) >> 1, &v35);
      if ( result < 0 )
        return result;
      v7 = &v5[v35 + 1];
      v8 = (char *)(v7 + 1);
      v31 = v7;
      if ( (unsigned int)(v7 + 1) >= v4 )
        break;
      v9 = 0;
      v10 = 1;
      v29 = 0;
      if ( *v5 )
      {
        v11 = v37;
        while ( v9 < 0x40 )
        {
          if ( v10 )
            *v11 = 0;
          else
            *v11 *= 16;
          v12 = *v5;
          if ( v12 == 32 )
          {
            if ( !v10 )
              return -1073741811;
          }
          else
          {
            if ( *v5 <= 0x2Fu )
              return -1073741811;
            if ( *v5 <= 0x39u )
            {
              v13 = *v11 + v12 - 48;
            }
            else
            {
              if ( *v5 <= 0x40u )
                return -1073741811;
              if ( *v5 <= 0x46u )
              {
                v13 = *v11 + v12 - 55;
              }
              else
              {
                if ( (unsigned int)(v12 - 97) > 5 )
                  return -1073741811;
                v13 = *v11 + v12 - 87;
              }
            }
            *v11 = v13;
          }
          if ( !v10 )
          {
            v29 = ++v9;
            ++v11;
          }
          if ( *v5 != 32 )
            v10 = !v10;
          v14 = v5[1];
          ++v5;
          if ( !v14 )
          {
            if ( !v10 )
              return -1073741811;
            goto LABEL_29;
          }
        }
        return -1073741811;
      }
LABEL_29:
      v15 = *v7;
      if ( v15 != 32772 && (unsigned int)(v15 - 32780) > 2 )
        return -1073741811;
      result = RtlStringCchLengthW(v7 + 1, (v4 - (unsigned int)v8) >> 1, &v33);
      if ( result < 0 )
        return result;
      v16 = v33;
      v17 = 0;
      v18 = &v8[2 * v33];
      v5 = (unsigned __int16 *)(v18 + 2);
      if ( v33 )
      {
        v19 = (char *)wcschr(v8, 59);
        if ( v19 || (v19 = v18) != 0 )
        {
          v20 = v36;
          v30 = v36;
          v21 = 0;
          v22 = v38;
          while ( 1 )
          {
            v23 = 0;
            if ( v8 > v19 )
              v24 = 0;
            else
              v24 = (unsigned int)(v19 - v8 + 1) >> 1;
            if ( v24 )
            {
              v25 = v22;
              do
              {
                v26 = *(_WORD *)v8;
                v8 += 2;
                ++v23;
                *v25++ = v26;
              }
              while ( v23 != v24 );
            }
            v38[v21 + v23] = 0;
            *(_WORD *)v20 = 2 * v23;
            *((_WORD *)v20 + 1) = 2 * v23 + 2;
            *((_DWORD *)v20 + 1) = v22;
            if ( *(_WORD *)v19 )
              v19 += 2;
            if ( !*(_WORD *)v19 )
              break;
            v8 = v19;
            v19 = (char *)wcschr(v19, 59);
            if ( !v19 )
              v19 = &v8[2 * wcslen((unsigned __int16 *)v8)];
            v21 += 64;
            ++v17;
            v20 = v30 + 8;
            v30 += 8;
            v22 += 64;
            if ( v21 >= 0xC0 || !v19 )
              goto LABEL_51;
          }
          ++v17;
LABEL_51:
          v6 = v28;
          v9 = v29;
        }
        if ( v16 )
          goto LABEL_54;
      }
      v17 = 0;
      if ( v16 )
LABEL_54:
        v27 = v36;
      else
        v27 = 0;
      if ( !dword_61D8A8 )
        return -1073741637;
      result = dword_61D8A8(7, v37, v9, *v31, v27, v17, 0);
      if ( result < 0 )
        return result;
      v28 = ++v6;
      if ( v6 >= v34 )
        return result;
      v4 = (unsigned int)v32;
    }
  }
  return -1073741811;
}
