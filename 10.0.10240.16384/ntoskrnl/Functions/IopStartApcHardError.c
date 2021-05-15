// IopStartApcHardError 
 
int __fastcall IopStartApcHardError(unsigned int a1)
{
  int v3; // [sp+10h] [bp-8h] BYREF

  if ( PsCreateSystemThread((int)&v3, 0, 0) >= 0 )
    return ZwClose();
  IofCompleteRequest(*(_DWORD *)(a1 + 16), 1);
  return ExFreePoolWithTag(a1);
}
