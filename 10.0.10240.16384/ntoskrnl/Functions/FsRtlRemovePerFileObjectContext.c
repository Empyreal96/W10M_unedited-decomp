// FsRtlRemovePerFileObjectContext 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlRemovePerFileObjectContext(int a1, int a2, int a3, int a4)
{
  int v7; // r5
  _DWORD *v8; // r4
  int v9; // r3
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  _DWORD *v13; // r2
  int v14; // r1 OVERLAPPED
  _DWORD *v15; // r2 OVERLAPPED
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v22[6]; // [sp+0h] [bp-18h] BYREF

  v22[0] = a4;
  if ( !a1 )
    return sub_51E814();
  IoGetFileObjectFilterContext(a1, v22, 0);
  v7 = v22[0];
  if ( !v22[0] )
    return sub_51E814();
  v8 = 0;
  v9 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
  v10 = KeAbPreAcquire(v7, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex((unsigned __int8 *)v7);
  while ( __strex(v12 | 1, (unsigned __int8 *)v7) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v10, v7);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  if ( a3 )
  {
    v13 = *(_DWORD **)(v7 + 4);
    if ( v13 != (_DWORD *)(v7 + 4) )
    {
      while ( v13[2] != a2 || v13[3] != a3 )
      {
        v13 = (_DWORD *)*v13;
        if ( v13 == (_DWORD *)(v7 + 4) )
          goto LABEL_19;
      }
      goto LABEL_14;
    }
  }
  else if ( a2 )
  {
    v13 = *(_DWORD **)(v7 + 4);
    if ( v13 != (_DWORD *)(v7 + 4) )
    {
      while ( v13[2] != a2 )
      {
        v13 = (_DWORD *)*v13;
        if ( v13 == (_DWORD *)(v7 + 4) )
          goto LABEL_19;
      }
LABEL_14:
      v8 = v13;
      goto LABEL_15;
    }
  }
  else if ( *(_DWORD *)(v7 + 4) != v7 + 4 )
  {
    v8 = *(_DWORD **)(v7 + 4);
LABEL_15:
    if ( v8 )
    {
      *(_QWORD *)&v14 = *(_QWORD *)v8;
      if ( *(_DWORD **)(*v8 + 4) != v8 || (_DWORD *)*v15 != v8 )
        __fastfail(3u);
      *v15 = v14;
      *(_DWORD *)(v14 + 4) = v15;
    }
    goto LABEL_19;
  }
LABEL_19:
  __pld((void *)v7);
  v16 = *(_DWORD *)v7;
  if ( (*(_DWORD *)v7 & 0xFFFFFFF0) > 0x10 )
    v17 = v16 - 16;
  else
    v17 = 0;
  if ( (v16 & 2) != 0 )
    goto LABEL_32;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)v7);
  while ( v18 == v16 && __strex(v17, (unsigned int *)v7) );
  if ( v18 != v16 )
LABEL_32:
    ExfReleasePushLock(v7);
  v19 = KeAbPostRelease(v7);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return (int)v8;
}
