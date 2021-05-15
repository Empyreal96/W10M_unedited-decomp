// MiReferenceIoPages 
 
int __fastcall MiReferenceIoPages(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v8; // r6
  int v9; // r5
  int *v10; // r9
  int v11; // r5
  _DWORD *v12; // r4
  int v13; // r0
  _DWORD *v14; // r3
  int v15; // r9
  _BYTE *v16; // r0
  _BYTE *v17; // r9
  _DWORD *v18; // lr
  __int64 v19; // kr00_8
  unsigned __int16 *v20; // r5
  unsigned int v21; // r9
  unsigned __int16 v22; // r3
  unsigned int v23; // r1
  int v24; // r3
  int v26; // r0
  int *v27; // lr
  __int64 *v28; // r1
  int *v29; // r2
  __int64 v30; // kr08_8
  int v31; // r3
  int v32; // r2
  unsigned int v33; // r3
  char *v34; // r0
  char *v35; // r2
  __int16 *v36; // r2
  __int16 *v37; // r0
  __int16 v38; // t1
  __int16 v39; // r1
  __int64 v40; // r1
  unsigned __int16 v41; // [sp+0h] [bp-C0h]
  _BYTE *v42; // [sp+4h] [bp-BCh]
  int *v43; // [sp+8h] [bp-B8h]
  char *v44; // [sp+Ch] [bp-B4h]
  int v45; // [sp+10h] [bp-B0h]
  char *v46; // [sp+14h] [bp-ACh]
  int *v47; // [sp+18h] [bp-A8h]
  char v50[16]; // [sp+30h] [bp-90h] BYREF
  char v51[28]; // [sp+40h] [bp-80h] BYREF
  char v52; // [sp+5Ch] [bp-64h] BYREF

  v8 = a2;
  if ( a5 )
    *a5 = 0;
  if ( a6 )
    *a6 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v9 = 0;
  v47 = &dword_634884[a1];
  if ( a1 == 1 )
    v10 = &dword_63488C;
  else
    v10 = 0;
  v43 = v10;
  KeAcquireInStackQueuedSpinLock(&dword_634880, v50);
  if ( a3 )
  {
    while ( 1 )
    {
      v11 = 0;
      v12 = (_DWORD *)*v47;
      if ( *v47 )
      {
        while ( 1 )
        {
          v13 = MiIoPfnCompare(v8, v12);
          if ( v13 > 0 )
          {
            v14 = (_DWORD *)v12[1];
            if ( !v14 )
            {
              v11 = 1;
              break;
            }
          }
          else
          {
            if ( v13 >= 0 )
            {
              v18 = v12;
              v42 = v12;
              goto LABEL_20;
            }
            v14 = (_DWORD *)*v12;
            if ( !*v12 )
            {
              v11 = 0;
              break;
            }
          }
          v12 = v14;
        }
      }
      if ( v10 && (v15 = *v10, (v42 = (_BYTE *)v15) != 0) )
      {
        v26 = MiIoPfnCompare(v8, v15);
        if ( v26 < 0 )
          return sub_513C40();
        if ( v26 > 0 )
          JUMPOUT(0x513C46);
        RtlAvlRemoveNode(v43, v15);
        v27 = MiState;
        v28 = (__int64 *)(v15 + 12);
        if ( dword_634890 == v15 + 12 )
        {
          v29 = *(int **)(v15 + 12);
          if ( v29 != &dword_634890 )
            dword_634898 = v29[4];
        }
        v30 = *v28;
        if ( *(__int64 **)(*(_DWORD *)v28 + 4) != v28 || *(__int64 **)HIDWORD(v30) != v28 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v30) = v30;
        *(_DWORD *)(v30 + 4) = HIDWORD(v30);
        __dmb(0xFu);
        v31 = KiCacheFlushTimeStamp;
        __dmb(0xBu);
        v32 = *(_DWORD *)(v15 + 28);
        v33 = v31 - v32;
        if ( v33 > 2 || (v32 & 1) == 0 && v33 >= 2 )
        {
          MiInitializeIoPageNodeArray(v15);
          v27 = MiState;
        }
        *(_DWORD *)(v15 + 28) = 0;
        --v27[1927];
        RtlAvlInsertNodeEx(v47, v12, v11, v15);
        v18 = (_DWORD *)v15;
      }
      else
      {
        v16 = (_BYTE *)ExAllocatePoolWithTag(512, 1056, 1867082061);
        v17 = v16;
        v42 = v16;
        if ( !v16 )
        {
          KeReleaseInStackQueuedSpinLock(v50);
          MiDereferenceIoPages(a1, a2, v8 - a2);
          return -1073741670;
        }
        memset(v16, 0, 1056);
        *((_DWORD *)v17 + 5) = v8 & 0xFFFFFE00;
        *((_DWORD *)v17 + 6) = v17 + 32;
        MiInitializeIoPageNodeArray(v17);
        RtlAvlInsertNodeEx(v47, v12, v11, v17);
        v18 = v17;
      }
LABEL_20:
      if ( a6 && !*a6 )
        *a6 = v18;
      v19 = *(_QWORD *)(v18 + 5);
      v20 = (unsigned __int16 *)(HIDWORD(v19) + 2 * (v8 - v19));
      if ( v8 + a3 > (unsigned int)(v19 + 512) )
        v21 = HIDWORD(v19) + 1024;
      else
        v21 = HIDWORD(v19) + 2 * (v8 - v19 + a3);
      for ( ; (unsigned int)v20 < v21; --a3 )
      {
        v22 = *v20;
        __dmb(0xBu);
        v23 = v22;
        if ( (v22 & 0x3FFF) != 0 )
        {
          if ( v22 >> 14 == a4 )
            ++dword_6348A0;
          else
            ++dword_6348A4;
        }
        else
        {
          ++v18[7];
          v24 = v22 >> 14;
          if ( v23 >> 14 == a4 )
          {
            ++dword_6348AC;
          }
          else
          {
            if ( v24 == 1 && v43 && !v45 )
            {
              v34 = v44;
              ++dword_6348B0;
              if ( v44 )
              {
                v35 = v46;
              }
              else
              {
                v34 = v51;
                v44 = v51;
                v35 = &v52;
              }
              *(_DWORD *)v35 = v8;
              v46 = v35 + 4;
              if ( v35 + 4 == v34 + 92 )
              {
                *(_DWORD *)v34 = 0;
                *((_DWORD *)v34 + 4) = 0;
                *((_DWORD *)v34 + 6) = 0;
                *((_DWORD *)v34 + 5) = 0x10000;
                *((_WORD *)v34 + 3) = 2;
                *((_WORD *)v34 + 2) = 92;
                ++dword_6348A8;
                if ( MiFlushCacheMdl(v34) )
                  v45 = 1;
                v18 = v42;
                v44 = 0;
              }
            }
            v23 = (unsigned __int16)((_WORD)a4 << 14);
          }
        }
        if ( a5 )
          *a5 |= 1 << (v23 >> 14);
        v41 = v23 & 0xC000 | (v23 + 1) & 0x3FFF;
        __dmb(0xBu);
        *v20++ = v41;
        ++v8;
      }
      if ( v45 )
      {
        v36 = (__int16 *)v18[6];
        v37 = v36 + 512;
        while ( v36 < v37 )
        {
          v38 = *v36++;
          __dmb(0xBu);
          v39 = v38;
          if ( (v38 & 0x3FFF) == 0 )
          {
            __dmb(0xBu);
            *(v36 - 1) = v39 | 0xC000;
          }
        }
      }
      if ( !a3 )
        break;
      v10 = v43;
    }
    v9 = 0;
    if ( v44 )
    {
      LODWORD(v40) = 0;
      *(_DWORD *)v44 = 0;
      HIDWORD(v40) = (v46 - v44 - 28) >> 2 << 12;
      *((_WORD *)v44 + 2) = 4 * (((unsigned int)(HIDWORD(v40) + 4095) >> 12) + 7);
      *((_QWORD *)v44 + 2) = v40;
      *((_DWORD *)v44 + 6) = 0;
      *((_WORD *)v44 + 3) = 2;
      ++dword_6348A8;
      MiFlushCacheMdl(v44);
    }
  }
  KeReleaseInStackQueuedSpinLock(v50);
  return v9;
}
