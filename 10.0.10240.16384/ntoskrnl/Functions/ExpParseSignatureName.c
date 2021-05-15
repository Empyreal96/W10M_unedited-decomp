// ExpParseSignatureName 
 
int __fastcall ExpParseSignatureName(char *a1, unsigned int a2, int a3, int a4, int a5, int a6, _BYTE *a7, _BYTE *a8)
{
  int v9; // r4
  _BYTE *v10; // r5
  int v11; // r0
  BOOL v13; // r8
  unsigned int v14; // r4
  char *v15; // r5
  int v16; // r1
  int v17; // t1
  int v18; // r10
  int v19; // r5
  unsigned int v20; // r4
  int v21; // r10
  _WORD *v22; // r9
  int v23; // r1
  char *v24; // r2
  unsigned int v25; // r0
  int v26; // t1
  unsigned int v27; // r5
  int v28; // r1
  unsigned int v29; // r4
  int v30; // r1
  char *v31; // r2
  unsigned int v32; // r0
  int v33; // t1
  unsigned int v34; // r5
  int v35; // r0
  char *v36; // r2
  unsigned int v37; // r1
  int v38; // t1
  unsigned int v39; // r5
  _WORD *v40; // r0
  unsigned int v41; // r9
  int v42; // r0
  _BYTE *v44; // [sp+0h] [bp-28h] BYREF
  char *v45; // [sp+4h] [bp-24h]
  int v46; // [sp+8h] [bp-20h]

  v44 = (_BYTE *)a2;
  v45 = (char *)a3;
  v46 = a4;
  v9 = *(unsigned __int16 *)a1;
  v10 = (_BYTE *)a3;
  v11 = 0;
  v46 = a4;
  v44 = (_BYTE *)a3;
  v13 = v9 == 123;
  v14 = 0;
  if ( a2 )
  {
    v15 = a1;
    do
    {
      v17 = *(unsigned __int16 *)v15;
      v15 += 2;
      v16 = v17;
      if ( v17 == 41 )
        break;
      if ( v13 )
      {
        if ( v16 == 125 )
        {
          v11 = 1;
          break;
        }
      }
      else if ( v16 == 45 )
      {
        break;
      }
      ++v14;
    }
    while ( v14 < a2 );
    v10 = v44;
  }
  if ( v13 && !v11 )
    return -1073741811;
  if ( v14 > 8 )
    v13 = 1;
  if ( v13 && v11 == 1 )
  {
    ++v14;
    v18 = 2 * v14;
    LOWORD(v44) = 2 * v14;
    HIWORD(v44) = 2 * v14;
    v45 = a1;
    v19 = RtlGUIDFromString((unsigned __int16 *)&v44, v10);
  }
  else
  {
    v18 = 2 * v14;
    v40 = (_WORD *)ExAllocatePoolWithTag(512, 2 * v14 + 2, 1920364101);
    v41 = (unsigned int)v40;
    if ( !v40 )
      return -1073741670;
    wcsncpy_s(v40, v14 + 1, a1, v14);
    *(_WORD *)(v18 + v41) = 0;
    if ( v13 )
      v42 = ExpTranslateHexStringToGUID(v41, v10);
    else
      v42 = ExpTranslateHexStringToULONG(v41, v10);
    v19 = v42;
    ExFreePoolWithTag(v41);
  }
  if ( v19 >= 0 )
  {
    if ( v14 >= a2 )
      return -1073741811;
    if ( *(_WORD *)&a1[v18] != 45 )
    {
      v21 = 0;
      goto LABEL_53;
    }
    v20 = v14 + 1;
    v21 = 1;
    if ( v20 >= a2 )
      return -1073741811;
    v22 = (_WORD *)ExAllocatePoolWithTag(512, 34, 1920364101);
    if ( v22 )
    {
      v23 = 2 * v20;
      v24 = &a1[2 * v20];
      v25 = v20;
      do
      {
        v26 = *(unsigned __int16 *)v24;
        v24 += 2;
        if ( v26 == 45 )
          break;
        ++v20;
      }
      while ( v20 < a2 );
      v27 = v20 - v25;
      if ( v20 != v25 && v27 <= 8 )
      {
        wcsncpy_s(v22, 17, &a1[v23], v20 - v25);
        v28 = v46;
        v22[v27] = 0;
        v19 = ExpTranslateHexStringToULONG(v22, v28);
        if ( v19 < 0 )
          goto LABEL_51;
        v29 = v20 + 1;
        if ( v29 < a2 )
        {
          v30 = 2 * v29;
          v31 = &a1[2 * v29];
          v32 = v29;
          do
          {
            v33 = *(unsigned __int16 *)v31;
            v31 += 2;
            if ( v33 == 45 )
              break;
            ++v29;
          }
          while ( v29 < a2 );
          v34 = v29 - v32;
          if ( v29 != v32 && v34 <= 0x10 )
          {
            wcsncpy_s(v22, 17, &a1[v30], v29 - v32);
            v22[v34] = 0;
            v19 = ExpTranslateHexStringToULONGLONG(v22, a5);
            if ( v19 >= 0 )
            {
              v14 = v29 + 1;
              if ( v14 < a2 )
              {
                v35 = 2 * v14;
                v36 = &a1[2 * v14];
                v37 = v14;
                do
                {
                  v38 = *(unsigned __int16 *)v36;
                  v36 += 2;
                  if ( v38 == 41 )
                    break;
                  ++v14;
                }
                while ( v14 < a2 );
                v39 = v14 - v37;
                if ( v14 != v37 && v39 <= 0x10 )
                {
                  wcsncpy_s(v22, 17, &a1[v35], v14 - v37);
                  v22[v39] = 0;
                  v19 = ExpTranslateHexStringToULONGLONG(v22, a6);
                  ExFreePoolWithTag((unsigned int)v22);
                  if ( v19 < 0 )
                    return v19;
LABEL_53:
                  if ( v14 < a2 && *(_WORD *)&a1[2 * v14] == 41 && (v13 || v21) )
                  {
                    v19 = 0;
                    *a7 = v13;
                    *a8 = v21;
                    return v19;
                  }
                  return -1073741811;
                }
              }
              goto LABEL_50;
            }
LABEL_51:
            ExFreePoolWithTag((unsigned int)v22);
            return v19;
          }
        }
      }
LABEL_50:
      v19 = -1073741811;
      goto LABEL_51;
    }
    return -1073741670;
  }
  return v19;
}
