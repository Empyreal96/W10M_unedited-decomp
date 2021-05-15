// MiAddPhysicalPagesToCrashDump 
 
int __fastcall MiAddPhysicalPagesToCrashDump(int result)
{
  int v1; // r5
  int (__fastcall **v2)(_DWORD, int, int, int); // r10
  _DWORD *v3; // r2
  int v4; // r6
  unsigned int v5; // r8
  int v6; // r7
  _DWORD *v7; // r4
  int v8; // r1
  int v9; // r3
  int v10; // r1

  v1 = 0;
  v2 = (int (__fastcall **)(_DWORD, int, int, int))result;
  v3 = (_DWORD *)MmPhysicalMemoryBlock;
  if ( *(_DWORD *)MmPhysicalMemoryBlock )
  {
    while ( 1 )
    {
      v4 = v3[2 * v1 + 2];
      v5 = 0;
      if ( v3[2 * v1 + 3] )
        break;
LABEL_15:
      if ( (unsigned int)++v1 >= *v3 )
        return result;
    }
    v6 = 24 * v4;
    while ( 1 )
    {
      v7 = (_DWORD *)(v6 + MmPfnDatabase);
      v8 = *(unsigned __int8 *)(v6 + MmPfnDatabase + 18);
      if ( (v8 & 0xFFFFFFC0) == 64 )
      {
        v9 = v8 & 7;
        if ( v9 == 6 )
        {
          v10 = v7[5];
          if ( (v10 & 0x7000000) == 0x1000000 || (v7[3] & 0x3FFFFFFF) == 1 && (v10 & 0xFFFFF) == 1048573 )
            goto LABEL_14;
        }
        else if ( v9 != 2 && v9 != 3 || (v7[2] & 0x400) != 0 )
        {
          goto LABEL_14;
        }
        result = (*v2)(v2, v4, 1, 2);
        v3 = (_DWORD *)MmPhysicalMemoryBlock;
      }
LABEL_14:
      ++v5;
      ++v4;
      v6 += 24;
      if ( v5 >= v3[2 * v1 + 3] )
        goto LABEL_15;
    }
  }
  return result;
}
