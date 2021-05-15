// IopBootLogToFile 
 
int __fastcall IopBootLogToFile(int a1, int a2, int a3)
{
  int v3; // r5
  unsigned int v4; // r4
  int v5; // r0
  __int16 v6; // r3
  int v8; // [sp+2Ch] [bp-3Ch]

  if ( !off_920070 )
    return 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  ExAcquireResourceExclusiveLite((int)off_920070 + 32, 1, a3, (int)off_920070);
  if ( !*((_DWORD *)off_920070 + 5) )
    RtlInitUnicodeString((unsigned int)off_920070 + 16, L"\\SystemRoot\\ntbtlog.txt");
  v3 = ZwCreateFile();
  if ( v3 >= 0 )
  {
    if ( v8 == 2 )
      v3 = ZwWriteFile();
    if ( v3 >= 0 )
      v3 = ZwWriteFile();
    ZwClose();
  }
  v5 = ExReleaseResourceLite((int)off_920070 + 32);
  v6 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return v3;
}
