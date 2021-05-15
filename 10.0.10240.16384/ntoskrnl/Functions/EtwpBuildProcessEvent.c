// EtwpBuildProcessEvent 
 
int __fastcall EtwpBuildProcessEvent(int a1, int *a2, int a3, int a4, _DWORD *a5, _DWORD *a6, int *a7, int *a8, unsigned __int16 *a9, unsigned __int16 *a10, int **a11)
{
  int v13; // r4
  unsigned int v14; // r5
  int v15; // r4
  int *v16; // r2
  int v17; // r3
  int v18; // r3
  int v19; // r4
  char *v20; // r5
  int v21; // r9
  int v22; // r4
  int v23; // r2
  _DWORD *v24; // r3
  int result; // r0
  int v26; // r2
  int v27; // r4
  _DWORD *v28; // r1
  int v29; // r2
  _DWORD *v30; // r1
  int v31; // r2
  int v32; // r4
  _WORD *v33; // r1
  int v34; // r1
  int v35; // r2
  _DWORD *v36; // r2
  int *v37; // [sp+0h] [bp-28h] BYREF
  int v38; // [sp+4h] [bp-24h]
  int *v39; // [sp+8h] [bp-20h]

  v37 = a2;
  v38 = a3;
  v39 = a2;
  RtlInitAnsiString((unsigned int)a9, 0);
  *(_DWORD *)a4 = a1;
  *(_DWORD *)(a4 + 4) = *(_DWORD *)(a1 + 176);
  v13 = *(_DWORD *)(a1 + 312);
  *a11 = 0;
  *(_DWORD *)(a4 + 8) = v13;
  *(_DWORD *)(a4 + 12) = MmGetSessionIdEx(a1);
  *(_DWORD *)(a4 + 16) = *(_DWORD *)(a1 + 632);
  *(_QWORD *)(a4 + 20) = *(unsigned int *)(a1 + 24);
  if ( (*(_BYTE *)(a1 + 734) & 7) != 0 )
    return sub_7C36C8();
  *a6 = a4;
  a6[1] = 0;
  a6[2] = 28;
  a6[3] = 0;
  v14 = PsReferencePrimaryToken(a1);
  EtwpQueryTokenPackageInfo(v14, a8, a4 + 24);
  v15 = SeQueryInformationToken(v14, 1, &v37);
  ObFastDereferenceObject((_DWORD *)(a1 + 244), v14);
  if ( v15 < 0 )
  {
    v18 = 4;
    v16 = &EtwpNull;
  }
  else
  {
    v16 = v37;
    v17 = *v37;
    *a11 = v37;
    v18 = 4 * (*(unsigned __int8 *)(v17 + 1) + 4);
  }
  v19 = a1 + 360;
  a6[4] = v16;
  a6[5] = 0;
  a6[6] = v18;
  a6[7] = 0;
  v20 = strlen(a1 + 360);
  if ( v20 == (char *)14 )
  {
    v33 = *(_WORD **)(a1 + 380);
    if ( *v33 )
    {
      if ( RtlUnicodeStringToAnsiString(a9, v33, 1) >= 0 )
      {
        v34 = *a9;
        v35 = *((_DWORD *)a9 + 1);
        v19 = v35 + v34;
        while ( v19 != v35 )
        {
          if ( *(_BYTE *)--v19 == 92 )
          {
            ++v19;
            break;
          }
        }
        v20 = (char *)(v35 - v19 + v34);
      }
    }
  }
  v21 = v38;
  a6[8] = v19;
  a6[9] = 0;
  a6[10] = v20;
  a6[11] = 0;
  a6[12] = &EtwpNull;
  a6[13] = 0;
  v22 = 4;
  a6[14] = 1;
  a6[15] = 0;
  if ( v21 )
  {
    EtwpQueryProcessOtherInfo(a1, a5);
  }
  else
  {
    *a5 = 0;
    a5[1] = 0;
  }
  *a10 = 0;
  if ( *(_DWORD *)(a1 + 320) )
  {
    if ( v21 )
    {
      EtwpQueryProcessCommandLine(a1, a10);
      v23 = *a10;
      if ( *a10 )
      {
        a6[16] = *((_DWORD *)a10 + 1);
        a6[17] = 0;
        a6[18] = v23;
        a6[19] = 0;
        v22 = 5;
      }
    }
  }
  v24 = &a6[4 * v22];
  result = (int)a8;
  *v24 = &EtwpNull;
  v24[1] = 0;
  v24[2] = 2;
  v24[3] = 0;
  v26 = *a8;
  v27 = v22 + 1;
  v28 = &a6[4 * v27];
  v28[1] = 0;
  v28[2] = v26;
  *v28 = a8 + 2;
  v28[3] = 0;
  v29 = a8[1];
  ++v27;
  v30 = &a6[4 * v27];
  v30[1] = 0;
  v30[2] = v29;
  v31 = (int)v39;
  *v30 = a8 + 66;
  v32 = v27 + 1;
  v30[3] = 0;
  if ( v31 == 807 )
  {
    v36 = &a6[4 * v32];
    *v36 = a1 + 696;
    v36[1] = 0;
    v36[2] = 8;
    v36[3] = 0;
    ++v32;
  }
  *a7 = v32;
  return result;
}
