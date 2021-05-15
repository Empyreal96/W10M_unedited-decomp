// EtwpValidatePayloadFilter 
 
int __fastcall EtwpValidatePayloadFilter(unsigned int a1, unsigned __int16 *a2, unsigned int a3)
{
  int v5; // r1
  unsigned int v6; // r9
  int v7; // r0
  int v8; // r3
  unsigned int v9; // r1
  int v10; // r6
  int v11; // r3
  int v12; // r10
  int v13; // r7
  int v14; // r3
  int v15; // lr
  int v16; // r3
  int v17; // r8
  int v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r1
  unsigned __int16 *v21; // r10
  unsigned __int8 *v22; // r6
  _WORD *v23; // r7
  unsigned int v24; // lr
  int v25; // r0
  unsigned __int16 *v26; // r5
  int v27; // r8
  int v28; // r1
  unsigned int v29; // r0
  int v30; // r2
  char v31; // r1
  int v32; // t1
  unsigned int v33; // r8
  unsigned int v34; // r1
  __int16 v35; // r2
  unsigned int v36; // r7
  unsigned int v37; // r6
  unsigned int v38; // r2
  int v39; // r3
  int v40; // r1
  char *v41; // r0
  char *v42; // r2
  char *v43; // r2
  char *v44; // r3
  int v45; // r1
  char *v46; // r0
  char *v47; // r2
  char *v48; // r2
  char *v49; // r3
  __int64 v50; // r2
  int v52; // [sp+0h] [bp-68h]
  int v53; // [sp+4h] [bp-64h]
  int v54; // [sp+8h] [bp-60h]
  char *v55; // [sp+Ch] [bp-5Ch]
  int v56; // [sp+10h] [bp-58h]
  int v57; // [sp+14h] [bp-54h]
  int v58; // [sp+18h] [bp-50h]
  char *v59; // [sp+1Ch] [bp-4Ch]
  _WORD *v60; // [sp+20h] [bp-48h]
  int v61; // [sp+24h] [bp-44h]
  int v62; // [sp+28h] [bp-40h]
  unsigned __int8 *v63; // [sp+2Ch] [bp-3Ch]
  unsigned int v64; // [sp+30h] [bp-38h]
  unsigned int v65; // [sp+38h] [bp-30h]
  unsigned int v66; // [sp+3Ch] [bp-2Ch]
  unsigned __int8 *v67; // [sp+40h] [bp-28h]
  unsigned int v68; // [sp+44h] [bp-24h]

  if ( a3 >= 0x50 && a2[1] == a3 && a3 <= 0x1000 )
  {
    v5 = *a2;
    if ( (*a2 & 0xFFF) == 2662 && (v5 & 0xFFFFF000) == 4096 )
    {
      v6 = a2[2];
      if ( v6 <= 0xAA && !a2[3] && !memcmp(a1, (unsigned int)(a2 + 8), 16) )
      {
        v7 = a2[16];
        v8 = 24 * v6 + 56;
        if ( v7 == v8 )
        {
          v9 = a2[17];
          v10 = a2[18];
          v11 = v8 + v9;
          if ( v10 == v11 )
          {
            v12 = a2[19];
            v13 = a2[20];
            v14 = v11 + v12;
            if ( v13 == v14 )
            {
              v15 = a2[22];
              v16 = v14 + a2[21];
              if ( v15 == v16 )
              {
                v17 = a2[24];
                v18 = v16 + a2[23];
                v64 = a2[23];
                if ( v17 == v18 && a3 == v18 + a2[25] )
                {
                  v19 = v9 / 0xC;
                  v68 = v9 / 0xC;
                  if ( !(v9 % 0xC) && (v12 & 3) == 0 )
                  {
                    v20 = a2[21];
                    if ( (v20 & 3) == 0
                      && (v64 & 1) == 0
                      && (v7 & 3) == 0
                      && (v10 & 3) == 0
                      && (v13 & 3) == 0
                      && (v15 & 3) == 0 )
                    {
                      v57 = 0;
                      v58 = 0;
                      v56 = 0;
                      v53 = 0;
                      v54 = 0;
                      v59 = (char *)a2 + v15;
                      v55 = (char *)a2 + v17;
                      v21 = (unsigned __int16 *)((char *)a2 + v7);
                      v22 = (unsigned __int8 *)a2 + v10;
                      v23 = (unsigned __int16 *)((char *)a2 + v13);
                      v24 = a2[19];
                      v25 = 0;
                      v65 = 0;
                      v26 = a2 + 28;
                      v63 = v22;
                      v60 = v23;
                      v27 = 0;
                      if ( v19 )
                      {
                        while ( 1 )
                        {
                          v28 = *v21 % 63;
                          v61 = v25 | (1 << (v28 - 32));
                          v62 = v27 | (1 << v28);
                          if ( v21[2] != v56 )
                            break;
                          v29 = v21[3];
                          v66 = v29;
                          v67 = v22;
                          v56 += v29;
                          v30 = 0;
                          if ( v21[3] )
                          {
                            while ( *((unsigned __int16 *)v22 + 1) < 0x40u )
                            {
                              if ( v22[1] >= 0x40u )
                                break;
                              v32 = *v22;
                              v22 += 4;
                              v31 = v32;
                              v63 = v22;
                              if ( (v32 & 0xFFFFFFC0) != 0 || (v31 & 0xFu) >= 9 )
                                break;
                              if ( ++v30 >= v29 )
                                goto LABEL_31;
                            }
                            return -1073741811;
                          }
LABEL_31:
                          if ( v21[4] != v57 )
                            return -1073741811;
                          v33 = v21[5];
                          v34 = 0;
                          v52 = 0;
                          v57 += v33;
                          if ( v21[5] )
                          {
                            while ( 1 )
                            {
                              v35 = *v23;
                              if ( (*v23 & 0xFCu) > 0x20 || (unsigned __int16)v23[1] != v58 )
                                return -1073741811;
                              v36 = (unsigned __int8)v35 >> 2;
                              v58 += v36;
                              v37 = 0;
                              if ( (unsigned __int8)v35 >> 2 )
                              {
                                while ( 1 )
                                {
                                  v38 = *v26;
                                  if ( v38 >= v24 >> 2 || v38 >= v29 || v38 > *((unsigned __int8 *)v21 + 3) )
                                    return -1073741811;
                                  v39 = v67[4 * v38] & 0xF;
                                  if ( v39 == 3 )
                                    break;
                                  if ( v39 == 4 )
                                  {
                                    v40 = v54;
                                    if ( *((_QWORD *)v26 + 1) != v54 || *((_QWORD *)v26 + 2) )
                                      return -1073741811;
                                    v41 = (char *)a2 + a2[23] + a2[22];
                                    v42 = v59;
                                    if ( *(_WORD *)v59 )
                                    {
                                      do
                                      {
                                        if ( v42 >= v41 - 2 )
                                          break;
                                        v42 += 2;
                                      }
                                      while ( *(_WORD *)v42 );
                                      v40 = v54;
                                    }
                                    v43 = v42 + 2;
                                    if ( v43 > v41 )
                                      return -1073741811;
                                    v44 = v59;
                                    v59 = v43;
                                    v54 = v40 + ((v43 - v44) >> 1);
LABEL_57:
                                    v29 = v66;
                                  }
                                  ++v37;
                                  v26 += 12;
                                  if ( v37 >= v36 )
                                  {
                                    v34 = v52;
                                    goto LABEL_60;
                                  }
                                }
                                v45 = v53;
                                if ( *((_QWORD *)v26 + 1) != v53 || *((_QWORD *)v26 + 2) )
                                  return -1073741811;
                                v46 = (char *)a2 + a2[24] + a2[25];
                                v47 = v55;
                                if ( *v55 )
                                {
                                  do
                                  {
                                    if ( v47 >= v46 - 1 )
                                      break;
                                    ++v47;
                                  }
                                  while ( *v47 );
                                  v45 = v53;
                                }
                                v48 = v47 + 1;
                                if ( v48 > v46 )
                                  return -1073741811;
                                v49 = v55;
                                v55 = v48;
                                v53 = v45 + v48 - v49;
                                goto LABEL_57;
                              }
LABEL_60:
                              v52 = ++v34;
                              v23 = v60 + 2;
                              v60 += 2;
                              if ( v34 >= v33 )
                              {
                                v22 = v63;
                                break;
                              }
                            }
                          }
                          v27 = v62;
                          ++v65;
                          v25 = v61;
                          v21 += 6;
                          if ( v65 >= v68 )
                          {
                            v20 = a2[21];
                            goto LABEL_64;
                          }
                        }
                      }
                      else
                      {
LABEL_64:
                        LODWORD(v50) = *((_DWORD *)a2 + 3);
                        HIDWORD(v50) = *((_DWORD *)a2 + 2);
                        if ( __PAIR64__(v27, v25) == v50
                          && v58 == v6
                          && v56 == v24 >> 2
                          && v57 == v20 >> 2
                          && v54 == v64 >> 1
                          && v53 == a2[25] )
                        {
                          return 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -1073741811;
}
