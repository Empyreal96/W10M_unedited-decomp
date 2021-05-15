// MiDrainZeroLookasides 
 
int __fastcall MiDrainZeroLookasides(int result, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r4
  int v6; // r10
  unsigned int v7; // r8
  int v8; // r6
  unsigned int v9; // r3
  int v10; // r2
  int v11; // r7
  int v12; // r4
  _DWORD *v13; // r5
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned __int8 *v18; // r1
  int v19; // r3
  unsigned int v20; // r2
  int v21; // [sp+0h] [bp-48h]
  int v22; // [sp+4h] [bp-44h]
  unsigned int v24; // [sp+Ch] [bp-3Ch]
  int v25; // [sp+10h] [bp-38h]
  int v26; // [sp+14h] [bp-34h]
  unsigned int v27; // [sp+18h] [bp-30h]
  unsigned int v28; // [sp+1Ch] [bp-2Ch]
  int v29; // [sp+20h] [bp-28h]
  _DWORD *v30; // [sp+24h] [bp-24h]

  v4 = a4;
  v6 = result;
  v25 = result;
  if ( !a2 )
    return sub_526044();
  v7 = a4 + 1;
  v8 = 1;
  v9 = a2 + 24 * a3;
  v10 = 2;
  v26 = 2;
  v27 = v9;
  v24 = v7;
  do
  {
    if ( v4 < v7 )
    {
      v11 = *(_DWORD *)(v6 + 1032) + 8 * v4;
      v21 = v7 - v4;
      v22 = v11;
      v12 = v7 - v4;
      do
      {
        if ( *(_WORD *)(v11 + 4) )
        {
          result = RtlpInterlockedFlushSList((unsigned __int64 *)v11);
          v13 = (_DWORD *)result;
          if ( result )
          {
            do
            {
              v30 = (_DWORD *)*v13;
              v28 = (int)((unsigned __int64)(715827883i64 * ((int)v13 - MmPfnDatabase)) >> 32) >> 2;
              if ( a2 && ((unsigned int)v13 < a2 || (unsigned int)v13 >= v27) )
                v8 &= 0xFFFFFFBF;
              else
                v8 |= 0x40u;
              v29 = KfRaiseIrql(2);
              v14 = (unsigned __int8 *)v13 + 15;
              do
                v15 = __ldrex(v14);
              while ( __strex(v15 | 0x80, v14) );
              __dmb(0xBu);
              if ( v15 >> 7 )
              {
                v18 = (unsigned __int8 *)v13 + 15;
                do
                {
                  do
                  {
                    __dmb(0xAu);
                    __yield();
                    v19 = v13[3];
                    __dmb(0xBu);
                  }
                  while ( v19 < 0 );
                  do
                    v20 = __ldrex(v18);
                  while ( __strex(v20 | 0x80, v18) );
                  __dmb(0xBu);
                }
                while ( v20 >> 7 );
              }
              MiInsertPageInFreeOrZeroedList(v28 + (v28 >> 31), v8);
              __dmb(0xBu);
              v16 = v13 + 3;
              do
                v17 = __ldrex(v16);
              while ( __strex(v17 & 0x7FFFFFFF, v16) );
              result = KfLowerIrql(v29);
              v13 = v30;
            }
            while ( v30 );
            v12 = v21;
            v11 = v22;
          }
        }
        v11 += 8;
        v21 = --v12;
        v22 = v11;
      }
      while ( v12 );
      v4 = a4;
      v7 = v24;
      v6 = v25;
      v10 = v26;
    }
    v8 = 2;
    --v10;
    v6 += 4;
    v25 = v6;
    v26 = v10;
  }
  while ( v10 );
  return result;
}
