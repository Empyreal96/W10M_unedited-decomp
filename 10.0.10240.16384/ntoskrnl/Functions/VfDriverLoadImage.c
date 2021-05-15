// VfDriverLoadImage 
 
int __fastcall VfDriverLoadImage(int a1, int a2, int a3, int a4)
{
  int result; // r0
  unsigned __int16 v9[2]; // [sp+0h] [bp-20h] BYREF
  const __int16 *v10; // [sp+4h] [bp-1Ch]
  int v11; // [sp+8h] [bp-18h]

  v11 = a4;
  v9[0] = 30;
  v9[1] = 32;
  v10 = L"VerifierExt.sys";
  result = RtlEqualUnicodeString((unsigned __int16 *)(a1 + 44), v9, 1);
  if ( result == 1 )
    return sub_8E5150();
  if ( ViVerifierDriverAddedThunkListHead )
    return VfSuspectDriversLoadCallback(a1, a2, a3, a4);
  if ( !a4 )
    result = VfTargetDriversAdd(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 32), 0, ViVerifierDriverAddedThunkListHead);
  return result;
}
