// NtQueryDefaultLocale 
 
int __fastcall NtQueryDefaultLocale(int a1, _DWORD *a2)
{
  _DWORD *v2; // r2

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v2 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v2 = (_DWORD *)MmUserProbeAddress;
    *v2 = *v2;
  }
  if ( a1 )
    *a2 = MmGetSessionLocaleId(a1);
  else
    *a2 = PsDefaultSystemLocaleId;
  return 0;
}
