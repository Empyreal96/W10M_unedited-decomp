// KeExpandKernelStackAndCalloutEx 
 
int __fastcall KeExpandKernelStackAndCalloutEx(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5

  v5 = 0;
  if ( a4 )
    v5 = 2;
  return KeExpandKernelStackAndCalloutInternal(a1, a2, a3, v5, a5);
}
