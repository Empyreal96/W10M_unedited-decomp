// PiUEventDequeuePendingEventWorker 
 
int __fastcall PiUEventDequeuePendingEventWorker(int a1, _DWORD *a2)
{
  if ( *(_DWORD **)(*a2 + 4) != a2 )
    JUMPOUT(0x7C0C14);
  return sub_7C0C0C(a1, a2[1]);
}
