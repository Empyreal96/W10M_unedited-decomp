// GetPrintableOperandValue 
 
int __fastcall GetPrintableOperandValue(unsigned __int8 *a1, int a2, int *a3, int *a4, int a5, int a6, int a7, unsigned __int8 a8)
{
  unsigned __int16 *v9; // r4
  int v10; // r5
  int v14; // r3
  unsigned int v15; // r4
  unsigned int v16; // r3
  unsigned int v17; // r0
  unsigned int v18; // r4
  _WORD *v19; // r0
  unsigned int v20; // r10
  _BYTE *v21; // r0
  int v22; // r1
  int v23; // r0
  unsigned int v24; // r8
  unsigned __int16 *v25; // r4
  unsigned int v26; // r0
  unsigned int v27; // r2
  unsigned int v28; // r4
  int v29; // r0
  unsigned int v30; // r3
  int v31; // r3
  unsigned int v32; // r4
  unsigned int v33; // r0
  unsigned int v34; // r10
  _BYTE *v35; // r0
  unsigned int v36; // r7
  unsigned int v37; // r0
  int v38; // r2
  _BYTE *v39; // r0
  int v40; // r7
  int v41; // r10
  int v42; // r8
  _BYTE *v43; // r0
  _WORD *v44; // r4
  __int16 v45; // r3
  const __int16 *v46; // r2
  char *v48; // [sp+10h] [bp-A0h] BYREF
  unsigned int v49; // [sp+14h] [bp-9Ch] BYREF
  int v50; // [sp+18h] [bp-98h]
  unsigned int v51; // [sp+1Ch] [bp-94h] BYREF
  unsigned int v52; // [sp+20h] [bp-90h]
  int v53; // [sp+24h] [bp-8Ch]
  unsigned __int8 *v54; // [sp+28h] [bp-88h]
  int v55; // [sp+2Ch] [bp-84h]
  int v56; // [sp+30h] [bp-80h]
  _WORD v57[8]; // [sp+38h] [bp-78h] BYREF
  char v58[104]; // [sp+48h] [bp-68h] BYREF

  v9 = 0;
  v10 = 0;
  v56 = a5;
  v55 = a6;
  v53 = a7;
  v48 = 0;
  v49 = 0;
  v51 = 0;
  if ( !a1 || !a3 || !a2 )
    return 87;
  *a4 = 1;
  v14 = *a1;
  if ( !*a1 )
    goto LABEL_77;
  if ( *a1 <= 4u )
  {
    if ( (unsigned int)(a2 - 1) < 0xA )
      return 1336;
    v49 = 32;
    v40 = *(_DWORD *)(a1 + 1);
    v41 = *(_DWORD *)(a1 + 5);
    v42 = a1[10];
    v50 = a1[9];
    if ( RtlULongLongToULong(64, 0, &v49) < 0 )
      return 534;
    v43 = SddlpAlloc(v49);
    v44 = v43;
    *a3 = (int)v43;
    if ( !v43 )
      goto LABEL_58;
    if ( v50 == 1 )
    {
      v45 = 43;
    }
    else
    {
      if ( v50 != 2 )
      {
LABEL_65:
        if ( v42 == 1 )
        {
          v46 = L"%I64o";
          *v44++ = 48;
        }
        else if ( v42 == 3 )
        {
          *v44 = 48;
          v46 = L"%I64x";
          v44[1] = 120;
          v44 += 2;
        }
        else
        {
          v46 = L"%I64u";
        }
        if ( RtlStringCchCopyW(v57, 8u, (int)v46) < 0
          || (v40 | v41 || v42 != 1)
          && RtlStringCchPrintfW(v44, (v49 >> 1) - (((int)v44 - *a3) >> 1), (int)v57, v49 >> 1) < 0 )
        {
          goto LABEL_68;
        }
        v31 = *a4 + 10;
LABEL_76:
        *a4 = v31;
        goto LABEL_59;
      }
      v45 = 45;
    }
    *(_WORD *)v43 = v45;
    v44 = v43 + 2;
    goto LABEL_65;
  }
  switch ( v14 )
  {
    case 16:
      if ( (unsigned int)(a2 - 1) < 4 )
        return 1336;
      v32 = *(_DWORD *)(a1 + 1);
      *a4 = 5;
      if ( a2 - 5 < v32 )
        return 1336;
      if ( v32 + 6 >= v32 )
      {
        v39 = SddlpAlloc(v32 + 6);
        *a3 = (int)v39;
        if ( !v39 )
          goto LABEL_58;
        *(_WORD *)v39 = 34;
        memmove(*a3 + 2, (int)&a1[*a4], v32);
        *(_WORD *)(*a3 + 2 * (v32 >> 1) + 2) = 34;
        *(_WORD *)(*a3 + 2 * (v32 >> 1) + 4) = 0;
LABEL_54:
        v31 = *a4 + v32;
        goto LABEL_76;
      }
      return 534;
    case 24:
      if ( (unsigned int)(a2 - 1) < 4 )
        return 1336;
      v32 = *(_DWORD *)(a1 + 1);
      *a4 = 5;
      if ( a2 - 5 < v32 || !v32 )
        return 1336;
      if ( RtlULongLongToULong(2 * v32, v32 >> 31, &v49) >= 0 )
      {
        v33 = v49 + 2;
        if ( v49 + 2 >= v49 )
        {
          v49 += 2;
          if ( RtlULongLongToULong(2 * v33, v33 >> 31, &v49) >= 0 )
          {
            v34 = v49;
            v35 = SddlpAlloc(v49);
            *a3 = (int)v35;
            if ( !v35 )
              goto LABEL_58;
            v36 = 0;
            *(_WORD *)v35 = 35;
            do
            {
              v37 = a1[*a4 + v36];
              *(_WORD *)(*a3 + 4 * v36 + 2) = a0123456789abcd[v37 >> 4];
              v38 = *a3 + 4 * v36++;
              *(_WORD *)(v38 + 4) = a0123456789abcd[v37 & 0xF];
            }
            while ( v36 < v32 );
            *(_WORD *)(*a3 + 2 * (v34 >> 1) - 2) = 0;
            goto LABEL_54;
          }
        }
      }
      return 534;
    case 80:
      if ( (unsigned int)(a2 - 1) < 4 )
        return 1336;
      v20 = *(_DWORD *)(a1 + 1);
      *a4 = 5;
      if ( !v20 || a2 - 5 < v20 )
        return 1336;
      v49 = 6;
      v21 = SddlpAlloc(6);
      *a3 = (int)v21;
      if ( !v21 )
        goto LABEL_58;
      *(_WORD *)v21 = 123;
      v50 = *a4;
      v22 = v50;
      v23 = (int)&a1[v50];
      v9 = (unsigned __int16 *)v48;
      v54 = &a1[v50];
      v24 = 0;
      while ( *(_BYTE *)(v23 + v24) != 80 )
      {
        v10 = GetPrintableOperandValue(v23 + v24, a2 - v24 - v22, &v48, a4, v56, v55, v53, a8);
        if ( v10 )
          goto LABEL_59;
        v24 += *a4;
        if ( ULongAddStringSize(v49, v48, &v51) < 0 || (v52 = v51 + 4, v51 + 4 < v51) )
        {
          v10 = 534;
          goto LABEL_59;
        }
        v25 = (unsigned __int16 *)*a3;
        v51 += 4;
        v26 = wcslen(v25);
        v27 = (unsigned int)v25;
        v28 = v52;
        v29 = SddlpReAlloc(2 * v26, v52, v27);
        *a3 = v29;
        if ( !v29 )
          goto LABEL_58;
        if ( RtlStringCchPrintfW((_WORD *)(v29 + 2 * ((v49 >> 1) - 2)), (v28 - v49 + 4) >> 1, (int)L"%ls, ", (int)v48) < 0 )
          goto LABEL_68;
        if ( v48 )
          ExFreePoolWithTag((unsigned int)v48);
        v30 = v52;
        v9 = 0;
        v22 = v50;
        v48 = 0;
        v49 = v52;
        if ( v20 <= v24 )
        {
          *(_WORD *)(*a3 + 2 * (v52 >> 1) - 8) = 125;
          *(_WORD *)(*a3 + 2 * (v30 >> 1) - 6) = 0;
          v31 = v22 + v20;
          goto LABEL_76;
        }
        v23 = (int)v54;
      }
      break;
    case 81:
      if ( (unsigned int)(a2 - 1) >= 4 )
      {
        v15 = *(_DWORD *)(a1 + 1);
        *a4 = 5;
        if ( v15 <= 0x44 && a2 - 5 >= v15 )
        {
          memmove((int)v58, (int)(a1 + 5), v15);
          v10 = LocalGetStringForSid(v58, &v48);
          if ( v10 )
            goto LABEL_59;
          v16 = *a4 + v15;
          v9 = (unsigned __int16 *)v48;
          *a4 = v16;
          v17 = wcslen(v9);
          if ( v17 + 6 < v17 || (v49 = v17 + 6, RtlULongLongToULong(2 * (v17 + 6), (v17 + 6) >> 31, &v49) < 0) )
          {
            v10 = 534;
            goto LABEL_78;
          }
          v18 = v49;
          v19 = SddlpAlloc(v49);
          *a3 = (int)v19;
          if ( v19 )
          {
            if ( RtlStringCchPrintfW(v19, v18 >> 1, (int)L"SID(%ls)", (int)v48) < 0 )
LABEL_68:
              v10 = 50;
LABEL_59:
            v9 = (unsigned __int16 *)v48;
            goto LABEL_78;
          }
LABEL_58:
          v10 = 8;
          goto LABEL_59;
        }
      }
      return 1336;
  }
LABEL_77:
  v10 = 1336;
LABEL_78:
  if ( v9 )
    ExFreePoolWithTag((unsigned int)v9);
  return v10;
}
