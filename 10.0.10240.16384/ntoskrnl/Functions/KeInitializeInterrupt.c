// KeInitializeInterrupt 
 
int __fastcall KeInitializeInterrupt(int a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8, char a9, int a10, char a11, int a12)
{
  int v13; // [sp+24h] [bp-14h]

  return KeInitializeInterruptEx(a1, a2, a3, a4, a5, a6, 0, a7, a8, a9, a10, a11, a12, v13, 0, 0);
}
