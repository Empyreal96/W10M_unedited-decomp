// NtQueryInstallUILanguage 
 
int __fastcall NtQueryInstallUILanguage(_WORD *a1)
{
  int result; // r0
  _WORD *v3; // r2

  result = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v3 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v3 = (_WORD *)MmUserProbeAddress;
    *v3 = *v3;
  }
  *a1 = PsInstallUILanguageId;
  return result;
}
