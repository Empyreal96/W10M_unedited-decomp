// SepInternalFillNoAttribs 
 
int __fastcall SepInternalFillNoAttribs(_DWORD *a1, unsigned int a2, _DWORD *a3)
{
  *a3 = 12;
  if ( a2 < 0xC )
    return -1073741789;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  *(_WORD *)a1 = 1;
  return 0;
}
