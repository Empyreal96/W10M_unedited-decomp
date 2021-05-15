// PsSetLegoNotifyRoutine 
 
int __fastcall PsSetLegoNotifyRoutine(int (__fastcall *a1)(_DWORD))
{
  PspLegoNotifyRoutine = a1;
  return 440;
}
