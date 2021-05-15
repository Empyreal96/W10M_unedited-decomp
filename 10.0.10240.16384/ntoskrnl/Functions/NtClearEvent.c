// NtClearEvent 
 
int __fastcall NtClearEvent(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  int result; // r0
  int v6; // r4
  int v7; // [sp+8h] [bp-8h] BYREF

  v7 = a4;
  v4 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  result = ObReferenceObjectByHandle(a1, 2, ExEventObjectType, v4, &v7);
  v6 = result;
  if ( result >= 0 )
  {
    KeResetEvent(v7);
    ObfDereferenceObject(v7);
    result = v6;
  }
  return result;
}
