// CmpIsHiveOnRemovableDisk 
 
BOOL __fastcall CmpIsHiveOnRemovableDisk(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r0
  BOOL v6; // r4
  int v8; // [sp+8h] [bp-8h] BYREF

  v8 = a4;
  v4 = *(_DWORD *)(a1 + 1776);
  if ( !v4 )
    return 0;
  v6 = 1;
  if ( ObReferenceObjectByHandle(v4, 1, *(_DWORD *)CmIoFileObjectType, 0, &v8) >= 0 )
  {
    v5 = *(_DWORD *)(v8 + 4);
    if ( (*(_DWORD *)(v5 + 28) & 0x600100) != 0 || (*(_DWORD *)(v5 + 32) & 0x40001) == 0 )
      v6 = 0;
  }
  if ( v8 )
    ObfDereferenceObject(v8);
  return v6;
}
