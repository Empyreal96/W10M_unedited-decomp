// LocalGetStringForRelativeAttribute 
 
int __fastcall LocalGetStringForRelativeAttribute(unsigned int *a1, unsigned int a2, int a3, int a4, int a5, int a6, unsigned int *a7)
{
  unsigned int v9; // r5
  int v10; // r6
  unsigned int v11; // r7
  int v12; // r10
  unsigned int v13; // r5
  unsigned __int16 *v14; // r5
  char *v15; // r4
  unsigned int v16; // r3
  char *v17; // r9
  unsigned int v18; // r5
  unsigned int *v19; // r9
  unsigned int v20; // r3
  unsigned int v21; // r0
  _WORD *v22; // r0
  unsigned int *v23; // r9
  unsigned int v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r3
  _BYTE *v28; // r0
  int v29; // r2
  unsigned int v30; // r3
  unsigned int *v31; // r9
  unsigned int v32; // r3
  unsigned int *v33; // r9
  unsigned int v34; // r1
  unsigned int v35; // r0
  unsigned int *v36; // r9
  unsigned int v37; // r1
  unsigned int v38; // r0
  int v39; // r1
  unsigned int v40; // r5
  _WORD *v41; // r4
  _WORD *v42; // r5
  const __int16 *v43; // r3
  _WORD *v44; // r5
  unsigned int v45; // r0
  unsigned int v46; // r4
  _WORD *v47; // r9
  unsigned int *v48; // r1
  unsigned int v49; // r3
  int v50; // r0
  unsigned __int8 *i; // r4
  unsigned int v52; // t1
  unsigned int v53; // r10
  unsigned int *v54; // r5
  int v55; // r9
  unsigned int v56; // r4
  unsigned int *v57; // r10
  unsigned int v58; // r4
  int v59; // r9
  unsigned int v60; // r5
  _WORD *v61; // r9
  unsigned int *v62; // r5
  int v63; // r9
  unsigned int v64; // r4
  unsigned int *v65; // r5
  int v66; // r9
  unsigned int v67; // r4
  unsigned int v68; // r5
  char *v70; // [sp+8h] [bp-120h]
  unsigned int v71; // [sp+Ch] [bp-11Ch] BYREF
  _WORD *v72; // [sp+10h] [bp-118h] BYREF
  char *v73; // [sp+14h] [bp-114h] BYREF
  unsigned int v74; // [sp+18h] [bp-110h] BYREF
  unsigned __int16 *v75; // [sp+1Ch] [bp-10Ch] BYREF
  unsigned __int16 *v76; // [sp+20h] [bp-108h]
  int v77; // [sp+24h] [bp-104h]
  unsigned int *v78; // [sp+28h] [bp-100h]
  unsigned __int16 v79; // [sp+30h] [bp-F8h] BYREF
  char v80[68]; // [sp+32h] [bp-F6h] BYREF
  unsigned __int16 v81; // [sp+78h] [bp-B0h] BYREF
  char v82[138]; // [sp+7Ah] [bp-AEh] BYREF

  v78 = a7;
  v9 = 0;
  v75 = 0;
  v76 = 0;
  v79 = 0;
  memset(v80, 0, sizeof(v80));
  v81 = 0;
  memset(v82, 0, sizeof(v82));
  v73 = 0;
  v74 = 0;
  v70 = 0;
  v71 = 0;
  v72 = 0;
  if ( !a1 || !a2 || !a7 )
  {
    v10 = 87;
    v15 = 0;
    goto LABEL_114;
  }
  if ( a2 < 0x14 )
    return 1336;
  v11 = a1[3];
  v12 = *((unsigned __int16 *)a1 + 2);
  if ( !v11 )
    return 1336;
  ultow_s();
  v13 = *a1;
  if ( a2 < *a1 || a2 - v13 < 4 || RtlStringCbLengthW((int)a1 + v13, a2 - v13, &v72) < 0 || !v72 )
    return 1336;
  v10 = EncodeAttributeName((unsigned __int16 *)((char *)a1 + v13), (unsigned int)v72, (int *)&v75);
  v77 = v10;
  if ( v10 )
  {
    v76 = v75;
    goto LABEL_14;
  }
  v76 = v75;
  v14 = (unsigned __int16 *)(2 * wcslen(v75));
  v75 = v14;
  if ( RtlULongLongToULong(2 * v11, v11 >> 31, &v74) >= 0 )
  {
    v16 = v74 + 24;
    if ( v74 < 0xFFFFFFE8 )
    {
      v17 = (char *)v14 + v16;
      if ( (unsigned int)v14 + v16 >= v16 )
      {
        v18 = (unsigned int)&v17[2 * wcslen(&v79)];
        if ( v18 >= (unsigned int)v17 && RtlULongLongToULong(4 * v11, v11 >> 30, &v71) >= 0 )
        {
          if ( a2 - 16 < v71 )
            goto LABEL_26;
          if ( v12 != 1 )
          {
            switch ( v12 )
            {
              case 2:
                goto LABEL_62;
              case 3:
                v71 = 0;
                v31 = a1;
                while ( 1 )
                {
                  v32 = v31[4];
                  if ( a2 < v32 || a2 - v32 < 2 || RtlStringCbLengthW((int)a1 + v32, a2 - v32, &v72) < 0 )
                    goto LABEL_26;
                  if ( (unsigned int)v72 + v18 + 4 < v18 )
                    goto LABEL_13;
                  v18 += (unsigned int)(v72 + 2);
                  ++v31;
                  if ( ++v71 >= v11 )
                    goto LABEL_34;
                }
              case 5:
                v71 = 0;
                v23 = a1;
                while ( 1 )
                {
                  v24 = v23[4];
                  if ( a2 < v24 )
                    break;
                  if ( a2 - v24 < 4 )
                    break;
                  v25 = *(unsigned int *)((char *)a1 + v24);
                  v26 = v24 + 4;
                  if ( !v25 )
                    break;
                  v27 = a2 - v26;
                  if ( a2 - v26 < v25 )
                    break;
                  if ( v27 < 8 )
                    break;
                  v28 = (char *)a1 + v26;
                  v29 = *((unsigned __int8 *)a1 + v26 + 1);
                  if ( !v29 || v27 - 8 < 4 * v29 )
                    break;
                  v10 = LocalGetStringForSid(v28, &v73);
                  v77 = v10;
                  if ( v10 )
                  {
                    v15 = v73;
                    goto LABEL_116;
                  }
                  v70 = v73;
                  v30 = v18 + 2 * wcslen((unsigned __int16 *)v73);
                  if ( v30 < v18 )
                    goto LABEL_51;
                  v18 = v30;
                  if ( v70 )
                  {
                    ExFreePoolWithTag((unsigned int)v70);
                    v70 = 0;
                    v73 = 0;
                  }
                  ++v23;
                  if ( ++v71 >= v11 )
                    goto LABEL_34;
                }
                v10 = 1336;
LABEL_54:
                v15 = v70;
                goto LABEL_116;
              case 6:
LABEL_62:
                v71 = 0;
                v33 = a1;
                while ( 1 )
                {
                  v34 = v33[4];
                  if ( a2 < v34 || a2 - v34 < 8 )
                    break;
                  ui64tow_s();
                  v35 = wcslen(&v81);
                  if ( v18 + 2 * v35 < v18 )
                    goto LABEL_13;
                  v18 += 2 * v35;
                  ++v33;
                  if ( ++v71 >= v11 )
                    goto LABEL_34;
                }
                break;
              case 16:
                v71 = 0;
                v19 = a1;
                while ( 1 )
                {
                  v20 = v19[4];
                  if ( a2 < v20 )
                    break;
                  if ( a2 - v20 < 4 )
                    break;
                  v21 = *(unsigned int *)((char *)a1 + v20);
                  v74 = v21;
                  if ( a2 - v20 - 4 < v21 )
                    break;
                  if ( RtlULongLongToULong(4 * v21, v21 >> 30, &v74) < 0 || v74 + v18 < v18 )
                    goto LABEL_13;
                  v18 += v74;
                  ++v19;
                  if ( ++v71 >= v11 )
                    goto LABEL_34;
                }
                break;
            }
LABEL_26:
            v10 = 1336;
            goto LABEL_14;
          }
          v71 = 0;
          v36 = a1;
          do
          {
            v37 = v36[4];
            if ( a2 < v37 || a2 - v37 < 8 )
              goto LABEL_26;
            i64tow_s();
            v38 = wcslen(&v81);
            if ( v18 + 2 * v38 < v18 )
              goto LABEL_13;
            v18 += 2 * v38;
            ++v36;
            ++v71;
          }
          while ( v71 < v11 );
LABEL_34:
          if ( v18 + 3 < v18 )
          {
LABEL_51:
            v10 = 534;
            goto LABEL_54;
          }
          v22 = SddlpAlloc((v18 + 3) & 0xFFFFFFFC);
          v72 = v22;
          if ( !v22 )
          {
            v10 = 8;
            goto LABEL_54;
          }
          v40 = (unsigned int)v75;
          v39 = (int)v76;
          *v22 = 40;
          v41 = v22 + 2;
          v22[1] = 34;
          memmove((int)(v22 + 2), v39, v40);
          v42 = &v41[v40 >> 1];
          *v42 = 34;
          v42[1] = 44;
          switch ( v12 )
          {
            case 1:
              v43 = L"TI";
              break;
            case 2:
              v43 = L"TU";
              break;
            case 3:
              v43 = L"TS";
              break;
            case 5:
              v43 = L"TD";
              break;
            case 6:
              v43 = L"TB";
              break;
            default:
              v43 = L"TX";
              break;
          }
          *((_DWORD *)v42 + 1) = *(_DWORD *)v43;
          v44 = v42 + 4;
          *v44 = 44;
          v45 = wcslen(&v79);
          v44[1] = 48;
          v44[2] = 120;
          v44 += 3;
          v46 = v45;
          memmove((int)v44, (int)&v79, 2 * v45);
          v47 = &v44[v46];
          switch ( v12 )
          {
            case 1:
              v65 = a1;
              do
              {
                *v47 = 44;
                v66 = (int)(v47 + 1);
                i64tow_s();
                v67 = wcslen(&v81);
                memmove(v66, (int)&v81, 2 * v67);
                ++v65;
                --v11;
                v47 = (_WORD *)(v66 + 2 * v67);
              }
              while ( v11 );
              goto LABEL_110;
            case 2:
              goto LABEL_105;
            case 3:
              v57 = a1;
              do
              {
                *v47 = 44;
                v47[1] = 34;
                v58 = v57[4];
                v59 = (int)(v47 + 2);
                v60 = wcslen((unsigned __int16 *)((char *)a1 + v58));
                memmove(v59, (int)a1 + v58, 2 * v60);
                v61 = (_WORD *)(v59 + 2 * v60);
                *v61 = 34;
                v47 = v61 + 1;
                ++v57;
                --v11;
              }
              while ( v11 );
              goto LABEL_110;
          }
          if ( v12 != 5 )
          {
            if ( v12 != 6 )
            {
              v48 = a1;
              do
              {
                *v47++ = 44;
                v49 = v48[4];
                v50 = *(unsigned int *)((char *)a1 + v49);
                for ( i = (unsigned __int8 *)a1 + v49 + 4; v50; v47 += 2 )
                {
                  v52 = *i++;
                  --v50;
                  *v47 = a0123456789abcd[v52 >> 4];
                  v47[1] = a0123456789abcd[v52 & 0xF];
                }
                ++v48;
                --v11;
              }
              while ( v11 );
              goto LABEL_111;
            }
LABEL_105:
            v62 = a1;
            do
            {
              *v47 = 44;
              v63 = (int)(v47 + 1);
              ui64tow_s();
              v64 = wcslen(&v81);
              memmove(v63, (int)&v81, 2 * v64);
              ++v62;
              --v11;
              v47 = (_WORD *)(v63 + 2 * v64);
            }
            while ( v11 );
LABEL_110:
            v10 = v77;
LABEL_111:
            *v47 = 41;
            v68 = (unsigned int)v72;
            v47[1] = 0;
            *v78 = v68;
            goto LABEL_54;
          }
          v53 = 0;
          v54 = a1;
          while ( 1 )
          {
            *v47 = 44;
            v55 = (int)(v47 + 1);
            v10 = LocalGetStringForSid((_BYTE *)a1 + v54[4] + 4, &v73);
            if ( v10 )
              break;
            v70 = v73;
            v56 = wcslen((unsigned __int16 *)v73);
            memmove(v55, (int)v70, 2 * v56);
            v47 = (_WORD *)(v55 + 2 * v56);
            if ( v70 )
            {
              ExFreePoolWithTag((unsigned int)v70);
              v70 = 0;
              v73 = 0;
            }
            ++v53;
            ++v54;
            if ( v53 >= v11 )
              goto LABEL_111;
          }
          v9 = (unsigned int)v72;
          v15 = v73;
LABEL_114:
          if ( v9 )
            ExFreePoolWithTag(v9);
          goto LABEL_116;
        }
      }
    }
  }
LABEL_13:
  v10 = 534;
LABEL_14:
  v15 = 0;
LABEL_116:
  if ( v76 )
    ExFreePoolWithTag((unsigned int)v76);
  if ( v15 )
    ExFreePoolWithTag((unsigned int)v15);
  return v10;
}
