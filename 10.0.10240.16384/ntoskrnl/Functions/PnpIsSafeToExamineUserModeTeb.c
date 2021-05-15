// PnpIsSafeToExamineUserModeTeb 
 
BOOL PnpIsSafeToExamineUserModeTeb()
{
  unsigned int v0; // r4

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1
      && !*(_WORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136)
      && KeAreInterruptsEnabled()
      && !KeGetCurrentIrql()
      && *(unsigned __int8 *)(v0 + 974) <= 1u;
}
