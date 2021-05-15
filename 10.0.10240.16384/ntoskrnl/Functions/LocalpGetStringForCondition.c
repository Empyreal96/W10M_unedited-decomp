// LocalpGetStringForCondition 
 
int __fastcall LocalpGetStringForCondition(int *a1, unsigned int a2, _DWORD *a3, int a4, int a5, int a6, int a7, unsigned __int8 a8)
{
  int v8; // lr
  int v9; // r7
  int v10; // r4
  int v11; // r6
  int v12; // r2
  unsigned int v13; // r8
  int *v14; // r9
  unsigned int *v15; // r10
  int v16; // r3
  unsigned int v17; // r5
  int v18; // r0
  int v19; // r2
  bool v20; // zf
  unsigned int *v21; // r0
  signed int v22; // r0
  int v23; // r7
  unsigned int v24; // r0
  __int16 **v25; // r10
  int v26; // r3
  int v27; // r0
  unsigned int v28; // r8
  unsigned int v29; // r9
  _WORD *v30; // r7
  __int16 *v31; // r3
  const __int16 *v32; // r2
  int v33; // r3
  int v34; // r6
  int *v35; // r2
  int *v36; // r9
  unsigned int v37; // r5
  unsigned int v38; // r8
  unsigned int v39; // r9
  _WORD *v40; // r0
  _DWORD *v41; // r5
  int v42; // r3
  unsigned int *v43; // r0
  int *v44; // r5
  unsigned int v45; // r0
  unsigned int v46; // t1
  _WORD *v48; // [sp+10h] [bp-458h] BYREF
  int *v49; // [sp+14h] [bp-454h]
  int *v50; // [sp+18h] [bp-450h]
  int v51; // [sp+1Ch] [bp-44Ch] BYREF
  unsigned int *v52; // [sp+20h] [bp-448h]
  int *v53; // [sp+24h] [bp-444h]
  int v54; // [sp+28h] [bp-440h]
  int v55; // [sp+2Ch] [bp-43Ch]
  unsigned int v56; // [sp+30h] [bp-438h]
  unsigned int v57; // [sp+34h] [bp-434h]
  int v58; // [sp+38h] [bp-430h]
  _DWORD *v59; // [sp+3Ch] [bp-42Ch]
  int v60; // [sp+40h] [bp-428h] BYREF
  int v61; // [sp+44h] [bp-424h] BYREF
  int v62[264]; // [sp+48h] [bp-420h] BYREF

  v8 = a5;
  v9 = 0;
  v59 = a3;
  v60 = a6;
  v10 = 0;
  v11 = 0;
  v58 = a7;
  v48 = 0;
  v55 = a5;
  v56 = a2;
  v53 = a1;
  v51 = 0;
  if ( !a1 || !a3 || !a2 )
    return 87;
  if ( a2 < 6 )
    return 805;
  v12 = *a1;
  if ( *a1 != 2020897377 )
    return 805;
  v13 = 4;
  v57 = 4;
  v49 = &v60;
  v14 = v62;
  v15 = (unsigned int *)&v61;
  v52 = (unsigned int *)&v61;
  v50 = v62;
  do
  {
    v16 = a8;
    if ( v11 == 255 )
    {
      v10 = 1001;
      goto LABEL_84;
    }
    v17 = *((unsigned __int8 *)a1 + v13);
    if ( v17 > 0x51 )
    {
      if ( *((unsigned __int8 *)a1 + v13) < 0x80u )
        goto LABEL_22;
      if ( *((unsigned __int8 *)a1 + v13) > 0x93u )
      {
        if ( *((unsigned __int8 *)a1 + v13) <= 0x9Fu )
          goto LABEL_22;
        if ( *((unsigned __int8 *)a1 + v13) > 0xA2u )
        {
          if ( *((unsigned __int8 *)a1 + v13) <= 0xF7u || *((unsigned __int8 *)a1 + v13) > 0xFBu )
            goto LABEL_22;
          v18 = GetPrintableAttributeName((int)a1 + v13, a2 - v13, v17, &v48, &v51);
          goto LABEL_16;
        }
      }
      if ( v17 == 160 || v17 == 161 )
      {
        if ( v11 < 2 )
          goto LABEL_22;
        v10 = EncloseSubCondition(v15, a2, v12, a8);
        if ( v10 )
          goto LABEL_23;
        v21 = (unsigned int *)v49;
      }
      else
      {
        if ( v17 != 162 )
        {
LABEL_43:
          v22 = GetOperatorIndexByToken(*((unsigned __int8 *)a1 + v13));
          if ( v22 < 0 )
            goto LABEL_22;
          v23 = 5 * v22;
          v54 = 5 * v22;
          v24 = wcslen((unsigned __int16 *)(&Operators)[5 * v22]);
          v25 = &(&Operators)[v23];
          v26 = *((unsigned __int8 *)v25 + 12);
          v27 = 2 * v24;
          v48 = (_WORD *)v27;
          if ( v26 )
          {
            if ( !v11 )
              return 1336;
            v28 = *(v14 - 1);
            if ( ULongAddStringSize(v27, v28, &v48) < 0 )
              goto LABEL_78;
            v29 = (unsigned int)(v48 + 4);
            v30 = SddlpAlloc((int)(v48 + 4));
            if ( !v30 )
              goto LABEL_77;
            if ( v17 == 162 )
            {
              v31 = (&Operators)[v54];
              v32 = L"(%ls%ls)";
            }
            else
            {
              v33 = *((unsigned __int8 *)v25 + 4);
              if ( (v33 == 135 || v33 == 141) && (!wcsnicmp(v28, L"@USER.", 6) || !wcsnicmp(v28, L"@DEVICE.", 8)) )
              {
                v10 = 1336;
LABEL_81:
                if ( v30 )
                  ExFreePoolWithTag((unsigned int)v30);
LABEL_23:
                if ( !v11 )
                  return v10;
                goto LABEL_24;
              }
              v31 = (&Operators)[v54];
              v32 = L"(%ls %ls)";
            }
            if ( RtlStringCchPrintfW(v30, v29 >> 1, (int)v32, (int)v31) < 0 )
              goto LABEL_80;
            if ( v28 )
              ExFreePoolWithTag(v28);
            v34 = v11 - 1;
            v35 = v49 - 1;
            v36 = v50 - 1;
            v15 = v52 - 1;
          }
          else
          {
            if ( v11 < 2 )
              goto LABEL_22;
            v37 = *(v14 - 1);
            if ( ULongAddStringSize(v27, v37, &v48) < 0 || (v38 = *(v14 - 2), ULongAddStringSize(v48, v38, &v48) < 0) )
            {
LABEL_78:
              v10 = 534;
              goto LABEL_23;
            }
            v39 = (unsigned int)(v48 + 5);
            v40 = SddlpAlloc((int)(v48 + 5));
            v30 = v40;
            if ( !v40 )
            {
LABEL_77:
              v10 = 8;
              goto LABEL_23;
            }
            if ( RtlStringCchPrintfW(v40, v39 >> 1, (int)L"(%ls %ls %ls)", v38) < 0 )
            {
LABEL_80:
              v10 = 50;
              goto LABEL_81;
            }
            if ( v37 )
              ExFreePoolWithTag(v37);
            if ( v38 )
              ExFreePoolWithTag(v38);
            v34 = v11 - 2;
            v35 = v49 - 2;
            v36 = v50 - 2;
            v15 = v52 - 2;
          }
          *v36 = (int)v30;
          v14 = v36 + 1;
          v11 = v34 + 1;
          v12 = (int)(v35 + 1);
          v9 = 1;
          v13 = v57;
          v51 = 1;
          goto LABEL_70;
        }
        if ( v11 < 1 )
          goto LABEL_22;
        v21 = v15;
      }
      v10 = EncloseSubCondition(v21, a2, v12, v16);
      if ( v10 )
        goto LABEL_23;
      a1 = v53;
      goto LABEL_43;
    }
    if ( *((unsigned __int8 *)a1 + v13) >= 0x50u )
      goto LABEL_15;
    if ( *((_BYTE *)a1 + v13) )
    {
      if ( *((unsigned __int8 *)a1 + v13) > 4u && v17 != 16 && v17 != 24 )
        goto LABEL_22;
LABEL_15:
      v18 = GetPrintableOperandValue((unsigned __int8 *)a1 + v13, a2 - v13, (int *)&v48, &v51, v8, v60, v58, a8);
LABEL_16:
      v10 = v18;
      if ( v18 )
      {
        v30 = v48;
        goto LABEL_81;
      }
      v19 = (int)v49;
      v9 = v51;
      ++v11;
      *v14 = (int)v48;
      v12 = v19 + 4;
      ++v14;
LABEL_70:
      ++v15;
      v8 = v55;
      a2 = v56;
      a1 = v53;
      v52 = v15;
      v49 = (int *)v12;
      v50 = v14;
      v48 = 0;
      goto LABEL_71;
    }
    while ( 1 )
    {
      v20 = ++v13 == a2;
      if ( v13 >= a2 )
        break;
      if ( *((_BYTE *)a1 + v13) )
      {
        v20 = v13 == a2;
        break;
      }
    }
    if ( !v20 )
    {
LABEL_22:
      v10 = 1336;
      goto LABEL_23;
    }
LABEL_71:
    v13 += v9;
    v57 = v13;
  }
  while ( v13 < a2 );
  if ( v11 != 1 )
    goto LABEL_23;
  v41 = v59;
  v42 = v62[0];
  v43 = v59;
  *v59 = v62[0];
  v10 = EncloseSubCondition(v43, a2, v12, v42);
  if ( !v10 )
    return v10;
  *v41 = 0;
LABEL_24:
  if ( !v10 )
    v10 = 1336;
LABEL_84:
  v44 = &v62[v11];
  do
  {
    v46 = *--v44;
    v45 = v46;
    --v11;
    if ( v46 )
      ExFreePoolWithTag(v45);
  }
  while ( v11 );
  return v10;
}
