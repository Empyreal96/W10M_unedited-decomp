// KeCheckProcessorGroupAffinity 
 
int __fastcall KeCheckProcessorGroupAffinity(_DWORD *a1, char a2)
{
  return (*a1 >> a2) & 1;
}
