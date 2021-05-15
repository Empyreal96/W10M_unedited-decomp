// CcSetReadAheadGranularity 
 
int __fastcall CcSetReadAheadGranularity(int result, int a2)
{
  *(_DWORD *)(*(_DWORD *)(result + 24) + 4) = a2 - 1;
  return result;
}
