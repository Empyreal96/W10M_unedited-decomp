// NtSetEventBoostPriority 
 
int __fastcall NtSetEventBoostPriority(int a1, int a2, int a3, int a4)
{
  char v4; // r3
  int v5; // r2
  int v6; // r5
  int v7; // r4
  int v8; // r3
  int v10[4]; // [sp+8h] [bp-10h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 2, ExEventObjectType, v4, (int)v10, 0);
  if ( v6 >= 0 )
  {
    v7 = v10[0];
    v8 = *(unsigned __int8 *)v10[0];
    if ( (v8 & 0x7F) != 0 )
      KeSetEventBoostPriority(v10[0], 0, v5, v8);
    else
      v6 = -1073741788;
    ObfDereferenceObject(v7);
  }
  return v6;
}
