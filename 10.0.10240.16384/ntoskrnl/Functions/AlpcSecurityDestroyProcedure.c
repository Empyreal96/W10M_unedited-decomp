// AlpcSecurityDestroyProcedure 
 
int __fastcall AlpcSecurityDestroyProcedure(int *a1)
{
  int v2; // r0
  int v3; // r3
  unsigned __int8 *v4; // r7
  int *v5; // r5
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  int *v9; // r2
  int **v10; // r1
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r0
  unsigned int *v14; // r1
  int v15; // r3
  unsigned int v16; // r2

  v2 = *a1;
  if ( v2 )
    AlpcDeleteBlobByHandle(v2, a1[1], a1);
  v3 = a1[3];
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
        sub_805FE8();
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
    ObfDereferenceObject(a1[3]);
  }
  if ( a1[2] )
  {
    v12 = a1[7];
    if ( v12 || MEMORY[0xA8] == 1 )
      ObfDereferenceObject(v12);
    v13 = a1[2];
    if ( v13 )
    {
      v14 = (unsigned int *)(v13 + 668);
      v15 = *(_DWORD *)(v13 + 668);
      __dmb(0xBu);
      if ( (unsigned int)(v15 + 104) >= 0x1000 )
      {
        PsReturnProcessPagedPoolQuota(v13, 0x68u);
      }
      else
      {
        __dmb(0xBu);
        do
          v16 = __ldrex(v14);
        while ( __strex(v16 + 104, v14) );
        __dmb(0xBu);
      }
    }
    ObfDereferenceObjectWithTag(a1[2]);
  }
  return 0;
}
