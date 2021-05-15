// BvgaDisplayString 
 
int __fastcall BvgaDisplayString(unsigned int a1)
{
  char *v2; // r0

  if ( BvgaDisplayState )
    return 0;
  BvgaAcquireLock(a1);
  if ( BvgaBootDriverInstalled )
    VidDisplayString_0();
  v2 = strlen(a1);
  if ( HeadlessGlobals )
  {
    if ( *(_DWORD *)(HeadlessGlobals + 4) )
      v2 = (char *)HdlspDispatch(3, a1, v2 + 1, 0);
  }
  BvgaReleaseLock(v2);
  return 1;
}
