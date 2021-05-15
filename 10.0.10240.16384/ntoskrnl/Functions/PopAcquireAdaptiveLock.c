// PopAcquireAdaptiveLock 
 
_BYTE *__fastcall PopAcquireAdaptiveLock(int a1)
{
  int v2; // r5
  int v3; // r2
  int v4; // r3
  _BYTE *result; // r0
  int v6; // r3
  char v7[4]; // [sp+8h] [bp-28h] BYREF
  char v8[20]; // [sp+Ch] [bp-24h] BYREF

  v7[0] = 0;
  memset(v8, 0, sizeof(v8));
  v2 = -1;
  if ( !a1 )
  {
    v2 = PoBlockConsoleSwitch(v7);
    v6 = PopConsoleContext;
    __dmb(0xBu);
    if ( v2 != v6 )
      return (_BYTE *)sub_7EAC80();
  }
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  result = (_BYTE *)ExAcquireResourceExclusiveLite((int)&PopAdpmLock, 1, v3, v4);
  PopAdpmLockThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !a1 )
  {
    result = memset(&PopLazyContext, 0, 24);
    PopLazyContext = 1;
    dword_61DE04 = v2;
  }
  return result;
}
