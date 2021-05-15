// PopFxDestroyDeviceCommon 
 
int __fastcall PopFxDestroyDeviceCommon(int a1)
{
  ExFreePoolWithTag(*(_DWORD *)(a1 + 104));
  return ExFreePoolWithTag(a1);
}
