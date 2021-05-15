// MmSetSessionObjectIoEvent 
 
int __fastcall MmSetSessionObjectIoEvent(int a1)
{
  return KeSetEvent(*(_DWORD *)(a1 + 16) + 8396, 0, 0);
}
