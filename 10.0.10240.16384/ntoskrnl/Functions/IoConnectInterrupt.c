// IoConnectInterrupt 
 
int __fastcall IoConnectInterrupt(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, int a8, unsigned __int8 a9, int a10)
{
  int v15[8]; // [sp+20h] [bp-20h] BYREF

  if ( KeGetCurrentIrql(a1) )
    sub_8194A0();
  v15[1] = 0;
  v15[2] = 0;
  v15[0] = a10;
  return IopConnectInterruptFullySpecified(a1, a2, a3, a4, a5, a6, a7, a8, a9, v15);
}
