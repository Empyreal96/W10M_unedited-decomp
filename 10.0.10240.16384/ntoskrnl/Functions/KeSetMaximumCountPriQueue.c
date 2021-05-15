// KeSetMaximumCountPriQueue 
 
int __fastcall KeSetMaximumCountPriQueue(int result, int a2)
{
  if ( !a2 )
    a2 = KeNumberProcessors_0;
  *(_DWORD *)(result + 400) = a2;
  return result;
}
