// MmAllocateMdlForIoSpace 
 
int __fastcall MmAllocateMdlForIoSpace(__int64 *a1, unsigned int a2, int *a3)
{
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r6
  __int64 *v7; // r8
  __int64 *v8; // r4
  int v9; // r9
  int v10; // r0
  int result; // r0
  _DWORD *i; // r1
  int v13; // r4
  int j; // r3
  __int16 v15; // r2

  v3 = a2;
  v4 = 0;
  v5 = 0;
  v7 = a1;
  v8 = a1;
  if ( a2 )
  {
    while ( 1 )
    {
      v9 = *((_DWORD *)v8 + 2);
      if ( (v9 & 0xFFF) != 0 || (*(_DWORD *)v8 & 0xFFF) != 0 || MI_IS_PFN(*v8 >> 12) || v9 + v4 < v4 )
        break;
      v4 += v9;
      ++v5;
      v8 += 2;
      if ( v5 >= v3 )
        goto LABEL_7;
    }
    result = -1073741585;
  }
  else
  {
LABEL_7:
    v10 = IoAllocateMdl(0, v4, 0, 0, 0);
    if ( v10 )
    {
      for ( i = (_DWORD *)(v10 + 28); v3; --v3 )
      {
        v13 = *((_DWORD *)v7 + 2) >> 12;
        for ( j = *v7 >> 12; v13; --v13 )
          *i++ = j++;
        v7 += 2;
      }
      v15 = *(_WORD *)(v10 + 6);
      *(_DWORD *)(v10 + 8) = 0;
      *(_WORD *)(v10 + 6) = v15 | 0x802;
      *a3 = v10;
      result = 0;
    }
    else
    {
      result = -1073741670;
    }
  }
  return result;
}
