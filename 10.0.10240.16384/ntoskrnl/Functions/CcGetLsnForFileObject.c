// CcGetLsnForFileObject 
 
// local variable allocation has failed, the output may be wrong!
unsigned int *__fastcall CcGetLsnForFileObject(unsigned int *a1, int a2, _QWORD *a3)
{
  unsigned int *v3; // r4
  unsigned int v4; // r7 OVERLAPPED
  _DWORD *v5; // r9
  _QWORD *v6; // r10
  unsigned int v7; // r8 OVERLAPPED
  unsigned int v8; // r6
  int v9; // r5
  int v10; // r1
  unsigned int v11; // r2
  int v12; // r1
  unsigned int v13; // r6
  unsigned int v14; // r4
  __int64 v15; // kr00_8
  int v16; // r5
  unsigned int v17; // r1
  unsigned int v19; // [sp+0h] [bp-30h]
  unsigned int v20; // [sp+4h] [bp-2Ch]
  int v21; // [sp+8h] [bp-28h]

  v3 = a1;
  v4 = 0;
  v5 = *(_DWORD **)(*(_DWORD *)(a2 + 20) + 4);
  v6 = a3;
  v7 = 0;
  v19 = 0;
  v20 = 0;
  if ( v5 )
  {
    v8 = (unsigned int)(v5 + 45);
    v9 = KeAbPreAcquire((unsigned int)(v5 + 45), 0, 0);
    v10 = KfRaiseIrql(1);
    v21 = v10;
    do
      v11 = __ldrex((unsigned __int8 *)v8);
    while ( __strex(v11 & 0xFE, (unsigned __int8 *)v8) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
    {
      ExpAcquireFastMutexContended((int)(v5 + 45), v9);
      v10 = v21;
    }
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    v5[46] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5[52] = v10;
    v12 = v5[4] - 16;
    if ( (_DWORD *)v5[4] != v5 + 4 )
    {
      v13 = 0;
      v14 = 0;
      do
      {
        if ( *(_WORD *)v12 == 765 )
        {
          if ( *(_BYTE *)(v12 + 2) )
          {
            v15 = *(_QWORD *)(v12 + 32);
            if ( v15 )
            {
              if ( !(v4 | v7) || v15 < __SPAIR64__(v7, v4) )
              {
                v7 = HIDWORD(v15);
                v4 = v15;
              }
              if ( *(_QWORD *)(v12 + 40) > __SPAIR64__(v14, v13) )
              {
                v14 = *(_DWORD *)(v12 + 44);
                v13 = *(_DWORD *)(v12 + 40);
              }
            }
          }
        }
        v12 = *(_DWORD *)(v12 + 16) - 16;
      }
      while ( (_DWORD *)(v12 + 16) != v5 + 4 );
      v6 = a3;
      v19 = v13;
      v20 = v14;
      v3 = a1;
      v8 = (unsigned int)(v5 + 45);
    }
    v16 = *(_DWORD *)(v8 + 28);
    *(_DWORD *)(v8 + 4) = 0;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)v8);
    while ( !v17 && __strex(1u, (unsigned int *)v8) );
    if ( v17 )
      ExpReleaseFastMutexContended((unsigned int *)v8, v17);
    KfLowerIrql((unsigned __int8)v16);
    KeAbPostRelease(v8);
    if ( v6 )
      *v6 = *(_QWORD *)&v4;
    *v3 = v19;
    v3[1] = v20;
  }
  else
  {
    *a1 = 0;
    a1[1] = 0;
  }
  return v3;
}
