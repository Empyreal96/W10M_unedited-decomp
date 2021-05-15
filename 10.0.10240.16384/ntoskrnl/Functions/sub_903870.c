// sub_903870 
 
void __fastcall sub_903870(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, unsigned int a15, unsigned int a16, int a17, int a18, int a19, unsigned int a20)
{
  int v20; // r6
  unsigned __int16 *v21; // r8
  unsigned int v22; // r5
  unsigned int v23; // r7
  int v24; // r4
  int v25; // r1
  const char *v26; // r2
  __int64 v27; // r8

  memmove(v20, *((_DWORD *)v21 + 1), *v21);
  *(_WORD *)(v20 + 2 * (*v21 >> 1)) = 0;
  v22 = a15;
  v23 = a16;
  DbgPrintEx(
    0,
    0,
    (int)"KdPullRemoteFile(%p): About to overwrite %ls and preallocate to %I64x\n",
    __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v24 = ZwCreateFile();
  DbgPrintEx(
    0,
    0,
    (int)"KdPullRemoteFile(%p): Return from ZwCreateFile with status %x\n",
    __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( v24 >= 0 )
  {
    v27 = 0i64;
    if ( !a16 )
      goto LABEL_9;
    while ( 1 )
    {
      if ( KdpReadRemoteFile(a13, v25, v27, HIDWORD(v27)) < 0 || !a15 )
        goto LABEL_14;
      v24 = ZwWriteFile();
      if ( v24 < 0 )
        break;
      if ( a20 < a15 )
        goto LABEL_14;
      v27 += a20;
      v23 = (__PAIR64__(v23, v22) - a20) >> 32;
      v22 -= a20;
      if ( !v23 )
      {
LABEL_9:
        if ( !v22 )
          goto LABEL_14;
      }
    }
    v26 = "\nKdPullRemoteFile: Local file write failed, 0x%08x\n";
  }
  else
  {
    v26 = "\nKdPullRemoteFile: Local file open failed, 0x%08x\n";
  }
  DbgPrintEx(0, 2, (int)v26, v24);
LABEL_14:
  JUMPOUT(0x9027F2);
}
