// AlpcpEnumerateResourcesPort 
 
int __fastcall AlpcpEnumerateResourcesPort(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r5
  int v7; // r7
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r1
  int *i; // r4
  int *v12; // r6
  int *v13; // t1
  unsigned int v14; // r2

  v4 = (unsigned int *)(a1 + 196);
  v7 = 0;
  v8 = KeAbPreAcquire(a1 + 196, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v4);
  while ( !v10 && __strex(0x11u, v4) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v4, v8, (unsigned int)v4);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v13 = *(int **)(a1 + 200);
  v12 = (int *)(a1 + 200);
  for ( i = v13; i != v12; i = (int *)*i )
  {
    if ( *((_BYTE *)i + 9) == 6 )
    {
      v7 = AlpcpViewSearchCallbackFunction(i + 6, a4);
      if ( v7 < 0 )
        break;
    }
  }
  __dmb(0xBu);
  do
    v14 = __ldrex(v4);
  while ( v14 == 17 && __strex(0, v4) );
  if ( v14 != 17 )
    ExfReleasePushLockShared(v4);
  KeAbPostRelease((unsigned int)v4);
  return v7;
}
