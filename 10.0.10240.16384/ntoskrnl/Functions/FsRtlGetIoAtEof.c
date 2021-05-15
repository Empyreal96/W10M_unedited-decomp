// FsRtlGetIoAtEof 
 
int __fastcall FsRtlGetIoAtEof(int a1, __int64 a2, __int64 a3, char a4, _BYTE *a5)
{
  int v6; // r4
  int v7; // r1
  unsigned int v8; // r5

  v6 = HIDWORD(a2);
  v7 = a2;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)a1 == v8 )
    return sub_54B944();
  if ( a2 >= 0 )
  {
    v6 = (unsigned __int64)(a2 + a3) >> 32;
    v7 = a2 + a3;
  }
  if ( !*(_DWORD *)a1 )
  {
    *(_WORD *)(a1 + 22) = 1;
    *(_DWORD *)a1 = v8;
    *a5 = 1;
    return 0;
  }
  if ( a4 )
  {
    *a5 = FsRtlpWaitForIoAtEof(a1, v7, v7, v6);
    return 0;
  }
  return -1073741740;
}
