// KeDisconnectInterrupt 
 
int __fastcall KeDisconnectInterrupt(int a1, unsigned int a2, int a3)
{
  int v3; // r4
  int v6; // r5
  int v7; // r0
  int v8; // r3
  unsigned __int8 v9; // r8
  int v10; // r6
  int v12; // r4
  unsigned int *v13; // r2
  int v14; // [sp+0h] [bp-28h]

  v3 = a1;
  v6 = 0;
  KeMaskInterrupt(a1, a2);
  v14 = KiIsInterruptTypeSecondary(a3);
  v7 = KiIntSteerDisable(v3, a2);
  v8 = 0;
  if ( !a2 )
    return v6;
  v9 = 0;
  while ( 1 )
  {
    v10 = *(_DWORD *)(v3 + 4 * v8);
    if ( v14 )
      break;
    v12 = KiDisconnectInterruptCommon(0, v10, a3);
    __dmb(0xBu);
    v13 = (unsigned int *)(v10 + 60);
    do
      v7 = __ldrex(v13);
    while ( __strex(v7 | a1 | 1, v13) );
    __dmb(0xBu);
    if ( v12 < 0 )
    {
      v6 = v12;
    }
    else if ( v12 == 296 )
    {
      v6 = 296;
    }
    v3 = a1;
    v8 = ++v9;
    if ( v9 >= a2 )
      return v6;
  }
  return sub_50FA64(v7);
}
