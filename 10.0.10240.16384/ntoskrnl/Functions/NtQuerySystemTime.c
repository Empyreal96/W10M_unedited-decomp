// NtQuerySystemTime 
 
int __fastcall NtQuerySystemTime(unsigned int a1, int a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]

  v6 = a3;
  v7 = a4;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a1 = *(_BYTE *)a1;
    *(_BYTE *)(a1 + 4) = *(_BYTE *)(a1 + 4);
    KeQuerySystemTime(&v6);
    *(_DWORD *)a1 = v6;
    *(_DWORD *)(a1 + 4) = v7;
  }
  else
  {
    KeQuerySystemTime((_DWORD *)a1);
  }
  return 0;
}
