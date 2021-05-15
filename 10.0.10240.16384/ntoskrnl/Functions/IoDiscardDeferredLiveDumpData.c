// IoDiscardDeferredLiveDumpData 
 
int __fastcall IoDiscardDeferredLiveDumpData(unsigned int a1)
{
  IopLiveDumpTraceInterfaceStart();
  IopLiveDumpTraceInterfaceEnd();
  IopLiveDumpReleaseResources(a1);
  ExFreePoolWithTag(a1);
  return 0;
}
