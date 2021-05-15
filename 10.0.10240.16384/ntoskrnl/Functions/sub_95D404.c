// sub_95D404 
 
int __fastcall sub_95D404(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v7; // r2
  int v9; // r1
  unsigned __int8 *v10; // r4
  unsigned int i; // r0
  int v12; // t1
  __int64 v13; // kr08_8
  int v14; // r2
  int v15; // r7
  int v16; // r3
  unsigned int v17; // r8
  unsigned int v18; // r1
  unsigned int v19; // r2
  int v20; // r3
  unsigned int v21; // r6
  int v22; // r0
  int v23; // r5
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // [sp+10h] [bp-9Ch]
  int v28; // [sp+14h] [bp-98h] BYREF
  int v29; // [sp+18h] [bp-94h] BYREF
  unsigned int v30[3]; // [sp+1Ch] [bp-90h] BYREF
  unsigned int v31[7]; // [sp+28h] [bp-84h] BYREF
  unsigned int v32; // [sp+44h] [bp-68h]
  unsigned int v33; // [sp+4Ch] [bp-60h]
  int v34; // [sp+54h] [bp-58h]
  int v35; // [sp+58h] [bp-54h]
  int *v36; // [sp+5Ch] [bp-50h]

  v35 = a4;
  v31[1] = a3;
  v28 = 0;
  v29 = 0;
  v30[0] = 0;
  v30[1] = a1;
  if ( ExpValidateFastCacheSize(a1, a2, 0) < 0 )
    JUMPOUT(0x96D55C);
  if ( a2 >= 0x18 )
  {
    v9 = *(_DWORD *)(a3 + 8);
    if ( a2 - 24 == v9 && *(_DWORD *)a3 == 1 )
    {
      v10 = (unsigned __int8 *)(a3 + 24);
      if ( a3 != -24 )
      {
        for ( i = 0; v9; --v9 )
        {
          v12 = *v10++;
          i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v12 - 23737705 + i), 21), 21), 21);
          v7 += v12 - 23737705 + i;
        }
        v13 = *(_QWORD *)(a3 + 16);
        if ( __PAIR64__(i, v7) == v13 )
        {
          if ( ExpParseFastCacheHelper(a3, v31, v30, v13) >= 0 )
          {
            v14 = 5 * a1;
            v15 = v30[0];
            v36 = &dword_920288[2 * v14];
            v16 = *((unsigned __int8 *)v36 + 36);
            v17 = v31[0];
            v34 = v14;
            v33 = v30[0];
            if ( v16 == 1 )
            {
              v18 = 0;
              if ( v31[0] )
              {
                v19 = v30[0];
                do
                {
                  v20 = *(_DWORD *)(v19 + 4);
                  v27 = *(_DWORD *)(v20 + 32);
                  v32 = *(_DWORD *)(v20 + 36);
                  v30[2] = v27 - dword_920280;
                  if ( qword_922C10 < __PAIR64__(v32, v27) - (unsigned int)dword_920280 )
                    JUMPOUT(0x96D1A6);
                  if ( qword_922C10 > __PAIR64__(v32, dword_920280) + v27 )
                    JUMPOUT(0x96D182);
                  ++v18;
                  v19 += 8;
                }
                while ( v18 < v31[0] );
              }
            }
            v21 = a2;
            v22 = sub_7A2A90(a2, &v28, &v29);
            v23 = v29;
            if ( v22 >= 0 )
            {
              memmove(v29, a3, v21);
              if ( !v17 )
              {
                v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                --*(_WORD *)(v24 + 308);
                v25 = KeAbPreAcquire((unsigned int)&ExpFastCacheUpdateLock, 0, 0);
                do
                  v26 = __ldrex((unsigned __int8 *)&ExpFastCacheUpdateLock);
                while ( __strex(v26 | 1, (unsigned __int8 *)&ExpFastCacheUpdateLock) );
                __dmb(0xBu);
                if ( (v26 & 1) == 0 )
                {
                  if ( !v25 )
                    JUMPOUT(0x96D2DA);
                  JUMPOUT(0x96D2D0);
                }
                JUMPOUT(0x96D2BE);
              }
              if ( ExpParseFastCache(v23, v15, v17, 0) >= 0 )
                JUMPOUT(0x96D1B2);
            }
            JUMPOUT(0x96D530);
          }
          JUMPOUT(0x96D544);
        }
        JUMPOUT(0x96D552);
      }
    }
  }
  return sub_96D17C();
}
