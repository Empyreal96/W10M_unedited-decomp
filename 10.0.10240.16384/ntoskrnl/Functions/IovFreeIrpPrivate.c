// IovFreeIrpPrivate 
 
int __fastcall IovFreeIrpPrivate(int a1)
{
  int v2; // r3
  int result; // r0

  v2 = IovpDisabledWithoutReboot;
  __dmb(0xBu);
  if ( !v2 )
  {
    if ( *(_WORD *)a1 != 6 )
      KeBugCheckEx(201, 1, a1, 0, 0);
    if ( *(_DWORD *)(a1 + 16) != a1 + 16 )
      KeBugCheckEx(201, 2, a1, 0, 0);
  }
  result = ((int (__fastcall *)(int))VfIoFreeIrp)(a1);
  if ( !result )
    result = IopFreeIrp(a1);
  return result;
}
