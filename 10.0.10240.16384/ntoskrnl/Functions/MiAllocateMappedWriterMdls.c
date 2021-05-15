// MiAllocateMappedWriterMdls 
 
int __fastcall MiAllocateMappedWriterMdls(int a1)
{
  int v3; // r6
  unsigned int v4; // r5
  int v5; // r8
  _BYTE *v6; // r0
  _DWORD *v7; // r7
  int v8; // r3
  _DWORD *v9; // r2

  if ( *(_DWORD *)(a1 + 3592) >> 15 >= 0x14u )
    return sub_54E02C();
  v3 = 0;
  v4 = 0;
  *(_DWORD *)(a1 + 344) = 20;
  v5 = a1 + 356;
  while ( 1 )
  {
    v6 = (_BYTE *)MiAllocateModWriterEntry((__int16 *)a1, 16, 1);
    v7 = v6;
    if ( !v6 )
      break;
    memset(v6, 0, 160);
    v8 = v7[5];
    v7[30] = a1;
    v7[5] = v8 | 1;
    v9 = *(_DWORD **)(a1 + 360);
    *v7 = v5;
    v7[1] = v9;
    if ( *v9 != v5 )
      __fastfail(3u);
    ++v4;
    *v9 = v7;
    *(_DWORD *)(a1 + 360) = v7;
    if ( v4 >= 4 )
      return v3;
  }
  if ( !v4 )
    v3 = -1073741670;
  return v3;
}
