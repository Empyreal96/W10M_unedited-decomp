// MiExtendPagingFileMaximum 
 
int __fastcall MiExtendPagingFileMaximum(_DWORD *a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *v4; // r6
  int *v6; // r9
  unsigned int v7; // r4
  _BYTE *v8; // r8
  unsigned int v9; // r6
  unsigned int v10; // r7
  unsigned int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r4
  int *v14; // r1
  int *v15; // r2
  int *v16; // r3
  int *v17; // r4
  int result; // r0
  unsigned int v19; // r10
  _DWORD *v20; // r4
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned __int8 *v23; // r1
  int v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r3
  int v27; // r2
  unsigned int *v28; // r0
  unsigned int v29; // r5
  unsigned int v31; // [sp+4h] [bp-4Ch]
  _BYTE *v32; // [sp+8h] [bp-48h]
  int v33; // [sp+Ch] [bp-44h]
  char v34[16]; // [sp+10h] [bp-40h] BYREF
  int *v35[4]; // [sp+20h] [bp-30h] BYREF
  int v36; // [sp+30h] [bp-20h]

  v4 = a1;
  RtlSetAllBits(a2 + 1);
  RtlSetAllBits(a2 + 3);
  KeAcquireInStackQueuedSpinLock(v4 + 29, (unsigned int)v34);
  v6 = (int *)v4[16];
  v7 = v6[1];
  if ( a3 )
  {
    v8 = (_BYTE *)(((v4[27] >> 10) & 0x3FFFFC) - 0x40000000);
    v9 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
    v32 = v8;
    v10 = (((4 * (_WORD)v7) & 0xFFF) != 0) + ((4 * v7) >> 12);
    v31 = v10;
    memmove(v9, (int)v8, 4 * v10);
    memset(v8, 0, 4 * v10);
  }
  else
  {
    v9 = 0;
    v10 = 0;
    v8 = 0;
    v31 = 0;
    v32 = 0;
  }
  v11 = 4 * (((v7 & 0x1F) != 0) + (v7 >> 5));
  memmove(a2[2], v6[2], v11);
  memmove(a2[4], v6[4], v11);
  v12 = v6[1];
  v13 = 8 * v11 - v12;
  if ( v13 )
  {
    RtlSetBits((_BYTE *)a2 + 4, v12, v13);
    RtlSetBits((_BYTE *)a2 + 12, v6[3], v13);
  }
  a1[1] = a2[1];
  v14 = (int *)v6[1];
  v15 = (int *)v6[2];
  v16 = (int *)v6[3];
  v35[0] = (int *)*v6;
  v35[1] = v14;
  v35[2] = v15;
  v35[3] = v16;
  v36 = v6[4];
  v35[0] = v6;
  v17 = MiDerefPageFileSpaceBitmaps((int)a1, v35, 1, v36);
  a1[16] = a2;
  a1[27] = a3;
  result = KeReleaseInStackQueuedSpinLock((int)v34);
  if ( v17 )
    result = ExFreePoolWithTag(v17);
  if ( v8 )
  {
    if ( v10 )
    {
      v19 = v10;
      do
      {
        if ( (*(_DWORD *)v9 & 2) != 0 )
        {
          v20 = (_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)v9 >> 12));
          if ( (v20[1] | 0x80000000) != v9 )
          {
            v33 = KfRaiseIrql(2);
            v21 = (unsigned __int8 *)v20 + 15;
            do
              v22 = __ldrex(v21);
            while ( __strex(v22 | 0x80, v21) );
            __dmb(0xBu);
            if ( v22 >> 7 )
            {
              v23 = (unsigned __int8 *)v20 + 15;
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v24 = v20[3];
                  __dmb(0xBu);
                }
                while ( (v24 & 0x80000000) != 0 );
                do
                  v25 = __ldrex(v23);
                while ( __strex(v25 | 0x80, v23) );
                __dmb(0xBu);
              }
              while ( v25 >> 7 );
            }
            KeAcquireInStackQueuedSpinLock(a1 + 29, (unsigned int)v34);
            if ( (*(_DWORD *)v9 & 2) != 0
              && v20 == (_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)v9 >> 12))
              && (v20[1] | 0x80000000) != v9 )
            {
              v26 = *(_DWORD *)(((v9 >> 10) & 0x3FFFFC) - 0x40000000);
              v27 = v20[5];
              v20[1] = v9;
              v20[5] = v27 & 0xFFF00000 | (v26 >> 12);
            }
            KeReleaseInStackQueuedSpinLock((int)v34);
            __dmb(0xBu);
            v28 = v20 + 3;
            do
              v29 = __ldrex(v28);
            while ( __strex(v29 & 0x7FFFFFFF, v28) );
            KfLowerIrql(v33);
          }
        }
        v9 += 4;
        --v19;
      }
      while ( v19 );
      v10 = v31;
      v8 = v32;
    }
    result = MiReleasePtes(&dword_634D58, (unsigned int)v8, v10);
  }
  return result;
}
