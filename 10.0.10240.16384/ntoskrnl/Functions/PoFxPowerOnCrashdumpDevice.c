// PoFxPowerOnCrashdumpDevice 
 
int __fastcall PoFxPowerOnCrashdumpDevice(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int (__fastcall *v5)(int *); // r2
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v7 = a2;
  v8 = a3;
  v9 = a4;
  v4 = 0;
  if ( !a1 )
    return -1073741811;
  v5 = *(int (__fastcall **)(int *))(a1 + 336);
  if ( !v5 || (v7 = *(_DWORD *)(a1 + 40), v8 = a2, !v5(&v7)) )
    v4 = -1073741823;
  return v4;
}
