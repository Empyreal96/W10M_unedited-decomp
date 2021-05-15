// KxWaitForLockOwnerShip 
 
int __fastcall KxWaitForLockOwnerShip(int a1, _DWORD *a2)
{
  int result; // r0

  *(_DWORD *)(a1 + 4) |= 1u;
  __dmb(0xBu);
  *a2 = a1;
  result = 0;
  do
  {
    __dmb(0xAu);
    __yield();
    result += 2;
  }
  while ( (*(_DWORD *)(a1 + 4) & 1) != 0 );
  __dmb(0xBu);
  return result;
}
