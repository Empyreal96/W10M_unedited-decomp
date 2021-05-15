// BiReleasePrivilege 
 
int __fastcall BiReleasePrivilege(int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // [sp+0h] [bp-10h] BYREF
  int v6; // [sp+4h] [bp-Ch]
  int v7; // [sp+8h] [bp-8h]

  v6 = a3;
  v7 = a4;
  v4 = result;
  if ( !*(_BYTE *)(result + 4) )
    result = BiAdjustPrivilege(*(_DWORD *)result, 0, &v5);
  if ( !*(_BYTE *)(v4 + 5) )
  {
    v6 = 0;
    result = ZwSetInformationThread();
  }
  return result;
}
