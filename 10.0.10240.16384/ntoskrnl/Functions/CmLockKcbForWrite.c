// CmLockKcbForWrite 
 
int __fastcall CmLockKcbForWrite(unsigned int *a1)
{
  int v2; // r0
  unsigned int v4; // r0
  unsigned int v5; // r2
  unsigned int i; // r4

  v2 = CmpLockKcbExclusive(a1);
  if ( (a1[1] & 0x20000) != 0 )
    return sub_818670(v2);
  v4 = *a1;
  __dmb(0xBu);
  if ( v4 == -1 )
    JUMPOUT(0x81867C);
  __dmb(0xBu);
  do
    v5 = __ldrex(a1);
  while ( v5 == v4 && __strex(v4 + 1, a1) );
  __dmb(0xBu);
  if ( v5 != v4 )
    JUMPOUT(0x818674);
  *((_WORD *)a1 + 2) |= 0xA0u;
  CmpUnlockKcb(a1);
  for ( i = a1[10]; i; i = *(_DWORD *)(i + 40) )
  {
    if ( *(void **)(i + 20) == CmpMasterHive )
      break;
    CmpLockKcbExclusive((_DWORD *)i);
    *(_WORD *)(i + 4) |= 0x100u;
    CmpUnlockKcb((_DWORD *)i);
  }
  return 0;
}
