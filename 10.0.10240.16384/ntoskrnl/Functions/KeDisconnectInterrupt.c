// KeDisconnectInterrupt 
 
void __fastcall KeDisconnectInterrupt(int a1, unsigned int a2, int a3)
{
  int *v3; // r4
  int v6; // r3
  unsigned __int8 v7; // r8
  int v8; // r6
  unsigned int *v9; // r2
  unsigned int v10; // r0
  int v11; // [sp+0h] [bp-28h]

  v3 = (int *)a1;
  KeMaskInterrupt(a1, a2, a3);
  v11 = KiIsInterruptTypeSecondary((_DWORD *)a3);
  KiIntSteerDisable(v3, a2);
  v6 = 0;
  if ( a2 )
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = v3[v6];
      if ( v11 )
        break;
      KiDisconnectInterruptCommon(0, v8, a3);
      __dmb(0xBu);
      v9 = (unsigned int *)(v8 + 60);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | a1 | 1, v9) );
      __dmb(0xBu);
      v3 = (int *)a1;
      v6 = ++v7;
      if ( v7 >= a2 )
        return;
    }
    sub_50FA64();
  }
}
