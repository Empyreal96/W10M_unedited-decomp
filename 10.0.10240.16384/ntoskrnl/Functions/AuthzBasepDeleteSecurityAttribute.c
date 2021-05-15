// AuthzBasepDeleteSecurityAttribute 
 
int __fastcall AuthzBasepDeleteSecurityAttribute(int a1, int a2)
{
  int result; // r0
  __int16 v3[2]; // [sp+8h] [bp-20h] BYREF
  int v4; // [sp+Ch] [bp-1Ch]

  v3[0] = *(_WORD *)a2;
  v3[1] = v3[0];
  v4 = *(_DWORD *)(a2 + 4);
  if ( AuthzBasepFindSecurityAttribute(a1, (int)v3) )
    result = sub_52ADF4();
  else
    result = -1073741275;
  return result;
}
