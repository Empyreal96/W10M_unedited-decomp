// WmipProbeWmiOpenGuidBlock 
 
int __fastcall WmipProbeWmiOpenGuidBlock(_DWORD *a1, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6, int a7)
{
  int result; // r0

  if ( a6 != 16 || a7 != 16 )
    return -1073741823;
  *a4 = a5[1];
  result = WmipProbeAndCaptureGuidObjectAttributes(a1, a2, a3, *a5);
  if ( result >= 0 && (a1[1] || a1[3] || a1[4] || a1[5]) )
    result = -1073741811;
  return result;
}
