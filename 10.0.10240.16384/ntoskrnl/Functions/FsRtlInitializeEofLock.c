// FsRtlInitializeEofLock 
 
_BYTE *__fastcall FsRtlInitializeEofLock(int a1, int a2)
{
  _BYTE *result; // r0

  result = memset((_BYTE *)a1, 0, 24);
  *(_DWORD *)(a1 + 12) = a2;
  *(_DWORD *)(a1 + 4) = a1 + 4;
  *(_DWORD *)(a1 + 8) = a1 + 4;
  return result;
}
