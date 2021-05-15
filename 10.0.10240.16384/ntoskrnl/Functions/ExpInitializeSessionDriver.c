// ExpInitializeSessionDriver 
 
int __fastcall ExpInitializeSessionDriver(int (__fastcall *a1)(__int16 *, _DWORD), int a2)
{
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r4
  __int16 v9; // [sp+0h] [bp-B0h] BYREF
  _WORD v10[83]; // [sp+2h] [bp-AEh] BYREF

  v9 = 0;
  memset(v10, 0, sizeof(v10));
  *(_DWORD *)&v10[5] = a2;
  v7 = a1(&v9, 0);
  if ( v7 >= 0 )
    MmSessionSetUnloadAddress((int)&v9, v4, v5, v6);
  return v7;
}
