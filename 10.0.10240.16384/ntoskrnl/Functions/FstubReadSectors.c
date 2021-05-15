// FstubReadSectors 
 
int __fastcall FstubReadSectors(int a1, unsigned int a2, __int64 a3, int a4, int a5)
{
  _DWORD *v7; // r0
  int result; // r0
  __int64 v9; // [sp+10h] [bp-30h] BYREF
  int v10; // [sp+18h] [bp-28h] BYREF
  char v11[32]; // [sp+20h] [bp-20h] BYREF

  v9 = a3 * a2;
  KeInitializeEvent((int)v11, 0, 0);
  v7 = IoBuildSynchronousFsdRequest(3, a1, a5, a2 * a4, &v9, (int)v11, (int)&v10);
  if ( !v7 )
    return -1073741670;
  *(_BYTE *)(v7[24] - 38) |= 2u;
  result = IofCallDriver(a1, (int)v7);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
    result = v10;
  }
  return result;
}
