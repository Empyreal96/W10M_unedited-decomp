// BvgaSetProgressBarSubset 
 
int __fastcall BvgaSetProgressBarSubset(int result, int a2)
{
  BvgaProgressState = 100 * result;
  dword_631C04 = 100 * a2;
  dword_631C08 = a2 - result;
  return result;
}
