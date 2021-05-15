// sub_7E16D0 
 
void sub_7E16D0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, ...)
{
  int v12; // r5
  int v13; // r8
  int *v14; // r0
  unsigned int v15; // r4
  int **v16; // r1
  int v17; // r6
  int *v18; // r2
  __int64 v19; // kr00_8
  int v20; // r3
  char *v21; // r7
  char *v22; // r5
  _WORD *v23; // r0
  _WORD *v24; // r10
  unsigned __int16 *v25; // r0
  unsigned __int16 *v26; // r4
  _WORD *v27; // r0
  char *v28; // r4
  int v29; // r5
  int *v30; // r9
  int v31; // t1
  int *v32; // r5
  int v33; // r4
  int *v34; // r9
  int v35; // r0
  int *v36; // r2
  int v37; // r0
  int *v38; // r0
  int **v39; // r1
  int v40; // [sp+8h] [bp+8h]
  _WORD *v41; // [sp+Ch] [bp+Ch]
  int v42; // [sp+Ch] [bp+Ch]
  unsigned __int16 *v43; // [sp+14h] [bp+14h]
  int *v44; // [sp+20h] [bp+20h] BYREF
  va_list va; // [sp+20h] [bp+20h]
  int **v46; // [sp+24h] [bp+24h]
  va_list va1; // [sp+28h] [bp+28h] BYREF

  va_start(va1, a12);
  va_start(va, a12);
  v44 = va_arg(va1, int *);
  v46 = va_arg(va1, int **);
  v14 = (int *)ExAllocatePoolWithTag(1, 12, 1667526736);
  v15 = (unsigned int)v14;
  if ( !v14 )
    goto LABEL_69;
  v14[2] = v13;
  v16 = v46;
  *v14 = (int)va;
  v14[1] = (int)v16;
  if ( *v16 != (int *)va )
    __fastfail(3u);
  *v16 = v14;
  v46 = (int **)v14;
  v17 = 0;
  v18 = v44;
  do
  {
LABEL_6:
    if ( v18 == (int *)va )
    {
      v20 = 0;
    }
    else
    {
      v19 = *(_QWORD *)v15;
      if ( *(int ***)v15 != (int **)va || *(_DWORD *)HIDWORD(v19) != v15 )
        __fastfail(3u);
      v46 = *(int ***)(v15 + 4);
      *(_DWORD *)HIDWORD(v19) = va;
      v12 = *(_DWORD *)(v15 + 8);
      a9 = v12;
      ExFreePoolWithTag(v15);
      v18 = v44;
      v15 = (unsigned int)v46;
      v20 = 1;
    }
    if ( !v20 )
      goto LABEL_69;
    v21 = *(char **)(v12 + 204);
  }
  while ( !v21 );
  if ( !*(_WORD *)v21 )
    goto LABEL_58;
  while ( 1 )
  {
    v22 = v21;
    v43 = (unsigned __int16 *)v21;
    v23 = wcschr(v21, 58);
    v24 = v23;
    v41 = v23;
    if ( !v23 )
      goto LABEL_54;
    *v23 = 0;
    v21 = (char *)(v23 + 1);
    if ( !wcscmp(v22, (char *)L"*") )
      v43 = 0;
    v25 = wcsrchr(v24 + 1, 46);
    v26 = v25;
    if ( !v25 )
      goto LABEL_54;
    *v25 = 0;
    v21 = (char *)(v25 + 1);
    if ( !wcscmp((char *)v25 + 2, (char *)L"*") )
    {
      v40 = -1;
    }
    else
    {
      v40 = 0;
      v21 = (char *)(v26 + 1);
      if ( v26[1] )
      {
        do
        {
          v27 = wcschr(v21, 44);
          if ( v27 )
          {
            *v27 = 0;
            v28 = (char *)(v27 + 1);
          }
          else
          {
            v28 = &v21[2 * wcslen((unsigned __int16 *)v21)];
          }
          v29 = 0;
          v30 = (int *)&off_8C6E54;
          while ( 1 )
          {
            v31 = *v30;
            v30 += 2;
            if ( !wcsicmp(v31, (unsigned __int16 *)v21) )
              break;
            if ( (unsigned int)++v29 >= 6 )
              goto LABEL_29;
          }
          v40 |= (unsigned int)*(&off_8C6E54 + 2 * v29 + 1);
LABEL_29:
          v21 = v28;
        }
        while ( *(_WORD *)v28 );
        v13 = a11;
        v24 = v41;
      }
    }
    v42 = 0;
    RtlInitUnicodeString((unsigned int)va1, v24 + 1);
    v32 = *(int **)(v13 + 208);
    v33 = v13 + 208;
    if ( v32 == (int *)(v13 + 208) )
      goto LABEL_37;
    do
    {
      v34 = v32;
      v42 = (int)v32;
      if ( RtlEqualUnicodeString((unsigned __int16 *)v32 + 22, (unsigned __int16 *)va1, 1)
        && (!v43 || !wcsicmp(v32[6], v43)) )
      {
        break;
      }
      v32 = (int *)*v32;
      v34 = 0;
      v42 = 0;
    }
    while ( v32 != (int *)v33 );
    v13 = a11;
    if ( !v34 )
    {
LABEL_37:
      v12 = a9;
      v35 = PiDevCfgQueryIncludedDriverNode(a9, v43, v24 + 1, v40);
      v17 = v35;
      if ( v35 < 0 )
      {
        if ( v35 == -1073741685 )
        {
          *(_DWORD *)(v13 + 236) = -536870319;
        }
        else if ( v35 == -1073741072 )
        {
          *(_DWORD *)(v13 + 236) = -536870320;
          goto LABEL_69;
        }
        v15 = (unsigned int)v46;
        goto LABEL_57;
      }
      v36 = *(int **)(v33 + 4);
      *(_DWORD *)v42 = v33;
      *(_DWORD *)(v42 + 4) = v36;
      if ( *v36 != v33 )
        __fastfail(3u);
      *v36 = v42;
      *(_DWORD *)(v33 + 4) = v42;
      if ( PiDevCfgQueryDriverConfiguration((_DWORD *)v42) < 0 )
        goto LABEL_69;
      if ( *(_DWORD *)(v42 + 172) && !*(_DWORD *)(v13 + 172) )
      {
        if ( *(_DWORD *)(v42 + 172) )
        {
          v37 = ExpAllocateStringRoutine(*(unsigned __int16 *)(v42 + 170));
          *(_DWORD *)(v13 + 172) = v37;
          if ( !v37 )
          {
            v17 = -1073741670;
            v15 = (unsigned int)v46;
LABEL_56:
            v12 = a9;
LABEL_57:
            v18 = v44;
LABEL_58:
            if ( v17 < 0 )
LABEL_69:
              JUMPOUT(0x77933E);
            goto LABEL_6;
          }
          memmove(v37, *(_DWORD *)(v42 + 172), *(unsigned __int16 *)(v42 + 170));
        }
        else
        {
          *(_DWORD *)(v13 + 172) = 0;
        }
        *(_WORD *)(v13 + 168) = *(_WORD *)(v42 + 168);
        *(_WORD *)(v13 + 170) = *(_WORD *)(v42 + 170);
      }
      if ( *(_DWORD *)(v42 + 180) && PiDevCfgAppendMultiSz(v13 + 176, 0, v42 + 176, 0) < 0 )
        goto LABEL_69;
      if ( *(_DWORD *)(v42 + 188) && PiDevCfgAppendMultiSz(v13 + 184, 0, v42 + 184, 0) < 0 )
        goto LABEL_69;
      v38 = (int *)ExAllocatePoolWithTag(1, 12, 1667526736);
      v15 = (unsigned int)v38;
      if ( !v38 )
        goto LABEL_69;
      v38[2] = v42;
      v39 = v46;
      *v38 = (int)va;
      v38[1] = (int)v39;
      if ( *v39 != (int *)va )
        __fastfail(3u);
      *v39 = v38;
      v46 = (int **)v38;
      v17 = 0;
    }
    else
    {
LABEL_54:
      v15 = (unsigned int)v46;
    }
    v21 += 2 * wcslen((unsigned __int16 *)v21) + 2;
    if ( !*(_WORD *)v21 )
      goto LABEL_56;
  }
}
