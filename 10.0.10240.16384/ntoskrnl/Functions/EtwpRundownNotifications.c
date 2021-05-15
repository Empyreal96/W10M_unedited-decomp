// EtwpRundownNotifications 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpRundownNotifications(int result, int *a2, int a3, int a4)
{
  int v4; // r5
  unsigned int v6; // r2
  unsigned __int8 *v7; // r4
  int v8; // r0
  unsigned int v9; // r2
  int *v10; // r6
  int *v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r1
  int v14; // r3
  int *v15; // r1
  int *v16; // r3
  __int64 v17; // kr00_8
  int *v18; // r5
  int v19; // r1
  unsigned int v20; // r0
  int *v21; // r4
  int *v22; // r1 OVERLAPPED
  int *v23; // [sp+0h] [bp-20h] BYREF
  int **v24; // [sp+4h] [bp-1Ch]
  int v25; // [sp+8h] [bp-18h]

  v23 = a2;
  v24 = (int **)a3;
  v25 = a4;
  v4 = *(_DWORD *)(result + 348);
  if ( v4 && (v4 & 1) == 0 )
  {
    v24 = &v23;
    v23 = (int *)&v23;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = (unsigned __int8 *)(v4 + 4);
    v8 = KeAbPreAcquire(v4 + 4, 0, 0);
    do
      v9 = __ldrex(v7);
    while ( __strex(v9 | 1, v7) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
    {
      result = sub_7D6C44(v8);
    }
    else
    {
      if ( v8 )
        *(_BYTE *)(v8 + 14) |= 1u;
      v10 = (int *)(v4 + 8);
      if ( *(_DWORD *)(v4 + 8) != v4 + 8 )
      {
        v11 = *(int **)(v4 + 8);
        while ( v11 != v10 )
        {
          v15 = v11;
          v16 = (int *)v11[3];
          v11 = (int *)*v11;
          if ( v16 == a2 )
          {
            v17 = *(_QWORD *)v15;
            if ( *(int **)(*v15 + 4) != v15 || *(int **)HIDWORD(v17) != v15 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v17) = v17;
            *(_DWORD *)(v17 + 4) = HIDWORD(v17);
            v18 = v23;
            *v15 = (int)v23;
            v15[1] = (int)&v23;
            if ( (int **)v18[1] != &v23 )
              __fastfail(3u);
            v18[1] = (int)v15;
            v23 = v15;
          }
        }
      }
      __pld(v7);
      v19 = *(_DWORD *)v7;
      if ( (*(_DWORD *)v7 & 0xFFFFFFF0) <= 0x10 )
        v20 = 0;
      else
        v20 = v19 - 16;
      if ( (v19 & 2) != 0 )
        goto LABEL_31;
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)v7);
      while ( v12 == v19 && __strex(v20, (unsigned int *)v7) );
      if ( v12 != v19 )
LABEL_31:
        ExfReleasePushLock(v7, v19);
      result = KeAbPostRelease((unsigned int)v7);
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        result = KiCheckForKernelApcDelivery(result);
      while ( 1 )
      {
        v21 = v23;
        if ( v23 == (int *)&v23 )
          break;
        *(_QWORD *)&v22 = *(_QWORD *)v23;
        if ( (int **)v23[1] != &v23 || (int *)v22[1] != v23 )
          __fastfail(3u);
        v23 = v22;
        v22[1] = (int)&v23;
        EtwpUnreferenceDataBlock(v21[2]);
        result = EtwpReleaseQueueEntry(v21, 1);
      }
    }
  }
  return result;
}
