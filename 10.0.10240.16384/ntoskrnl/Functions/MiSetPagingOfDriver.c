// MiSetPagingOfDriver 
 
int __fastcall MiSetPagingOfDriver(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r5
  int v4; // r8
  unsigned int v5; // r9
  int result; // r0
  unsigned int v7; // r1
  int *v8; // r2
  unsigned int v9; // r7
  int v10; // r6
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r2
  unsigned int v15; // r0
  int v16; // r0
  unsigned int v17; // [sp+0h] [bp-C8h]
  int v20; // [sp+Ch] [bp-BCh]
  int v21; // [sp+10h] [bp-B8h] BYREF
  char v22; // [sp+14h] [bp-B4h]
  char v23; // [sp+15h] [bp-B3h]
  int v24; // [sp+18h] [bp-B0h]
  int v25; // [sp+1Ch] [bp-ACh]
  int v26; // [sp+20h] [bp-A8h]
  int v27; // [sp+24h] [bp-A4h]

  v3 = a2;
  v17 = a2 << 10;
  v25 = 0;
  v26 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 33;
  v27 = 0;
  v4 = 0;
  v5 = 0;
  v20 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54E04C();
  do
  {
    v7 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
    v8 = (int *)__strex(v7 | 0x80, (unsigned __int8 *)&dword_634F00 + 3);
  }
  while ( v8 );
  __dmb(0xBu);
  v9 = 0x920u;
  if ( v7 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
  while ( 1 )
  {
    v10 = dword_634F00;
    if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634F00 & 0x40000000) == 0 )
    {
      v8 = &dword_634F00;
      do
        v15 = __ldrex((unsigned int *)&dword_634F00);
      while ( v15 == v10 && __strex(v10 | 0x40000000, (unsigned int *)&dword_634F00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( v3 <= a3 )
  {
    do
    {
      if ( !MiDriverPageMustStayResident(a1, v3, v8) )
      {
        v11 = *(_DWORD *)v3;
        if ( (*(_DWORD *)v3 & 2) != 0 )
        {
          v8 = (int *)(MmPfnDatabase + 24 * (v11 >> 12));
          if ( !*v8 || (*((_BYTE *)v8 + 19) & 8) != 0 )
          {
            v12 = *((unsigned __int16 *)v8 + 8);
            if ( v12 == 1 || v12 == 2 && (*((_BYTE *)v8 + 18) & 8) != 0 )
            {
              if ( !v5 )
                v5 = v3;
              v13 = v11 & 0xFFFFFFFC | 0x400;
              if ( v3 + 0x40000000 > 0x3FFFFF )
              {
                *(_DWORD *)v3 = v13;
              }
              else
              {
                __dmb(0xBu);
                *(_DWORD *)v3 = v13;
                if ( v3 >= 0xC0300000 && v3 <= 0xC0300FFF )
                {
                  v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * (v3 & 0xFFF)), v13);
                }
              }
              MiInsertTbFlushEntry((int)&v21, v17, 1, 0);
            }
          }
        }
        else if ( (v11 & 0x400) != 0 && v5 )
        {
          MiFlushTbList((unsigned int)&v21, v11);
          v4 += MiTrimSystemImagePages(v5, v3 - 4);
          v5 = 0;
        }
      }
      v3 += 4;
      v17 += 4096;
    }
    while ( v3 <= a3 );
    v9 = 2336;
    if ( v5 )
    {
      MiFlushTbList((unsigned int)&v21, v11);
      v4 += MiTrimSystemImagePages(v5, a3);
    }
  }
  result = MiUnlockWorkingSetExclusive((int)&MiState[v9], v20);
  if ( v4 )
  {
    v14 = *(_DWORD *)(a1 + 24);
    if ( v14 == PsNtosImageBase || v14 == PsHalImageBase )
    {
      do
        result = __ldrex((unsigned int *)algn_632F58);
      while ( __strex(result + v4, (unsigned int *)algn_632F58) );
    }
    else
    {
      do
        result = __ldrex((unsigned int *)&algn_632F58[4]);
      while ( __strex(result + v4, (unsigned int *)&algn_632F58[4]) );
    }
  }
  return result;
}
