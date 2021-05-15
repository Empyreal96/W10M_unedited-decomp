// VerifierEtwRegisterClassicProvider 
 
int __fastcall VerifierEtwRegisterClassicProvider(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r3
  int v6; // r4
  int vars4; // [sp+14h] [bp+4h]

  v6 = pXdvEtwRegisterClassicProvider();
  if ( v6 >= 0 )
    VfTargetEtwRegister(*(_DWORD *)a5, *(_DWORD *)(a5 + 4), vars4, v5);
  return v6;
}
