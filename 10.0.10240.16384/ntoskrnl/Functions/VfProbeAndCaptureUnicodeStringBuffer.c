// VfProbeAndCaptureUnicodeStringBuffer 
 
int __fastcall VfProbeAndCaptureUnicodeStringBuffer(unsigned __int16 *a1, int a2)
{
  unsigned __int16 *v2; // r5
  int v3; // r3
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r6

  v2 = a1;
  v3 = *a1;
  if ( (v3 & 1) == 0 )
  {
    if ( *a1 )
    {
      v5 = *((_DWORD *)a1 + 1);
      if ( v5 + v3 > MmUserProbeAddress || v5 + v3 < v5 )
        *(_BYTE *)MmUserProbeAddress = 0;
      v6 = ExAllocatePoolWithTag(a2, *a1, 1129539158);
      v7 = v6;
      if ( !v6 )
        return -1073741801;
      memmove(v6, *((_DWORD *)v2 + 1), *v2);
      *((_DWORD *)v2 + 1) = v7;
    }
    else
    {
      *((_DWORD *)a1 + 1) = MmBadPointer;
    }
    v2[1] = *v2;
    return 0;
  }
  return -1073741811;
}
