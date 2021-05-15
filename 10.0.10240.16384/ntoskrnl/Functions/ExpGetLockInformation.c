// ExpGetLockInformation 
 
int __fastcall ExpGetLockInformation(int a1, unsigned int a2, unsigned int *a3)
{
  int v5; // r4
  _DWORD *v7; // [sp+8h] [bp-18h] BYREF
  int v8[5]; // [sp+Ch] [bp-14h] BYREF

  *a3 = 0;
  v5 = ExLockUserBuffer(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, (int *)&v7, v8);
  if ( v5 >= 0 )
  {
    v5 = ExQuerySystemLockInformation(v7, a2, a3);
    ExUnlockUserBuffer(v8[0]);
  }
  return v5;
}
