// ExpGetObjectInformation 
 
int __fastcall ExpGetObjectInformation(int a1, int a2, unsigned int *a3, int a4)
{
  int v7; // r4
  unsigned int *v9; // [sp+8h] [bp-18h] BYREF
  int v10[5]; // [sp+Ch] [bp-14h] BYREF

  v9 = a3;
  v10[0] = a4;
  *a3 = 0;
  v7 = ExLockUserBuffer(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, (int *)&v9, v10);
  if ( v7 >= 0 )
  {
    v7 = ObGetObjectInformation(a1, (int)v9, a2, a3);
    ExUnlockUserBuffer(v10[0]);
  }
  return v7;
}
