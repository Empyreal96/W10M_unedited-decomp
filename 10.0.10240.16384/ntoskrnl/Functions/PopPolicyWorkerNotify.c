// PopPolicyWorkerNotify 
 
int __fastcall PopPolicyWorkerNotify(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r4
  unsigned int v5; // r2
  void **v6; // r3
  int v7; // r0
  unsigned int v9; // [sp+0h] [bp-28h] BYREF
  int v10; // [sp+4h] [bp-24h]
  int v11; // [sp+8h] [bp-20h]

  v9 = a2;
  v10 = a3;
  v11 = a4;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&PopNotifyEvents);
  while ( __strex(0, (unsigned int *)&PopNotifyEvents) );
  __dmb(0xBu);
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = __clz(__rbit(v4));
      v4 &= ~(1 << v5);
      v6 = &PopNotifyWork + 2 * v5;
      if ( *v6 )
      {
        v7 = ((int (__fastcall *)(void *))*v6)(v6[1]);
        if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
          sub_7F2A9C(v7);
      }
      if ( !v4 )
      {
        v9 = -100000;
        v10 = -1;
        KeDelayExecutionThread(0, 0, &v9);
        __dmb(0xBu);
        do
          v4 = __ldrex((unsigned int *)&PopNotifyEvents);
        while ( __strex(0, (unsigned int *)&PopNotifyEvents) );
        __dmb(0xBu);
        if ( !v4 )
          break;
      }
    }
  }
  return 0;
}
