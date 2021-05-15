// MiScrubNode 
 
__int16 *__fastcall MiScrubNode(_DWORD *a1)
{
  _DWORD *v2; // r2
  unsigned int v3; // r8
  __int16 *result; // r0
  unsigned __int8 *v5; // r10
  int v6; // t1
  __int64 v7; // kr00_8
  unsigned int v8; // r5
  int v9; // r6
  unsigned int *v10; // r7
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned __int8 *v14; // r1
  int v15; // r3
  unsigned int v16; // r1
  int v17; // [sp+10h] [bp-28h] BYREF
  int v18; // [sp+14h] [bp-24h]
  int v19[8]; // [sp+18h] [bp-20h] BYREF

  v2 = (_DWORD *)a1[7];
  v3 = 0;
  if ( *v2 )
  {
    result = MiSystemPartition;
    v5 = (unsigned __int8 *)&v2[2 * *v2 + 2];
    do
    {
      v6 = *v5;
      v5 += 2;
      if ( v6 == a1[8] )
      {
        v7 = *(_QWORD *)(a1[7] + 8 * v3 + 8);
        v8 = HIDWORD(v7) + v7 - 1;
        v9 = MmPfnDatabase + 24 * v8;
        if ( v8 >= (unsigned int)v7 )
        {
          v10 = (unsigned int *)(v9 + 12);
          do
          {
            if ( !(_DWORD)v7 )
              break;
            if ( *(_DWORD *)(a1[5] + 4) )
              return result;
            v17 = 0;
            if ( !MiPfnsWorthTrying((unsigned __int16)MiSystemPartition[0], v9, 1, 100663296, &v17, v19) )
            {
              if ( v17 == 1 )
                MiEmptyKernelStackCache();
              if ( !MiClaimPhysicalRun(MiSystemPartition, v8, 1, (int)a1, 100663296, -1, 0) )
              {
                v17 = MiScrubPage(a1, 0, v9);
                v18 = KfRaiseIrql(2);
                v11 = (unsigned __int8 *)(v9 + 15);
                do
                {
                  v12 = __ldrex(v11);
                  v13 = __strex(v12 | 0x80, v11);
                }
                while ( v13 );
                __dmb(0xBu);
                if ( v12 >> 7 )
                {
                  v14 = (unsigned __int8 *)v10 + 3;
                  do
                  {
                    do
                    {
                      __dmb(0xAu);
                      __yield();
                      v15 = *v10;
                      __dmb(0xBu);
                    }
                    while ( v15 < 0 );
                    do
                      v13 = __ldrex(v14);
                    while ( __strex(v13 | 0x80, v14) );
                    __dmb(0xBu);
                  }
                  while ( v13 >> 7 );
                }
                if ( v17 < 0 || (*(_BYTE *)(v9 + 19) & 0x40) != 0 )
                  MiMakePageBad(v9, 1, (unsigned int *)v13);
                else
                  MiInsertPageInFreeOrZeroedList(v8, 2);
                __dmb(0xBu);
                do
                  v16 = __ldrex(v10);
                while ( __strex(v16 & 0x7FFFFFFF, v10) );
                KfLowerIrql(v18);
              }
            }
            --v8;
            result = MiSystemPartition;
            v9 -= 24;
            v10 -= 6;
          }
          while ( v8 >= (unsigned int)v7 );
        }
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)a1[7] );
  }
  MiScrubNonPagedPool(a1, a1[8], a1[5]);
  return (__int16 *)MiScrubNodeLargePages(a1, a1[8], a1[5]);
}
