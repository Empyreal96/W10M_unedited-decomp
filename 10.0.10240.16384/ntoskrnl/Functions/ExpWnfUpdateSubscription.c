// ExpWnfUpdateSubscription 
 
int __fastcall ExpWnfUpdateSubscription(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, _DWORD *a7, _DWORD *a8, _DWORD *a9)
{
  _DWORD *i; // r6
  _DWORD *v13; // r5
  unsigned __int8 *v15; // r6
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r2
  int v19; // r2
  int v20; // r3
  int v21; // r3
  unsigned int v22; // r1
  unsigned int *v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r1
  unsigned int v28; // r1
  __int64 v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r1
  unsigned int v32; // r1

  for ( i = *(_DWORD **)(a2 + 44); ; i = (_DWORD *)*i )
  {
    if ( i == (_DWORD *)(a2 + 44) )
      return -1073741772;
    v13 = i - 4;
    if ( i[3] == a1 )
      break;
  }
  v15 = (unsigned __int8 *)(a2 + 52);
  *a7 = 0;
  *a8 = 0;
  v16 = KeAbPreAcquire(a2 + 52, 0, 0);
  v17 = v16;
  do
    v18 = __ldrex(v15);
  while ( __strex(v18 | 1, v15) );
  __dmb(0xBu);
  if ( (v18 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v15, v16, (unsigned int)v15);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  if ( (a5 & 1) != 0 && (v13[15] & 1) == 0 )
  {
    __dmb(0xBu);
    v30 = (unsigned int *)(a1 + 88);
    do
    {
      v31 = __ldrex(v30);
      v32 = v31 + 1;
    }
    while ( __strex(v32, v30) );
    __dmb(0xBu);
    if ( v32 == 1 )
      *a7 = 1;
  }
  else if ( (a5 & 1) == 0 && (v13[15] & 1) != 0 )
  {
    __dmb(0xBu);
    v26 = (unsigned int *)(a1 + 88);
    do
    {
      v27 = __ldrex(v26);
      v28 = v27 - 1;
    }
    while ( __strex(v28, v26) );
    __dmb(0xBu);
    if ( !v28 )
      *a7 = -1;
  }
  v19 = v13[18];
  if ( v19 != 2 && (v13[19] & 1) != 0 && (a5 & 1) == 0 )
    *a8 = -1;
  v20 = v13[19];
  v13[12] = a3;
  v13[13] = a4;
  v13[15] = a5;
  v21 = v20 & a5;
  v13[19] = v21;
  if ( v19 && !v21 && !v13[20] )
  {
    v29 = *((_QWORD *)v13 + 8);
    if ( *(_DWORD **)(v29 + 4) != v13 + 16 || *(_DWORD **)HIDWORD(v29) != v13 + 16 )
      sub_7C431C();
    *(_DWORD *)HIDWORD(v29) = v29;
    *(_DWORD *)(v29 + 4) = HIDWORD(v29);
    v13[18] = 0;
  }
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)v15);
  while ( __strex(v22 - 1, (unsigned int *)v15) );
  if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v15);
  KeAbPostRelease((unsigned int)v15);
  v23 = v13 + 1;
  __pld(v13 + 1);
  v24 = v13[1] & 0xFFFFFFFE;
  do
    v25 = __ldrex(v23);
  while ( v25 == v24 && __strex(v24 + 2, v23) );
  __dmb(0xBu);
  if ( v25 != v24 )
    ExfAcquireRundownProtection(v23);
  *a6 = v13;
  if ( a9 )
  {
    *a9 = v13[2];
    a9[1] = v13[3];
  }
  return 0;
}
