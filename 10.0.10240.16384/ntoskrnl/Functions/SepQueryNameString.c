// SepQueryNameString 
 
int __fastcall SepQueryNameString(int a1, unsigned int *a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r4
  int v8; // r0
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  *a2 = 0;
  v6 = ObQueryNameString(a1, 0, 0, v10);
  v7 = v6;
  if ( v6 == -1073741820 || v6 == -1073741789 )
  {
    v8 = ExAllocatePoolWithTag(1, v10[0], 1850697043);
    *a2 = v8;
    if ( v8 )
    {
      v7 = ObQueryNameString(a1, v8, v10[0], v10);
      if ( v7 < 0 || !*(_WORD *)*a2 )
      {
        ExFreePoolWithTag(*a2);
        *a2 = 0;
        if ( v7 >= 0
          && ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)] == PsProcessType )
        {
          SeLocateProcessImageName(a1);
        }
        v7 = 0;
      }
    }
    else
    {
      v7 = -1073741670;
    }
  }
  return v7;
}
