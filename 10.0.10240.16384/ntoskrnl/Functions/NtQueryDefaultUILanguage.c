// NtQueryDefaultUILanguage 
 
int __fastcall NtQueryDefaultUILanguage(_WORD *a1, int a2, _WORD *a3)
{
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    a3 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a3 = (_WORD *)MmUserProbeAddress;
    *a3 = *a3;
  }
  if ( ExpGetCurrentUserUILanguage((int)a1, a1, (int)a3) < 0 )
    *a1 = PsInstallUILanguageId;
  return 0;
}
