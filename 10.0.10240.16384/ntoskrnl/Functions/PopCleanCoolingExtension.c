// PopCleanCoolingExtension 
 
unsigned int __fastcall PopCleanCoolingExtension(unsigned int a1)
{
  int v2; // r0

  v2 = *(_DWORD *)(a1 + 28);
  if ( v2 )
    IoUnregisterPlugPlayNotificationEx(v2);
  if ( *(_BYTE *)(a1 + 32) )
    (*(void (__fastcall **)(_DWORD))(a1 + 56))(*(_DWORD *)(a1 + 48));
  return ExFreePoolWithTag(a1);
}
