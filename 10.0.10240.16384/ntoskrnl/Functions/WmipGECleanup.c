// WmipGECleanup 
 
unsigned int __fastcall WmipGECleanup(int a1)
{
  __int64 v2; // r0

  v2 = *(_QWORD *)(a1 + 72);
  if ( v2 )
    EtwUnregister(v2);
  return ExFreePoolWithTag(*(_DWORD *)(a1 + 64));
}
