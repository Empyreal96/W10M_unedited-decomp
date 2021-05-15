// ExpScanGeneralLookasideList 
 
int __fastcall ExpScanGeneralLookasideList(_DWORD *a1, unsigned int *a2)
{
  unsigned int *v3; // r9
  int v4; // r6
  unsigned int v6; // r2
  _DWORD *v7; // r4
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r6
  unsigned int v14; // r0
  int v15; // r5
  int v16; // r5
  unsigned int v17; // r0
  unsigned int v18; // r3
  int v20; // [sp+4h] [bp-24h]

  v3 = a2;
  v4 = KfRaiseIrql(2);
  v20 = v4;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51DB90();
  do
    v6 = __ldrex(v3);
  while ( __strex(1u, v3) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire(v3);
  v7 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 != a1 )
  {
    do
    {
      v8 = *(v7 - 8);
      v9 = v7[3];
      v7[3] = v8;
      v10 = v8 - v9;
      v11 = *(v7 - 9);
      v12 = v7[2];
      v13 = *((unsigned __int16 *)v7 - 19);
      v7[2] = v11;
      v14 = v11 - v12;
      if ( v13 != 0xFFFF )
      {
        v15 = *((unsigned __int16 *)v7 - 20);
        if ( v14 >= 0x4B )
        {
          v17 = 1000 * v10 / v14;
          if ( v17 >= 5 )
          {
            v18 = (v13 - v15) * v17 / 0x7D0 + 5;
            if ( v18 > 0x1E )
              v18 = 30;
            v16 = v15 + v18;
            if ( v16 > v13 )
              LOWORD(v16) = v13;
          }
          else
          {
            v16 = v15 - 1;
            if ( v16 < 4 )
              LOWORD(v16) = 4;
          }
        }
        else
        {
          v16 = v15 - 10;
          if ( v16 < 4 )
            LOWORD(v16) = 4;
        }
        *((_WORD *)v7 - 20) = v16;
      }
      v7 = (_DWORD *)*v7;
    }
    while ( v7 != a1 );
    v3 = a2;
    v4 = v20;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v4);
}
