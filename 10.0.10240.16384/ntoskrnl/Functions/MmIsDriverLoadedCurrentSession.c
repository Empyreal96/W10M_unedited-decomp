// MmIsDriverLoadedCurrentSession 
 
BOOL __fastcall MmIsDriverLoadedCurrentSession(int a1)
{
  return MiSessionLookupImage(a1) != 0;
}
