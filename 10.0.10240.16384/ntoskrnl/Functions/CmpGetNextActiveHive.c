// CmpGetNextActiveHive 
 
int __fastcall CmpGetNextActiveHive(int a1)
{
  void **v2; // r9
  void ***v3; // r6
  int v4; // r0
  unsigned int v5; // r2
  void **i; // r6
  unsigned int *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  unsigned int *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1

  v2 = 0;
  if ( a1 )
    v3 = (void ***)(a1 + 1808);
  else
    v3 = (void ***)&CmpHiveListHead;
  v4 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
  do
    v5 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&CmpHiveListHeadLock) );
  __dmb(0xBu);
  if ( v5 )
    return sub_7D39F0(v4, 17);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  for ( i = *v3; i != &CmpHiveListHead; v2 = 0 )
  {
    v2 = i - 452;
    v8 = (unsigned int *)(i + 6);
    __pld(i + 6);
    v9 = (unsigned int)i[6] & 0xFFFFFFFE;
    do
      v10 = __ldrex(v8);
    while ( v10 == v9 && __strex(v9 + 2, v8) );
    __dmb(0xBu);
    if ( v10 == v9 )
      break;
    if ( ExfAcquireRundownProtection(v8) )
      break;
    i = (void **)*i;
  }
  __pld(&CmpHiveListHeadLock);
  v11 = CmpHiveListHeadLock;
  if ( (CmpHiveListHeadLock & 0xFFFFFFF0) > 0x10 )
    v12 = CmpHiveListHeadLock - 16;
  else
    v12 = 0;
  if ( (CmpHiveListHeadLock & 2) != 0 )
    goto LABEL_31;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&CmpHiveListHeadLock) );
  if ( v13 != v11 )
LABEL_31:
    ExfReleasePushLock(&CmpHiveListHeadLock, v11);
  KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
  if ( a1 )
  {
    v14 = (unsigned int *)(a1 + 1832);
    __pld((void *)(a1 + 1832));
    v15 = *(_DWORD *)(a1 + 1832) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 - 2, v14) );
    if ( v16 != v15 )
      ExfReleaseRundownProtection((unsigned __int8 *)v14);
  }
  return (int)v2;
}
