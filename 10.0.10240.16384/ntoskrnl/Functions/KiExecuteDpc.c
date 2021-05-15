// KiExecuteDpc 
 
void __fastcall __noreturn KiExecuteDpc(int a1)
{
  __int64 v1; // r4
  unsigned __int8 *v2; // r3
  int v3; // r2
  unsigned __int16 *v4; // r6
  unsigned int v5; // r2
  unsigned int v6; // r2
  int v7[56]; // [sp+0h] [bp-E0h] BYREF

  LODWORD(v1) = a1;
  HIDWORD(v1) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeSetPriorityThread(SHIDWORD(v1), 31);
  __dmb(0xBu);
  v2 = (unsigned __int8 *)(HIDWORD(v1) + 80);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  __dmb(0xBu);
  KiSetSystemAffinityThreadToProcessor(*(_DWORD *)(v1 + 20), 0, v3, (int)v2);
  *(_BYTE *)(v1 + 1752) = 1;
  v4 = (unsigned __int16 *)(v1 + 1758);
  while ( 1 )
  {
    v7[0] = 0;
    KeWaitForGate(v1 + 1792, 5);
    do
    {
      __dmb(0xBu);
      do
        v5 = __ldrex(v4);
      while ( __strex(1u, v4) );
      __dmb(0xBu);
      __disable_irq();
      KiExecuteAllDpcs(v1, (int)v7, 1);
      __enable_irq();
      __dmb(0xBu);
      do
        v6 = __ldrex(v4);
      while ( v6 == 1 && __strex(0, v4) );
      __dmb(0xBu);
    }
    while ( (__int16)v6 != 1 );
    *(_DWORD *)(v1 + 1724) = 0;
  }
}
