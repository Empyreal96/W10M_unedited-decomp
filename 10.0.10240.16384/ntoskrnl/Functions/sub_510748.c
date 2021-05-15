// sub_510748 
 
void sub_510748(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  int v5; // r5
  int v6; // r6
  int v7; // r7
  unsigned int *v8; // r8
  unsigned int v9; // r1
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  v8 = (unsigned int *)(v4 + 192);
  while ( 1 )
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 & 0xFF7FFFFF, v8) );
    __dmb(0xBu);
    KeReleaseInStackQueuedSpinLock((int)va);
    MiUpdateSystemPdes(v4);
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v5 + v6), (unsigned int)va);
    if ( (*(_DWORD *)(v4 + 192) & v7) == 0 )
      JUMPOUT(0x428192);
  }
}
