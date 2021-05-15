// AuthzBasepInitializeSystemSecurityAttributes 
 
int __fastcall AuthzBasepInitializeSystemSecurityAttributes(int a1, int a2)
{
  _DWORD *v2; // r4
  BOOL v3; // r0
  bool v4; // r6
  int v5; // r5
  unsigned int v6; // r1
  int v8; // [sp+0h] [bp-48h] BYREF
  int v9[2]; // [sp+8h] [bp-40h] BYREF
  __int16 v10[2]; // [sp+10h] [bp-38h] BYREF
  int v11; // [sp+14h] [bp-34h]
  __int16 *v12; // [sp+18h] [bp-30h]
  __int16 v13[2]; // [sp+20h] [bp-28h] BYREF
  const __int16 *v14; // [sp+24h] [bp-24h]
  int v15; // [sp+28h] [bp-20h]
  int v16; // [sp+2Ch] [bp-1Ch]
  int v17; // [sp+30h] [bp-18h]
  int *v18; // [sp+34h] [bp-14h]

  v13[0] = 46;
  v13[1] = 48;
  v14 = L"WIN://ISMULTISESSIONSKU";
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v10[1] = 0;
  v8 = 2;
  v11 = 1;
  v10[0] = 1;
  v12 = v13;
  v2 = AuthzBasepAllocateSecurityAttributesList(a1, a2);
  if ( !v2 )
    return -1073741670;
  v3 = RtlIsMultiSessionSku();
  v4 = v3;
  v9[0] = v3;
  LOWORD(v15) = 6;
  v17 = 1;
  v9[1] = 0;
  v18 = v9;
  v5 = AuthzBasepSetSecurityAttributesToken((int)v2, &v8, (int)v10);
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&WindowsSystemAttributes);
  while ( !v6 && __strex((unsigned int)v2, (unsigned int *)&WindowsSystemAttributes) );
  __dmb(0xBu);
  if ( v6 )
  {
    v5 = -1073741823;
  }
  else
  {
    v2 = 0;
    if ( !&SepAllowAccessUponLogoff )
      return v5;
    LOBYTE(SepAllowAccessUponLogoff) = v4;
  }
  if ( v2 )
    return sub_8102A0();
  return v5;
}
