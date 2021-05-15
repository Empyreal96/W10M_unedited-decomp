// NtQueryIntervalProfile 
 
int __fastcall NtQueryIntervalProfile(int a1, int *a2)
{
  int *v2; // r2
  int *varsC; // [sp+24h] [bp+Ch]

  varsC = a2;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v2 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v2 = (int *)MmUserProbeAddress;
    *v2 = *v2;
  }
  *a2 = KeQueryIntervalProfile(a1);
  return 0;
}
