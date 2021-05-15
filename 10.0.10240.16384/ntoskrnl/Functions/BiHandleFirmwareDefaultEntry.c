// BiHandleFirmwareDefaultEntry 
 
int __fastcall BiHandleFirmwareDefaultEntry(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5[2]; // [sp+0h] [bp-28h] BYREF
  unsigned int v6[8]; // [sp+8h] [bp-20h] BYREF

  v6[0] = a4;
  v5[0] = 0;
  v5[1] = a4;
  if ( BiGetElement(a2, 587202563, v5, v6) != -1073741275 )
    return sub_812F68();
  if ( v5[0] )
    ExFreePoolWithTag(v5[0]);
  return 0;
}
