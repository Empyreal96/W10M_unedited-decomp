// KeFlushMultipleRangeCurrentTb 
 
int __fastcall KeFlushMultipleRangeCurrentTb(int result, _DWORD *a2, int a3)
{
  int v3; // r6
  _DWORD *v5; // r8
  int v6; // r7
  int *v7; // lr
  int v8; // r4
  int v9; // t1
  int v10; // r2
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r0
  int v14; // r4

  v3 = result;
  v5 = a2;
  if ( result )
  {
    v6 = result;
    result = -1069547521;
    v7 = a2;
    while ( 1 )
    {
      v9 = *v7++;
      v8 = v9;
      __dsb(0xFu);
      __mcr(15, 0, v9 & 0xFFFFF000, 8, 7, 3);
      if ( (v9 & 0xFFFFF000) >= 0xC0000000 )
        break;
      v10 = v8 & 0x7FF;
      if ( (v8 & 0x800) != 0 )
        v11 = 0x400000;
      else
        v11 = 4096;
      if ( (v8 & 0x7FF) != 0 )
      {
        do
        {
          v8 += v11;
          __mcr(15, 0, v8 & 0xFFFFF000, 8, 7, 3);
          if ( (v8 & 0xFFFFF000) >= 0xC0000000 && (v8 & 0xFFFFF000) <= 0xC03FFFFF )
          {
            v12 = (v8 & 0xFFFFF000) << 10;
            v13 = 4;
            do
            {
              __mcr(15, 0, v12, 8, 7, 3);
              v12 += 0x100000;
              --v13;
            }
            while ( v13 );
            result = -1069547521;
          }
          --v10;
        }
        while ( v10 );
      }
      __dsb(0xFu);
      __isb(0xFu);
      if ( !--v6 )
        goto LABEL_11;
    }
    result = sub_50A124(-1069547521);
  }
  else
  {
LABEL_11:
    if ( VmTbFlushEnabled )
      result = VmFlushTb(v3, v5);
    if ( ExTbFlushActive )
    {
      v14 = KfRaiseIrql(15);
      ExFlushTb(v3, v5, a3);
      result = KfLowerIrql(v14);
    }
  }
  return result;
}
