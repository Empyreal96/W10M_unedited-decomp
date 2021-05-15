// ExpWnfLookupNameInstance 
 
int __fastcall ExpWnfLookupNameInstance(int a1, int a2, int a3, int a4, int *a5)
{
  unsigned int *v5; // r6
  int v7; // r0
  int v8; // r4
  int v9; // r1
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r5
  unsigned int *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r2
  int result; // r0
  int varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  v5 = (unsigned int *)(a1 + 28);
  v7 = KeAbPreAcquire(a1 + 28, 0, 0);
  v8 = v7;
  v9 = 17;
  do
    v10 = __ldrex(v5);
  while ( !v10 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v5, v7, (unsigned int)v5);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v11 = ExpWnfFindStateName(a1, v9, a3, a4);
  v12 = v11;
  if ( v11 )
  {
    v13 = (unsigned int *)(v11 + 4);
    __pld((void *)(v12 + 4));
    v14 = *(_DWORD *)(v12 + 4) & 0xFFFFFFFE;
    do
      v15 = __ldrex(v13);
    while ( v15 == v14 && __strex(v14 + 2, v13) );
    __dmb(0xBu);
    if ( v15 != v14 && !ExfAcquireRundownProtection(v13) )
      v12 = 0;
  }
  __dmb(0xBu);
  do
    v16 = __ldrex(v5);
  while ( v16 == 17 && __strex(0, v5) );
  if ( v16 != 17 )
    ExfReleasePushLockShared(v5);
  KeAbPostRelease((unsigned int)v5);
  if ( !v12 )
    return -1073741772;
  result = 0;
  *a5 = v12;
  return result;
}
