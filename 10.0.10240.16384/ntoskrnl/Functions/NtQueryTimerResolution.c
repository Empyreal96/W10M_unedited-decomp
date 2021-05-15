// NtQueryTimerResolution 
 
int __fastcall NtQueryTimerResolution(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v4; // r4
  _DWORD *v5; // r2
  _DWORD *v6; // r2

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v4 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v4 = (_DWORD *)MmUserProbeAddress;
    *v4 = *v4;
    v5 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
    v6 = a3;
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      v6 = (_DWORD *)MmUserProbeAddress;
    *v6 = *v6;
    *a1 = KeMaximumIncrement;
    *a2 = KeMinimumIncrement;
    *a3 = KeTimeIncrement;
  }
  else
  {
    *a1 = KeMaximumIncrement;
    *a2 = KeMinimumIncrement;
    *a3 = KeTimeIncrement;
  }
  return 0;
}
