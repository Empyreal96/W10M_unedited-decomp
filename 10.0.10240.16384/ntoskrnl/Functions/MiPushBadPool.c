// MiPushBadPool 
 
int __fastcall MiPushBadPool(int a1, int a2, int a3, int a4)
{
  int v6; // r6
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r0
  _DWORD v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a2;
  v13[1] = a3;
  v13[2] = a4;
  v6 = KfRaiseIrql(2);
  v7 = (unsigned __int8 *)(a2 + 15);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v8 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v9 = *(_DWORD *)(a2 + 12);
      __dmb(0xBu);
    }
    while ( v9 < 0 );
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
  }
  *(_BYTE *)(a2 + 18) = *(_BYTE *)(a2 + 18) & 0xF8 | 5;
  __dmb(0xBu);
  v10 = (unsigned int *)(a2 + 12);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & 0x7FFFFFFF, v10) );
  KfLowerIrql(v6);
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 128), (unsigned int)v13);
  *(_DWORD *)a2 = dword_632A94;
  dword_632A94 = a2;
  return KeReleaseInStackQueuedSpinLock((int)v13);
}
