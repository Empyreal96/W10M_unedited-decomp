// IopAcquireReleaseDispatcherLock 
 
int __fastcall IopAcquireReleaseDispatcherLock(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r1
  __int16 v4; // r3
  int v5; // r3

  if ( a2 )
  {
    v5 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v5 & 0xFFFFFFC0) + 0x134);
    result = KeWaitForSingleObject(a1 + 92, 0, 0, 0, 0);
  }
  else
  {
    result = KeSetEvent(a1 + 92, 0, 0);
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = *(_WORD *)(v3 + 0x134) + 1;
    *(_WORD *)(v3 + 308) = v4;
    if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 )
      result = sub_819BF4(result);
  }
  return result;
}
