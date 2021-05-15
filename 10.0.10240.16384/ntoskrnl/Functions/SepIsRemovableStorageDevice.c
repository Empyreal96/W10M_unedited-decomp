// SepIsRemovableStorageDevice 
 
BOOL __fastcall SepIsRemovableStorageDevice(int a1)
{
  int v1; // r3
  BOOL result; // r0

  result = 0;
  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 44);
    if ( v1 == 2 || v1 == 31 || v1 == 45 || v1 == 51 || v1 == 64 || (*(_DWORD *)(a1 + 32) & 0x40001) != 0 )
      result = 1;
  }
  return result;
}
