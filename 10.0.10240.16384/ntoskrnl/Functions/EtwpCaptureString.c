// EtwpCaptureString 
 
int __fastcall EtwpCaptureString(unsigned __int16 *a1, unsigned int a2)
{
  int v2; // r9
  unsigned __int16 *v3; // r8
  int v4; // r4
  int v5; // r5
  unsigned int v6; // r0
  int v7; // r3
  unsigned int v8; // r2
  int v9; // r0
  unsigned __int16 *v10; // r6

  v2 = a2;
  v3 = a1;
  v4 = 0;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = RtlInitUnicodeString(a2, 0);
  if ( v5 )
  {
    v7 = *v3;
    if ( *v3 )
    {
      v8 = *((_DWORD *)v3 + 1);
      if ( (v8 & 1) != 0 )
        ExRaiseDatatypeMisalignment(v6);
      if ( v8 + v7 > MmUserProbeAddress || v8 + v7 < v8 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  v9 = ExAllocatePoolWithTag(1, *v3 + 2, 1350005829);
  v10 = (unsigned __int16 *)v9;
  if ( !v9 || (memmove(v9, *((_DWORD *)v3 + 1), *v3), v10[*v3 >> 1] = 0, !RtlCreateUnicodeString(v2, v10)) )
    v4 = -1073741801;
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
  return v4;
}
