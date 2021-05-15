// SepDeleteAccessState 
 
int __fastcall SepDeleteAccessState(int a1)
{
  _DWORD *v2; // r4
  int result; // r0
  int v4; // r0
  int (*v5)(void); // r3

  v2 = *(_DWORD **)(a1 + 48);
  if ( *(_BYTE *)(a1 + 11) )
    return sub_50C72C();
  v4 = *(_DWORD *)(a1 + 104);
  if ( v4 )
    ExFreePoolWithTag(v4, 0);
  result = *(_DWORD *)(a1 + 112);
  if ( result )
    result = ExFreePoolWithTag(result, 0);
  if ( v2 )
  {
    if ( v2[11] )
      result = SeDeassignSecurity(v2 + 11);
    v5 = (int (*)(void))v2[14];
    if ( v5 )
    {
      result = v2[15];
      if ( result )
      {
        if ( v2[12] )
          result = v5();
        if ( v2[13] )
          result = ((int (__fastcall *)(_DWORD))v2[14])(v2[15]);
      }
    }
  }
  return result;
}
