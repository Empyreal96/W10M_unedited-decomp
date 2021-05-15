// IopFileUtilWalkDirectoryTreeHelper 
 
int __fastcall IopFileUtilWalkDirectoryTreeHelper(unsigned __int16 *a1, char a2, int (__fastcall *a3)(unsigned int, unsigned __int16 *), int a4, int a5, int a6, int a7)
{
  unsigned __int16 *v8; // r9
  int v9; // r4
  int v10; // r5
  _DWORD *v11; // r8
  unsigned __int16 *v12; // r1
  int v13; // r3
  __int16 v14; // r2
  int v15; // r6
  int v16; // r2
  int v17; // r3
  BOOL v18; // r6
  unsigned int *v19; // r2
  char *v20; // r3
  int v21; // r9
  int v22; // r0
  unsigned int v23; // r5
  int *v25; // [sp+0h] [bp-80h]
  int v26; // [sp+4h] [bp-7Ch]
  int v27; // [sp+8h] [bp-78h]
  int v28; // [sp+Ch] [bp-74h]
  int v29; // [sp+10h] [bp-70h]
  int v30; // [sp+14h] [bp-6Ch]
  int v31; // [sp+18h] [bp-68h]
  __int16 v34; // [sp+2Ch] [bp-54h]
  unsigned __int16 v36[4]; // [sp+38h] [bp-48h] BYREF
  int v37[16]; // [sp+40h] [bp-40h] BYREF

  v8 = a1;
  v37[2] = 24;
  v37[3] = 0;
  v37[4] = (int)a1;
  v37[5] = 576;
  v37[6] = 0;
  v37[7] = 0;
  v9 = ZwOpenFile();
  if ( v9 < 0 )
    return v9;
  v28 = 3;
  v27 = 1022;
  v31 = 1;
  v10 = a5;
  v25 = v37;
  v30 = 0;
  v29 = 0;
  v26 = a5;
  v9 = ZwQueryDirectoryFile();
  if ( v9 < 0 )
    goto LABEL_29;
  do
  {
    if ( v9 == 259 )
    {
      ZwWaitForSingleObject();
      v9 = v37[0];
      if ( v37[0] < 0 )
        break;
    }
    v11 = (_DWORD *)v10;
    v12 = (unsigned __int16 *)(v10 + 94);
    v13 = v10 + 2 * (*(_DWORD *)(v10 + 60) >> 1);
    v14 = *(_WORD *)(v13 + 94);
    *(_WORD *)(v13 + 94) = 0;
    v15 = v10 + 94;
    v34 = v14;
    while ( 1 )
    {
      RtlInitUnicodeString((unsigned int)v36, v12);
      v21 = (unsigned __int16)(v36[0] + *v8 + 2);
      v22 = ExAllocatePoolWithTag(1, v21 + 18, 1967550281);
      v23 = v22;
      if ( !v22 )
        break;
      *(_WORD *)(v22 + 10) = v21;
      v8 = a1;
      *(_WORD *)(v22 + 8) = 0;
      *(_DWORD *)(v22 + 12) = v22 + 16;
      RtlCopyUnicodeString((unsigned __int16 *)(v22 + 8), a1);
      RtlAppendUnicodeToString((unsigned __int16 *)(v23 + 8), (int)L"\\", v16, v17);
      RtlAppendUnicodeStringToString((unsigned __int16 *)(v23 + 8), v36);
      if ( (v11[14] & 0x10) == 0 )
      {
        if ( (a2 & 1) != 0 )
          v9 = a3(v23 + 8, v36);
LABEL_21:
        ExFreePoolWithTag(v23);
        goto LABEL_22;
      }
      v18 = !wcsicmp(v15, L".") || !wcsicmp(v15, L"..");
      if ( (a2 & 2) != 0 )
      {
        if ( (a2 & 4) != 0 && v18 )
          goto LABEL_21;
        v9 = ((int (__fastcall *)(unsigned int, unsigned __int16 *, _DWORD, int, int *, int, int, int, int, int, int))a3)(
               v23 + 8,
               v36,
               v11[14],
               a4,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31);
      }
      if ( v18 || (a2 & 8) == 0 )
        goto LABEL_21;
      v19 = *(unsigned int **)(a7 + 4);
      *(_DWORD *)v23 = a7;
      *(_DWORD *)(v23 + 4) = v19;
      if ( *v19 != a7 )
        __fastfail(3u);
      *v19 = v23;
      *(_DWORD *)(a7 + 4) = v23;
LABEL_22:
      if ( v9 < 0 )
        goto LABEL_29;
      *((_WORD *)v11 + (v11[15] >> 1) + 47) = v34;
      if ( !*v11 )
        goto LABEL_27;
      v11 = (_DWORD *)((char *)v11 + *v11);
      v15 = (int)v11 + 94;
      v12 = (unsigned __int16 *)v11 + 47;
      v20 = (char *)v11 + 2 * (v11[15] >> 1);
      v34 = *((_WORD *)v20 + 47);
      *((_WORD *)v20 + 47) = 0;
    }
    v9 = -1073741670;
    v8 = a1;
LABEL_27:
    if ( v9 < 0 )
      break;
    v28 = 3;
    v10 = a5;
    v27 = 1022;
    v25 = v37;
    v31 = 0;
    v30 = 0;
    v29 = 0;
    v26 = a5;
    v9 = ZwQueryDirectoryFile();
  }
  while ( v9 >= 0 );
LABEL_29:
  ZwClose();
  if ( v9 == -2147483642 )
    v9 = 0;
  return v9;
}
