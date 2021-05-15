// VfProbeAndCaptureUnicodeString 
 
int __fastcall VfProbeAndCaptureUnicodeString(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *varg_r1; // [sp+1Ch] [bp+Ch]

  varg_r1 = a2;
  if ( (unsigned int)a2 >= MmUserProbeAddress )
    a2 = (_DWORD *)MmUserProbeAddress;
  *a1 = *a2;
  a1[1] = a2[1];
  return VfProbeAndCaptureUnicodeStringBuffer(a1, a3);
}
