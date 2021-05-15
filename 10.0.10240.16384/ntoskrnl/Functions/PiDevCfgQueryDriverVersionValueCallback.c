// PiDevCfgQueryDriverVersionValueCallback 
 
int __fastcall PiDevCfgQueryDriverVersionValueCallback(int a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6)
{
  if ( a2 == 3 && a4 == 8 && a3 )
  {
    *a6 = *a3;
    a6[1] = a3[1];
  }
  return 0;
}
