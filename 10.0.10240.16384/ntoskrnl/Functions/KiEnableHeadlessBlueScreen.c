// KiEnableHeadlessBlueScreen 
 
int __fastcall KiEnableHeadlessBlueScreen(int a1, int a2, int a3)
{
  int v3; // r2
  int v6; // [sp+8h] [bp-10h] BYREF
  int v7[3]; // [sp+Ch] [bp-Ch] BYREF

  v6 = a3;
  v3 = HeadlessGlobals;
  v7[0] = KiBugCheckData;
  LOBYTE(v6) = 1;
  if ( HeadlessGlobals )
  {
    if ( *(_DWORD *)(HeadlessGlobals + 4) )
    {
      a1 = 0;
      HdlspDispatch(14, 0, 0, 0);
      v3 = HeadlessGlobals;
    }
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 + 4) )
      {
        a1 = 0;
        HdlspDispatch(1, &v6, 1, 0);
        v3 = HeadlessGlobals;
      }
      if ( v3 && *(_DWORD *)(v3 + 4) )
      {
        a1 = 0;
        HdlspDispatch(20, v7, 4, 0);
      }
    }
  }
  return a1;
}
