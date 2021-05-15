// -StNpLeafDelete@-$ST_STORE@USM_TRAITS@@@@SAXPAUNP_CTX@NP_CONTEXT@@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StNpLeafDelete(int a1, int a2)
{
  unsigned int v3; // r4
  int v5[8]; // [sp+0h] [bp-20h] BYREF

  v3 = a2 & 0xFFFFFFFC;
  memset(v5, 0, 24);
  v5[1] = v3;
  v5[0] = v5[0] & 0xFFFFFFF8 | 1;
  v5[2] = 1;
  return ST_STORE<SM_TRAITS>::StDmPageRemove(*(_DWORD *)(*(_DWORD *)a1 + 84), (int)v5);
}
