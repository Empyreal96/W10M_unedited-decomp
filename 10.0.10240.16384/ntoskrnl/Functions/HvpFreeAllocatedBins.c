// HvpFreeAllocatedBins 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall HvpFreeAllocatedBins(int result)
{
  int v1; // r6
  int v2; // r3
  unsigned int v3; // r8
  unsigned int v4; // r7
  unsigned int v5; // r9
  _DWORD *v6; // r4
  int v7; // r0
  int v8; // r5
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED

  v1 = result;
  v2 = *(_DWORD *)(result + 952) >> 12;
  if ( v2 )
    v3 = (unsigned int)(v2 - 1) >> 9;
  else
    v3 = 0;
  if ( *(_DWORD *)(result + 956) )
  {
    v4 = 0;
    do
    {
      v5 = 0;
      v6 = *(_DWORD **)(*(_DWORD *)(v1 + 956) + 4 * v4);
      do
      {
        result = HvpMapEntryIsBinPresent((int)v6);
        if ( result )
        {
          result = HvpMapEntryIsNewAlloc((int)v6);
          if ( result )
          {
            v7 = HvpMapEntryGetFreeBin((int)v6);
            v8 = v7;
            if ( v7 )
            {
              if ( (*(_DWORD *)(v7 + 16) & 1) != 0 )
                HvpFreeBin(v1, v6[4], 0, v6[1] & 0xFFFFFFF0, v6[2] & 0xFFFFFFF0);
              *(_QWORD *)&v9 = *(_QWORD *)v8;
              if ( *(_DWORD *)(*(_DWORD *)v8 + 4) != v8 || *v10 != v8 )
                __fastfail(3u);
              *v10 = v9;
              *(_DWORD *)(v9 + 4) = v10;
              result = (*(int (__fastcall **)(int, int))(v1 + 16))(v8, 20);
            }
            else
            {
              result = HvpFreeBin(v1, v6[4], 0, v6[1] & 0xFFFFFFF0, v6[2] & 0xFFFFFFF0);
            }
          }
          v6[1] = 0;
          v6[2] = 0;
        }
        ++v5;
        v6 += 5;
      }
      while ( v5 < 0x200 );
      ++v4;
    }
    while ( v4 <= v3 );
  }
  return result;
}
