// PpHotSwapInitRemovalPolicy 
 
int __fastcall PpHotSwapInitRemovalPolicy(int result)
{
  *(_BYTE *)(result + 318) = 0;
  *(_BYTE *)(result + 319) = 0;
  return result;
}
