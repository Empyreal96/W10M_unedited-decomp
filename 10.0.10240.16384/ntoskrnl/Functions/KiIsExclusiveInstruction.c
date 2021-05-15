// KiIsExclusiveInstruction 
 
BOOL __fastcall KiIsExclusiveInstruction(int a1)
{
  unsigned int v1; // r2

  v1 = a1 & 0xFFF000F0;
  return (a1 & 0xFFF000F0) == -390070208
      || v1 == -390070192
      || v1 == -390070160
      || v1 == -389021632
      || v1 == -389021616
      || v1 == -389021584
      || (a1 & 0xFFF00000) == -398458880
      || (a1 & 0xFFF00000) == -397410304;
}
