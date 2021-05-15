// KeQueryBasePriorityThread 
 
int __fastcall KeQueryBasePriorityThread(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  unsigned int *v6; // r1
  unsigned int v7; // r2
  int v8; // r4
  unsigned int *v9; // r0
  unsigned int v11; // r1
  unsigned int v12; // r2
  int v13[4]; // [sp+0h] [bp-10h] BYREF

  v13[0] = a4;
  v4 = *(_DWORD *)(a1 + 336);
  KiAcquireProcessLockShared(v4, v13);
  v6 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v7 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( !v7 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v6 );
  }
  v8 = *(char *)(a1 + 347) - *(char *)(v4 + 104);
  if ( *(_BYTE *)(a1 + 397) )
    v8 = 16 * *(char *)(a1 + 397);
  __dmb(0xBu);
  *v6 = 0;
  v9 = (unsigned int *)(v4 + 48);
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_51F6FC(v9);
  __dmb(0xBu);
  do
    v11 = __ldrex(v9);
  while ( __strex(v11 & 0xBFFFFFFF, v9) );
  __dmb(0xBu);
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 - 1, v9) );
  KfLowerIrql(LOBYTE(v13[0]));
  return v8;
}
