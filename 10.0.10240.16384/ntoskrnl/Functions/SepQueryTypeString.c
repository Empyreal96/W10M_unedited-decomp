// SepQueryTypeString 
 
int __fastcall SepQueryTypeString(int a1, unsigned int *a2)
{
  int result; // r0
  int v5; // r0
  int v6[2]; // [sp+0h] [bp-20h] BYREF
  __int16 v7; // [sp+8h] [bp-18h] BYREF
  int v8; // [sp+Ah] [bp-16h]
  __int16 v9; // [sp+Eh] [bp-12h]

  v7 = 0;
  v8 = 0;
  v9 = 0;
  *a2 = 0;
  result = ObQueryTypeName(a1, (int)&v7, 0, v6);
  if ( result == -1073741820 )
  {
    v5 = ExAllocatePoolWithTag(1, v6[0], 1851024723);
    *a2 = v5;
    if ( v5 )
    {
      result = ObQueryTypeName(a1, v5, v6[0], v6);
      if ( result < 0 )
      {
        ExFreePoolWithTag(*a2);
        *a2 = 0;
        result = 0;
      }
    }
    else
    {
      result = -1073741670;
    }
  }
  return result;
}
