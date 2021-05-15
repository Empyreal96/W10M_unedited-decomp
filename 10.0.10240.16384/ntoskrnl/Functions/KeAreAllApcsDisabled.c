// KeAreAllApcsDisabled 
 
BOOL __fastcall KeAreAllApcsDisabled(int a1)
{
  return *(_WORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136) || (__get_CPSR() & 0x80) != 0 || KeGetCurrentIrql(a1);
}
