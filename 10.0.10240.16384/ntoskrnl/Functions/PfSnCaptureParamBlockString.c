// PfSnCaptureParamBlockString 
 
int __fastcall PfSnCaptureParamBlockString(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r1

  *a3 = *a2;
  a3[1] = a2[1];
  v3 = a3[1];
  if ( !v3 || !*(_WORD *)a3 )
    return -1073741275;
  if ( (*(_DWORD *)(a1 + 8) & 1) == 0 )
    a3[1] = v3 + a1;
  return 0;
}
