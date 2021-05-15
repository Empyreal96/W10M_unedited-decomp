// BgkDisplayStringEx 
 
int __fastcall BgkDisplayStringEx(unsigned __int16 *a1)
{
  BOOL v2; // r5
  unsigned int v3; // r0
  unsigned int v4; // r4
  unsigned int v5; // r1

  if ( !a1 )
    return 0;
  if ( !*a1 )
    return 1;
  if ( !BgkpAcquireConsole() )
    return 0;
  v3 = wcslen(a1);
  if ( HeadlessGlobals && *(_DWORD *)(HeadlessGlobals + 4) )
    v3 = HdlspDispatch(23, a1, 2 * (v3 + 1), 0);
  if ( byte_63760A || byte_63761C )
  {
    byte_63760A = 0;
    byte_63761C = 0;
    BgDisplayFade(v3);
  }
  v2 = (*(int (__fastcall **)(unsigned __int16 *))(dword_637614 + 12))(a1) >= 0;
  __pld(&dword_61646C);
  v4 = dword_61646C & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_61646C);
  while ( v5 == v4 && __strex(v4 - 2, (unsigned int *)&dword_61646C) );
  if ( v5 != v4 )
    ExfReleaseRundownProtection((unsigned __int8 *)&dword_61646C);
  return v2;
}
