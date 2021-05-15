// MiSnapThunk 
 
int __fastcall MiSnapThunk(int a1, int a2, int *a3, _DWORD *a4, unsigned __int16 *a5)
{
  _DWORD *v5; // r7
  int v7; // r10
  _DWORD *v9; // r0
  _DWORD *v10; // r4
  int v11; // r2
  unsigned __int16 *v12; // r5
  unsigned int v13; // r7
  unsigned int v14; // r6
  int v15; // r2
  int v16; // r3
  int v17; // r10
  unsigned int v18; // r2
  _BYTE *v20; // r6
  int v21; // r4
  int v22; // r9
  int v23; // r6
  int v24; // r7
  signed int v25; // r0
  _BYTE *v26; // r0
  int v27; // r3
  int v28; // r9
  int i; // r5
  char *v30; // r8
  int v31; // r0
  _WORD *v32; // r7
  int v33; // r0
  int v34; // [sp+8h] [bp-40h] BYREF
  _DWORD *v35; // [sp+Ch] [bp-3Ch]
  int v36; // [sp+10h] [bp-38h]
  int v37[2]; // [sp+18h] [bp-30h] BYREF
  unsigned __int16 v38[20]; // [sp+20h] [bp-28h] BYREF

  v5 = a4;
  v7 = a2;
  v35 = a4;
  v36 = a2;
  v9 = (_DWORD *)RtlImageDirectoryEntryToData(a1, 1, 0, (int)v37);
  v10 = v9;
  if ( !v9 )
    return -1073741213;
  v11 = *a3;
  v12 = a5;
  if ( v11 < 0 )
  {
    if ( !a5 )
    {
      v18 = (unsigned __int16)(v11 - v9[4]);
      goto LABEL_9;
    }
  }
  else if ( !a5 )
  {
    v12 = (unsigned __int16 *)(v11 + v7);
  }
  v13 = *v12;
  v14 = v9[6];
  v15 = v9[8] + a1;
  v16 = v9[9];
  v34 = v15;
  v17 = v16 + a1;
  if ( v13 < v14 )
  {
    if ( !strcmp((int)(v12 + 1), (unsigned int *)(*(_DWORD *)(v15 + 4 * v13) + a1)) )
    {
      v18 = *(unsigned __int16 *)(v17 + 2 * v13);
      goto LABEL_8;
    }
    v15 = v34;
  }
  v22 = 0;
  if ( !v14 )
    return -1073741213;
  v23 = v14 - 1;
  if ( v23 < 0 )
    return -1073741213;
  while ( 1 )
  {
    v24 = (v23 + v22) >> 1;
    v25 = strcmp((int)(v12 + 1), (unsigned int *)(*(_DWORD *)(v15 + 4 * v24) + a1));
    if ( v25 >= 0 )
      break;
    if ( !v24 )
      return -1073741213;
    v23 = v24 - 1;
LABEL_20:
    if ( v23 < v22 )
      return -1073741213;
    v15 = v34;
  }
  if ( v25 > 0 )
  {
    v22 = v24 + 1;
    goto LABEL_20;
  }
  if ( v23 < v22 )
    return -1073741213;
  v18 = *(unsigned __int16 *)(v17 + 2 * v24);
LABEL_8:
  v5 = v35;
  v7 = v36;
LABEL_9:
  if ( v18 >= v10[5] )
    return sub_7CDC24();
  v20 = (_BYTE *)(*(_DWORD *)(v10[7] + 4 * v18 + a1) + a1);
  *v5 = v20;
  if ( v20 <= (_BYTE *)v10 || v20 >= (_BYTE *)v10 + v37[0] )
    return 0;
  v37[1] = (int)v20;
  v26 = strchr(v20, 46);
  v27 = v26 - v20 + 1;
  v28 = (unsigned __int16)v27;
  LOWORD(v37[0]) = (_WORD)v26 - (_WORD)v20 + 1;
  HIWORD(v37[0]) = v37[0];
  v21 = -1073741213;
  if ( RtlAnsiStringToUnicodeString(v38, (unsigned __int16 *)v37, 1, v27) >= 0 )
  {
    for ( i = PsLoadedModuleList; (int *)i != &PsLoadedModuleList; i = *(_DWORD *)i )
    {
      if ( RtlPrefixString(v38, (unsigned __int16 *)(i + 44), 1) )
      {
        v30 = strlen((unsigned int)&v20[v28]);
        v31 = ExAllocatePoolWithTag(1, (int)(v30 + 5), 538996045);
        v32 = (_WORD *)v31;
        if ( v31 )
        {
          memmove(v31 + 2, (int)&v20[v28], (unsigned int)(v30 + 1));
          *v32 = 0;
          v33 = *(_DWORD *)(i + 24);
          v34 = 0;
          v21 = MiSnapThunk(v33, v7, &v34, &v34, v32);
          ExFreePoolWithTag((unsigned int)v32);
          *v35 = v34;
        }
        break;
      }
    }
    RtlFreeAnsiString(v38);
  }
  return v21;
}
