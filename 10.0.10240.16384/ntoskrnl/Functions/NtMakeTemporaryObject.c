// NtMakeTemporaryObject 
 
int __fastcall NtMakeTemporaryObject(int a1)
{
  int v1; // r4
  int v2; // r0
  int v4; // [sp+8h] [bp-18h] BYREF
  int v5; // [sp+10h] [bp-10h]

  v1 = ObReferenceObjectByHandle(a1, 0x10000, 0, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), &v4);
  if ( v1 >= 0 )
  {
    v2 = ObMakeTemporaryObject(v4);
    if ( (v5 & 4) != 0 )
      return sub_7EA5FC(v2);
    ObfDereferenceObject(v4);
  }
  return v1;
}
