// SmIssueIo 
 
int __fastcall SmIssueIo(void *a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // r5
  int v8; // r7
  int v9; // r4
  int v10; // lr
  int v11; // r10
  int v12; // r9
  int v13; // r8
  unsigned int v14; // r10
  _DWORD *v15; // r4
  unsigned int *v16; // r7
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r3
  unsigned int v20; // r4
  unsigned int v21; // r1
  int v22; // r5
  unsigned int *v23; // r2
  unsigned int v24; // r1
  int v25; // r3
  void (__cdecl *v26)(void *, struct _IO_STATUS_BLOCK *, unsigned int); // r2
  unsigned int *v27; // r2
  unsigned int v28; // r1
  _DWORD *v29; // r0
  unsigned int v30; // r4
  unsigned int v31; // r1
  int v34; // [sp+Ch] [bp-44h]
  int v35; // [sp+10h] [bp-40h]
  int v36[14]; // [sp+18h] [bp-38h] BYREF

  v34 = a3;
  v35 = a2;
  v7 = (_DWORD *)a6;
  v8 = a4;
  v9 = 0;
  v10 = a3;
  v11 = a2;
  v12 = 0;
  if ( (a6 & 1) != 0 )
  {
    v7 = (_DWORD *)(a6 & 0xFFFFFFFE);
    v13 = 1;
  }
  else
  {
    v13 = 0;
  }
  if ( (v7[4] & 4) != 0 )
  {
    if ( (*((_BYTE *)a1 + 3517) & 1) != 0 )
      return -1073741058;
    goto LABEL_22;
  }
  v14 = *((_DWORD *)a1 + 878);
  v15 = &SmGlobals[24 * (v14 & 0x1F)];
  v16 = v15 + 1;
  __pld(v15 + 1);
  v17 = v15[1] & 0xFFFFFFFE;
  do
    v18 = __ldrex(v16);
  while ( v18 == v17 && __strex(v17 + 2, v16) );
  __dmb(0xBu);
  if ( v18 != v17 && !ExfAcquireRundownProtection(v15 + 1) )
    goto LABEL_17;
  if ( (v15[3] & 0x7FF) != v14 >> 5 )
  {
    __pld(v16);
    v20 = *v16 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v21 = __ldrex(v16);
    while ( v21 == v20 && __strex(v20 - 2, v16) );
    if ( v21 != v20 )
      ExfReleaseRundownProtection((unsigned __int8 *)v16);
LABEL_17:
    v19 = 0;
    goto LABEL_18;
  }
  v19 = *v15;
LABEL_18:
  if ( !v19 )
    return -1073741058;
  v8 = a4;
  v10 = v34;
  v11 = v35;
  v9 = 1;
LABEL_22:
  if ( v13 )
  {
    __dmb(0xBu);
    v23 = (unsigned int *)((char *)a1 + 3576);
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 + 1, v23) );
    __dmb(0xBu);
    v12 = 1;
  }
  v25 = *((_DWORD *)a1 + 913);
  v36[4] = v11;
  v36[5] = v25;
  v36[2] = v8;
  v36[3] = v10;
  v36[1] = a5;
  v36[6] = v13 != 0;
  if ( (*(_DWORD *)a1 & 0x2000) != 0 )
  {
    v26 = (void (__cdecl *)(void *, struct _IO_STATUS_BLOCK *, unsigned int))SmpIoCompletionApc;
    v36[0] = (int)(v7 + 6);
    v7 = a1;
  }
  else
  {
    v36[0] = (int)(v7 + 8);
    v26 = (void (__cdecl *)(void *, struct _IO_STATUS_BLOCK *, unsigned int))SmpDeviceIoCompletion;
    v7[6] = v8;
    v7[7] = a1;
  }
  v22 = SmKmIssueIo((int)a1 + 3660, (int)v36, v26, v7, (*(_DWORD *)a1 >> 13) & 1);
  if ( v22 >= 0 )
  {
    v9 = 0;
    v12 = 0;
  }
  if ( v12 )
  {
    __dmb(0xBu);
    v27 = (unsigned int *)((char *)a1 + 3576);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 - 1, v27) );
    __dmb(0xBu);
  }
  if ( v9 )
  {
    v29 = &SmGlobals[24 * (*((_DWORD *)a1 + 878) & 0x1F) + 1];
    __pld(v29);
    v30 = *v29 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v31 = __ldrex(v29);
    while ( v31 == v30 && __strex(v30 - 2, v29) );
    if ( v31 != v30 )
      ExfReleaseRundownProtection((unsigned __int8 *)v29);
  }
  return v22;
}
