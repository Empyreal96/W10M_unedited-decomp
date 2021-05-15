// AlpcSectionDeleteProcedure 
 
int __fastcall AlpcSectionDeleteProcedure(_DWORD *a1)
{
  int result; // r0
  int v3; // r8
  _DWORD *v4; // r4
  unsigned __int8 *v5; // r7
  int v6; // r0
  unsigned int v7; // r2
  unsigned int *v8; // r2
  unsigned int v9; // r1
  int v10; // r1
  unsigned __int8 *v11; // r7
  int v12; // r0
  int v13; // r6
  unsigned int v14; // r2
  _DWORD *v15; // r2
  _DWORD *v16; // r1
  unsigned int v17; // r1
  char v18; // r2
  int v19; // r7
  int v20; // r3
  unsigned int *v21; // r6
  unsigned int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r0
  int v25; // r0

  result = a1[2];
  if ( result )
  {
    result = AlpcDeleteBlobByHandle(result, a1[3], a1);
    a1[2] = 0;
  }
  v3 = a1[5];
  if ( v3 )
  {
    v4 = a1 - 6;
    v5 = (unsigned __int8 *)(a1 - 1);
    v6 = KeAbPreAcquire((unsigned int)(a1 - 1), 0, 0);
    do
      v7 = __ldrex(v5);
    while ( __strex(v7 | 1, v5) );
    __dmb(0xBu);
    if ( (v7 & 1) != 0 )
    {
      result = sub_805F78(v6);
    }
    else
    {
      if ( v6 )
        *(_BYTE *)(v6 + 14) |= 1u;
      *((_BYTE *)a1 - 16) |= 1u;
      __dmb(0xBu);
      v8 = a1 - 3;
      do
      {
        v9 = __ldrex(v8);
        v10 = v9 + 0x10000;
      }
      while ( __strex(v10, v8) );
      __dmb(0xBu);
      if ( v10 <= 0 )
        KeBugCheckEx(24, 0, (int)a1, 38, v10);
      v11 = (unsigned __int8 *)(v3 + 196);
      v12 = KeAbPreAcquire(v3 + 196, 0, 0);
      v13 = v12;
      do
        v14 = __ldrex(v11);
      while ( __strex(v14 | 1, v11) );
      __dmb(0xBu);
      if ( (v14 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 196), v12, v3 + 196);
      if ( v13 )
        *(_BYTE *)(v13 + 14) |= 1u;
      v15 = (_DWORD *)*v4;
      if ( (_DWORD *)*v4 != v4 )
      {
        v16 = (_DWORD *)*(a1 - 5);
        if ( (_DWORD *)v15[1] != v4 || (_DWORD *)*v16 != v4 )
          __fastfail(3u);
        *v16 = v15;
        v15[1] = v16;
        *v4 = v4;
        *(a1 - 5) = a1 - 6;
      }
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)v11);
      while ( __strex(v17 - 1, (unsigned int *)v11) );
      if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v3 + 196));
      KeAbPostRelease(v3 + 196);
      a1[5] = 0;
      v18 = *((_BYTE *)a1 - 16);
      v19 = 0;
      if ( (v18 & 1) != 0 )
      {
        v20 = *((__int16 *)a1 - 7);
        *((_WORD *)a1 - 7) = 0;
        v19 = 0x10000 - v20;
        *((_BYTE *)a1 - 16) = v18 & 0xFE;
      }
      v21 = a1 - 1;
      __dmb(0xBu);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 - 1, v21) );
      if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
        ExfTryToWakePushLock(a1 - 1);
      KeAbPostRelease((unsigned int)(a1 - 1));
      if ( v19 > 0 )
      {
        __dmb(0xBu);
        v23 = a1 - 3;
        do
        {
          v24 = __ldrex(v23);
          v25 = v24 - v19;
        }
        while ( __strex(v25, v23) );
        __dmb(0xBu);
        if ( v25 <= 0 )
        {
          if ( v25 )
            KeBugCheckEx(24, 0, (int)a1, 40, v25);
          AlpcpDestroyBlob((int)a1);
        }
      }
      result = ObfDereferenceObject(v3);
    }
  }
  return result;
}
