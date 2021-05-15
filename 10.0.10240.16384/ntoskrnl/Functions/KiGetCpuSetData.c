// KiGetCpuSetData 
 
int __fastcall KiGetCpuSetData(int a1, int a2)
{
  return KiCpuSetData + 16 * a2;
}
