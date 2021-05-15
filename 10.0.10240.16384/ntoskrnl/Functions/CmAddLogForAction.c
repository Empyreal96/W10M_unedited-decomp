// CmAddLogForAction 
 
int __fastcall CmAddLogForAction(_DWORD *a1)
{
  int v2; // r0
  unsigned int v3; // r6
  unsigned int v4; // r10
  int v5; // r9
  int v6; // r3
  int v7; // r4
  unsigned __int16 *v8; // r8
  int v9; // r0
  int v10; // r1
  unsigned int v11; // r2
  int v12; // r5
  unsigned int v13; // r1
  int v14; // r4
  int v15; // r0
  unsigned int v16; // r5
  unsigned int v17; // r5
  unsigned int v18; // r3
  int v19; // r4
  int v20; // r3
  int v21; // r0
  int v22; // r0
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r0
  int v29; // r3
  unsigned int v30; // r2
  int v31; // r3
  int v32; // r3
  _WORD *v33; // r5
  unsigned int v34; // r4
  int v35; // r1
  unsigned int v36; // r2
  int v37; // r1
  int v38; // r1
  unsigned int v39; // r5
  int v40; // r2
  _WORD *v41; // r0
  int v42; // r3
  int v43; // r10
  int v44; // r1
  int v45; // r0
  unsigned int v46; // r5
  char v48[4]; // [sp+10h] [bp-58h] BYREF
  unsigned int v49; // [sp+14h] [bp-54h]
  unsigned int v50; // [sp+18h] [bp-50h] BYREF
  unsigned int v51; // [sp+1Ch] [bp-4Ch]
  int v52; // [sp+20h] [bp-48h]
  int v53; // [sp+24h] [bp-44h]
  int v54; // [sp+28h] [bp-40h] BYREF
  unsigned int v55; // [sp+2Ch] [bp-3Ch] BYREF
  unsigned int v56; // [sp+30h] [bp-38h] BYREF
  int v57; // [sp+34h] [bp-34h] BYREF
  int v58; // [sp+38h] [bp-30h]
  int v59; // [sp+3Ch] [bp-2Ch] BYREF
  int v60[10]; // [sp+40h] [bp-28h] BYREF

  v2 = a1[6];
  v3 = 0;
  v53 = 0;
  v54 = -1;
  v50 = 0;
  v51 = 0;
  v49 = 0;
  v57 = -1;
  v4 = 0;
  v5 = 0;
  v6 = *(_DWORD *)(*(_DWORD *)(v2 + 20) + 3256);
  v52 = -1;
  v55 = -1163005939;
  v56 = -1163005939;
  v59 = v6;
  if ( !*(_DWORD *)(v6 + 56) || !*(_DWORD *)(a1[7] + 24) || a1[9] == 13 )
    return 0;
  v8 = (unsigned __int16 *)CmpConstructName(v2);
  if ( !v8 )
    return -1073741670;
  v9 = a1[6];
  v10 = a1[9];
  v11 = 0;
  v12 = *(_DWORD *)(v9 + 20);
  v58 = v12;
  switch ( v10 )
  {
    case 0:
    case 2:
      v13 = 52;
      v11 = *(_DWORD *)(*(_DWORD *)(v9 + 48) + 16) + 52;
      goto LABEL_36;
    case 4:
    case 5:
    case 6:
      v14 = 60;
      if ( v10 == 4 || v10 == 5 )
      {
        v52 = a1[13];
        v15 = (*(int (__fastcall **)(int, int, int *))(v12 + 4))(v12, v52, &v54);
        v5 = v15;
        if ( !v15 )
          goto LABEL_12;
        v16 = *(_DWORD *)(v15 + 4);
        v51 = v16;
        if ( v16 >= 0x80000000 )
        {
          v16 += 0x80000000;
          v51 = v16;
        }
        v14 = v16 + 60;
        v50 = v16;
        if ( v16 >= 0xFFFFFFC4 )
        {
          v7 = -1073741675;
          goto LABEL_77;
        }
        v13 = v16 + 60;
      }
      else
      {
        v52 = a1[12];
        v5 = (*(int (__fastcall **)(int, int, int *))(v12 + 4))(v12, v52, &v54);
        if ( !v5 )
        {
LABEL_12:
          v7 = -1073741670;
          goto LABEL_81;
        }
        v13 = 60;
      }
      if ( (*(_WORD *)(v5 + 16) & 1) != 0 )
        v17 = (unsigned __int16)(2 * *(_WORD *)(v5 + 2));
      else
        v17 = *(unsigned __int16 *)(v5 + 2);
      v49 = v17;
      v11 = v14 + v17;
LABEL_36:
      if ( v11 >= v13 )
      {
LABEL_25:
        v18 = *v8;
        v19 = v18 + v11;
        if ( v18 + v11 >= v18 )
        {
          v22 = ExAllocatePoolWithTag(1, v19, 538987843);
          v3 = v22;
          if ( v22 )
          {
            *(_DWORD *)(v22 + 4) = v19;
            *(_DWORD *)(v22 + 8) = 1;
            v23 = *(_DWORD *)(a1[7] + 44);
            v24 = *(_DWORD *)(a1[7] + 48);
            v25 = *(_DWORD *)(a1[7] + 52);
            *(_DWORD *)(v22 + 16) = *(_DWORD *)(a1[7] + 40);
            *(_DWORD *)(v22 + 20) = v23;
            *(_DWORD *)(v22 + 24) = v24;
            *(_DWORD *)(v22 + 28) = v25;
            *(_WORD *)(v22 + 32) = *v8;
            *(_WORD *)(v22 + 34) = v8[1];
            v26 = a1[9];
            switch ( v26 )
            {
              case 0:
              case 2:
                if ( v26 )
                  *(_DWORD *)(v22 + 12) = 2;
                else
                  *(_DWORD *)(v22 + 12) = 1;
                v27 = a1[10];
                *(_DWORD *)(v22 + 36) = v22 + 52;
                *(_DWORD *)(v22 + 40) = v27;
                memmove(v22 + 52, *((_DWORD *)v8 + 1), *v8);
                v28 = *v8 + v3 + 52;
                *(_DWORD *)(v3 + 48) = v28;
                v29 = *(_DWORD *)(a1[6] + 48);
                v30 = *(_DWORD *)(v29 + 16);
                goto LABEL_45;
              case 4:
              case 5:
              case 6:
                v56 = -1;
                if ( v26 == 4 )
                {
                  v31 = 3;
                }
                else if ( v26 == 5 )
                {
                  v31 = 4;
                }
                else
                {
                  v31 = 5;
                }
                *(_DWORD *)(v22 + 12) = v31;
                v32 = *(_DWORD *)(v5 + 12);
                *(_DWORD *)(v22 + 36) = v22 + 60;
                *(_DWORD *)(v22 + 48) = v32;
                memmove(v22 + 60, *((_DWORD *)v8 + 1), *v8);
                v33 = (_WORD *)(*v8 + v3 + 60);
                *(_DWORD *)(v3 + 44) = v33;
                v34 = v49;
                if ( (*(_WORD *)(v5 + 16) & 1) != 0 )
                  CmpCopyCompressedName(v33, v49, v5 + 20, *(unsigned __int16 *)(v5 + 2));
                else
                  memmove((int)v33, v5 + 20, v49);
                *(_WORD *)(v3 + 42) = v49;
                *(_WORD *)(v3 + 40) = v34;
                if ( a1[9] == 6 )
                {
                  *(_DWORD *)(v3 + 52) = 0;
                  *(_DWORD *)(v3 + 56) = 0;
                }
                else
                {
                  v35 = v52;
                  *(_DWORD *)(v3 + 52) = v51;
                  if ( !CmpGetValueData(*(_DWORD *)(a1[6] + 20), v35, v5, &v50, (int *)&v55, v48, (int)&v56) )
                    goto LABEL_39;
                  v36 = v50;
                  v37 = v55;
                  *(_DWORD *)(v3 + 56) = (char *)v33 + v34;
                  memmove((int)v33 + v34, v37, v36);
                  if ( v48[0] == 1 )
                    ExFreePoolWithTag(v55);
                  else
                    (*(void (__fastcall **)(_DWORD, unsigned int *))(*(_DWORD *)(a1[6] + 20) + 8))(
                      *(_DWORD *)(a1[6] + 20),
                      &v56);
                }
LABEL_67:
                *(_DWORD *)v3 = HvBufferCheckSum(v3, *(_DWORD *)(v3 + 4));
                if ( ClfsLsnInvalid(a1[7] + 56) )
                  v42 = 2;
                else
                  v42 = 0;
                v43 = v59;
                v7 = CmpTransWriteLog(v59, v3, *(_DWORD *)(v3 + 4), v42, v60);
                if ( v7 >= 0 && ClfsLsnInvalid(a1[7] + 56) )
                {
                  v44 = a1[7];
                  *(_DWORD *)(v44 + 56) = v60[0];
                  *(_DWORD *)(v44 + 60) = v60[1];
                }
                v59 = 120;
                v45 = ExAllocatePoolWithTag(1, 120, 538987843);
                v46 = v45;
                if ( v45 )
                {
                  ClfsGetLogFileInformation(*(_DWORD *)(v43 + 52), v45, &v59);
                  ExFreePoolWithTag(v46);
                }
                break;
              case 7:
                *(_DWORD *)(v22 + 12) = 6;
                *(_DWORD *)(v22 + 36) = v22 + 44;
                memmove(v22 + 44, *((_DWORD *)v8 + 1), *v8);
                *(_DWORD *)(v3 + 40) = a1[12];
                goto LABEL_67;
              case 8:
                *(_DWORD *)(v22 + 12) = 7;
                *(_DWORD *)(v22 + 36) = v22 + 48;
                memmove(v22 + 48, *((_DWORD *)v8 + 1), *v8);
                *(_DWORD *)(v3 + 40) = a1[12];
                *(_DWORD *)(v3 + 44) = a1[13];
                goto LABEL_67;
              case 9:
                *(_DWORD *)(v22 + 12) = 8;
                *(_DWORD *)(v22 + 36) = v22 + 48;
                memmove(v22 + 48, *((_DWORD *)v8 + 1), *v8);
                v38 = v58;
                v39 = v56;
                v30 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v58 + 2004) + 8 * v56 + 4) + 16);
                *(_DWORD *)(v3 + 40) = v30;
                v28 = *v8 + v3 + 48;
                *(_DWORD *)(v3 + 44) = v28;
                v29 = *(_DWORD *)(*(_DWORD *)(v38 + 2004) + 8 * v39 + 4);
LABEL_45:
                memmove(v28, v29 + 24, v30);
                goto LABEL_67;
              case 11:
                *(_DWORD *)(v22 + 12) = 9;
                *(_DWORD *)(v22 + 36) = v22 + 48;
                memmove(v22 + 48, *((_DWORD *)v8 + 1), *v8);
                v40 = v53;
                v41 = (_WORD *)(*v8 + v3 + 48);
                *(_DWORD *)(v3 + 44) = v41;
                if ( (*(_WORD *)(v40 + 2) & 0x20) != 0 )
                  CmpCopyCompressedName(v41, v4, v40 + 76, *(unsigned __int16 *)(v40 + 72));
                else
                  memmove((int)v41, v40 + 76, v4);
                *(_WORD *)(v3 + 42) = v4;
                *(_WORD *)(v3 + 40) = v4;
                goto LABEL_67;
              default:
                goto LABEL_67;
            }
          }
          else
          {
LABEL_39:
            v7 = -1073741670;
          }
        }
        else
        {
          v7 = -1073741562;
        }
      }
      else
      {
        v7 = -1073741675;
      }
      if ( v53 )
        (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1[12] + 20) + 8))(*(_DWORD *)(a1[12] + 20), &v57);
LABEL_77:
      if ( v5 )
        (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1[6] + 20) + 8))(*(_DWORD *)(a1[6] + 20), &v54);
      if ( v3 )
        ExFreePoolWithTag(v3);
LABEL_81:
      ExFreePoolWithTag((unsigned int)v8);
      break;
    case 7:
      v11 = 44;
      goto LABEL_25;
    case 8:
      v11 = 48;
      goto LABEL_25;
    case 9:
      if ( !CmpFindSecurityCellCacheIndex((_DWORD *)v12, a1[12], (int *)&v55) )
        goto LABEL_12;
      v20 = *(_DWORD *)(v12 + 2004);
      v56 = v55;
      v11 = *(_DWORD *)(*(_DWORD *)(v20 + 8 * v55 + 4) + 16) + 48;
      goto LABEL_35;
    case 11:
      v21 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(a1[12] + 20) + 4))(
              *(_DWORD *)(a1[12] + 20),
              *(_DWORD *)(a1[12] + 24),
              &v57);
      v53 = v21;
      if ( !v21 )
        goto LABEL_12;
      if ( (*(_WORD *)(v21 + 2) & 0x20) != 0 )
        v4 = (unsigned __int16)(2 * *(_WORD *)(v21 + 72));
      else
        v4 = *(unsigned __int16 *)(v21 + 72);
      v11 = v4 + 48;
LABEL_35:
      v13 = 48;
      goto LABEL_36;
    default:
      goto LABEL_25;
  }
  return v7;
}
