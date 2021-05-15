// FstubWriteSector 
 
int __fastcall FstubWriteSector(int a1, unsigned int a2, __int64 a3, int a4)
{
  _DWORD *v6; // r0
  int result; // r0
  __int64 v8; // [sp+10h] [bp-30h] BYREF
  int v9; // [sp+18h] [bp-28h] BYREF
  char v10[32]; // [sp+20h] [bp-20h] BYREF

  v8 = a3 * a2;
  KeInitializeEvent((int)v10, 0, 0);
  v6 = IoBuildSynchronousFsdRequest(4, a1, a4, a2, &v8, (int)v10, (int)&v9);
  if ( !v6 )
    return -1073741670;
  *(_BYTE *)(v6[24] - 38) |= 0x12u;
  result = IofCallDriver(a1, (int)v6);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v10, 0, 0, 0, 0);
    result = v9;
  }
  return result;
}
