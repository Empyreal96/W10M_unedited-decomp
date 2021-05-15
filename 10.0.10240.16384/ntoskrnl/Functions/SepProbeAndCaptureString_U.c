// SepProbeAndCaptureString_U 
 
int __fastcall SepProbeAndCaptureString_U(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // r6
  int v3; // r4
  unsigned int v4; // r8
  unsigned int v5; // r5
  _WORD *v6; // r0
  _DWORD *_30; // [sp+30h] [bp+8h]

  _30 = a1;
  v2 = a2;
  *a2 = 0;
  v3 = 0;
  if ( (unsigned int)a1 >= MmUserProbeAddress )
    a1 = (_DWORD *)MmUserProbeAddress;
  v4 = a1[1];
  v5 = (unsigned __int16)*a1;
  if ( (unsigned __int16)*a1 )
  {
    if ( (v4 & 1) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( v5 + v4 > MmUserProbeAddress || v5 + v4 < v4 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  if ( (v5 & 1) != 0 || v5 == 65534 )
    return -1073741811;
  v6 = (_WORD *)ExAllocatePoolWithTag(1, v5 + 8, 1934976339);
  *v2 = v6;
  if ( !v6 )
    return -1073741670;
  *v6 = v5;
  *(_WORD *)(*v2 + 2) = v5;
  *(_DWORD *)(*v2 + 4) = *v2 + 8;
  if ( v5 )
    memmove(*(_DWORD *)(*v2 + 4), v4, v5);
  return v3;
}
