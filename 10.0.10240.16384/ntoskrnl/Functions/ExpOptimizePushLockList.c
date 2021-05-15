// ExpOptimizePushLockList 
 
unsigned int __fastcall ExpOptimizePushLockList(unsigned int *a1, unsigned int a2)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r3
  int v5; // r3
  unsigned int result; // r0
  unsigned int *_18; // [sp+18h] [bp+8h]
  unsigned int varsC; // [sp+1Ch] [bp+Ch]

  _18 = a1;
  varsC = a2;
  if ( (a2 & 1) == 0 )
    return ExpWakePushLock(a1, a2);
  while ( 1 )
  {
    v3 = (_DWORD *)(a2 & 0xFFFFFFF0);
    if ( !*(_DWORD *)((a2 & 0xFFFFFFF0) + 0x14) )
    {
      do
      {
        v4 = v3;
        v3 = (_DWORD *)v3[4];
        v3[6] = v4;
        v5 = v3[5];
      }
      while ( !v5 );
      if ( v3 != (_DWORD *)(a2 & 0xFFFFFFF0) )
        *(_DWORD *)((a2 & 0xFFFFFFF0) + 0x14) = v5;
    }
    __dmb(0xBu);
    do
      result = __ldrex(a1);
    while ( result == a2 && __strex(a2 - 4, a1) );
    __dmb(0xBu);
    if ( result == a2 )
      break;
    a2 = result;
    if ( (result & 1) == 0 )
      return ExpWakePushLock(a1, a2);
  }
  return result;
}
