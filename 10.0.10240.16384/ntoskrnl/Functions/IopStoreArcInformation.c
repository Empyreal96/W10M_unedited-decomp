// IopStoreArcInformation 
 
int __fastcall IopStoreArcInformation(int a1)
{
  _DWORD *v1; // r10
  int result; // r0

  v1 = *(_DWORD **)(a1 + 128);
  IoArcTableListHead = &IoArcTableListHead;
  *(_DWORD *)algn_9209DC = &IoArcTableListHead;
  if ( (_DWORD *)*v1 == v1 )
    result = 0;
  else
    result = sub_96EB48();
  return result;
}
