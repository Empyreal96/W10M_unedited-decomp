// HeadlessTerminalAddResources 
 
int __fastcall HeadlessTerminalAddResources(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  if ( HeadlessGlobals )
    return sub_80CEA8();
  *a4 = 0;
  *a5 = 0;
  return 0;
}
