// VfSuspectDriversParseRegistryString 
 
void __fastcall VfSuspectDriversParseRegistryString(int a1, int a2, int a3, int a4)
{
  __int16 *v4; // r1
  BOOL v5; // r7
  __int16 *v6; // r6
  int v7; // r3
  __int16 *i; // r4
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // r3
  int *v13; // r5
  int *v14; // r5
  int **v15; // r2
  int v16; // [sp+0h] [bp-20h] BYREF
  __int16 *v17; // [sp+4h] [bp-1Ch]

  v16 = a3;
  v17 = (__int16 *)a4;
  v4 = MmVerifyDriverBuffer;
  v5 = (VfOptionFlags & 1) == 0;
  v6 = &MmVerifyDriverBuffer[(unsigned int)(MmVerifyDriverBufferLength - 2) >> 1];
  if ( MmVerifyDriverBuffer < v6 )
  {
    do
    {
      v7 = (unsigned __int16)*v4;
      if ( v7 == 9 || v7 == 10 || v7 == 13 || v7 == 32 || v7 == 12288 || !*v4 )
      {
        ++v4;
        continue;
      }
      if ( v7 == 42 && v5 )
      {
        ViVerifyAllDrivers = 1;
        return;
      }
      if ( v7 == 34 )
      {
        i = ++v4 + 1;
        if ( v4 + 1 >= v6 )
          return;
        do
        {
          if ( *i == 34 )
            break;
          ++i;
        }
        while ( i < v6 );
        if ( i >= v6 )
          return;
      }
      else
      {
        for ( i = v4 + 1; i < v6; ++i )
        {
          v9 = (unsigned __int16)*i;
          if ( v9 == 9 || v9 == 10 || v9 == 13 || v9 == 32 || v9 == 12288 || !*i )
            break;
        }
      }
      v10 = 2 * (i - v4);
      if ( v10 )
      {
        v11 = (unsigned __int16)v10;
        v12 = (unsigned __int16)(v10 + 2);
        HIWORD(v16) = v12;
        LOWORD(v16) = v11;
        if ( v12 < v11 )
          return;
        v17 = v4;
        if ( v5 )
        {
          v13 = (int *)VfSuspectDriversAllocateEntry((unsigned __int16 *)&v16);
          if ( v13 )
          {
            VfDriverLock();
            VfSuspectDriversInsert(v13);
LABEL_33:
            VfDriverUnlock();
            goto LABEL_34;
          }
        }
        else
        {
          v14 = (int *)VfSuspectExcludedDriversAllocateEntry((unsigned __int16 *)&v16, 1145398870);
          if ( v14 )
          {
            VfDriverLock();
            v15 = (int **)dword_61CF0C;
            *v14 = (int)&VfExcludedDriversList;
            v14[1] = (int)v15;
            if ( *v15 != &VfExcludedDriversList )
              __fastfail(3u);
            *v15 = v14;
            dword_61CF0C = (int)v14;
            goto LABEL_33;
          }
        }
      }
LABEL_34:
      v4 = i + 1;
    }
    while ( v4 < v6 );
  }
}
