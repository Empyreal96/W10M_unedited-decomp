// IopSetIoRoutines 
 
void IopSetIoRoutines()
{
  if ( !pIofCompleteRequest )
    pIofCompleteRequest = (int (__fastcall *)(_DWORD, _DWORD))IopfCompleteRequest;
  if ( !pIoAllocateIrp )
    pIoAllocateIrp = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))IopAllocateIrpPrivate;
  if ( !pIoFreeIrp )
    pIoFreeIrp = IopFreeIrp;
}
