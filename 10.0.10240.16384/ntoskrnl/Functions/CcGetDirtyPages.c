// CcGetDirtyPages 
 
int __fastcall CcGetDirtyPages(_DWORD *a1, int a2, void (__fastcall *a3)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD), int a4, int a5)
{
  int v5; // r5
  int v6; // r10
  int v7; // r0
  _DWORD *i; // r4
  int v9; // r2
  unsigned __int8 *v10; // r6
  int v11; // r5
  int v12; // r8
  unsigned int v13; // r2
  int j; // r5
  int v15; // r9
  unsigned int *v16; // r8
  int v17; // r6
  unsigned int v18; // r1
  int v19; // r6
  int v20; // r6
  int v21; // r9
  unsigned int v22; // r2
  unsigned int v23; // r3
  unsigned int *v24; // r5
  int v25; // r6
  unsigned int v26; // r1
  unsigned int *v27; // r5
  unsigned int k; // r0
  unsigned int v29; // r1
  int v31; // [sp+14h] [bp-5Ch]
  __int64 v36; // [sp+38h] [bp-38h] BYREF
  _DWORD v37[2]; // [sp+40h] [bp-30h] BYREF
  _DWORD _48[11]; // [sp+48h] [bp-28h] BYREF
  _DWORD *varg_r0; // [sp+78h] [bp+8h]
  int varg_r1; // [sp+7Ch] [bp+Ch]
  void (__fastcall *varg_r2)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a2;
  varg_r0 = a1;
  v6 = 0;
  *a1 = 0;
  a1[1] = 0;
  v7 = KeAcquireQueuedSpinLock(5);
  for ( i = (_DWORD *)(CcDirtySharedCacheMapWithLogHandleList - 80);
        i + 20 != &CcDirtySharedCacheMapWithLogHandleList;
        i = (_DWORD *)(i[20] - 80) )
  {
    v9 = i[24];
    if ( (v9 & 0x800) != 0 )
      KeBugCheckEx(52, 962, -1073740768);
    if ( (v9 & 0x2000000) != 0 && i[38] == v5 || (v9 & 0x1000000) != 0 && *(_DWORD *)i[38] == v5 )
    {
      ++i[1];
      ++i[19];
      KeReleaseQueuedSpinLock(5, v7);
      v31 = ObFastReferenceObject(i + 17);
      if ( !v31 )
        v31 = CcSlowReferenceSharedCacheMapFileObject((int)i);
      v10 = (unsigned __int8 *)(i + 45);
      v11 = KeAbPreAcquire((unsigned int)(i + 45), 0, 0);
      v12 = KfRaiseIrql(1);
      do
        v13 = __ldrex(v10);
      while ( __strex(v13 & 0xFE, v10) );
      __dmb(0xBu);
      if ( (v13 & 1) == 0 )
        ExpAcquireFastMutexContended((int)(i + 45), v11);
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
      i[46] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      i[52] = v12;
      for ( j = i[4] - 16; (_DWORD *)(j + 16) != i + 4; j = *(_DWORD *)(j + 16) - 16 )
      {
        if ( *(_WORD *)j == 765 && *(_BYTE *)(j + 2) )
        {
          _48[0] = *(_DWORD *)(j + 8);
          _48[1] = *(_DWORD *)(j + 12);
          v15 = *(_DWORD *)(j + 4);
          v36 = *(_QWORD *)(j + 32);
          v37[0] = *(_DWORD *)(j + 40);
          v37[1] = *(_DWORD *)(j + 44);
          ++*(_DWORD *)(j + 52);
          v16 = i + 45;
          i[46] = 0;
          v17 = i[52];
          __dmb(0xBu);
          do
            v18 = __ldrex(v16);
          while ( !v18 && __strex(1u, v16) );
          if ( v18 )
            ExpReleaseFastMutexContended(i + 45, v18);
          KfLowerIrql((unsigned __int8)v17);
          KeAbPostRelease((unsigned int)(i + 45));
          if ( v6 )
          {
            CcUnpinFileDataEx(v6, 1, 1);
            v6 = 0;
          }
          a3(v31, _48, v15, &v36, v37, a4, a5);
          v19 = HIDWORD(v36);
          if ( v36 && (!*(_QWORD *)a1 || v36 < *(_QWORD *)a1) )
          {
            *a1 = v36;
            a1[1] = v19;
          }
          v20 = KeAbPreAcquire((unsigned int)(i + 45), 0, 0);
          v21 = KfRaiseIrql(1);
          do
            v22 = __ldrex((unsigned __int8 *)v16);
          while ( __strex(v22 & 0xFE, (unsigned __int8 *)v16) );
          __dmb(0xBu);
          if ( (v22 & 1) == 0 )
            ExpAcquireFastMutexContended((int)(i + 45), v20);
          if ( v20 )
            *(_BYTE *)(v20 + 14) |= 1u;
          i[46] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          i[52] = v21;
          v23 = *(_DWORD *)(j + 52);
          if ( v23 <= 1 )
            v6 = j;
          else
            *(_DWORD *)(j + 52) = v23 - 1;
        }
      }
      v24 = i + 45;
      i[46] = 0;
      v25 = i[52];
      __dmb(0xBu);
      do
        v26 = __ldrex(v24);
      while ( !v26 && __strex(1u, v24) );
      if ( v26 )
        ExpReleaseFastMutexContended(i + 45, v26);
      KfLowerIrql((unsigned __int8)v25);
      KeAbPostRelease((unsigned int)(i + 45));
      v27 = i + 17;
      __pld(i + 17);
      for ( k = i[17]; (k ^ v31) < 7; k = v29 )
      {
        __dmb(0xBu);
        do
          v29 = __ldrex(v27);
        while ( v29 == k && __strex(k + 1, v27) );
        if ( v29 == k )
          goto LABEL_54;
      }
      ObDereferenceObjectDeferDeleteWithTag(v31);
LABEL_54:
      if ( v6 )
      {
        CcUnpinFileDataEx(v6, 1, 1);
        v6 = 0;
      }
      v7 = KeAcquireQueuedSpinLock(5);
      --i[1];
      --i[19];
      v5 = a2;
    }
  }
  KeReleaseQueuedSpinLock(5, v7);
  return (int)varg_r0;
}
