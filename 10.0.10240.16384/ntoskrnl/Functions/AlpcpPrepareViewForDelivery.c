// AlpcpPrepareViewForDelivery 
 
int __fastcall AlpcpPrepareViewForDelivery(_DWORD *a1, int a2, char a3)
{
  _DWORD *v4; // r5
  int *v5; // r7
  unsigned __int8 *v6; // r10
  int v7; // r8
  unsigned int v8; // r4
  unsigned int *v10; // r1
  unsigned int v11; // r2
  int v12; // r2
  int v13; // r2
  unsigned int v14; // r3
  int v15; // r4
  int v16; // r8
  char v17; // r2
  int v18; // r3
  unsigned int *v19; // r6
  unsigned int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r0
  int v23; // r0
  _DWORD *v24; // r8
  int v25; // lr
  int v26; // r4
  bool v27; // zf
  unsigned int *v28; // r10
  int v29; // r0
  int v30; // r1
  int v31; // r3
  int v32; // r3
  int v33; // r3
  int v34; // r3
  unsigned int *v35; // r2
  unsigned int v36; // r1
  int v37; // r1
  char v40[56]; // [sp+10h] [bp-38h] BYREF

  v4 = (_DWORD *)a1[2];
  v5 = 0;
  v6 = (unsigned __int8 *)(v4 - 1);
  v7 = KeAbPreAcquire((unsigned int)(v4 - 1), 0, 0);
  do
    v8 = __ldrex(v6);
  while ( __strex(v8 | 1, v6) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_7F5C2C();
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  *((_BYTE *)v4 - 16) |= 1u;
  __dmb(0xBu);
  v10 = v4 - 3;
  do
  {
    v11 = __ldrex(v10);
    v12 = v11 + 0x10000;
  }
  while ( __strex(v12, v10) );
  __dmb(0xBu);
  if ( v12 <= 0 )
    KeBugCheckEx(24, 0, (int)v4, 38, v12);
  v13 = v4[6];
  if ( (v13 & 1) != 0 )
  {
    if ( a1 != (_DWORD *)v4[11] )
      goto LABEL_32;
    if ( !a2 )
    {
      v5 = (int *)v4[10];
      if ( v5 )
      {
        KiStackAttachProcess(v5[4], 0, (int)v40);
        MmUnsecureVirtualMemory(v5[8]);
        KiUnstackDetachProcess((unsigned int)v40, 0);
        v33 = v5[9];
        v5[8] = 0;
        v5[9] = v33 | 1;
        v4[10] = 0;
      }
      v34 = v4[6];
      v4[11] = 0;
      v4[6] = v34 & 0xFFFFFFFE;
      goto LABEL_16;
    }
    if ( a1[10] )
    {
LABEL_32:
      v15 = -1073741790;
      goto LABEL_18;
    }
  }
  else if ( a2 )
  {
    if ( !a1[10] )
    {
      v14 = v4[7];
      if ( v14 <= 2 )
      {
        if ( v14 == 1 )
        {
          v4[6] = v13 | 1;
          v4[11] = a1;
        }
        else
        {
          v24 = (_DWORD *)v4[8];
          if ( v24 == a1 )
            v24 = (_DWORD *)*v24;
          v25 = MmSecureVirtualMemoryAgainstWrites(a1[4], a1[5], a1[6]);
          if ( !v25 )
          {
            v15 = 0;
            goto LABEL_17;
          }
          v26 = *(a1 - 3);
          v27 = v26 == 0;
          if ( v26 <= 0 )
          {
LABEL_46:
            if ( !v27 )
              KeBugCheckEx(24, 0, (int)a1, 32, v26);
          }
          else
          {
            v28 = a1 - 3;
            while ( 1 )
            {
              v29 = v26;
              __dmb(0xBu);
              do
                v30 = __ldrex(v28);
              while ( v30 == v26 && __strex(v26 + 1, v28) );
              v26 = v30;
              __dmb(0xBu);
              if ( v30 == v29 )
                break;
              if ( v30 <= 0 )
              {
                v27 = v30 == 0;
                goto LABEL_46;
              }
            }
          }
          v31 = a1[9];
          a1[8] = v25;
          a1[9] = v31 & 0xFFFFFFFE;
          v32 = v4[6];
          v4[10] = a1;
          v4[11] = v24;
          v4[6] = v32 | 1;
        }
      }
    }
  }
LABEL_16:
  v15 = 0;
LABEL_17:
  ++a1[10];
LABEL_18:
  v16 = 0;
  a1[9] ^= ((unsigned __int8)a1[9] ^ (unsigned __int8)(2 * a3)) & 2;
  v17 = *((_BYTE *)v4 - 16);
  if ( (v17 & 1) != 0 )
  {
    v18 = *((__int16 *)v4 - 7);
    *((_WORD *)v4 - 7) = 0;
    v16 = 0x10000 - v18;
    *((_BYTE *)v4 - 16) = v17 & 0xFE;
  }
  v19 = v4 - 1;
  __dmb(0xBu);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 - 1, v19) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock(v4 - 1);
  KeAbPostRelease((unsigned int)(v4 - 1));
  if ( v16 > 0 )
  {
    __dmb(0xBu);
    v21 = v4 - 3;
    do
    {
      v22 = __ldrex(v21);
      v23 = v22 - v16;
    }
    while ( __strex(v23, v21) );
    __dmb(0xBu);
    if ( v23 <= 0 )
    {
      if ( v23 )
        KeBugCheckEx(24, 0, (int)v4, 40, v23);
      AlpcpDestroyBlob(v4);
    }
  }
  if ( v5 )
  {
    __dmb(0xBu);
    v35 = (unsigned int *)(v5 - 3);
    do
    {
      v36 = __ldrex(v35);
      v37 = v36 - 1;
    }
    while ( __strex(v37, v35) );
    __dmb(0xBu);
    if ( v37 <= 0 )
    {
      if ( v37 )
        KeBugCheckEx(24, 0, (int)v5, 33, v37);
      AlpcpDestroyBlob(v5);
    }
  }
  return v15;
}
