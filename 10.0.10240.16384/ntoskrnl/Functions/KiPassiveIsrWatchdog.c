// KiPassiveIsrWatchdog 
 
void __fastcall __noreturn KiPassiveIsrWatchdog(int a1, int a2)
{
  KeSetEvent(a2, 0, 0);
  DbgPrintEx(101, 0, (int)"\nPassive-level ISR watchdog timeout! Interrupt: %p\n", *(_DWORD *)(a2 + 16));
  __debugbreak();
}
