// sub_523810 
 
void __fastcall sub_523810(unsigned __int8 *a1, int a2, int a3, __int16 a4)
{
  _DWORD *v4; // r6
  int v5; // r7
  int v6; // lr
  int v7; // r5
  unsigned int *v8; // r2
  unsigned int v9; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r0

  if ( (a4 & 0x100) == 0 )
  {
    v7 = v4[38];
    __dmb(0xBu);
    v8 = (unsigned int *)(v7 + 4 * (v6 + 68));
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 - 1, v8) );
    __dmb(0xBu);
    v10 = (unsigned int *)(v7 + 4 * (v5 + 68));
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
    __dmb(0xBu);
    if ( v5 < v6 )
      a2 = 1;
  }
  v4[83] = (unsigned __int8)v5 | a4 & 0x100;
  if ( a2 )
  {
    __dmb(0xBu);
    do
      v12 = __ldrex(a1);
    while ( __strex(v12 | 0x80, a1) );
    __dmb(0xBu);
    __dmb(0xBu);
    v4[11] = 0;
    if ( v12 >> 7 )
      KiActivateWaiterQueueWithNoLocks((int)v4, (unsigned int)a1, 0);
    else
      KiActivateWaiterPriQueue((int)a1, a2, v12, 0);
    v13 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( *(_DWORD *)(v13 + 2948) )
      KiProcessThreadWaitList(v13 + 1408, 1, 0);
    JUMPOUT(0x45A7B6);
  }
  JUMPOUT(0x45A7AE);
}
