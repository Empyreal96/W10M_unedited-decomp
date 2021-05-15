// HvpMapHiveImageFromFile 
 
int __fastcall HvpMapHiveImageFromFile(int a1, int a2, int a3, int a4)
{
  int v7; // r4
  int v8; // [sp+14h] [bp-1Ch]

  v8 = ExAllocatePoolWithTag(1, a4, 1867074883);
  if ( !v8 )
    return sub_7F3694();
  v7 = HvpMapHiveImage(a1, a4);
  ExFreePoolWithTag(v8);
  return v7;
}
