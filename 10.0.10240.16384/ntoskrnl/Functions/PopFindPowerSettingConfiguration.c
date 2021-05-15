// PopFindPowerSettingConfiguration 
 
_DWORD *__fastcall PopFindPowerSettingConfiguration(unsigned int a1, int a2)
{
  _DWORD *v4; // r5
  int v5; // r0
  _DWORD *v6; // r4

  v4 = (_DWORD *)PopGetListHead(a1);
  v5 = PopStateIsSessionSpecific(a1);
  v6 = (_DWORD *)*v4;
  if ( v5 )
  {
    while ( v6 != v4 )
    {
      if ( v6[8] == a2 && (v6[9] & 4) == 0 )
        return v6;
      v6 = (_DWORD *)*v6;
    }
  }
  else
  {
    while ( v6 != v4 )
    {
      if ( !memcmp((unsigned int)(v6 + 4), a1, 16) )
        return v6;
      v6 = (_DWORD *)*v6;
    }
  }
  return 0;
}
