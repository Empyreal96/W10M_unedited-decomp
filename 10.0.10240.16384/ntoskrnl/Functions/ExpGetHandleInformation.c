// ExpGetHandleInformation 
 
int __fastcall ExpGetHandleInformation(int a1, unsigned int a2, _DWORD *a3)
{
  int v5; // r3
  int v6; // r4
  _DWORD *v8; // [sp+8h] [bp-18h] BYREF
  int v9[5]; // [sp+Ch] [bp-14h] BYREF

  *a3 = 0;
  v6 = ExLockUserBuffer(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, (int *)&v8, v9);
  if ( v6 >= 0 )
  {
    v6 = ObGetHandleInformation(v8, a2, a3, v5);
    ExUnlockUserBuffer(v9[0]);
  }
  return v6;
}
