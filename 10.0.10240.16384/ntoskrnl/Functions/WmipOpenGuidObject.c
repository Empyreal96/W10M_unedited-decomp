// WmipOpenGuidObject 
 
int __fastcall WmipOpenGuidObject(int a1, int a2, int a3, _DWORD *a4)
{
  unsigned int v6; // r5
  int result; // r0
  int v9; // [sp+0h] [bp-30h] BYREF
  char v10[40]; // [sp+8h] [bp-28h] BYREF

  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4);
  if ( memcmp(v6, (unsigned int)L"\\WmiGuid\\", 16) )
    return -1073741811;
  result = WmipUuidFromString(v6 + 18, v10);
  if ( result >= 0 )
  {
    result = WmipCreateGuidObject(a1, a3, v10, &v9);
    if ( result >= 0 )
    {
      result = 0;
      *a4 = v9;
    }
  }
  return result;
}
