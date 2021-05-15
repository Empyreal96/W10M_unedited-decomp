// CmpNotifyChangeKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpNotifyChangeKey(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v9; // r1
  int *v13; // r4
  int v14; // r7
  int *v15; // r0
  int v16; // r1
  int **v17; // r2
  _DWORD *v18; // r2 OVERLAPPED
  int v19; // r1 OVERLAPPED
  int v20; // r3
  int v21; // r2
  __int64 v22; // r0
  int v24; // lr
  unsigned int v25; // r2
  char v26; // r3
  char v27; // r3
  bool v28; // zf
  _DWORD *v29; // r2
  unsigned int v30; // r3
  __int64 v31; // r0
  int v32; // r2
  _DWORD *v33; // r0
  _DWORD *v34; // r0

  v9 = *(_DWORD *)(a1 + 4);
  if ( (*(_DWORD *)(v9 + 4) & 0x20000) != 0 )
    return sub_806AC4();
  v13 = *(int **)(a1 + 8);
  v14 = *(_DWORD *)(v9 + 20);
  if ( !v13 )
  {
    v15 = (int *)ExAllocatePoolWithQuotaTag(9u, 0x2Cu, 1651395907);
    v13 = v15;
    if ( !v15 )
      JUMPOUT(0x806AC8);
    v15[4] = *(_DWORD *)(a1 + 4);
    v15[6] = a3 & 0x3FFFFFFF | ((a4 & 1) << 30);
    v15[2] = (int)(v15 + 2);
    v15[3] = (int)(v15 + 2);
    *(_DWORD *)(a1 + 8) = v15;
    v15[5] = a1;
    SeCaptureSubjectContext(v15 + 7, v16, a4 & 1, (int)(v15 + 2));
    v17 = (int **)(v14 + 1800);
    if ( *(_DWORD *)(v14 + 1800) )
    {
      while ( 1 )
      {
        v17 = (int **)*v17;
        if ( (((unsigned int)v17[4][1] >> 21) & 0x3FF) > ((*(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) >> 21) & 0x3FFu) )
          break;
        if ( !*v17 )
          goto LABEL_8;
      }
      *v13 = (int)v17;
      *v17[1] = (int)v13;
      v13[1] = (int)v17[1];
      v17[1] = v13;
    }
    else
    {
LABEL_8:
      *v17 = v13;
      *v13 = 0;
      v13[1] = (int)v17;
    }
  }
  v18 = v13 + 2;
  v19 = v13[2];
  *(_QWORD *)a2 = *(_QWORD *)&v19;
  if ( *(int **)(v19 + 4) != v13 + 2 )
    __fastfail(3u);
  *(_DWORD *)(v19 + 4) = a2;
  *v18 = a2;
  if ( (*(_DWORD *)(a2 + 28) & 0x10000) != 0 )
  {
    *(_DWORD *)(a2 + 16) = a2 + 16;
    *(_DWORD *)(a2 + 20) = a2 + 16;
  }
  else
  {
    v32 = a2 + 16;
    v33 = *(_DWORD **)(a7 + 20);
    *(_DWORD *)(a2 + 16) = a7 + 16;
    *(_DWORD *)(a2 + 20) = v33;
    if ( *v33 != a7 + 16 )
      __fastfail(3u);
    *v33 = v32;
    *(_DWORD *)(a7 + 20) = v32;
  }
  v20 = *(unsigned __int16 *)(a2 + 28);
  if ( v20 == 4 || v20 == 3 )
  {
    v21 = a2 + 8;
    v22 = __PAIR64__(&CmpAsyncKernelPostList, (unsigned int)off_920020);
    *(_DWORD *)(a2 + 8) = &CmpAsyncKernelPostList;
    *(_DWORD *)(a2 + 12) = v22;
    if ( *(int **)v22 != &CmpAsyncKernelPostList )
      __fastfail(3u);
    *(_DWORD *)v22 = v21;
    off_920020 = (void *)(a2 + 8);
  }
  else
  {
    v24 = KfRaiseIrql(1);
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v26 = *(_BYTE *)(v25 + 0x3C8);
    __dmb(0xBu);
    if ( (v26 & 8) == 0 )
    {
      v27 = *(_BYTE *)(v25 + 968) | 8;
      __dmb(0xBu);
      *(_BYTE *)(v25 + 968) = v27;
      __dmb(0xFu);
      *(_DWORD *)(v25 + 856) = v25 + 852;
      *(_DWORD *)(v25 + 852) = v25 + 852;
    }
    v28 = (*(_DWORD *)(a2 + 28) & 0x10000) == 0;
    v29 = (_DWORD *)(a2 + 8);
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v28 )
    {
      v34 = *(_DWORD **)(v30 + 856);
      *v29 = v30 + 852;
      *(_DWORD *)(a2 + 12) = v34;
      if ( *v34 != v30 + 852 )
        __fastfail(3u);
      *v34 = v29;
      *(_DWORD *)(v30 + 856) = v29;
    }
    else
    {
      HIDWORD(v31) = v30 + 852;
      LODWORD(v31) = *(_DWORD *)(v30 + 852);
      *(_QWORD *)v29 = v31;
      if ( *(_DWORD *)(v31 + 4) != v30 + 852 )
        __fastfail(3u);
      *(_DWORD *)(v31 + 4) = v29;
      *(_DWORD *)HIDWORD(v31) = v29;
    }
    v22 = KfLowerIrql(v24);
  }
  if ( (dword_682608 & 0x2000000) != 0 )
    CmpLogNotificationRegister(
      a2,
      *(_DWORD *)(a1 + 4),
      (unsigned __int16)*(_DWORD *)(a2 + 28),
      a4,
      (*(_DWORD *)(a2 + 28) & 0x10000) != 0);
  if ( v13[6] >= 0 )
    return 259;
  CmpPostNotify((int)v13, SHIDWORD(v22), v21, 268, 1, 0, 0);
  return 0;
}
