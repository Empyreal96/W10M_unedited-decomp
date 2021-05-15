// -CompareLangName@@YAHPBX0@Z 
 
int __fastcall CompareLangName(const void *a1, const void *a2)
{
  return wcsicmp(a1, *(_DWORD *)a2);
}
