// _wcstoi64 
 
int __fastcall wcstoi64(int a1, int a2, int a3)
{
  return wcstoxq(&_initiallocalestructinfo, a1, a2, a3);
}
