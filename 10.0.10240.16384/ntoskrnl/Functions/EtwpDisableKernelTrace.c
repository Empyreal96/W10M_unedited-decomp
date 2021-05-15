// EtwpDisableKernelTrace 
 
int __fastcall EtwpDisableKernelTrace(int a1, int a2)
{
  if ( !a2 )
    JUMPOUT(0x7D0856);
  return sub_7D06F0();
}
