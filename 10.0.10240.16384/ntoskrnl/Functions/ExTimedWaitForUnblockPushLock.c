// ExTimedWaitForUnblockPushLock 
 
int __fastcall ExTimedWaitForUnblockPushLock(int a1, int a2)
{
  int v3; // r4
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  int v6; // r4

  *(_BYTE *)(a2 + 2) = 4;
  *(_BYTE *)a2 = 0;
  *(_BYTE *)(a2 + 1) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = a2 + 8;
  *(_DWORD *)(a2 + 12) = a2 + 8;
  if ( MEMORY[0xFFFF936A] > 1u )
  {
    v3 = ExpSpinCount;
    if ( ExpSpinCount )
    {
      while ( (*(_DWORD *)(a2 + 32) & 2) != 0 )
      {
        __dmb(0xAu);
        __yield();
        if ( !--v3 )
          goto LABEL_5;
      }
      return 0;
    }
  }
LABEL_5:
  __dmb(0xBu);
  v4 = (unsigned __int8 *)(a2 + 32);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 & 0xFD, v4) );
  __dmb(0xBu);
  if ( !((unsigned __int8)(v5 & 2) >> 1) )
    return 0;
  v6 = KeWaitForSingleObject(a2, 28, 0);
  if ( v6 )
    return sub_529188();
  return v6;
}
