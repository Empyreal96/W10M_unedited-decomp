// PsSetSiloObjectRootDirectoryByPointer 
 
int __fastcall PsSetSiloObjectRootDirectoryByPointer(int a1, int *a2)
{
  return ObSetSiloRootDirectoryByPointer(a1, *a2, *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
}
