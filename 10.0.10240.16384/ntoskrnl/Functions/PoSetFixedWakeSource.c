// PoSetFixedWakeSource 
 
int __fastcall PoSetFixedWakeSource(int result)
{
  PopFixedWakeSourceMask |= result;
  return result;
}
