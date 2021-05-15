// MiEmptyPteBins 
 
int __fastcall MiEmptyPteBins(int a1, int a2)
{
  int v2; // r2
  int v3; // r10
  int v4; // r0
  unsigned int *v5; // r7
  unsigned int v6; // r6
  unsigned int *v7; // r5
  unsigned int v8; // r4
  unsigned int v9; // r8
  unsigned int v11; // r3
  unsigned __int64 v12; // kr08_8
  int v13; // r3
  unsigned int v14; // r3
  BOOL v15; // r2
  int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r4
  int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r4
  int v22; // [sp+0h] [bp-40h]
  int v24; // [sp+8h] [bp-38h]
  int v25; // [sp+Ch] [bp-34h]
  int v26; // [sp+10h] [bp-30h]
  __int64 v27; // [sp+18h] [bp-28h]

  v2 = a1;
  v25 = a2;
  v3 = 0;
  __dmb(0xFu);
  v4 = KiTbFlushTimeStamp;
  v26 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  v5 = *(unsigned int **)(v2 + 44);
  v22 = (unsigned __int16)KeNumberNodes;
  if ( KeNumberNodes )
  {
    do
    {
      v6 = 0;
      v7 = v5;
      do
      {
        v9 = v7[1];
        v8 = *v7;
        v27 = *(_QWORD *)v7;
        if ( *v7 )
        {
          if ( (v11 = (v4 - v8) & 0xFFFFF, v11 > 2) || (v8 & 1) == 0 && v11 >= 2 || a2 )
          {
            v24 = KfRaiseIrql(2);
            do
              v12 = __ldrexd((unsigned __int64 *)v7);
            while ( __PAIR64__(v12, HIDWORD(v12)) == __PAIR64__(v8, v9) && __strexd(0i64, (unsigned __int64 *)v7) );
            __dmb(0xBu);
            if ( __PAIR64__(v12, HIDWORD(v12)) == __PAIR64__(v8, v9) )
            {
              __dmb(0xFu);
              v13 = KiTbFlushTimeStamp;
              __dmb(0xBu);
              v14 = (v13 - v27) & 0xFFFFF;
              v15 = v14 <= 2 && ((v27 & 1) != 0 || v14 < 2);
              v16 = MiReplenishBitMap(a1, HIDWORD(v27), v15);
              v17 = (unsigned int *)(a1 + 48);
              do
                v18 = __ldrex(v17);
              while ( __strex(v18 + v16, v17) );
              v19 = -v16;
              v20 = v5 + 16;
              do
                v21 = __ldrex(v20);
              while ( __strex(v21 + v19, v20) );
              v3 = 1;
            }
            else
            {
              --v6;
              v7 -= 2;
            }
            KfLowerIrql(v24);
            a2 = v25;
            v4 = v26;
          }
        }
        ++v6;
        v7 += 2;
      }
      while ( v6 < 8 );
      v5 += 18;
      --v22;
    }
    while ( v22 );
  }
  return v3;
}
