// KeEnterCriticalRegionThread 
 
int __fastcall KeEnterCriticalRegionThread(int result)
{
  --*(_WORD *)(result + 308);
  return result;
}
