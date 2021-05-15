// PopFreeHiberContext 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall __spoils<R2,R3,R12> PopFreeHiberContext(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r5
  unsigned int v7; // r2
  unsigned int v8; // r1
  int v9; // r2
  unsigned __int64 v10; // kr00_8
  int v11; // r3
  unsigned int v12; // r0
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  unsigned int v15; // r0
  unsigned int v16; // r0
  int v17[6]; // [sp+8h] [bp-18h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  v4 = dword_61EC98;
  if ( dword_61EC98 )
  {
    if ( PopBcdOpen(v17) >= 0 )
    {
      PopBcdClearPendingResume(v17[0]);
      PopBcdClose(v17[0]);
    }
    v5 = *(_DWORD *)(v4 + 152);
    if ( v5 )
    {
      ExFreePoolWithTag(v5);
      *(_DWORD *)(v4 + 152) = 0;
    }
    while ( *(_DWORD *)(v4 + 80) )
    {
      v6 = *(_DWORD *)(v4 + 80);
      v7 = *(_DWORD *)(v4 + 92);
      *(_DWORD *)(v4 + 80) = *(_DWORD *)v6;
      v8 = *(_DWORD *)(v6 + 20);
      v10 = __PAIR64__(v7, *(_DWORD *)(v4 + 88)) - (v8 >> 12);
      v9 = HIDWORD(v10);
      *(_QWORD *)(v4 + 88) = v10;
      v11 = *(unsigned __int16 *)(v6 + 6);
      if ( (v11 & 1) != 0 )
        MmUnmapLockedPages(*(_DWORD *)(v6 + 12), v6, SHIDWORD(v10));
      MmFreePagesFromMdl(v6, v8, v9, v11);
      ExFreePoolWithTag(v6);
    }
    *(_DWORD *)(v4 + 144) = 0;
    *(_DWORD *)(v4 + 148) = 0;
    while ( *(_DWORD *)(v4 + 40) != v4 + 40 )
    {
      v12 = *(_DWORD *)(v4 + 40);
      *(_QWORD *)&v13 = *(_QWORD *)v12;
      if ( *(_DWORD *)(*(_DWORD *)v12 + 4) != v12 || *v14 != v12 )
        __fastfail(3u);
      *v14 = v13;
      *(_DWORD *)(v13 + 4) = v14;
      ExFreePoolWithTag(v12);
      --*(_DWORD *)(v4 + 48);
    }
    if ( *(_DWORD *)(v4 + 108) && CrashdmpImageEntry && dword_637658 )
      dword_637658();
    if ( *(_QWORD *)(v4 + 88) )
    {
      PopInternalAddToDumpFile(v4, 312, 0);
      KeBugCheckEx(160, 259, 10, v4, 0);
    }
    if ( *(_DWORD *)(v4 + 120) == 1073742484 )
      PopClearHiberFileSignature();
    *(_BYTE *)(v4 + 20) = 0;
    MmUnlockPreChargedPagedPool(*(unsigned int *)algn_61EEDC, dword_61EEE0);
    v15 = *(_DWORD *)(v4 + 180);
    if ( v15 )
      ExFreePoolWithTag(v15);
    v16 = *(_DWORD *)(v4 + 188);
    if ( v16 )
      MmReleaseDumpHibernateResources(v16, *(_DWORD *)(v4 + 160) << 16);
    if ( PopBgkResumePrepared )
    {
      BgkResumeFinished();
      PopBgkResumePrepared = 0;
    }
    memset((_BYTE *)v4, 0, 312);
    dword_61EC98 = 0;
  }
}
