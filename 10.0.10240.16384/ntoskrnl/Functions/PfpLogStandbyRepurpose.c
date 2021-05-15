// PfpLogStandbyRepurpose 
 
int __fastcall PfpLogStandbyRepurpose(unsigned int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int result; // r0
  unsigned int v7; // r2
  unsigned int *v8; // r1
  unsigned int v9; // r2
  int v10; // [sp+0h] [bp-8h] BYREF

  v10 = a4;
  v5 = PfTAcquireLogEntry((int)&algn_64390C[4], &v10, 1);
  if ( !v5 )
    return -1073741670;
  v7 = (v5 + 19) & 0xFFFFFFFC;
  result = 0;
  v8 = (unsigned int *)(v7 + 8 * v10);
  v9 = *v8;
  v8[1] = a1;
  *v8 = v9 & 0xFFFC0000 | 0x6007;
  return result;
}
