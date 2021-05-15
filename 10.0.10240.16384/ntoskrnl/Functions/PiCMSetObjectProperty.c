// PiCMSetObjectProperty 
 
int __fastcall PiCMSetObjectProperty(unsigned int a1, unsigned int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r5
  char v8[88]; // [sp+24h] [bp-58h] BYREF

  *a6 = 0;
  v6 = PiCMCapturePropertyInputData(a1, a2, 0, (int)v8);
  if ( v6 >= 0 )
    return sub_7DEC74();
  PiCMReleasePropertyInputData((int)v8);
  return v6;
}
