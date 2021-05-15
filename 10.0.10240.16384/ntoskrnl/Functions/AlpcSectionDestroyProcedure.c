// AlpcSectionDestroyProcedure 
 
int __fastcall AlpcSectionDestroyProcedure(int *a1)
{
  int v3; // r3
  unsigned __int8 *v4; // r6
  int *v5; // r5
  int v6; // r0
  int v7; // r7
  unsigned int v8; // r2
  int *v9; // r2
  int **v10; // r1
  unsigned int v11; // r1

  if ( a1[2] )
    return sub_7EA074();
  v3 = a1[5];
  if ( v3 )
  {
    v4 = (unsigned __int8 *)(v3 + 196);
    v5 = a1 - 6;
    v6 = KeAbPreAcquire(v3 + 196, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex(v4);
    while ( __strex(v8 | 1, v4) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4, v6, (unsigned int)v4);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = (int *)*v5;
    if ( (int *)*v5 != v5 )
    {
      v10 = (int **)*(a1 - 5);
      if ( (int *)v9[1] != v5 || *v10 != v5 )
        __fastfail(3u);
      *v10 = v9;
      v9[1] = (int)v10;
      *v5 = (int)v5;
      *(a1 - 5) = (int)(a1 - 6);
    }
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)v4);
    while ( __strex(v11 - 1, (unsigned int *)v4) );
    if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v4);
    KeAbPostRelease((unsigned int)v4);
    ObfDereferenceObject(a1[5]);
    a1[5] = 0;
  }
  if ( *a1 )
    ObfDereferenceObject(*a1);
  return 0;
}
