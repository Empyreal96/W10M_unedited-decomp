// AuthzBasepReplaceSecurityAttribute 
 
int __fastcall AuthzBasepReplaceSecurityAttribute(int a1, _DWORD *a2)
{
  int v3; // r3
  int v4; // r4
  int v5; // r5
  int result; // r0
  _DWORD v8[12]; // [sp+0h] [bp-30h] BYREF

  v3 = a2[1];
  v4 = a2[2];
  v5 = a2[3];
  v8[0] = *a2;
  v8[1] = v3;
  v8[2] = v4;
  v8[3] = v5;
  v8[5] = a2[5];
  v8[4] = 0;
  result = AuthzBasepDeleteSecurityAttribute(a1, v8);
  if ( result == -1073741275 )
    result = 0;
  if ( result >= 0 )
  {
    if ( a2[4] )
      result = AuthzBasepAddSecurityAttribute(a1, a2);
  }
  return result;
}
