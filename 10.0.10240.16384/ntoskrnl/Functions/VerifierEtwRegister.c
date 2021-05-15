// VerifierEtwRegister 
 
int __fastcall VerifierEtwRegister(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r4
  int vars4; // [sp+Ch] [bp+4h]

  v6 = pXdvEtwRegister();
  if ( v6 >= 0 )
    VfTargetEtwRegister(*(_DWORD *)a4, *(_DWORD *)(a4 + 4), vars4, v5);
  return v6;
}
