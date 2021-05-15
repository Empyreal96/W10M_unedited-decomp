// NtSetWnfProcessNotificationEvent 
 
int __fastcall NtSetWnfProcessNotificationEvent(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  int v5; // r0
  int v6; // r4
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // [sp+8h] [bp-18h] BYREF
  int v13[5]; // [sp+Ch] [bp-14h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v4 = *(_DWORD *)(v3 + 724);
  v12 = v4;
  __dmb(0xBu);
  if ( !v4 )
  {
    v5 = ExpWnfCreateProcessContext(v3, &v12);
    v6 = v5;
    if ( v5 < 0 )
      goto LABEL_11;
    v4 = v12;
  }
  v5 = ObReferenceObjectByHandle(a1, 2, ExEventObjectType, 1, v13);
  v6 = v5;
  if ( v5 >= 0 )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)(v4 + 64);
    v5 = v13[0];
    do
      v8 = __ldrex(v7);
    while ( !v8 && __strex(v5, v7) );
    __dmb(0xBu);
    if ( v8 )
      return sub_7E8F40(v5);
    v6 = 0;
  }
LABEL_11:
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return v6;
}
