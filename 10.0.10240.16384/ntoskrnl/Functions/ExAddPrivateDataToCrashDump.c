// ExAddPrivateDataToCrashDump 
 
int __fastcall ExAddPrivateDataToCrashDump(int (__fastcall **a1)(_DWORD, unsigned int, int, int))
{
  int *v1; // r6
  int v2; // r4
  int v3; // r5
  unsigned int v5; // r1
  unsigned int v6; // t1
  int v7; // r0
  unsigned int *v8; // r5
  int v9; // r6
  unsigned int *v10; // r8
  unsigned int v11; // t1
  int v12; // r0
  int v13; // r6
  unsigned int v14; // t1
  int v15; // r0
  int v16; // r0

  v1 = ExPoolTagTables;
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v6 = *v1++;
    v5 = v6;
    if ( v6 )
    {
      v7 = MmAddRangeToCrashDump(a1, v5, 28 * PoolTrackTableSize);
      if ( v7 < 0 )
      {
        v2 = v7;
        if ( v7 == -1073741789 )
          return v2;
      }
    }
    if ( (unsigned int)++v3 >= 0x20 )
    {
      v8 = (unsigned int *)ExpPagedPoolDescriptor;
      v9 = 0;
      if ( ExpNumberOfNonPagedPools )
      {
        v10 = (unsigned int *)ExpNonPagedPoolDescriptor;
        while ( 1 )
        {
          v11 = *v10++;
          v12 = MmAddRangeToCrashDump(a1, v11, 9472);
          if ( v12 < 0 )
          {
            v2 = v12;
            if ( v12 == -1073741789 )
              break;
          }
          if ( ++v9 >= (unsigned int)ExpNumberOfNonPagedPools )
            goto LABEL_11;
        }
      }
      else
      {
LABEL_11:
        v13 = 0;
        if ( ExpNumberOfPagedPools == -1 )
        {
LABEL_15:
          v16 = MmAddRangeToCrashDump(a1, ExpSessionPoolTrackTable, 28 * ExpSessionPoolTrackTableSize);
          if ( v16 < 0 )
            v2 = v16;
        }
        else
        {
          while ( 1 )
          {
            v14 = *v8++;
            v15 = MmAddRangeToCrashDump(a1, v14, 4736);
            if ( v15 < 0 )
            {
              v2 = v15;
              if ( v15 == -1073741789 )
                break;
            }
            if ( ++v13 >= (unsigned int)(ExpNumberOfPagedPools + 1) )
              goto LABEL_15;
          }
        }
      }
      return v2;
    }
  }
}
