// FsRtlLookupPerFileObjectContext 
 
int __fastcall FsRtlLookupPerFileObjectContext(int a1, int a2, int a3)
{
  int *v6; // r2
  unsigned int *v7; // r6
  unsigned int *v8; // r8
  int v9; // r3
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3

  if ( !a1 )
    return sub_51DC1C();
  v6 = *(int **)(a1 + 124);
  if ( !v6 )
    return 0;
  if ( v6 == IopRevocationExtension )
    return 0;
  v7 = (unsigned int *)v6[4];
  if ( !v7 )
    return 0;
  v8 = 0;
  v9 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
  v10 = KeAbPreAcquire(v7, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v7);
  while ( !v12 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(v7, v10, v7);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  if ( a3 )
  {
    v13 = (unsigned int *)v7[1];
    if ( v13 == v7 + 1 )
      goto LABEL_19;
    while ( v13[2] != a2 || v13[3] != a3 )
    {
      v13 = (unsigned int *)*v13;
      if ( v13 == v7 + 1 )
        goto LABEL_19;
    }
    goto LABEL_18;
  }
  if ( !a2 )
  {
    if ( (unsigned int *)v7[1] != v7 + 1 )
      v8 = (unsigned int *)v7[1];
    goto LABEL_19;
  }
  v13 = (unsigned int *)v7[1];
  if ( v13 != v7 + 1 )
  {
    while ( v13[2] != a2 )
    {
      v13 = (unsigned int *)*v13;
      if ( v13 == v7 + 1 )
        goto LABEL_19;
    }
LABEL_18:
    v8 = v13;
  }
LABEL_19:
  __pld(v7);
  v14 = *v7;
  if ( (*v7 & 0xFFFFFFF0) > 0x10 )
    v15 = v14 - 16;
  else
    v15 = 0;
  if ( (v14 & 2) != 0 )
    goto LABEL_32;
  __dmb(0xBu);
  do
    v16 = __ldrex(v7);
  while ( v16 == v14 && __strex(v15, v7) );
  if ( v16 != v14 )
LABEL_32:
    ExfReleasePushLock(v7);
  v17 = KeAbPostRelease(v7);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return (int)v8;
}
