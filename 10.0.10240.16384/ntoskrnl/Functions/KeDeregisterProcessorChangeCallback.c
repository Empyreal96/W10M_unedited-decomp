// KeDeregisterProcessorChangeCallback 
 
int __fastcall KeDeregisterProcessorChangeCallback(int a1)
{
  return ExUnregisterCallback(a1);
}
