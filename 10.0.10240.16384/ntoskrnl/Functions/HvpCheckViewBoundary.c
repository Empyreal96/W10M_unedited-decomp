// HvpCheckViewBoundary 
 
BOOL __fastcall HvpCheckViewBoundary(int a1, int a2)
{
  return (((a2 + 4096) ^ (a1 + 4096)) & 0xFFFC0000) == 0;
}
