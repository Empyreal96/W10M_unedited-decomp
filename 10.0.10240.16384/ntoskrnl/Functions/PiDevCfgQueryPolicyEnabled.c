// PiDevCfgQueryPolicyEnabled 
 
int __fastcall PiDevCfgQueryPolicyEnabled(int a1, unsigned __int16 *a2, bool *a3, int a4)
{
  int v5; // r4
  unsigned int v6; // r0
  BOOL v7; // r3
  bool v8; // r3
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  *a3 = 0;
  v5 = IopGetRegistryValue(a1, a2, 0, v10);
  v6 = v10[0];
  if ( v5 >= 0 )
  {
    v7 = *(_DWORD *)(v10[0] + 4) == 4 && *(_DWORD *)(v10[0] + 12) == 4;
    v8 = v7 && *(_DWORD *)(*(_DWORD *)(v10[0] + 8) + v10[0]) == 1;
    *a3 = v8;
  }
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v5;
}
