// KiInitializeDebugRegisters 
 
int __fastcall KiInitializeDebugRegisters(int a1, int a2, int a3, int a4)
{
  if ( (__mrc(15, 0, 0, 1, 2) & 0xFu) < 4 )
    sub_519464();
  return KiInitializeCP14DebugState(a1, a2, a3, a4);
}
