// sub_518914 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_518914(int a1, int a2, int a3, int a4)
{
  if ( !*(_DWORD *)(a4 + 4) )
    JUMPOUT(0x4D92B0);
  return HdlspKernelAddLogEntry();
}
