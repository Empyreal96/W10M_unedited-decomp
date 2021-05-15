// WmipEnumerateMofResources 
 
int __fastcall WmipEnumerateMofResources(int *a1, unsigned int a2, int *a3)
{
  int *v4; // r9
  int v5; // r6
  int v6; // r10
  int **v7; // r8
  int **v8; // r7
  unsigned int v9; // r4
  unsigned int v10; // r0
  int v11; // r4
  int v12; // r7
  int *v13; // r10
  int *v14; // r6
  unsigned int v15; // r9
  int *v16; // r2
  unsigned int v17; // r4
  unsigned int v18; // r0
  int v19; // r3
  int *v22; // [sp+8h] [bp-28h]

  v4 = a3;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v5 = 0;
  v6 = 0;
  v7 = (int **)WmipMRHeadPtr;
  v8 = *(int ***)WmipMRHeadPtr;
  if ( *(_DWORD *)WmipMRHeadPtr == WmipMRHeadPtr )
    goto LABEL_11;
  do
  {
    ++v5;
    v9 = wcslen((unsigned __int16 *)v8[5]);
    v10 = wcslen((unsigned __int16 *)v8[6]);
    v8 = (int **)*v8;
    v6 += 2 * (v10 + v9 + 2);
  }
  while ( v8 != v7 );
  if ( !v5 )
  {
LABEL_11:
    *a1 = 0;
    v19 = 16;
    goto LABEL_12;
  }
  v11 = 12 * (v5 - 1) + 16;
  v12 = v11 + v6;
  if ( a2 < v11 + v6 )
  {
    *a1 = v12;
    v19 = 4;
LABEL_12:
    *v4 = v19;
    goto LABEL_13;
  }
  *a1 = v5;
  v13 = *v7;
  if ( *v7 != (int *)v7 )
  {
    v14 = a1 + 1;
    v15 = a2;
    do
    {
      v16 = v14;
      v14 += 3;
      v16[2] = (v13[2] & 1) != 0;
      v22 = v16;
      *v16 = v11;
      RtlStringCbCopyW((int)a1 + v11, v15 - v11);
      v17 = v11 + 2 * (wcslen((unsigned __int16 *)v13[5]) + 1);
      v22[1] = v17;
      RtlStringCbCopyW((int)a1 + v17, v15 - v17);
      v18 = wcslen((unsigned __int16 *)v13[6]);
      v13 = (int *)*v13;
      v11 = v17 + 2 * (v18 + 1);
    }
    while ( v13 != (int *)v7 );
    v4 = a3;
  }
  *v4 = v12;
LABEL_13:
  KeReleaseMutex((int)&WmipSMMutex);
  return 0;
}
