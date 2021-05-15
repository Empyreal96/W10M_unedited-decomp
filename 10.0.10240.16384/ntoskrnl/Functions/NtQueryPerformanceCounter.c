// NtQueryPerformanceCounter 
 
int __fastcall NtQueryPerformanceCounter(unsigned int a1, unsigned int a2)
{
  int v5; // [sp+0h] [bp-20h] BYREF
  int v6; // [sp+4h] [bp-1Ch]
  int v7; // [sp+8h] [bp-18h] BYREF
  int v8; // [sp+Ch] [bp-14h]

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a1 = *(_BYTE *)a1;
    *(_BYTE *)(a1 + 4) = *(_BYTE *)(a1 + 4);
    if ( a2 )
    {
      if ( (a2 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a2 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a2 = *(_BYTE *)a2;
      *(_BYTE *)(a2 + 4) = *(_BYTE *)(a2 + 4);
    }
    KeQueryPerformanceCounter(&v7, &v5);
    *(_DWORD *)a1 = v7;
    *(_DWORD *)(a1 + 4) = v8;
    if ( a2 )
    {
      *(_DWORD *)a2 = v5;
      *(_DWORD *)(a2 + 4) = v6;
    }
  }
  else
  {
    KeQueryPerformanceCounter(&v7, &v5);
    *(_DWORD *)a1 = v7;
    *(_DWORD *)(a1 + 4) = v8;
    if ( a2 )
    {
      *(_DWORD *)a2 = v5;
      *(_DWORD *)(a2 + 4) = v6;
    }
  }
  return 0;
}
