// IopDropIrp 
 
int __fastcall IopDropIrp(_DWORD *a1, int a2)
{
  int result; // r0
  _DWORD *v5; // r0
  _DWORD *v6; // r4
  int v7; // r0
  unsigned int *v8; // r4
  unsigned int v9; // r1

  if ( (a1[2] & 0x20) != 0 )
    return sub_527874();
  v5 = (_DWORD *)a1[1];
  if ( v5 )
  {
    do
    {
      v6 = (_DWORD *)*v5;
      IoFreeMdl((int)v5);
      v5 = v6;
    }
    while ( v6 );
  }
  v7 = a1[11];
  if ( v7 && a2 && (a1[2] & 4) == 0 )
    ObfDereferenceObjectWithTag(v7);
  if ( (a1[2] & 0x2000) != 0 )
    IopDequeueIrpFromFileObject(a1, a2);
  if ( a2 && (a1[2] & 0x80) == 0 )
  {
    v8 = (unsigned int *)(a2 - 24);
    if ( ObpTraceFlags )
      ObpPushStackInfo(a2 - 24, 0, 1, 1953261124);
    __dmb(0xBu);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 - 1, v8) );
    if ( (int)(v9 - 1) <= 0 )
    {
      if ( v9 != 1 )
        KeBugCheckEx(24, 0, a2);
      ObpDeferObjectDeletion(a2 - 24);
    }
  }
  if ( (a1[2] & 0x8000) == 0 || (result = sub_456A04(a1 + 12, -1)) == 0 )
    result = pIoFreeIrp(a1);
  return result;
}
