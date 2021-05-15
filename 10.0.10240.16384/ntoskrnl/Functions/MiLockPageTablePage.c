// MiLockPageTablePage 
 
int __fastcall MiLockPageTablePage(int a1, int a2)
{
  int v3; // r5
  int v4; // r10
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  int v7; // r1
  int result; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r4
  unsigned int v11; // r0
  int i; // r9
  bool v13; // zf
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  BOOL v16; // r4
  unsigned int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r4
  unsigned int *v20; // r2
  unsigned int v21; // r4
  unsigned __int8 *v22; // r1
  int v23; // r3
  unsigned int v24; // r2
  int v25; // r6
  unsigned int v26; // r4
  unsigned __int8 *v27; // r1
  int v28; // r3
  unsigned int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r0
  unsigned int *v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // r4
  unsigned int *v35; // r2
  unsigned int v36; // r0

  v3 = a1;
  if ( a2 == 1 )
    v4 = a1;
  else
    v4 = 0;
  while ( 1 )
  {
    if ( a2 == 1 )
      v3 = MmPfnDatabase + 24 * (*(_DWORD *)(v4 + 20) & 0xFFFFF);
    if ( (*(_DWORD *)(v3 + 12) & 0x3FFFFFFFu) >= 0x10000 )
      break;
LABEL_16:
    if ( !MiChargeResident(MiSystemPartition, 1, 512) )
      return 0;
    do
      v11 = __ldrex(&dword_634A2C[19]);
    while ( __strex(v11 + 1, &dword_634A2C[19]) );
    for ( i = 0; ; i = 1 )
    {
      v13 = i == 1;
      if ( i )
        goto LABEL_34;
      v14 = (unsigned __int8 *)(v3 + 15);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
      {
        v22 = (unsigned __int8 *)(v3 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v3 + 12);
            __dmb(0xBu);
          }
          while ( (v23 & 0x80000000) != 0 );
          do
            v24 = __ldrex(v22);
          while ( __strex(v24 | 0x80, v22) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
      }
      if ( a2 == 1 && v3 != MmPfnDatabase + 24 * (*(_DWORD *)(v4 + 20) & 0xFFFFF) )
        break;
      v16 = (*(_DWORD *)(v3 + 12) & 0x3FFFFFFFu) >= 0x10000;
      if ( !MiIncrementPageTableLockCheckWrap(v3) )
      {
        __dmb(0xBu);
        v35 = (unsigned int *)(v3 + 12);
        do
          v36 = __ldrex(v35);
        while ( __strex(v36 & 0x7FFFFFFF, v35) );
        v25 = 0;
        goto LABEL_47;
      }
      if ( v16 )
      {
        __dmb(0xBu);
        v20 = (unsigned int *)(v3 + 12);
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 & 0x7FFFFFFF, v20) );
        v13 = 0;
LABEL_34:
        if ( v13 )
          return 1;
        v25 = 1;
LABEL_47:
        MiReturnResidentAvailable(1 - i);
        do
          v26 = __ldrex(&dword_634A2C[21]);
        while ( __strex(v26 + 1 - i, &dword_634A2C[21]) );
        return v25;
      }
      v17 = MiCaptureDirtyBitToPfn(v3);
      __dmb(0xBu);
      v18 = (unsigned int *)(v3 + 12);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 & 0x7FFFFFFF, v18) );
      if ( v17 )
        MiReleasePageFileInfo((int)MiSystemPartition, v17, 1, 0);
      v3 = MmPfnDatabase + 24 * (*(_DWORD *)(v3 + 20) & 0xFFFFF);
    }
    __dmb(0xBu);
    v32 = (unsigned int *)(v3 + 12);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 & 0x7FFFFFFF, v32) );
    MiReturnResidentAvailable(1);
    do
      v34 = __ldrex(&dword_634A2C[21]);
    while ( __strex(v34 + 1, &dword_634A2C[21]) );
  }
  v5 = (unsigned __int8 *)(v3 + 15);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
  {
    v27 = (unsigned __int8 *)(v3 + 15);
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v28 = *(_DWORD *)(v3 + 12);
        __dmb(0xBu);
      }
      while ( (v28 & 0x80000000) != 0 );
      do
        v29 = __ldrex(v27);
      while ( __strex(v29 | 0x80, v27) );
      __dmb(0xBu);
    }
    while ( v29 >> 7 );
  }
  if ( a2 == 1 && v3 != MmPfnDatabase + 24 * (*(_DWORD *)(v4 + 20) & 0xFFFFF) )
    return sub_5454FC(0x80000000);
  if ( (*(_DWORD *)(v3 + 12) & 0x3FFFFFFFu) < 0x10000 )
  {
    __dmb(0xBu);
    v30 = (unsigned int *)(v3 + 12);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 & 0x7FFFFFFF, v30) );
    goto LABEL_16;
  }
  v7 = *(_DWORD *)(v3 + 12);
  if ( (v7 & 0x3FFFFFFFu) >= 0x3FFEFBFF )
  {
    result = 0;
  }
  else
  {
    *(_DWORD *)(v3 + 12) = v7 & 0xC0000000 | (v7 + 0x10000) & 0x3FFFFFFF;
    result = 1;
  }
  __dmb(0xBu);
  v9 = (unsigned int *)(v3 + 12);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 & 0x7FFFFFFF, v9) );
  return result;
}
