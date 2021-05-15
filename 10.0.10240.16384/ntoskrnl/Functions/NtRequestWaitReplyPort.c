// NtRequestWaitReplyPort 
 
int __fastcall NtRequestWaitReplyPort(int a1, int a2, int a3, int a4)
{
  int v6; // r5
  int v7; // r4
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = a4;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v6, v9);
  if ( v7 >= 0 )
  {
    v7 = LpcpRequestWaitReplyPort(v9[0], a2, a3, v6);
    ObfDereferenceObject(v9[0]);
  }
  return v7;
}
