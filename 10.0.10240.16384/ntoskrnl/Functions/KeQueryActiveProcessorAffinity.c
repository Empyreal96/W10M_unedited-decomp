// KeQueryActiveProcessorAffinity 
 
int __fastcall KeQueryActiveProcessorAffinity(_DWORD *a1)
{
  int v1; // r2
  int v2; // r3

  v1 = dword_681D74;
  v2 = dword_681D78[0];
  *a1 = *(_DWORD *)&KeActiveProcessors;
  a1[1] = v1;
  a1[2] = v2;
  return KeNumberProcessors_0;
}
