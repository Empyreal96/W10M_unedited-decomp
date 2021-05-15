// MiSwitchToPfns 
 
int __fastcall MiSwitchToPfns(int a1)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r10
  int *v5; // r6
  int v6; // r8
  int v7; // r4
  unsigned int v8; // r7
  int v9; // r1
  _DWORD *v10; // lr
  int v11; // r0

  if ( !dword_640500 )
    return sub_96B214(0);
  MiInitializeLargePageNodeLists((int)MiSystemPartition);
  v3 = *(_DWORD **)(a1 + 24);
  v4 = (_DWORD *)(a1 + 24);
  while ( v3 != v4 )
  {
    v7 = v3[2];
    v6 = v3[4];
    if ( v7 == 2 || v7 == 5 || v7 == 4 || v7 == 24 || v7 == 8 )
    {
      MiCreateFreePfns(v3);
      goto LABEL_7;
    }
    v8 = v3[3];
    if ( !v8 )
    {
      if ( !--v6 )
        goto LABEL_7;
      v8 = 1;
    }
    if ( v7 != 6 && v7 != 32 && v7 != 31 && v7 != 30 && v7 != 23 )
    {
      if ( v7 == 3 )
      {
        if ( v8 <= dword_640504 && v8 + v6 > dword_640504 + 1 )
          v3[4] = dword_640504 - v8 + 1;
      }
      else if ( v7 != 22 )
      {
        v5 = (int *)(MmPfnDatabase + 24 * v8);
        if ( v6 )
        {
          while ( RtlCompareMemoryUlong(v5, (char *)0x18, 0) != (char *)24 )
          {
            if ( v7 == 29 )
            {
              v10 = (_DWORD *)v5[1];
              if ( v10 )
              {
                if ( (unsigned int)(v10 + 0x10000000) > 0x3FFFFF )
                {
                  *v10 = 0;
                }
                else
                {
                  __dmb(0xBu);
                  *v10 = 0;
                  if ( (unsigned int)(v10 + 267649024) <= 0xFFF )
                  {
                    v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v11, (_DWORD *)(v11 + 4 * ((unsigned __int16)v10 & 0xFFF)), 0);
                  }
                }
                v5[1] = 0;
              }
              v9 = 29;
              goto LABEL_25;
            }
LABEL_6:
            v5 += 6;
            if ( !--v6 )
              goto LABEL_7;
          }
          v9 = v7;
LABEL_25:
          MiInitializeUnusablePfn(v5, v9);
          goto LABEL_6;
        }
      }
    }
LABEL_7:
    v3 = (_DWORD *)*v3;
  }
  return KeFlushTb(3, 1);
}
