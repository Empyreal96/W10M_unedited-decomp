// CmpPreserveSystemHiveData 
 
int __fastcall CmpPreserveSystemHiveData(int a1, int a2)
{
  unsigned __int16 *v4; // r9
  int v5; // r3
  int v6; // r10
  int v7; // r3
  int v8; // r8
  int v9; // r0
  int (__fastcall *v10)(int, int, int *); // r3
  int v11; // r4
  int v12; // r0
  int v13; // r6
  unsigned __int16 **v14; // r9
  int v15; // r4
  unsigned __int16 *v16; // t1
  int v17; // r10
  int v18; // r0
  int v19; // r0
  int v20; // r9
  int v21; // r0
  int v22; // r3
  int v23; // r4
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r6
  _WORD *v27; // r4
  unsigned int v28; // r2
  unsigned int v29; // r6
  int v30; // r0
  int *v31; // r6
  int v32; // r8
  unsigned int v33; // r0
  unsigned int v34; // r6
  int *v35; // r4
  int v36; // r8
  int v37; // r0
  int v38; // r0
  int v39; // r3
  int v40; // r0
  int v41; // r0
  _DWORD *v42; // r1
  unsigned int v43; // r9
  int v44; // r0
  int v45; // r0
  BOOL v46; // r4
  unsigned int v47; // r8
  int *v48; // r6
  int v49; // r0
  int v50; // r4
  int v51; // r3
  unsigned int v52; // r4
  _DWORD *v53; // r0
  unsigned __int16 *v55; // [sp+10h] [bp-B8h]
  int v56; // [sp+14h] [bp-B4h] BYREF
  int v57; // [sp+18h] [bp-B0h] BYREF
  int v58; // [sp+1Ch] [bp-ACh] BYREF
  _DWORD *v59; // [sp+20h] [bp-A8h]
  int v60; // [sp+24h] [bp-A4h] BYREF
  int v61; // [sp+28h] [bp-A0h] BYREF
  int v62; // [sp+2Ch] [bp-9Ch] BYREF
  int v63; // [sp+30h] [bp-98h] BYREF
  int v64; // [sp+34h] [bp-94h]
  int v65[2]; // [sp+38h] [bp-90h] BYREF
  int v66[2]; // [sp+40h] [bp-88h] BYREF
  int v67[11]; // [sp+48h] [bp-80h] BYREF
  char v68; // [sp+74h] [bp-54h]
  const __int16 *v69; // [sp+78h] [bp-50h]
  const __int16 *v70; // [sp+7Ch] [bp-4Ch]
  int v71; // [sp+80h] [bp-48h]
  int v72; // [sp+84h] [bp-44h]
  int v73; // [sp+88h] [bp-40h]
  int v74; // [sp+8Ch] [bp-3Ch]
  int v75; // [sp+90h] [bp-38h]
  int v76; // [sp+94h] [bp-34h]
  int v77; // [sp+98h] [bp-30h]
  int v78; // [sp+9Ch] [bp-2Ch]
  int v79; // [sp+A0h] [bp-28h]
  char v80; // [sp+A4h] [bp-24h]

  v65[0] = (int)L"WPA";
  v56 = -1;
  v67[0] = (int)L"Control\\FastCache";
  v67[1] = 0;
  v67[2] = -1;
  v67[3] = 0;
  v67[4] = -1;
  v67[5] = -1;
  v67[6] = 0;
  v67[7] = -1;
  v67[8] = 0;
  v67[9] = -1;
  v67[10] = 0;
  v68 = 0;
  v62 = -1;
  v63 = -1;
  v66[0] = -1;
  v69 = L"Control\\ProductOptions";
  v60 = -1;
  v61 = -1;
  v58 = -1;
  v70 = L"ProductPolicy";
  v71 = -1;
  v72 = 0;
  v73 = -1;
  v74 = -1;
  v75 = 0;
  v76 = -1;
  v77 = 0;
  v78 = -1;
  v79 = 0;
  v80 = 0;
  v4 = 0;
  v55 = 0;
  v64 = 0;
  v5 = *(_DWORD *)(a1 + 32);
  v59 = 0;
  v6 = *(_DWORD *)(v5 + 36);
  v7 = *(_DWORD *)(a2 + 32);
  v57 = v6;
  v8 = *(_DWORD *)(v7 + 36);
  if ( v6 == -1 || v8 == -1 )
  {
    v15 = -1073741492;
    goto LABEL_29;
  }
  v9 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v6, &v62);
  v10 = *(int (__fastcall **)(int, int, int *))(a2 + 4);
  v11 = v9;
  v64 = v9;
  v12 = v10(a2, v8, &v63);
  v59 = (_DWORD *)v12;
  if ( !v11 || !v12 )
  {
    v15 = -1073741670;
    goto LABEL_29;
  }
  v13 = 0;
  v14 = (unsigned __int16 **)v65;
  do
  {
    v16 = *v14++;
    v15 = (int)v16;
    v17 = CmpWalkPath(a1, v6, v16);
    v18 = CmpWalkPath(a2, v8, v16);
    if ( v17 == -1 || v18 == -1 || !CmpCopySyncTree(a1, v17, a2, v18) )
    {
      v15 = -1073741492;
      goto LABEL_73;
    }
    ++v13;
    v6 = v57;
  }
  while ( !v13 );
  v19 = CmpWalkPath(a1, v57, L"CurrentControlSet");
  if ( v19 == -1 )
    v15 = 0;
  v20 = v19;
  if ( v19 == -1 )
    goto LABEL_73;
  v21 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v19, &v61);
  if ( !v21 )
    goto LABEL_14;
  v23 = CmpFindValueByName(a1, v21, (int)CmSymbolicLinkValueName, v22);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v61);
  if ( v23 != -1 )
  {
    v24 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v23, &v58);
    v25 = v24;
    if ( v24 )
    {
      if ( *(_DWORD *)(v24 + 12) == 6 )
      {
        v26 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v24 + 8), &v60);
        if ( !v26 )
        {
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v58);
LABEL_14:
          v15 = -1073741670;
LABEL_73:
          v4 = 0;
          goto LABEL_29;
        }
        v27 = (_WORD *)(*(_DWORD *)(v25 + 4) + v26 - 2);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v58);
        v28 = 0;
        while ( *v27 != 92 && (unsigned int)v27 >= v26 )
        {
          ++v28;
          --v27;
        }
        v29 = v28;
        v30 = ExAllocatePoolWithTag(1, 2 * v28 + 2, 1750093123);
        v4 = (unsigned __int16 *)v30;
        v55 = (unsigned __int16 *)v30;
        if ( !v30 )
        {
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v60);
          v15 = -1073741801;
          goto LABEL_29;
        }
        memmove(v30, (int)(v27 + 1), v29 * 2);
        v4[v29] = 0;
        v20 = CmpWalkPath(a1, v6, v4);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v60);
        if ( v20 == -1 )
          goto LABEL_27;
      }
      else
      {
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v58);
      }
    }
  }
  v34 = 0;
  v35 = v67;
  v36 = 0;
  do
  {
    v37 = CmpWalkPath(a1, v20, (unsigned __int16 *)*v35);
    v35[2] = v37;
    if ( v37 != -1 )
    {
      if ( v35[1] )
      {
        v38 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v37, v35 + 4);
        v35[3] = v38;
        if ( !v38 )
          goto LABEL_53;
        RtlInitUnicodeString((unsigned int)v65, (unsigned __int16 *)v35[1]);
        v40 = CmpFindValueByName(a1, v35[3], (int)v65, v39);
        v35[5] = v40;
        if ( v40 != -1 )
        {
          v36 = 1;
          v41 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v40, v35 + 7);
          v35[6] = v41;
          if ( !v41 )
            goto LABEL_53;
          if ( !CmpGetValueData(a1, v35[5], v41, (unsigned int *)v35 + 10, v35 + 8, (_BYTE *)v35 + 44, (int)(v35 + 9)) )
          {
            v15 = -1073741492;
            goto LABEL_28;
          }
        }
      }
      else
      {
        v36 = 1;
      }
    }
    ++v34;
    v35 += 12;
  }
  while ( v34 < 2 );
  if ( v36 )
  {
    v42 = v59;
    v43 = 0;
    if ( v59[5] )
    {
      while ( 1 )
      {
        CmpFindSubKeyByNumber(a2, v42, v43, &v57);
        v44 = (*(int (__fastcall **)(int, int, int *))(a2 + 4))(a2, v57, &v56);
        if ( !v44 )
          break;
        if ( *(_WORD *)(v44 + 72) == 13 )
        {
          if ( (*(_WORD *)(v44 + 2) & 0x20) != 0 )
            v45 = strnicmp((unsigned __int8 *)(v44 + 76), "ControlSet000", 10);
          else
            v45 = wcsnicmp(v44 + 76, L"ControlSet000", 10);
          v46 = v45 == 0;
          (*(void (__fastcall **)(int, int *))(a2 + 8))(a2, &v56);
          if ( v46 )
          {
            v47 = 0;
            v48 = v67;
            do
            {
              if ( v48[2] != -1 && (!v48[1] || v48[5] != -1) )
              {
                v49 = CmpWalkPath(a2, v57, (unsigned __int16 *)*v48);
                if ( v49 != -1 )
                {
                  if ( v48[1] )
                  {
                    v50 = (*(int (__fastcall **)(int, int, int *))(a2 + 4))(a2, v49, &v56);
                    if ( !v50 )
                      goto LABEL_53;
                    RtlInitUnicodeString((unsigned int)v65, (unsigned __int16 *)v48[1]);
                    v52 = CmpFindValueByName(a2, v50, (int)v65, v51);
                    (*(void (__fastcall **)(int, int *))(a2 + 8))(a2, &v56);
                    if ( v52 != -1 )
                    {
                      v53 = (_DWORD *)(*(int (__fastcall **)(int, unsigned int, int *))(a2 + 4))(a2, v52, v66);
                      if ( !v53 )
                        goto LABEL_53;
                      v15 = CmpSetValueKeyExisting(a2, v52, v53, *(_DWORD *)(v48[6] + 12), v48[8], v48[10], v52 >> 31);
                      (*(void (__fastcall **)(int, int *))(a2 + 8))(a2, v66);
                      if ( v15 < 0 )
                        goto LABEL_28;
                    }
                  }
                  else
                  {
                    CmpCopySyncTree(a1, v48[2], a2, v49);
                  }
                }
              }
              ++v47;
              v48 += 12;
            }
            while ( v47 < 2 );
          }
        }
        else
        {
          (*(void (__fastcall **)(int, int *))(a2 + 8))(a2, &v56);
        }
        v42 = v59;
        if ( ++v43 >= v59[5] )
          goto LABEL_27;
      }
LABEL_53:
      v15 = -1073741670;
      goto LABEL_28;
    }
  }
LABEL_27:
  v15 = 0;
LABEL_28:
  v4 = v55;
LABEL_29:
  v31 = v67;
  v32 = 2;
  do
  {
    if ( v31[3] )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v31 + 4);
    if ( v31[6] )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v31 + 7);
    v33 = v31[8];
    if ( v33 )
    {
      if ( *((_BYTE *)v31 + 44) )
        ExFreePoolWithTag(v33);
      else
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v31 + 9);
    }
    v31 += 12;
    --v32;
  }
  while ( v32 );
  if ( v64 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v62);
  if ( v59 )
    (*(void (__fastcall **)(int, int *))(a2 + 8))(a2, &v63);
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  return v15;
}
