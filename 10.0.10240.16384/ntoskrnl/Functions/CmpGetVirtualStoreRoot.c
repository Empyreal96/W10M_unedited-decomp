// CmpGetVirtualStoreRoot 
 
int __fastcall CmpGetVirtualStoreRoot(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int v6; // r4
  __int64 v8; // [sp+0h] [bp-18h] BYREF
  int v9; // [sp+8h] [bp-10h]

  v9 = a4;
  v8 = 0i64;
  v6 = CmpGetVirtualizationID(&v8);
  if ( v6 >= 0 )
  {
    v6 = CmpGetMappingHiveForString((unsigned __int16 *)&v8, a1);
    RtlFreeAnsiString(&v8);
    if ( v6 >= 0 )
      *a2 = *(_DWORD *)(*(_DWORD *)(*a1 + 32) + 36);
  }
  return v6;
}
