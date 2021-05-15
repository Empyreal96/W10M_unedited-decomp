// PiDmListInit 
 
int __fastcall PiDmListInit(unsigned int a1)
{
  int v1; // r4
  unsigned int v3[4]; // [sp+0h] [bp-10h] BYREF

  v3[0] = 0;
  v3[1] = 0;
  v3[2] = a1;
  v1 = PiDmEnumObjectsWithCallback(
         PiDmListDefs[5 * a1 + 2],
         (int (__fastcall *)(unsigned int *, int, char *))PiDmListInitEnumCallback,
         (int)v3);
  if ( v3[0] )
    ExFreePoolWithTag(v3[0]);
  return v1;
}
