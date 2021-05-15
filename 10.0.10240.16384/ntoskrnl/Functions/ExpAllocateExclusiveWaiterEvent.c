// ExpAllocateExclusiveWaiterEvent 
 
int __fastcall ExpAllocateExclusiveWaiterEvent(int a1, int a2)
{
  unsigned int v4; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1

  ExpUnlockResource(a1, a2);
  v4 = ExAllocatePoolWithTag(512, 16, 1984259410);
  if ( !v4 )
    return sub_54A244();
  *(_BYTE *)v4 = 1;
  *(_BYTE *)(v4 + 2) = 4;
  *(_BYTE *)(v4 + 1) = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = v4 + 8;
  *(_DWORD *)(v4 + 12) = v4 + 8;
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 20);
  do
    v7 = __ldrex(v6);
  while ( !v7 && __strex(v4, v6) );
  if ( v7 )
    ExFreePoolWithTag(v4, 0);
  return ExpLockResource(a1, a2);
}
