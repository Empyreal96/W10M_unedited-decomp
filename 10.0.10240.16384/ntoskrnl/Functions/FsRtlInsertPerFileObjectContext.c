// FsRtlInsertPerFileObjectContext 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlInsertPerFileObjectContext(int a1, _QWORD *a2, int a3, int a4)
{
  int result; // r0
  int v7; // r4
  _DWORD *v8; // r0
  int v9; // r3
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  _DWORD *v13; // r2 OVERLAPPED
  int v14; // r1 OVERLAPPED
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21[4]; // [sp+0h] [bp-10h] BYREF

  v21[0] = a4;
  if ( !a1 )
    return sub_51E86C();
  result = IoGetFileObjectFilterContext(a1, v21, 1);
  if ( result >= 0 )
  {
    v7 = v21[0];
    if ( v21[0] )
      goto LABEL_7;
    v8 = (_DWORD *)ExAllocatePoolWithTag(512, 12, 1480806214);
    v7 = (int)v8;
    v21[0] = (int)v8;
    if ( !v8 )
      return -1073741670;
    *v8 = 0;
    v8[1] = v8 + 1;
    v8[2] = v8 + 1;
    if ( IoChangeFileObjectFilterContext(a1, v8, 1) >= 0
      || (ExFreePoolWithTag(v7, 0), IoGetFileObjectFilterContext(a1, v21, 0), (v7 = v21[0]) != 0) )
    {
LABEL_7:
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
      v13 = (_DWORD *)(v7 + 4);
      v14 = *(_DWORD *)(v7 + 4);
      *a2 = *(_QWORD *)&v14;
      if ( *(_DWORD *)(v14 + 4) != v7 + 4 )
        __fastfail(3u);
      __pld((void *)v7);
      *(_DWORD *)(v14 + 4) = a2;
      *v13 = a2;
      v15 = *(_DWORD *)v7;
      if ( (*(_DWORD *)v7 & 0xFFFFFFF0) > 0x10 )
        v16 = v15 - 16;
      else
        v16 = 0;
      if ( (v15 & 2) != 0 )
        goto LABEL_28;
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)v7);
      while ( v17 == v15 && __strex(v16, (unsigned int *)v7) );
      if ( v17 != v15 )
LABEL_28:
        ExfReleasePushLock(v7);
      v18 = KeAbPostRelease(v7);
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v20 = *(_WORD *)(v19 + 0x134) + 1;
      *(_WORD *)(v19 + 308) = v20;
      if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
        KiCheckForKernelApcDelivery(v18);
      result = 0;
    }
    else
    {
      result = -1073741823;
    }
  }
  return result;
}
