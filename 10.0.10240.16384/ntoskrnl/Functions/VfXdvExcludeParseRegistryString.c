// VfXdvExcludeParseRegistryString 
 
void __fastcall VfXdvExcludeParseRegistryString(int a1, int a2, int a3, int a4)
{
  __int16 *v4; // r1
  __int16 *v5; // r5
  int v6; // r3
  __int16 *i; // r4
  int v8; // r3
  int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r3
  int *v12; // r6
  int **v13; // r2
  int v14; // [sp+0h] [bp-20h] BYREF
  __int16 *v15; // [sp+4h] [bp-1Ch]
  int v16; // [sp+8h] [bp-18h]

  v14 = a2;
  v15 = (__int16 *)a3;
  v16 = a4;
  if ( VfXdvSuppressDriversBufferLength == -1 )
  {
    VfXdvSuppressDriversBufferLength = 0;
  }
  else
  {
    v4 = VfXdvSuppressDriversBuffer;
    v5 = &VfXdvSuppressDriversBuffer[(unsigned int)(VfXdvSuppressDriversBufferLength - 2) >> 1];
    if ( VfXdvSuppressDriversBuffer < v5 )
    {
      do
      {
        v6 = (unsigned __int16)*v4;
        if ( v6 == 9 || v6 == 10 || v6 == 13 || v6 == 32 || v6 == 12288 || !*v4 )
        {
          ++v4;
        }
        else
        {
          if ( v6 == 34 )
          {
            i = ++v4 + 1;
            if ( v4 + 1 >= v5 )
              return;
            do
            {
              if ( *i == 34 )
                break;
              ++i;
            }
            while ( i < v5 );
            if ( i >= v5 )
              return;
          }
          else
          {
            for ( i = v4 + 1; i < v5; ++i )
            {
              v8 = (unsigned __int16)*i;
              if ( v8 == 9 || v8 == 10 || v8 == 13 || v8 == 32 || v8 == 12288 || !*i )
                break;
            }
          }
          v9 = 2 * (i - v4);
          if ( v9 )
          {
            v10 = (unsigned __int16)v9;
            v11 = (unsigned __int16)(v9 + 2);
            HIWORD(v14) = v11;
            LOWORD(v14) = v10;
            if ( v11 < v10 )
              return;
            v15 = v4;
            v12 = (int *)VfSuspectExcludedDriversAllocateEntry((unsigned __int16 *)&v14, 1163421270);
            if ( v12 )
            {
              VfDriverLock();
              v13 = (int **)dword_61CF14;
              *v12 = (int)&VfXdvExcludedDriversList;
              v12[1] = (int)v13;
              if ( *v13 != &VfXdvExcludedDriversList )
                __fastfail(3u);
              *v13 = v12;
              dword_61CF14 = (int)v12;
              VfDriverUnlock();
            }
          }
          v4 = i + 1;
        }
      }
      while ( v4 < v5 );
    }
  }
}
