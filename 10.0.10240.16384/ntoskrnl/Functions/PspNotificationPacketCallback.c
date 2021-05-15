// PspNotificationPacketCallback 
 
int __fastcall PspNotificationPacketCallback(int a1, _DWORD *a2, int a3)
{
  int v4; // r3
  unsigned int v5; // r5
  int v6; // r0
  int v7; // r1
  unsigned int *v8; // r9
  int v9; // r6
  unsigned int v10; // r2
  int v12; // r0
  int v13; // r0
  __int16 v14; // r3
  unsigned __int64 *v15; // r3
  unsigned __int64 v16; // kr00_8

  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = v4 & 0xFFFFFFC0;
  if ( (v4 & 0xFFFFFFC0) != 0 )
  {
    v4 = *(__int16 *)((v4 & 0xFFFFFFC0) + 0x136) - 1;
    *(_WORD *)(v5 + 310) = v4;
  }
  v6 = ExAcquireResourceExclusiveLite((int)(a2 + 8), 1, a3, v4);
  v7 = a2[186];
  v8 = a2 + 186;
  while ( 1 )
  {
    v9 = 0;
    v10 = v7;
    if ( (v7 & 0x4000) != 0 )
      return sub_7EAA6C(v6);
    if ( (v7 & 0x10000) != 0 && (v10 = v7 & 0xFFFEFFFF, (a2[107] & 0x1000) != 0) )
    {
      v9 = 12;
    }
    else if ( (v10 & 0x8000) != 0 && (v10 &= 0xFFFF7FFF, (a2[107] & 0x10) != 0) )
    {
      v9 = 4;
    }
    else
    {
      v10 &= 0xFFFFFFF7;
    }
    __dmb(0xBu);
    do
      v6 = __ldrex(v8);
    while ( v6 == v7 && __strex(v10, v8) );
    __dmb(0xBu);
    if ( v6 == v7 )
      break;
    v7 = v6;
  }
  v12 = a2[53];
  if ( !v12 )
    v9 = 0;
  if ( v9 )
  {
    a1 = v9;
    IoSetIoCompletionEx(v12, a2[54], 0, 0);
    __dmb(0xBu);
    v15 = (unsigned __int64 *)(a2 + 56);
    do
      v16 = __ldrexd(v15);
    while ( __strexd(v16 + 1, v15) );
    __dmb(0xBu);
  }
  v13 = ExReleaseResourceLite((int)(a2 + 8));
  if ( v5 )
  {
    v14 = *(_WORD *)(v5 + 310) + 1;
    *(_WORD *)(v5 + 310) = v14;
    if ( !v14 && *(_DWORD *)(v5 + 100) != v5 + 100 )
      KiCheckForKernelApcDelivery(v13);
  }
  if ( !v9 )
    ObfDereferenceObjectWithTag((int)a2);
  return a1;
}
