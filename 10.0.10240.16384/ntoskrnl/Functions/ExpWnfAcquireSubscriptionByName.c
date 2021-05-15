// ExpWnfAcquireSubscriptionByName 
 
int __fastcall ExpWnfAcquireSubscriptionByName(__int64 a1, int a2, int **a3)
{
  unsigned int *v3; // r5
  int v6; // r4
  int v7; // r0
  int *v8; // r2
  int *v9; // r1
  int *v10; // r6
  __int64 v11; // kr00_8
  unsigned int v12; // r2
  int result; // r0
  unsigned int *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r2
  int varg_r2; // [sp+28h] [bp+10h]
  int **varg_r3; // [sp+2Ch] [bp+14h]

  varg_r2 = a2;
  varg_r3 = a3;
  v3 = (unsigned int *)(a2 + 40);
  v6 = KeAbPreAcquire(a2 + 40, 0, 0);
  do
    v7 = __ldrex(v3);
  while ( !v7 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v7 )
    v7 = ExfAcquirePushLockSharedEx(v3, v6, (unsigned int)v3);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = *(int **)(a2 + 44);
  v9 = (int *)(a2 + 44);
  if ( v8 == (int *)(a2 + 44) )
  {
LABEL_12:
    __dmb(0xBu);
    do
      v12 = __ldrex(v3);
    while ( v12 == 17 && __strex(0, v3) );
    if ( v12 == 17 )
    {
      KeAbPostRelease((unsigned int)v3);
      result = -1073741772;
    }
    else
    {
      result = sub_7C06E4(v7, 0);
    }
  }
  else
  {
    while ( 1 )
    {
      v10 = v8 - 4;
      v11 = *((_QWORD *)v8 + 2);
      v7 = HIDWORD(v11);
      if ( v11 == a1 )
        break;
      v8 = (int *)*v8;
      if ( v8 == v9 )
        goto LABEL_12;
    }
    v14 = (unsigned int *)(v8 - 3);
    __pld(v8 - 3);
    v15 = *(v8 - 3) & 0xFFFFFFFE;
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 + 2, v14) );
    __dmb(0xBu);
    if ( v16 != v15 )
      ExfAcquireRundownProtection(v14);
    __dmb(0xBu);
    do
      v17 = __ldrex(v3);
    while ( v17 == 17 && __strex(0, v3) );
    if ( v17 != 17 )
      ExfReleasePushLockShared(v3);
    KeAbPostRelease((unsigned int)v3);
    *a3 = v10;
    result = 0;
  }
  return result;
}
