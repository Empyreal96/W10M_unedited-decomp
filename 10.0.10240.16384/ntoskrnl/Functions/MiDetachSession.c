// MiDetachSession 
 
int MiDetachSession()
{
  int result; // r0
  int v1; // r2

  result = MiDetachProcessFromSession(1);
  *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) = 0;
  __dmb(0xFu);
  v1 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  dword_633784 = v1;
  return result;
}
