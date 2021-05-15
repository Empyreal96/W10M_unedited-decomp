// NtCompareObjects 
 
int __fastcall NtCompareObjects(int a1, int a2, int a3, int a4)
{
  char v5; // r5
  int v6; // r4
  int v7; // r0
  int v8; // r5
  int v10; // [sp+8h] [bp-18h] BYREF
  int v11[5]; // [sp+Ch] [bp-14h] BYREF

  v10 = a3;
  v11[0] = a4;
  v5 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 0, 0, v5, (int)&v10, 0);
  if ( v6 >= 0 )
  {
    v6 = ObReferenceObjectByHandle(a2, 0, 0, v5, (int)v11, 0);
    if ( v6 >= 0 )
    {
      v8 = v10;
      if ( v10 == v11[0] )
        v6 = 0;
      else
        v6 = -1073741396;
      ObfDereferenceObject(v11[0]);
      v7 = v8;
    }
    else
    {
      v7 = v10;
    }
    ObfDereferenceObject(v7);
  }
  return v6;
}
