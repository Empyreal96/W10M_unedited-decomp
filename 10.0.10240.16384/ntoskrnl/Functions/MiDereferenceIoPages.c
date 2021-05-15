// MiDereferenceIoPages 
 
int __fastcall MiDereferenceIoPages(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r7
  int v6; // r5
  int v7; // r9
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r8
  unsigned int v11; // r2
  int v12; // r3
  __int64 v13; // kr00_8
  int v14; // r2
  _DWORD *v15; // r6
  _WORD *v16; // r7
  unsigned int v17; // r3
  __int16 v18; // r3
  unsigned int v19; // r2
  int result; // r0
  _DWORD *i; // r3
  int *v22; // r5
  __int16 *v23; // r2
  __int16 *v24; // r1
  __int16 v25; // t1
  int v26; // r1
  int **v27; // r0
  _DWORD *v28; // r5
  int v29; // r6
  int v30; // r2
  _DWORD *v31; // r5
  int v32; // r7
  int v33; // r2
  _DWORD *v34; // r3
  _DWORD *v35; // r3
  int v36; // [sp+Ch] [bp-4Ch]
  _DWORD *v37; // [sp+10h] [bp-48h] BYREF
  int *v38; // [sp+14h] [bp-44h]
  int *v39; // [sp+18h] [bp-40h]
  unsigned int v40; // [sp+1Ch] [bp-3Ch]
  int v41; // [sp+20h] [bp-38h]
  int v42; // [sp+24h] [bp-34h]
  int v43; // [sp+28h] [bp-30h]
  _WORD *v44; // [sp+2Ch] [bp-2Ch]
  char v45[40]; // [sp+30h] [bp-28h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v39 = &dword_634884;
  v41 = a3;
  v42 = a2;
  v43 = a1;
  v7 = a2;
  v36 = a3;
  v37 = 0;
  if ( a1 == 1 )
    v38 = &dword_63488C;
  else
    v38 = 0;
  KeAcquireInStackQueuedSpinLock(&dword_634880, v45);
  v8 = v39[a1];
  while ( v8 )
  {
    v9 = MiIoPfnCompare(v4, v8);
    if ( v9 > 0 )
    {
      v8 = *(_DWORD *)(v8 + 4);
    }
    else
    {
      if ( v9 >= 0 )
        break;
      v8 = *(_DWORD *)v8;
    }
  }
  if ( v3 )
  {
    while ( 1 )
    {
      if ( !v8 )
        KeBugCheckEx(26, 399688, v42);
      v10 = *(_DWORD *)(v8 + 4);
      v11 = v8;
      if ( v10 )
      {
        for ( i = *(_DWORD **)v10; i; i = (_DWORD *)*i )
          v10 = (unsigned int)i;
      }
      else
      {
        v12 = *(_DWORD *)(v8 + 8);
        while ( 1 )
        {
          v10 = v12 & 0xFFFFFFFC;
          if ( (v12 & 0xFFFFFFFC) == 0 || *(_DWORD *)v10 == v11 )
            break;
          v12 = *(_DWORD *)(v10 + 8);
          v11 = v10;
        }
      }
      v13 = *(_QWORD *)(v8 + 20);
      v14 = v36;
      v15 = (_DWORD *)v8;
      v16 = (_WORD *)(HIDWORD(v13) + 2 * (v7 - v13));
      v17 = v36 + v7 > (unsigned int)(v13 + 512) ? HIDWORD(v13) + 1024 : HIDWORD(v13) + 2 * (v7 - v13 + v36);
      v40 = v17;
      if ( (unsigned int)v16 < v17 )
        break;
LABEL_23:
      v8 = v10;
      if ( !v14 )
        goto LABEL_24;
    }
LABEL_15:
    v18 = *v16;
    __dmb(0xBu);
    if ( (v18 & 0x3FFF) == 0 )
      KeBugCheckEx(26, 399690, v42);
    __dmb(0xBu);
    *v16++ = v18 & 0xC000 | (v18 - 1) & 0x3FFF;
    v44 = v16;
    if ( ((v18 & 0xC000 | (v18 - 1) & 0x3FFF) & 0x3FFF) != 0 )
      goto LABEL_21;
    v19 = v15[7];
    if ( !v19 )
      return sub_513BC0();
    if ( v19 > 0x200 )
      KeBugCheckEx(26, 399691, v15);
    v15[7] = v19 - 1;
    if ( v19 != 1 )
      goto LABEL_21;
    RtlAvlRemoveNode(&v39[v43], v15);
    v22 = v38;
    if ( v38 )
    {
      v23 = (__int16 *)v15[6];
      v24 = v23 + 512;
      while ( v23 < v24 )
      {
        v25 = *v23++;
        __dmb(0xBu);
        if ( (v25 & 0xC000) == 0x4000 )
        {
          __dmb(0xFu);
          v26 = KiCacheFlushTimeStamp;
          __dmb(0xBu);
          v15[7] = v26;
          if ( (int *)dword_634890 == &dword_634890 )
            dword_634898 = v26;
          v27 = (int **)dword_634894;
          v15[3] = &dword_634890;
          v15[4] = v27;
          if ( *v27 != &dword_634890 )
            __fastfail(3u);
          *v27 = v15 + 3;
          dword_634894 = (int)(v15 + 3);
          v28 = (_DWORD *)*v22;
          v29 = v15[5];
          v30 = 0;
          if ( v28 )
          {
            while ( 1 )
            {
              if ( MiIoPfnCompare(v29, v28) < 0 )
              {
                v35 = (_DWORD *)*v28;
                if ( !*v28 )
                {
                  v30 = 0;
                  break;
                }
              }
              else
              {
                v35 = (_DWORD *)v28[1];
                if ( !v35 )
                {
                  v30 = 1;
                  break;
                }
              }
              v28 = v35;
            }
          }
          RtlAvlInsertNodeEx(v38, v28, v30, v8);
          v15 = 0;
          ++dword_63489C;
          break;
        }
      }
    }
    if ( !v15 )
      goto LABEL_21;
    v31 = v37;
    v32 = v15[5];
    v33 = 0;
    if ( !v37 )
      goto LABEL_46;
    while ( 1 )
    {
      if ( MiIoPfnCompare(v32, v31) < 0 )
      {
        v34 = (_DWORD *)*v31;
        if ( !*v31 )
        {
          v33 = 0;
LABEL_46:
          RtlAvlInsertNodeEx(&v37, v31, v33, v8);
          v16 = v44;
LABEL_21:
          ++v7;
          v14 = --v36;
          if ( (unsigned int)v16 >= v40 )
          {
            v6 = (int)v37;
            goto LABEL_23;
          }
          goto LABEL_15;
        }
      }
      else
      {
        v34 = (_DWORD *)v31[1];
        if ( !v34 )
        {
          v33 = 1;
          goto LABEL_46;
        }
      }
      v31 = v34;
    }
  }
LABEL_24:
  result = KeReleaseInStackQueuedSpinLock(v45);
  while ( v6 )
  {
    RtlAvlRemoveNode(&v37, v6);
    result = ExFreePoolWithTag(v6, 0);
    v6 = (int)v37;
  }
  return result;
}
